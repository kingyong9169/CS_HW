from collections import namedtuple
from random import choice
from monte_carlo_tree_search import MCTS, Node # 몬테카를로의 MCTS, Node를 가져온다.

TTTB = namedtuple("TicTacToeBoard", "tup turn winner terminal") # 틱택토보드 이름을 정한다.

# 명명된 튜플에서 상속하는 것은 클래스를 만들기 때문에 편리합니다.
# 불변 및 사전 정의 __init__, __repr__, __hash__, __eq__, 그 이외
class TicTacToeBoard(TTTB, Node):
    def find_children(board): # 보드에서 자식을 찾는다.
        if board.terminal:  # 게임이 끝나면 아무것도 하지 않음
            return set() # set 반환
        return { # 그렇지 않으면, 비어있는 곳에 각각 시도
            board.make_move(i) for i, value in enumerate(board.tup) if value is None
        } # 튜플의 board, tup을 각각 i, value에 넣고 반복문을 돌려서 value가 None이면 i위치에 board.turn을 표시한다

    def find_random_child(board): # 무작위로 move 선택
        if board.terminal:
            return None  # 게임이 끝나면 아무것도 하지 않음
        empty_spots = [i for i, value in enumerate(board.tup) if value is None]
        # 튜플의 board, tup을 각각 i, value에 넣고 반복문을 돌려서 value가 None이면 i를 empty_spots에 넣는다.
        return board.make_move(choice(empty_spots)) # empty_spots 중 아무거나 랜덤으로 인자로 선택한 위치에 board.turn을 표시한다.

    def reward(board): # 점수 계산
        if not board.terminal: # 게임이 끝나면
            raise RuntimeError(f"reward called on nonterminal board {board}") # 에러를 출력한다.
        if board.winner is board.turn:
            # 본인 차례이면서 본인이 이긴 상황은 불가능하다.
            raise RuntimeError(f"reward called on unreachable board {board}") # 에러를 출력한다.
        if board.turn is (not board.winner): # 상대가 이긴 상황이다.
            return 0  # 종료한다.
        if board.winner is None: # 비긴 상황이다.
            return 0.5  # 0.5를 반환한다.
        raise RuntimeError(f"board has unknown winner type {board.winner}") # 일어날 수 없는 상황이다.

    def is_terminal(board): # 게임 종료 여부를 묻는다.
        return board.terminal # 보드의 단말을 반환한다.

    def make_move(board, index): # index 위치에 board.turn 표시하기
        tup = board.tup[:index] + (board.turn,) + board.tup[index + 1 :] # 처음부터 index까지의 board.tup + board.turn + index+1부터 끝까지 board.tup
        turn = not board.turn # 순서 바꾸기
        winner = _find_winner(tup) # 승자 또는 미종료 판단
        is_terminal = (winner is not None) or not any(v is None for v in tup) # 승자가 존재하거나 미종료가 없는 경우 is_terminal에 넣는다.
        return TicTacToeBoard(tup, turn, winner, is_terminal) # 보드 상태 반환

    def to_pretty_string(board): # 보드 상태 출력
        to_char = lambda v: ("X" if v is True else ("O" if v is False else " ")) # v가 True이면 'X', v가 False이면 '0', 아니면 ' '을 반환하는 to_char함수
        rows = [ # 행
            [to_char(board.tup[3 * row + col]) for col in range(3)] for row in range(3) # 3개의 row, 3개의 col을 반복하며 board.tup값을 인자로 to_char을 호출하여 보드 모양을 만든다.
        ]
        return (
            "\n  1 2 3\n" # rows의 각 요소들을 출력한다.
            + "\n".join(str(i + 1) + " " + " ".join(row) for i, row in enumerate(rows))
            + "\n"
        )


def play_game(): # 게임하기
    tree = MCTS() # 몬테카를로의 클래스를 호출하여 tree에 넣는다.
    board = new_Board() # 비어있는 보드판을 만든다.
    print(board.to_pretty_string()) # 보드판의 상태를 출력한다.
    while True: # 참이면 반복
        row_col = input("enter row,col: ") # row, col을 입력한다.
        row, col = map(int, row_col.split(",")) # ,을 기준으로 잘라서 rows, col에 넣는다.
        index = 3 * (row - 1) + (col - 1) # index = 3 * (row - 1) + (col - 1)
        if board.tup[index] is not None: # 비어있는 위치가 아닌 경우
            raise RuntimeError("Invalid move") # 오류를 출력한다.
        board = board.make_move(index) # index 위치의 보드 상태 변경
        print(board.to_pretty_string()) # 보드판의 상태를 출력한다.
        if board.terminal: # 게임 종료
            break # 반복을 멈춘다.
        # 진행하면서 훈련하거나 처음에만 훈련할 수 있습니다.
        # 여기에서 우리는 매 턴마다 50번의 롤아웃을 하면서 훈련합니다.
        for _ in range(50): # 매변 50번의 rollout을 수행
            tree.do_rollout(board)
        board = tree.choose(board) # 최선의 값을 갖는 move 선택하여 보드에 반영
        print(board.to_pretty_string()) # 보드판의 상태를 출력한다.
        if board.terminal: # 게임 종료
            break # 반복을 멈춘다.


def _winning_combos(): # 이기는 배치 조합
    for start in range(0, 9, 3): # 행에 3개 연속
        yield (start, start + 1, start + 2)
    for start in range(3): # 열에 3개 연속
        yield (start, start + 3, start + 6)
    yield (0, 4, 8) # 오른쪽 아래로 가는 대각선 3개
    yield (2, 4, 6) # 왼쪽 아래로 가는 대각선 3개


def _find_winner(tup):
    "X가 이기면 True, 0이 이기면 False, 미종료 상태이면 None 반환"
    for i1, i2, i3 in _winning_combos(): # 이기는 배치 조합에서 3개의 값을 가져온다.
        v1, v2, v3 = tup[i1], tup[i2], tup[i3] # tup의 각각 위치에 해당하는 것으로 값을 저장한다.
        if False is v1 is v2 is v3: # v1, v2, v3이 모두 False이면 즉, 0이 이기면
            return False # False 리턴
        if True is v1 is v2 is v3: # 모두 True이면 즉, X가 이기면
            return True # True 리턴
    return None # 미종료 상태


def new_Board(): # 비어있는 보드판 생성
    return TicTacToeBoard(tup=(None,) * 9, turn=True, winner=None, terminal=False) # 보드판 초기화


if __name__ == "__main__":
    play_game() # 게임을 시작한다.