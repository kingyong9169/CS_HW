from numpy import mean # 모듈 import
from sklearn.datasets import make_classification
from sklearn.model_selection import LeaveOneOut
from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score
from sklearn.linear_model import LogisticRegression
from matplotlib import pyplot

def evaluate_model(cv): # 평가 모델 함수 선언
    X, y = make_classification(n_samples=100, n_features=20, n_informative=15, n_redundant=5, random_state=1)
    # 샘플 100개, 특징 20개, 정보 15개, redundant 5개, 랜덤 상태 1개로 분류를 만들어 X, y변수에 저장
    model = LogisticRegression() # 로지스틱 회귀를 사용하여 model에 저장
    scores = cross_val_score(model, X, y, scoring='accuracy', cv=cv, n_jobs=-1) # 위 변수들와 정확도 scoring, cv, jobs를 파라미터로 교차검증점수를 만들어 scores에 저장
    return mean(scores), scores.min(),scores.max() # scores의 평균, 최소값, 최대값 리턴
ideal, _, _=evaluate_model(LeaveOneOut()) # 평가모델 메소드를 호출하여 얻은 값을 ideal에 저장
print('Ideal: %.3f'% ideal) # ideal 출력
folds = range(2,20) # folds 범위를 2, 20으로 지정
means, mins, maxs = list(), list(), list() # 평균, 최소값, 최대값을 리스트로 초기화

for k in folds: # folds 범위에서
    cv = KFold(n_splits=k, shuffle=True, random_state=1) # split에 k, 셔플 true, 랜덤 상태 1을 파라미터로 K겹 값을 cv로 표현
    k_mean, k_min, k_max = evaluate_model(cv) # k겹 값을 평가모델로 하여 k평균, k최소값, k최대값을 얻어낸다.
    print('> folds=%d, accuracy=%.3f (%.3f, %.3f)'% (k, k_mean, k_min, k_max)) # 이 값들을 출력한다.
    means.append(k_mean) # k평균을 means에 추가한다.
    mins.append(k_mean - k_min) # k평균 - k최소값을 mins에 추가한다.
    maxs.append(k_max - k_mean) # k최대값 - k평균값을 maxs에 추가한다.
 
pyplot.errorbar(folds, means, yerr=[mins, maxs], fmt ='o') # 겹, 평균, 최소 최대값으로 에러바를 만든다.
pyplot.plot(folds, [ideal for _ in range(len(folds))], color='r') # 겹의 길이를 범위로 ideal, 겹을 출력한다.
pyplot.show()
