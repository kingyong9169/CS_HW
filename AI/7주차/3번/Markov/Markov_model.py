from pgmpy.models import MarkovNetwork
from pgmpy.factors.discrete import DiscreteFactor

# 마르코프 랜덤 필드(마르코프 모델) 모델 정의
# 모델의 vertex는 A, B, C, D이다.
model = MarkovNetwork([('A', 'B'), ('B', 'C'), ('C', 'D'), ('D', 'A')])
factor1 = DiscreteFactor(['A', 'B'], [2, 2], [30, 5, 1, 10], state_names={
                         'A': [0, 1], 'B': [0, 1]}) # A, B를 연결한 것을 factor1으로 정의
factor2 = DiscreteFactor(['B', 'C'], [2, 2], [100, 1, 1, 100], state_names={
                         'B': [0, 1], 'C': [0, 1]}) # B, C를 연결한 것을 factor2으로 정의
factor3 = DiscreteFactor(['C', 'D'], [2, 2], [1, 100, 100, 1], state_names={
                         'C': [0, 1], 'D': [0, 1]}) # C, D를 연결한 것을 factor2으로 정의
factor4 = DiscreteFactor(['D', 'A'], [2, 2], [100, 1, 1, 100], state_names={
                         'D': [0, 1], 'A': [0, 1]}) # D, A를 연결한 것을 factor2으로 정의
model.add_factors(factor1, factor2, factor3, factor4) # 모델에 요소 추가
print('모델의 타당성: ', model.check_model()) # 모델이 타당한지 체크
