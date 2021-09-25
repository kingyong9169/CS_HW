from abc import ABC, abstractmethod
from collections import defaultdict
import math


class MCTS:
    "Monte Carlo tree searcher. 먼저 rollout한 다음, 위치(move)선택"

    def __init__(self, c=1): # 클래스 초기화 함수
        self.Q = defaultdict(int)  # 노드별 이긴 횟수(reward) 값을 0으로 초기화
        self.N = defaultdict(int)  # 노드별 방문횟수(visit count)를 0으로 초기화
        self.children = dict()  # 노드의 자식노드
        self.c = c  # UCT 계산에 사용되는 계수

    def choose(self, node):
        "node의 최선인 자식 노드 선택"
        if node.is_terminal(): # node가 단말인 경우 오류
            raise RuntimeError(f"choose called on terminal node {node}") # 오류메시지 출력

        if node not in self.children: # node가 children에 포함되지 않으면 무작위 선택
            return node.find_random_child() # 노드의 메소드를 호출한다.

        def score(n):  # 점수 계산
            if self.N[n] == 0: # 노드별 방문횟수가 0이면
                return float("-inf")  # 한번도 방문하지 않은 노드인 경우 - 선택 배제
            return self.Q[n] / self.N[n]  # 아니면 노드별 이긴 횟수 / 방문횟수를 반환한다.

        return max(self.children[node], key=score) # grandchild와 점수 중에 큰 값을 반환한다.

    def do_rollout(self, node):
        "게임 트리에서 한 층만 더 보기"
        path = self._select(node) # path에 아직 시도해보지 않은 자식 노드를 찾아서 넣는다.
        leaf = path[-1] # node에 -1을 넣어 아직 시도해보지 않은 자식 노드를 찾아서 leaf에 넣는다
        self._expand(leaf) # leaf의 자식 노드를 찾는다.
        reward = self._simulate(leaf) # leaf의 무작위 시뮬레이션에 대한 결과를 반환해서 reward에 넣는다
        self._backpropagate(path, reward) # 단말 노드의 조상 노드(path)들에게 보상(reward) 전달

    def _select(self, node): # 선택 단계
        "node의 아직 시도해보지 않은 자식 노드 찾기"
        path = [] # 빈 배열 선언
        while True: # 참이면 반복
            path.append(node) # path에 node를 넣는다.
            if node not in self.children or not self.children[node]:
                # node의 child나 grandchild가 아닌 경우: 아직 시도해보지 않은 것 또는 단말 노드이면
                return path # path 반환
            unexplored = self.children[node] - self.children.keys() # grandchild - children의 차집합을 넣는다.
            if unexplored: # 차집합이 존재하면
                n = unexplored.pop() # 차집합에서 하나씩 pop하면서
                path.append(n) # path에 추가한다.
                return path # path 반환한다.
            node = self._uct_select(node)  # 한 단게 내려가기

    def _expand(self, node): # 확장 단계
        "children에 node의 자식노드 추가"
        if node in self.children:
            return  # 이미 확장된 노드
        self.children[node] = node.find_children() # 선택가능 move들을 node의 children에 추가

    def _simulate(self, node): # 시뮬레이션 단계
        "node의 무작위 시뮬레이션에 대한 결과(reward) 반환"
        invert_reward = True # 참으로 선언
        while True: # 참이면
            if node.is_terminal(): # 단말에 도달하면 승패여부 결정
                reward = node.reward() # 점수를 계산하여 reward에 넣는다.
                return 1 - reward if invert_reward else reward # 1 - invert_reward or reward를 반환한다.
            node = node.find_random_child() # 선택할 수 있는 것 중에서 무작위로 선택
            invert_reward = not invert_reward # invert_reward의 값을 뒤집는다.

    def _backpropagate(self, path, reward): # 역전파 단계
        "단말 노드의 조상 노드들에게 보상(reward) 전달"
        for node in reversed(path): # 역순으로 가면서 Monte Carlo 시뮬레이션 결과 반영
            self.N[node] += 1 # 노드의 방문횟수에 1씩 더한다.
            self.Q[node] += reward # 노드의 이긴 횟수에 reward를 더한다.
            reward = 1 - reward  # 자신에게는 1 상대에게는 0, 또는 그 반대

    def _uct_select(self, node): # UCB 정책 적용을 통한 노드 확장 대상 노드 선택
        "탐험(exploration)과 이용(exploitation)의 균형을 맞춰 node의 자식 노드 선택"

        assert all(n in self.children for n in self.children[node])
        # node의 모든 자신 노드가 이미 확장되었는지 확인한다.

        log_N_vertex = math.log(self.N[node]) # 노드의 방문횟수를 저장한다.

        def uct(n):
            "UCB(Upper confidence bound) 점수 계산"
            return self.Q[n] / self.N[n] + self.c * math.sqrt( # 노드별 이긴 횟수 / 방문횟수 + UCT 계산에 사용되는 계수
                log_N_vertex / self.N[n] # *루트(노드의 방분횟수 / 방문횟수)
            )

        return max(self.children[node], key=uct) # grandchild와 uct중 큰 값을 반환한다.


class Node(ABC): # ABC를 인자로 하여 노드 클래스 정의
    " 게임 트리의 노드로서 보드판의 상태 표현"
    @abstractmethod
    def find_children(self):
        "해당 보드판 상태의 가능한 모든 후속 상태"
        return set() # set 반환

    @abstractmethod
    def find_random_child(self):
        "현 보드에 대한 자식 노드 무작위 선택"
        return None # None 반환

    @abstractmethod
    def is_terminal(self):
        "자식 노드인지 판단"
        return True # True 반환

    @abstractmethod
    def reward(self):
        "점수 계산"
        return 0

    @abstractmethod
    def __hash__(self):
        "노드에 해시적용 가능하도록(hashable) 한다"
        return 123456789

    @abstractmethod
    def __eq__(node1, node2):
        "노드는 서로 비교 가능해야 함"
        return True # True 반환