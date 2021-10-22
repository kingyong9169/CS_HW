from pyswip import *

N = 3

def notify(t):
    print("%s --> %s" % tuple(t))
notify.arity = 1

prolog = Prolog()
registerForeign(notify)
prolog.consult("hanoi.pl")
list(prolog.query("hanoi(%d)" % N))

