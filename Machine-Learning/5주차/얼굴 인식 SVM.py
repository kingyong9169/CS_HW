from sklearn.datasets import fetch_lfw_people # 모듈 가져오기
from sklearn.svm import SVC
from sklearn.decomposition import PCA as RandomizedPCA
from sklearn.pipeline import make_pipeline
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split, GridSearchCV
import seaborn as sns
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix

faces = fetch_lfw_people(min_faces_per_person=60) # lfw사람들을 가져와서 저장하기
print(faces.target_names) # 프린트
print(faces.images.shape) # 프린트
Xtrain, Xtest, ytrain, ytest = train_test_split(faces.data, faces.target, random_state=0) # 학습, 테스트로 나누어 변수 추출

fig, ax = plt.subplots(3,5) # subplot 구하기
for i, axi in enumerate(ax.flat): # ax를 flat한 값들을 for문 돌리기
    axi.imshow(faces.images[i], cmap='bone') # axi값을 imshow
    axi.set(xticks=[], yticks=[],
            xlabel=faces.target_names[faces.target[i]]) # axi값을 set

pca = RandomizedPCA(n_components=150, whiten=True, random_state=0) # 랜덤 PCA를 구하기
svc = SVC(kernel='rbf', class_weight='balanced') # SVC구하기
model = make_pipeline(pca, svc) # 파이프라인 만들기

param_grid = {'svc__C':[1,5,10,50],'svc__gamma':[0.0001,0.0005,0.001,0.005]} # 파라미터 grid 선언
grid = GridSearchCV(model, param_grid) # 파라미터 grid를 이용하여 그리드 서치 CV처리
grid.fit(Xtrain,ytrain) # gird에 Xtrain, ytrain 파라미터로 fit 실행
print(grid.best_params_) # 프린트
model = grid.best_estimator_ # 그리드의 베스트 평가를 모델에 넣기
yfit = model.predict(Xtest) # 모델에서 Xtest로 예측하여 yfit구하기

fig, ax = plt.subplots(4,6) # subplot 구하기
for i, axi in enumerate(ax.flat): # ax를 flat한 값들을 for문 돌리기
    axi.imshow(Xtest[i].reshape(62,47), cmap='bone') # axi값을 imshow
    axi.set(xticks=[],yticks=[]) # axi값을 set
    axi.set_ylabel(faces.target_names[yfit[i]].split()[-1],
                   color='black' if yfit[i] == ytest[i] else 'red') # axi값을 ylabel값으로 set
fig.suptitle('Predicted Names(Incorrect Labels in Red)', size=14); # suptitle지정
print(classification_report(ytest,yfit,target_names=faces.target_names)) # 프린트
plt.show() # 그리기

mat = confusion_matrix(ytest, yfit) # 혼동행렬 구하기
sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
            xticklabels=faces.target_names, yticklabels=faces.target_names) # heatmap구하기
plt.xlabel('true label') # X라벨
plt.ylabel('predicted label'); # Y라벨
plt.show() # 그리기

from sklearn.metrics import accuracy_score # score가져오기
print('정확도: ', accuracy_score(ytest,yfit)) # 프린트