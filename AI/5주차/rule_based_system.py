from durable.lang import *

with ruleset('IT company'): # << 해당 조건을 만족하는 대상 지시하는 이름
    @when_all(c.first << (m.predicate == 'works') & (m.object == 'hard'), # 1번 규칙
            (m.predicate == 'handles') & (m.object == 'codes') & (m.subject == c.first.subject)) 
    def developer(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'developer' })
        # 사실(fact)의 추가

    @when_all(c.first << (m.predicate == 'works') & (m.object == 'hard'), # 2번 규칙
            (m.predicate == 'handles') & (m.object == 'design tools') & (m.subject == c.first.subject)) 
    def designer(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'designer' })

    @when_all(c.first << (m.predicate == 'works') & (m.object == 'hard'), # 3번 규칙
            c.second << (m.predicate == 'handles') & (m.object == 'documents') & (m.subject == c.first.subject),
            (m.predicate == 'manages') & (m.object == 'projects') & (m.subject == c.second.subject)) 
    def PM(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'PM' })

    @when_all(c.first << (m.predicate == 'works') & (m.object == 'hard'), # 4번 규칙
            c.second << (m.predicate == 'handles') & (m.object == 'employees') & (m.subject == c.first.subject),
            (m.predicate == 'manages') & (m.object == 'company') & (m.subject == c.second.subject))
    def CEO(c):
        c.assert_fact({ 'subject': c.first.subject, 'predicate': 'is', 'object': 'CEO' })
    
    @when_all((m.predicate == 'develops') & (m.object == 'new ideas')) # 5번 규칙
    def planner(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'planner' })

    @when_all((m.predicate == 'is') & (m.object == 'developer')) # 6번 규칙
    def wonderful(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'wonderful' })

    @when_all((m.predicate == 'is') & (m.object == 'designer')) # 7번 규칙
    def cool(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'cool' })

    @when_all((m.predicate == 'is') & (m.object == 'PM')) # 8번 규칙
    def respectful(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'respectful' })

    @when_all((m.predicate == 'is') & (m.object == 'CEO')) # 9번 규칙
    def perfect(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'perfect' })

    @when_all((m.predicate == 'is') & (m.object == 'planner')) # 10번 규칙
    def scrupulous(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'scrupulous' })

    @when_all((m.predicate == 'is') & (m.object == 'respectful')) # 11번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'lonely' })
    
    @when_all((m.predicate == 'is') & (m.object == 'perfect')) # 12번 규칙
    def blue(c):
        c.assert_fact({ 'subject': c.m.subject, 'predicate': 'is', 'object': 'leader' })

    @when_all(+m.subject) # m.subject가 한 번 이상
    def output(c):
        print('Fact: {0} {1} {2}'.format(c.m.subject, c.m.predicate, c.m.object))

assert_fact('IT company', { 'subject': 'velopert', 'predicate': 'works', 'object': 'hard' })
assert_fact('IT company', { 'subject': 'velopert', 'predicate': 'handles', 'object': 'codes' })
assert_fact('IT company', { 'subject': 'Greedy', 'predicate': 'works', 'object': 'hard' })
assert_fact('IT company', { 'subject': 'Greedy', 'predicate': 'handles', 'object': 'design tools' })
assert_fact('IT company', { 'subject': 'Tweety', 'predicate': 'works', 'object': 'hard' })
assert_fact('IT company', { 'subject': 'Tweety', 'predicate': 'handles', 'object': 'documents' })
assert_fact('IT company', { 'subject': 'Tweety', 'predicate': 'manages', 'object': 'projects' })
assert_fact('IT company', { 'subject': 'cook', 'predicate': 'works', 'object': 'hard' })
assert_fact('IT company', { 'subject': 'cook', 'predicate': 'handles', 'object': 'employees' })
assert_fact('IT company', { 'subject': 'cook', 'predicate': 'manages', 'object': 'company' })
assert_fact('IT company', { 'subject': 'challie', 'predicate': 'develops', 'object': 'new ideas' })