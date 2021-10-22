from pyswip import *

p = Prolog()
# 사실(fact)의 정의
p.assertz("female(심청)")  # 심청이는 여자다
p.assertz("female(홍련)")  # 홍련이는 여자다.
p.assertz("female(춘향)")  # 춘향이는 여자다.
p.assertz("female(월매)")  # 월매는 여자다.
p.assertz("female(몽룡모)")  # 몽룡모는 여자다.
p.assertz("male(배무룡)")  # 배무룡은 남자다.
p.assertz("male(심학규)")  # 심학규은 남자다.
p.assertz("male(성참판)")  # 성참판은 남자다.
p.assertz("male(이몽룡)")  # 이몽룡은 남자다.
p.assertz("male(이한림)")  # 이한림은 남자다.
p.assertz("male(변학도)")  # 변학도는 남자다.
p.assertz("female(숙향)")  # 숙향은 남자다.
p.assertz("father(심학규,심청)")  # 심청이의 아버지는 심학규이다.
p.assertz("father(성참판,춘향)")  # 춘향의 아버지는 성참판이다.
p.assertz("father(배무룡,홍련)")  # 홍련의 아버지는 배무룡이다.
p.assertz("father(이한림,이몽룡)")  # 이몽룡의 아버지는 이한림이다.
p.assertz("father(이몽룡,숙향)")  # 숙향의 아버지는 이몽룡이다.
p.assertz("mother(월매,춘향)")  # 춘향의 어머니는 월매다.
p.assertz("spouse(이한림,몽룡모)")  # 몽룡모의 배우자는 이한림이다.
p.assertz("healthy(이몽룡)")  # 이몽룡은 건강하다.
p.assertz("wealthy(이몽룡)")  # 이몽룡은 부유하다.
p.assertz("healthy(변학도)")  # 변학도는 건강하다.
p.assertz("healthy(심청)")  # 심청은 건강하다.
p.assertz("wealthy(변학도)")  # 변학도는 부유하다.
p.assertz("healthy(홍련)")  # 홍련은 건강하다.

# 규칙 정의
p.assertz("grandfather(X,Y) :- father(X,Z),father(Z,Y)")
p.assertz("husband(X,Y) :- father(X,Z),mother(Y,Z)")
p.assertz("wife(X,Y) :- mother(X,Z),father(Y,Z)")
p.assertz("wife(X,Y) :- spouse(Y,X), female(X)")
p.assertz("wife(X,Y) :- spouse(X,Y), female(X)")
p.assertz("traveler(X) :- healthy(X), wealthy(X)")
p.assertz("canTravel(X) :- traveler(X)")

# 질의(query) 정의 및 결과 추출
for ans in p.query("grandfather(이한림,X)"):
    print('이한림의 손주:', ans["X"])  # 사실과 규칙에 따라 질의를 통해 이한림의 손주가 누구인지 출력

for sol in p.query("traveler(Y)"):
    print('여행자:', sol["Y"])  # 사실과 규칙에 따라 질의를 통해 여행자가 누구인지 출력

for ans in p.query("healthy(X), wealthy(X)"):
    print('건강하고 여유있는 사람:', ans["X"])  # 사실과 규칙에 따라 질의를 통해 건강하고 여유있는 사람이 누구인지 출력

for ans in p.query("husband(X,Y)"):
    print('부부:', ans["X"], ans["Y"])  # 사실과 규칙에 따라 질의를 통해 누가 부부인지 출력

for ans in p.query("spouse(X,Y)"):
    print('부부:', ans["X"], ans["Y"])  # 사실과 규칙에 따라 질의를 통해 누가 부부인지 출력

for ans in p.query("wife(X,Y)"):
    print(ans["Y"], '아내:', ans["X"])  # 사실과 규칙에 따라 질의를 통해 누구의 아내인지 출력

# 이한림은 여행자이다라는 사실이 맞는지 질의하여 결과를 나타낸다.
print('이한림은 여행자이다:', bool(list(p.query("traveler(이한림)"))))
# 변학도는 여행자이다라는 사실이 맞는지 질의하여 결과를 나타낸다.
print('변학도는 여행자이다:', bool(list(p.query("traveler(변학도)"))))
