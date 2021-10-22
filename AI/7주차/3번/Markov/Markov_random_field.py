import numpy as np
from Markov_model import model
from pgmpy.inference import VariableElimination

pf_value = model.get_partition_function()  # 모델의 분할 함수를 pf_value에 넣는다.
print('\n분할 함수의 값: ', pf_value)  # 분할 함수 값 출력

infer = VariableElimination(model)  # 추론 객체 생성

phi_ABCD = infer.query(['A', 'B', 'C', 'D'])  # 전체 분포 phi(A, B, C, D)
print('phi(A, B, C, D')  # phi(A, B, C, D) 출력
print(phi_ABCD)
P_ABCD = phi_ABCD.values/pf_value  # 확률 = (팩터의 곱) / (분할 함수의 값)
PABCD = np.reshape(P_ABCD, -1)
for val in PABCD:  # 확률의 출력
    print(val, '\n')

A_dist = infer.query(['A'])  # A의 분포 phi(A)
print('phi(A)') # phi(A) 출력
print(A_dist)
P_A = A_dist.values/np.sum(A_dist.values) # 확률 = (팩터의 곱) / (분할 함수의 값)
for val in P_A: # 확률 출력
    print(val, '\n')

AIBOC1_dist = infer.query(['A'], evidence={'B': 0, 'C': 1})  # phi(A|B=0, C=1)
print('phi(A|B=0, C=1)') # phi(A|B=0, C=1) 출력
print(AIBOC1_dist)
P_AIBOC1 = AIBOC1_dist.values/np.sum(AIBOC1_dist.values) # 확률 = (팩터의 곱) / (분할 함수의 값)
for val in P_AIBOC1: # 확률 출력
    print(val, '\n')
