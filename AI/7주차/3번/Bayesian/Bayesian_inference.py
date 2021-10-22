from pgmpy.inference import VariableElimination
from Bayesian_register import model

# 베이지안 망의 추론
infer = VariableElimination(model)
A_dist = infer.query(['A'])
print('P(A)')
print(A_dist)

N_I_EF_BT = infer.query(['N'], evidence = {'E': 'F', 'B': 'T'})
print('P(N | E=F, B=T)')
print(N_I_EF_BT)

N_I_AF_BT = infer.query(['N'], evidence = {'A': 'F', 'B': 'T'})
print('P(N | A=F, B=T)')
print(N_I_AF_BT)