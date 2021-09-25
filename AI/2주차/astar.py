# -*- coding: utf-8 -*-
# import package
import numpy as np
import heapq # min heap을 구현하는 heap queue
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure

grid = np.array([ # 지도 그림 1: 벽, 0: 빈공간
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0],
    [0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]])

start = (19,0) # 시작 위치
goal = (19,19) # 목적지 위치


def heuristic(a, b): # 휴리스틱 함수: a와 b사이의 유클리드 거리 측정하는 함수입니다.
    return np.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2) # 루트(x좌표 차의 제곱 + y좌표 차의 제곱)


def astar(array, start, goal): # A* 알고리즘 함수
    neighbors = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)] # 이웃 좌표의 위치
    close_set = set() # 탐색이 종료된 위치들의 집합입니다.
    came_from = {} # 각 반복에서 가져온 모든 경로를 포함하는 객체입니다. 여기에는 부모 위치가 포함되며 목적지에 도달하면 이 객체에서 최단 경로를 찾습니다.
    gscore = {start:0} # 시작 위치까지 투입된 초기 비용
    fscore = {start:heuristic(start, goal)} # 시작위치를 경유하는 초기 전체 비용
    oheap = [] # min-heap
    heapq.heappush(oheap, (fscore[start], start)) # (출발지로부터 거리, 출발지)를 min-heap에 저장

    while oheap: # min-heap이 있는 동안 반복
        current = heapq.heappop(oheap)[1] # 힙큐에서 (출발지로부터 거리, 출발지)에 해당하는 것을 팝하여 current에 저장
        if current == goal: # 목적지에 도착하면
            data = [] # data 배열 선언
            while current in came_from: # 목적지까지의 경로가 남아있으면 반복 : 목적지까지의 위치에서 역순으로 경로를 추출한다.
                data.append(current) # 현재 위치를 data에 넣는다.
                current = came_from[current] # current에 목적지까지 경로[current]에 해당하는 것을 넣는다.
            return data # 데이터 리턴

        close_set.add(current) # 탐색이 종료된 위치에 현재값을 추가한다.

        for i, j in neighbors: # 이웃 좌표의 x, y값을 i, j에 대입
            neighbor = current[0] + i, current[1] + j # 이웃 위치에 현재 값에 이웃 좌표의 x, y값을 더한다.
            if 0 <= neighbor[0] < array.shape[0]: # 0 <= 이웃의 x좌표 < array의 행의 개수이면
                if 0 <= neighbor[1] < array.shape[1]: # 0 <= 이웃의 y좌표 < array의 열의 개수이면
                    if array[neighbor[0]][neighbor[1]] == 1: # 벽에 위치하면
                        continue # 그대로 다음 반복문 진행한다
                else: # y 방향의 경계를 벗어난 상황이면
                    continue # 그대로 다음 반복문 진행한다
            else: # x 방향의 경계를 벗어난 상황이면
                continue # 그대로 다음 반복문 진행한다
 
            tentative_g_score = gscore[current] + heuristic(current, neighbor) # g^(n) = g(c) + h(c,n)
            if neighbor in close_set and tentative_g_score >= gscore.get(neighbor, 0): # 이미 탐색을 종료한 위치이면서 g^(n)값이 g(n)값보다 큰 경우에는
                continue # 무시하고 다음 반복문으로 넘어간다.
 
            if  tentative_g_score < gscore.get(neighbor, 0) or neighbor not in [i[1]for i in oheap]: # g^(n) < g(n) 이거나 처음 방문한 경우
                came_from[neighbor] = current # neighbor에 도달한 최선의 경로의 위치는 current이다.
                gscore[neighbor] = tentative_g_score # g(n) = g^(n)
                fscore[neighbor] = tentative_g_score + heuristic(neighbor, goal) # f^(n) = g(n) + h^()
                heapq.heappush(oheap, (fscore[neighbor], neighbor)) # min-heap에 (f(), neighbor)을 푸쉬한다.
    return False

route = astar(grid, start, goal) # astar알고리즘을 호출한다.
route = route + [start] # 출발 위치를 추가한다.
route = route[::-1] # 역순으로 route를 변환한다.
print(route) # route를 출력한다.

x_coords = [] # x좌표를 모으는 배열
y_coords = [] # y좌표를 모으는 배열

for i in (range(0,len(route))): # route에서 추출한다.
    x = route[i][0] # route의 x좌표를 추출하여 x에 넣는다.
    y = route[i][1] # route의 y좌표를 추출하여 y에 넣는다.
    x_coords.append(x) # x모음에 추가한다.
    y_coords.append(y) # y모음에 추가한다.

fig, ax = plt.subplots(figsize=(10,10)) # 크기를 정한다.
ax.imshow(grid, cmap=plt.cm.Dark2) # 지도에 grid 좌표들을 그린다.
ax.scatter(start[1],start[0], marker = "*", color = "yellow", s = 200) # 시작점을 표시한다.
ax.scatter(goal[1],goal[0], marker = "*", color = "red", s = 200) # 마지막을 표시한다.
ax.plot(y_coords,x_coords, color = "black") # 경로를 검은색으로 표시한다.
plt.show() # 지도를 보여준다.