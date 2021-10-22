from pyswip import *

p = Prolog()

p.assertz("female(심청)")
p.assertz("female(홍련)")
p.assertz("female(춘향)")
p.assertz("female(월매)")
p.assertz("female(몽룡모)")
p.assertz("male(배무룡)")
p.assertz("male(심학규)")
p.assertz("male(성참판)")
p.assertz("male(이몽룡)")
p.assertz("male(이한림)")
p.assertz("male(변학도)")
p.assertz("female(숙향)")
p.assertz("father(심학규,심청)")
p.assertz("father(성참판,춘향)")
p.assertz("father(배무룡,홍련)")
p.assertz("father(이한림,이몽룡)")
p.assertz("father(이몽룡,숙향)")
p.assertz("mother(월매,춘향)")
p.assertz("spouse(이한림,몽룡모)")
p.assertz("healthy(이몽룡)")
p.assertz("wealthy(이몽룡)")
p.assertz("healthy(변학도)")
p.assertz("healthy(심청)")
p.assertz("wealthy(변학도)")
p.assertz("healthy(홍련)")

# 규칙 정의
p.assertz("grandfather(X,Y) :- father(X,Z),father(Z,Y)")
p.assertz("husband(X,Y) :- father(X,Z),mother(Y,Z)")
p.assertz("wife(X,Y) :- mother(X,Z),father(Y,Z)")
p.assertz("wife(X,Y) :- spouse(Y,X), female(X)")
p.assertz("wife(X,Y) :- spouse(X,Y), female(X)")
p.assertz("traveler(X) :- healthy(X), wealthy(X)")
p.assertz("canTravel(X) :- traveler(X)")

for ans in p.query("grandfather(이한림,X)"):
    print('이한림의 손주:', ans["X"])

for sol in p.query("traveler(Y)"):
    print('여행자:', sol["Y"])

for ans in p.query("healthy(X), wealthy(X)"):
    print('건강하고 여유있는 사람:', ans["X"])

for ans in p.query("husband(X,Y)"):
    print('부부:', ans["X"], ans["Y"])

for ans in p.query("spouse(X,Y)"):
    print('부부:', ans["X"], ans["Y"])

for ans in p.query("wife(X,Y)"):
    print(ans["Y"], '아내:', ans["X"])

print('이한림은 여행자이다:', bool(list(p.query("traveler(이한림)"))))
print('변학도는 여행자이다:', bool(list(p.query("traveler(변학도)"))))
