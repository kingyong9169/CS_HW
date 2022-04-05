import matplotlib.pyplot as plt # 모듈 가져오기
from sklearn import datasets, svm, metrics
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split

digits = datasets.load_digits() # 데이터셋을 10진수로 load
_, axes = plt.subplots(2, 5) # subplot값 중 추출하기
images_and_labels = list(zip(digits.images, digits.target)) # 이미지와 타겟으로 zip한 리스트 만들기
for ax, (image, label) in zip(axes[0, :], images_and_labels[:5]): # axes, 이미지와 라벨을 zip한 것을 for문 돌리기
    ax.set_axis_off() # ax의 axis를 off하기
    ax.imshow(image, cmap=plt.cm.gray_r, interpolation='nearest') # ax를 imshow하기
    ax.set_title('Training: %i' % label) # title 지정하기

n_samples = len(digits.images) # 10진수의 길이를 구하기
data = digits.images.reshape((n_samples, -1)) # 10진수의 이미지를 reshape한 값 구하기

X_train, X_test, y_train, y_test = train_test_split(data, digits.target, test_size=0.5, shuffle=False) # 학습, 테스트로 나누어 변수 추출
classifier = svm.SVC(kernel='rbf', gamma=0.001) # svm을 SVC한 값을 분류기에 넣기
classifier.fit(X_train, y_train) # X_train, y_train으로 분류하기

predicted = classifier.predict(X_test) # 분류기를 X_test로 예측하기

test_data = X_test.reshape((len(X_test), 8, 8)) # X_test값을 reshape한 값을 테스트 데이터로 넣기
images_and_predictions = list(zip(test_data, predicted)) # 테스트 데이터, 예측을 zip한 것들 리스트로 만들기
for ax, (image, prediction) in zip(axes[1, :], images_and_predictions[:5]): # 이미지와 예측을 zip한 것 중에 이미지, 예측을 for문 돌리기
    ax.set_axis_off() # ax의 axis를 off하기
    ax.imshow(image, cmap=plt.cm.gray_r, interpolation='nearest') # ax를 imshow하기
    ax.set_title('Predict: %i' % prediction) # title 지정하기

print("SVM 분류 결과 %s:\n%s\n"
    % (classifier, metrics.classification_report(y_test, predicted))) # 메트릭스의 분류 결과를 출력하기
disp = metrics.plot_confusion_matrix(classifier, X_test, y_test) # 메트릭스의 혼동행렬을 저장
disp.figure_.suptitle("Confusion Matrix") # suptitle지정
print("혼동 행렬: \n%s" % disp.confusion_matrix) # 프린트
print("정확도 : ", accuracy_score(y_test, predicted)) # 프린트

plt.show() # 그리기