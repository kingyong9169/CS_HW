from pgmpy.inference import VariableElimination
from Bayesian_register import model

# 베이지안 망의 추론
infer = VariableElimination(model)  # 모델을 추론한다.
A_dist = infer.query(['A'])  # A에 대한 추론을 A_dist에 넣는다.
print('P(A)')
print(A_dist)  # A_dist 출력

# E=F, B=T에 대하여 N인 경우를 추론한다.
N_I_EF_BT = infer.query(['N'], evidence={'E': 'F', 'B': 'T'})
print('P(N | E=F, B=T)')
print(N_I_EF_BT)  # P(N | E=F, B=T)를 출력한다.

# A=F, B=T에 대하여 N인 경우를 추론한다.
N_I_AF_BT = infer.query(['N'], evidence={'A': 'F', 'B': 'T'})
print('P(N | A=F, B=T)')
print(N_I_AF_BT)  # P(N | A=F, B=T)를 출력한다.
