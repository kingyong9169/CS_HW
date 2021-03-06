과제 주제 설명
================
#### 4주차 주제 "CSS박스모델과 레이아웃" 및 지금까지 배운 html, CSS기본 기능을 활용하여 과제 예시를 참고한 웹사이트 제작

주요 코드 설명
================
#### title아래에 style을 만들고 그 안에 여러 클래스들을 추가하여 아이템 박스, 텍스트 박스, 사진 및 텍스트 박스를 구현하여 웹사이트를 구성하였습니다.
#### 아래 코드 설명은 웹사이트 구성순서대로 작성하였습니다.

## 상위 seoul, tokyo, london 메뉴 구현
1. 'menu-box'클래스에 height: 40px로 설정하였고 seoul, tokyo, london문구를 추가하였습니다.
2. display : flex기능을 사용하여 컨텐츠를 배치하고 남은 공간에 컨텐츠 정렬이 가능할 수 있도록 하였습니다.
만약 이 기능을 사용하지 않는다면 seoul 밑에 tokyo, 그 밑에 london이 배치될 것입니다.
3. 'menu-item'클래스에 border를 넣어 경계선을 만들어 주었고 padding으로 내부 컨텐츠 간격을 상하5px, 좌우20px로 조정하였습니다.

## 아이템 박스에 사진 넣기
1. 'item box'클래스를 가진 div를 만들어 position : relative로 부모div위치 상태를 기준으로 위치 좌표 설정하도록 하였습니다.
2. display : flex기능을 사용하여 컨텐츠를 배치하고 남은 공간에 컨텐츠 정렬이 가능할 수 있도록 하였습니다.
만약 이 기능을 사용하지 않는다면 seoul 밑에 tokyo, 그 밑에 london이 배치될 것입니다.
3. align-self : center로 텍스트 컨텐츠를 height 중간위치에 배치되도록 하였습니다.
4. 하위 컨텐츠에 'item pic pic1' 클래스를 가진 img를 두 개 생성하였고 각 사진의 링크를 추가하였습니다.
5. 'item pic'클래스는 height:240px만 설정하였고 'pic1'클래스에 margin을 auto로 설정하여 컨텐츠의 남은 공간을 자동으로 배분하여 배치하도록 했으며 width를 350px로 설정하였습니다.

## 아이템 박스에 문구 넣기
1. 이미지의 형제 div를 'pic text text1'클래스를 생성하여 'Just do it Go right now!', 'Do it right when you do it.'문구 두 개를 추가하였습니다.
2. 'pic text'클래스에 position을 absolute로 부모 위치를 기준으로 절대 좌표를 설정하였고 z-index를 1로 두어 이미지 컨텐츠보다 위에 위치하도록 구현하였습니다. 또한 text-align속성을 center로 설정하여 텍스트 가운데 정렬을 하였습니다.
3. 'text1', 'text2'클래스에 top, left, font-size를 설정하여 각 문구의 위치, 폰트 크기를 설정하였습니다.

## 텍스트 박스
1. 'text box'클래스를 가진 div를 만들었고 display : flex기능을 사용하여 컨텐츠를 배치하고 남은 공간에 컨텐츠 정렬이 가능할 수 있도록 하였으며 height를 400px로 설정하였습니다.
2. 하위 div에 'text item item1, item2'클래스를 적용하여 콘텐츠 두 개를 제작하였고 각각 h2, p태그로 제목, 본문으로 구성하였습니다.
3. 'text item'클래스는 margin을 상하좌우 40px로 설정하였습니다. 또한 'item1'클래스, 'item2'클래스에 각각 width를 60%, 40%로 설정하여 flex로 설정된 부모 div안에서 6 : 4비율로 컨텐츠를 차지하도록 설정하였습니다.

## div없이 사진추가 및 텍스트 컨텐츠 추가
1. 'item pic pic2 left-float'클래스 특성을 지닌 img를 생성하였습니다. 'item pic'클래스는 위의 "아이템 박스에 사진 넣기"에서 설명하였고 'pic2'클래스는 margin을 상하좌우 10px로 설정, 그리고 높이를 240px로 설정하였습니다.
2. 'left-float'클래스를 추가하여 float:left로 사진을 왼쪽으로 부유하게 하여 남은 공간에 텍스트 컨텐츠가 들어갈 수 있게 하였습니다. 만약 이 기능을 사용하지 않았다면 사진 밑에 텍스트 컨텐츠가 위치할 것입니다. 
3. 사진이 위치하고 남은 공간에 h2, p태그로 제목, 본문 텍스트 컨텐츠를 삽입하였습니다.

## 마지막 아이템 박스에 텍스트 컨텐츠 추가
1. 'item box box2'클래스를 지닌 div를 추가하였고 'item box child'클래스를 지닌 하위 div를 추가하여 도록 copyright문구를 삽입하였습니다.
2. 'item box'클래스는 위의 "아이템 박스에 사진 넣기"에서 설명하였고 'box2'클래스에 배경을 회색, 높이를 120px로 설정하였습니다.
3. 'item box'클래스에서 align-self:center로 
    텍스트 컨텐츠를 height 중간위치에 배치하도록 하였습니다.
3. 'child'클래스에서 부모 div로 시작위치로부터 left:48%로 
    텍스트 컨텐츠 위치를 설정하였습니다.

비고 및 고찰
==============
#### 평소 알고리즘적인 문제를 해결하는 것에 초점을 맞춰온 저에게 웹디자인은 생소한 분야였고 많은 기능들을 이해하고 적용하는데 시간이 오래걸리게 되었습니다. 그 과정에서 CSS에는 방대한 기능이 있어 자주 사용하여 손에 익히는 것은 물론 오픈소스를 활용하여 제 지식으로 만드는 것이 가장 중요하다는 것을 깨달았습니다.
#### 웹 응용 프로그래밍 과목을 기회로 Git 및 GitHub를 활용하는 방법을 터득하고 있으며 README.md 파일에 작성한 내용을 토대로 여러 사람들이 참고하고 오픈소스로 활용할 수 있다는 사실을 알게 되었습니다. 
#### live server에서는 웹 화면이 나왔지만 GitHub Pages 생성시에 웹 화면이 나오지 않아 당황했었습니다. 문제는 파일명이었습니다. 초기 html파일을 추가할 때 index.html로 파일명을 설정해야한다는 사실을 알게 되었습니다. "git mv <기존파일명> index.html"로 파일명을 바꾼 후 add, commit, push단계로 수정하였습니다.