from sklearn import datasets
import numpy as np

def test_split(index, value, dataset): # 데이터 분할하기
  left, right = list(), list()  # 왼쪽, 오른쪽 데이터 list
  for row in dataset:
    if row[index] < value:  # value보다 작을 경우
      left.append(row)  # 왼쪽의 데이터 추가
    else:                 # 그렇지 않을 경우
      right.append(row) # 오른쪽의 데이터 추가
  return left, right    # 리턴

def gini_index(groups, classes): # 지니개수 계산하기
  n_instances = float(sum([len(group) for group in groups]))  # 분할 지점에서 모든 샘플 세기
  gini = 0.0  # 초기 지니 = 0
  for group in groups:
    size = float(len(group))  # 그룹 사이즈
    if size == 0: # 사이즈가 0이면 끝낸다
      continue
    score = 0.0 # 초기 점수 = 0
    for class_val in classes: # 각 클래스의 점수를 기준으로 한 점수 그룹
      p = [row[-1] for row in group].count(class_val) / size
      score += p * p  # 점수 계산
    gini += (1.0 - score) * (size / n_instances)  # 상대적 크기에 따른 체중 그룹 점수
  return gini # 지니개수 리턴

def get_split(dataset): # 중복을 피하기 위해 속성을 선택하는 데이터 세트에 대한 est 분할점
  class_values = list(set(row[-1] for row in dataset))  # 클래스 값 정의
  b_index, b_value, b_score, b_groups = 999, 999, 999, None # 초기값 정의
  for index in range(len(dataset[0])-1):
    for row in dataset:
      groups = test_split(index, row[index], dataset) # 데이터 분할하기
      gini = gini_index(groups, class_values) # 지니개수 구하기
      if gini < b_score:  # 지니가 b_socre보다 작을 경우
        b_index, b_value, b_score, b_groups = index, row[index], gini, groups # index, value, score, group 대입
  return {'index':b_index, 'value':b_value, 'groups':b_groups}  # 리턴

def split(node, max_depth, min_size, depth): # 분할
  left, right = node['groups']
  del(node['groups']) # 더 이상 필요하지 않으므로 노드에서 데이터 삭제하기
  if not left or not right: # 왼쪽 노드 또는 오른쪽 노드가 비어 있는 경우
    node['left'] = node['right'] = to_terminal(left + right)  # left + right터미널 노드 생성하기
    return
  if depth >= max_depth:  # 트리의 최대 깊이에 도달했는지 -> 터미널 노드 생성하기
    node['left'], node['right'] = to_terminal(left), to_terminal(right) # 각각 터미널 노드로 생성하기
    return
  # 최소 크기에 먼저 도달했는지 or 트리의 추가 분할이 필요한지 확인하기
  if len(left) <= min_size: # 왼쪽이 최소 사이즈보다 작을 경우
    node['left'] = to_terminal(left)  # 
  else:
    node['left'] = get_split(left)  # 추가 분할하기
    split(node['left'], max_depth, min_size, depth+1) # 다시 나누기
  #  Right child
  if len(right) <= min_size:  # 오른쪽이 최소 사이즈보다 작을 경우
    node['right'] = to_terminal(right)
  else:
    node['right'] = get_split(right)  # 추가 분할하기
    split(node['right'], max_depth, min_size, depth+1)  # 다시 나누기
  
def to_terminal(group): # 터미널 노드 값 생성하기
  outcomes = [row[-1] for row in group] # 결과
  return max(set(outcomes), key=outcomes.count) # 최대값 리턴

def build_tree(train, max_depth, min_size): # 결정트리 생성하기
  root = get_split(train) # 루트 받아오기
  split(root, max_depth, min_size, 1) # 분할하기
  return root

def print_tree(node, depth=0):  # 결정트리 출력
  if isinstance(node, dict):  # instance가 있을 경우
    print('%s[X%d < %.3f]' % ((depth*'', (node['index']+1), node['value'])))  # 출력하기
    print_tree(node['left'], depth+1) # 왼쪽 노드 출력
    print_tree(node['right'], depth+1) # 오른쪽 노드 출력
  else:
    print('%s[%s]' % ((depth*'', node)))  # 없을 경우 노드별 depth출력하기

iris = datasets.load_iris() # iris 데이터셋 가져오기
dataset = np.c_[iris.data,iris.target]  # 데이터셋 정의

tree = build_tree(dataset, 3, 1)  # 결정트리 생성하기
print_tree(tree)  # 결정트리 출력함수 호츨