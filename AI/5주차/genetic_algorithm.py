# 목적함수 : y = w1*x1 + w2*x2 + w3*x3 + w4*x4 + w5*x5 + w6*x6
#              (x1, x2, x3, x4, x5, x6) =(4, -1, 3.1, 4, -6, -4.5)

import numpy

def cal_pop_fitness(equation_inputs, pop): # 모집단 내의 각 염색체의 적합도 계산
    fitness = numpy.sum(pop*equation_inputs, axis=1)
    return fitness

def select_mating_pool(pop, fitness, num_parents): # 다음 세대를 만들 부모 선택
    parents = numpy.empty((num_parents, pop.shape[1]))
    for parent_num in range(num_parents):
        max_fitness_idx = numpy.where(fitness == numpy.max(fitness))
        max_fitness_idx = max_fitness_idx[0][0]
        parents[parent_num, :] = pop[max_fitness_idx, :]
        fitness[max_fitness_idx] = -99999999
    return parents

def crossover(parents, offspring_size): # 교차연산자
    offspring = numpy.empty(offspring_size)
    crossover_point = numpy.uint8(numpy.random.randint(1, offspring_size[1]-1))

    for k in range(offspring_size[0]):
        parent1_idx = k%parents.shape[0] # 첫번째 부모의 인덱스
        parent2_idx = (k+1)%parents.shape[0] # 두번째 부모의 인덱스
        offspring[k, 0:crossover_point] = parents[parent1_idx, 0:crossover_point]
        offspring[k, crossover_point:] = parents[parent2_idx, crossover_point:]
    return offspring

def mutation(offspring_crossover): # 돌연변이 연산자
    m_ptr = numpy.uint8(numpy.random.randint(0, offspring_crossover.shape[1]-1))
    for idx in range(offspring_crossover.shape[0]):
        random_value = numpy.random.uniform(-1.0, 1.0, 1)
        offspring_crossover[idx, m_ptr] = offspring_crossover[idx, m_ptr] + random_value
    return offspring_crossover

equation_inputs = [4, -1, 3.1, 4, -6, -4.5] # 입력 x의 값
num_weights = 6 # 가중치의 개수

sol_per_pop = 8 # 모집단의 염색체 개수
num_parents_mating = 4 # 부모 선택 개수

pop_size = (sol_per_pop, num_weights) # 모집단의 크기 = 모집단의 염색체 개수 x 가중치의 개수
new_population = numpy.random.uniform(low=-4.0, high=4.0, size=pop_size) # 초기 모집단 생성
print(new_population)

num_generations = 10 # 세대 교체 횟수
for generation in range(num_generations):
    fitness = cal_pop_fitness(equation_inputs, new_population) # 각 염색체의 적합도 계산
    parents = select_mating_pool(new_population, fitness, num_parents_mating) # 부모 선택
    # 교차 연산자 적용
    offspring_crossover = crossover(parents, offspring_size=(pop_size[0]-parents.shape[0], num_weights))
    offspring_mutation = mutation(offspring_crossover) # 돌연변이 연산자 적용

    new_population[0:parents.shape[0], :] = parents # 새로운 모집단 생성
    new_population[parents.shape[0]:, :] = offspring_mutation

    print("세대 ", generation, " => best 해 ", numpy.max(numpy.sum(new_population*equation_inputs, axis=1))) 

fitness = cal_pop_fitness(equation_inputs, new_population) # 최종 모집단의 각 염색체 적합도 계산
best_match_idx = numpy.where(fitness == numpy.max(fitness)) # 최적해의 위치

print("최적해 : ", new_population[best_match_idx, :])
print("최적해의 적합도 : ", fitness[best_match_idx])