from pyswip import *

p = Prolog()
# 사실(fact)의 정의
p.assertz("vegeterian(cinderella)")  # 신데렐라는 채식주의자다.
p.assertz("vegeterian(snow_white)")  # 스노우 화이트는 채식주의자다.
p.assertz("vegetable(사과)")  # 사과는 채소이다.
p.assertz("vegetable(가지)")  # 가지는 채소이다.
p.assertz("vegetable(당근)")  # 당근은 채소이다.
# X가 Y를 좋아한다 : X는 채식주의자이고 Y는 채소이다.
p.assertz("likes(X,Y) :- vegeterian(X), vegetable(Y)")
p.assertz("likes(X,오이) :- vegeterian(X)")  # X가 오이를 좋아한다 : X는 채식주의자다.
p.assertz("likes(cinderella, 달걀)")  # 신데델라는 달걀을 좋아한다.

# 질의(query) 정의 및 결과 추출
for ans in p.query("likes(X,가지)"):
    print(ans["X"], 'likes 가지')  # 사실에 따라 누가 가지를 좋아하는지 출력한다.

for ans in p.query("likes(snow-white,Y)"):
    print('snow-white likes', ans["Y"])  # 사실에 따라 스노우 화이트는 무엇을 좋아하는지 출력한다.

for ans in p.query("likes(cinderella,Y)"):
    print('cinderella likes', ans["Y"])  # 신데렐라는 무엇을 좋아하는지 출력한다.

vegetable = Functor("vegetable", 1)  # vegetable 함수의 원형 선언
likes = Functor("likes", 2)  # likes 함수의 원형 선언
Y = Variable()  # Y가 변수임을 알림

# 신데렐라는 Y를 좋아한다, Y는 채소이다라는 질의를 q에 저장
q = Query(likes("cinderella", Y), vegetable(Y))
while q.nextSolution():
    print("cinderella 좋아하는 채소:", Y.value)  # 신데렐라가 좋아하는 채소 출력
q.closeQuery()  # 질의를 멈춘다.
