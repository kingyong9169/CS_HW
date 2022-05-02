import numpy as np
import matplotlib.pyplot as plt

def f(x,y): # f함수 정의
    return 2*x**2 +4*x*y + 5*y**2 - 6*x + 2*y + 10

def dx(x,y):    # dx함수
    return 4*x + 4*y - 6

def dy(x,y):    # dy함수
    return 4*x + 10*y + 2

xi = np.linspace(-5, 20, 100)   # 100개 간격으로 배열
yi = np.linspace(-6, 6, 100)   # 100개 간격으로 배열
X, Y = np.meshgrid(xi, yi)  # 위 배열로 격자 그리드 만들기
Z = f(X,Y)  # 편미분 함수 호출

xj = np.linspace(-5, 20, 13)    # 13개 간격으로 배열
yj = np.linspace(-6, 6, 7)      # 7개 간격으로 배열
X1, Y1 = np.meshgrid(xj, yj)  # 위 배열로 격자 그리드 만들기
Dx = dx(X1, Y1) # 기울기
Dy = dy(X1, Y1) # 기울기

plt.figure(figsize=(10,5))
plt.contour(X, Y, Z, levels=np.logspace(0,3,10))    # contour
plt.quiver(X1, Y1, Dx, Dy, color='red', scale=500, minshaft=4)  # quiver
plt.xlabel('x') # x라벨
plt.ylabel('y') # y라벨
plt.show()  # 그래프 그리기
