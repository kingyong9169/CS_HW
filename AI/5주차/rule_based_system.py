from durable.lang import *

with ruleset('animal'): # << 해당 조건을 만족하는 대상 지시하는 이름
    @when_all(c.first << (m.predicate == 'eats') & (m.object == 'flies'), # 1번 규칙
            (m.predicate == 'lives') & (m.object == 'water') & (m.subject == c.first.subject)) 
    def frog(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'frog' })
        # 사실(fact)의 추가

    @when_all(c.first << (m.predicate == 'eats') & (m.object == 'flies'), # 2번 규칙
            (m.predicate == 'lives') & (m.object == 'land') & (m.subject == c.first.subject)) 
    def chameleon(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'chameleon' })

    @when_all(c.first << (m.predicate == 'eats') & (m.object == 'rabbits'), # 3번 규칙
            c.second << (m.predicate == 'lives') & (m.object == 'mountain') & (m.subject == c.first.subject),
            (m.predicate == 'hunts') & (m.object == 'deers') & (m.subject == c.second.subject)) 
    def wolf(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'wolf' })

    @when_all(c.first << (m.predicate == 'eats') & (m.object == 'horses'), # 4번 규칙
            c.second << (m.predicate == 'lives') & (m.object == 'grassland') & (m.subject == c.first.subject),
            (m.predicate == 'hunts') & (m.object == 'buffalos') & (m.subject == c.second.subject))
    def lion(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'lion' })
    
    @when_all((m.predicate == 'eats') & (m.object == 'worms')) # 5번 규칙
    def bird(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'bird' })

    @when_all((m.predicate == 'is') & (m.object == 'frog')) # 6번 규칙
    def green(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'green' })

    @when_all((m.predicate == 'is') & (m.object == 'chameleon')) # 7번 규칙
    def grey(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'grey' })

    @when_all((m.predicate == 'is') & (m.object == 'wolf')) # 8번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'blue' })

    @when_all((m.predicate == 'is') & (m.object == 'lion')) # 9번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'brown' })

    @when_all((m.predicate == 'is') & (m.object == 'bird')) # 10번 규칙
    def black(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'black' })

    @when_all((m.predicate == 'is') & (m.object == 'blue')) # 11번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'lonely' })
    
    @when_all((m.predicate == 'is') & (m.object == 'brown')) # 12번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'king of animals' })

    @when_all(+m.subject) # m.subject가 한 번 이상
    def output(c):
        print('Fact: {0} {1} {2}'.format(c.m.subject, c.m.predicate, c.m.object))

assert_fact('animal', { 'subject': 'Kermit', 'predicate': 'eats', 'object': 'flies' })
assert_fact('animal', { 'subject': 'Kermit', 'predicate': 'lives', 'object': 'water' })
assert_fact('animal', { 'subject': 'Greedy', 'predicate': 'eats', 'object': 'flies' })
assert_fact('animal', { 'subject': 'Greedy', 'predicate': 'lives', 'object': 'land' })
assert_fact('animal', { 'subject': 'Tweety', 'predicate': 'eats', 'object': 'worms' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'eats', 'object': 'rabbits' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'lives', 'object': 'mountain' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'hunts', 'object': 'deers' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'eats', 'object': 'horses' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'lives', 'object': 'grassland' })
assert_fact('animal', { 'subject': 'challie', 'predicate': 'hunts', 'object': 'buffalos' })