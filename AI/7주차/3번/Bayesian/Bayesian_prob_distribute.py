from pgmpy.factors.discrete import TabularCPD
import numpy as np

# 지진(Earthquake) 발생 확률 분포
P_E = TabularCPD('E', 2, [[0.9], [0.1]], state_names={
                 'E': ['F', 'T']})  # P(E)에서 E가 F, T일 때 확률
print('P(E)')
print(P_E)  # P(E) 확률 베이지안 출력

# 절도(Burglary) 발생 확률분포
P_B = TabularCPD('B', 2, [[0.7], [0.3]], state_names={
                 'B': ['F', 'T']})  # P(B)에서 B가 F, T일 때 확률
print('P(B)')
print(P_B)  # P(B) 확률 베이지안 출력

# 경보(Alarm) 발생 확률 분포
P_A_I_EB = TabularCPD('A', 2, [[0.99, 0.1, 0.3, 0.01], [0.01, 0.9, 0.7, 0.99]],
                      evidence=['E', 'B'], evidence_card=[2, 2],
                      state_names={'A': ['F', 'T'], 'E': ['F', 'T'], 'B': ['F', 'T']})  # P(A|EB)에서 E가 F, T B가 F, T일 때 확률

print('P(A|EB)')
print(P_A_I_EB)  # P(A|EB) 확률 베이지안 출력

# 이웃(Neighbor) 전화 확률 분포
P_N_I_A = TabularCPD('N', 2,
                     np.array([[0.9, 0.2], [0.1, 0.8]]),
                     evidence=['A'], evidence_card=[2],
                     state_names={'N': ['F', 'T'], 'A': ['F', 'T']})  # P(N|A)에서 A가 F, T일 때 확률
print('P(N|A)')
print(P_N_I_A)  # P(N|A) 확률 베이지안 출력
