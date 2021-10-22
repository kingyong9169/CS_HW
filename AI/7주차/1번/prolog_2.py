from pyswip import *

p = Prolog()
p.assertz("vegeterian(cinderella)")
p.assertz("vegeterian(snow_white)")
p.assertz("vegetable(사과)")
p.assertz("vegetable(가지)")
p.assertz("vegetable(당근)")
p.assertz("likes(X,Y) :- vegeterian(X), vegetable(Y)")
p.assertz("likes(X,오이) :- vegeterian(X)")
p.assertz("likes(cinderella, 달걀)")

for ans in p.query("likes(X,가지)"):
    print(ans["X"], 'likes 가지')

for ans in p.query("likes(snow-white,Y)"):
    print('snow-white likes', ans["Y"])

for ans in p.query("likes(cinderella,Y)"):
    print('cinderella likes', ans["Y"])

vegetable = Functor("vegetable", 1)
likes = Functor("likes", 2)
Y = Variable()

q = Query(likes("cinderella", Y), vegetable(Y))
while q.nextSolution():
    print("cinderella 좋아하는 채소:", Y.value)
q.closeQuery()