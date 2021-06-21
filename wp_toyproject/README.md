과제 주제 설명
================
#### 9주차 주제: 주소 검색API를 이용한 간단한 웹사이트 구현 및 예제 분석
웹사이트 설명
================
#### .html파일로 웹사이트의 뼈대를 만들고 .css파일로 웹사이트의 UI디자인을 구성하였습니다. 마지막으로 강의에서 배운 promise, async로 주소 검색 API를 활용하여 주소 검색 웹사이트를 구현하였습니다.
#### html, css, js순으로 설명을 넣었습니다.


## index.html
1. body에 nav를 넣어 웹사이트 상단에 메뉴버튼을 구현하였습니다.
2. nav안에 nav-item 5개를 넣어 리스트를 구성하였습니다.
3. THATISNEVERTHIS라는 글을 넣어 signUp-message라는 클래스로 구현하였습니다.
4. main-contatiner라는 클래스로 div를 넣었고 주소 검색 폼을 form으로 구현하였습니다.
5. form안에는 먼저 주소를 입력하라는 메시지를 넣었고 밑에 unordered list로 address-list를(즉, 내용이 없는 리스트) 넣었고 text타입으로 주소를 input하도록 하였습니다.
6. 그 다음 address-search를 사용하여 주소검색하는 함수를 부르는 submit타입의 버튼을 만들었고 address-list클래스를 갖고 id가 address-list인 unordered list를 넣어 완성하였습니다.


## style.css
1. 상단 메뉴를 담는 nav-container 클래스에는 display를 flex로 박스의 옆에 남는 공간을 유동적으로 채우도록 하였고 position을 fixed로 안의 리스트를 고정시켰습니다.
2. 메뉴의 각 아이템을 cursor를 pointer로 하였고 child를 text 정렬과 색깔, 폰트를 지정하였습니다. 또한 커서를 갖다 대었을 때 텍스트 색깔과 배경색이 바뀌도록 하였습니다.
3. 주소 검색리스트를 출력하는 main-container의 그림자효과를 주었고 form의 모든 font를 나눔고딕, sans-serif로 설정하였습니다.
4. form의 input과 input:focus를 설정하여 form의 text부분을 클릭했을 때 색이 바뀌도록하였습니다. 또한 form의 버튼:hover 속성을 지정하여 마우스를 갖다 대었을 때 색이 바뀌도록 하였습니다.
5. 주소리스트를 의미하는 address-list 속성에는 각 요소를 둥근 사각형으로 만들기 위해 border-radius를 설정하였고 hover할 때 배경색이 흰색으로 바뀌게 구현하였습니다. 


## script.js
1. 처음에 API의 URL, API의 KEY, form으로 선택될 수 있는 요소, address-list로 선택될 수 있는 요소를 각 변수로 설정해줍니다
2. submit동작에 대한 콜백함수를 async함수로 구현하며 1. 기본적인 동작을 막아준다 2. keyword의 값을 인코딩하여 keyword에 넣어준다 3. keyword를 인자로 search라는 함수 호출하여 결과를 response에 넣는다 4. response를 text로 받는다 5. JSON에서 양쪽의 ( )를 제거하여 results에 넣어준다 6. results를 출력, form 리셋을 한다 만약 에러가 발생하면 에러 메시지를 출력한다
3. search함수 : 1페이지 당 리스트 10개씩 보여준다 1. data안에 있는 정보에 API_KEY, keyword, 현재페이지, 페이지 당 몇 개인지를 저장하며 결과타입은 json형식 2. data를 (key & key의 값)형식으로 묶어서 맵핑하여 문자열로 가져온다 3.options에 POST방법, body, headers를 구성으로 한 타입을 선언 4. 마지막으로 결과를 API_URL로 options의 형태로 요청을 보낸다.
4. results를 출력하는 함수 : 1. addresslist의 innerHTML을 초기화 2. 결과 중 주소 하나씩 li에서 가져와서 하나의 요소로 만들고 li변수에 저장 3. li의 클래스이름을 address-li로 설정한다 4. li의 innerHTML에 "우편번호 도로명주소"로 저장한다 5. 이렇게 만들어진 li를 addressList에 차례대로 저장한다.


비고 및 고찰
==============
#### 지금까지 강의에서 배운 html, css를 바탕으로 뼈대 UI를 만들어 웹의 시각적인 부분을 익히고 기초적인 지식을 활용할 수 있는 기회였습니다. 또한, JS언어로 주소 검색 기능을 구현하였고 코드를 분석하며 promise, async, await 등 비동기 처리를 배우고 활용할 수 있는 기회였습니다.
#### 웹 응용 프로그래밍이라는 실습 위주 과목을 기회로 다른 이론적인 강의와는 다르게 Git 및 GitHub를 활용하는 시간을 더 많이 가질 수 있으며 포트폴리오를 조금 더 풍부하고 협업에 있어 기초 능력을 습득할 수 있는 시간이었습니다.
#### 처음 promise, async 관련 강의를 들으며 이해가 가지 않는 부분이 많아 과제를 어떻게 수행할지 굉장히 고민이었지만 교수님의 매뉴얼대로 예제를 하나씩 해석해보면서 이 기능들을 익히고 과제를 수행하고 지식을 쌓는데 큰 도움이 되었다고 생각했습니다.
#### 아쉬운 점은 다양한 API(네이버 지도, 카카오맵, 구글맵 등)를 활용해보지 못한 것이 가장 아쉬웠고 더욱 실력을 쌓아 주소를 입력하면 지도 상에서 주소의 위치를 보여주는 기능을 탑재해보고 싶습니다.
