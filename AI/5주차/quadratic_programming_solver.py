from cvxopt import matrix, solvers

H = 2*matrix([[1., 0.],[0., 1.]])
f = matrix([0.0,0.0])
A = matrix([[0.0,0.0], [0.0, -1.0]])
a = matrix([0.0, -3/4.0])
B = matrix([1.0, 1.0], (1, 2))
b = matrix(1.0)

sol = solvers.qp(H, f, A, a, B, b)
print('헤\n', 'x_1 = ', sol['x'][0])
print('x_2 = ', sol['x'][1])