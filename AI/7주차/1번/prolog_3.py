from pyswip import *

N = 3  # 원반 개수


def notify(t):  # notify 함수
    print("%s --> %s" % tuple(t))  # tuple(t)의 첫 번째, 두 번째 값을 출력한다.


notify.arity = 1

prolog = Prolog()  # 프롤로그 생성
registerForeign(notify)  # 외부 함수 prolog에 등록
prolog.consult("AI/7주차/1번/hanoi.pl")  # prolog 프로그램 파일 읽어들이기
list(prolog.query("hanoi(%d)" % N))  # hanoi(3)을 질의하여 출력한다.
