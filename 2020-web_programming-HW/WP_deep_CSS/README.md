과제 주제 설명
================
#### 5주차 주제 4주차 과제를 활용하여 Transition, Transform, animation기능사용

주요 코드 설명
================
#### .html파일에 css요소를 넣지 않고 css폴더를 만들어 가독성을 높였고 기존 html파일에 있던 css요소들은 basic.css파일에 옮겨 구현하였습니다.
#### 아래 코드 설명은 4주차 내용을 제외하고 변경한 내용을 바탕으로 순서대로 작성하였습니다.

## 상위 International 메뉴버튼 및 사이드 메뉴 구현
1. header안에 button의 id를 menu-button으로 설정하고 bar속성을 가진 div 3개를 생성하며 제목은 International로 지정
2. header속성의 주요 요소는 position : fixed로 각 요소를 고정하였고 box-shadow를 설정하여 그림자 효과를 나타내었습니다. 또한, z-index를 10으로 두어 메뉴가, 모든 요소들의 가장 윗 부분에 위치하도록 하였습니다.
3. menu-button의 주요 요소는 background-color를 투명으로 설정하였고 cursor를 pointer로 설정하여 메뉴버튼에 커서를 갖다 대었을 때, 손모양이 되도록 하였습니다. 또한, menu-button의 bar 부분을 style.css파일의 내용과 같이 하여 컴팩트한 디자인을 완성하였습니다.
4. nav의 id를 side-menu, hidden속성을 갖게 하고 unordered list 8개를 만들어 사이드메뉴를 구현하였습니다.
5. side-menu가 hidden상태일 때 좌측으로 -100%로 설정하여 가리도록 하였고 side-menu에 있는 seoul, busan 등 요소의 디자인을 style.css파일과 같이 나타내었습니다.
6. javascript코드를 이용해 메뉴버튼을 누르면 사이드메뉴가 생기고 닫히고를 구현하였습니다. 코드를 살펴보면 처음에 hidden=true로 사이드메뉴를 감추게 하였습니다. 그리고 document. getElementById를 통해 menu-button, side-menu를 연결하여 화면에 나타내었고 메뉴버튼을 클릭했을 때, hidden=true이면 사이드메뉴를 열고 false이면 사이드메뉴를 감추도록 구현하였습니다.

## 메인 배너 만들기
1. banner.css로 배너의 요소를 만들었고 div를 contain속성으로하여 문구 2개를 삽입하였습니다.
2. contain 클래스를 선언하여 처음에 height를 300px로 선언하였고 transition-duration:1s로 트랜지션 기능을 사용하였습니다.
3. 배경을 이미지 링크로 하였고 background-blend-mode를 overlay로 선언하여 만약 배경에 두 개 이상의 사진이나 색이 겹칠 때 가장 밝은 색이 겹친 부분에 오도록 설정하였습니다.
4. contain의 모든 요소의 포지션은 absolute로 설정하였고 배경화면이 overflow가 발생할 경우 hidden으로 설정하여 가리도록 하였습니다.
5. hover 즉, 마우스를 갖다 대었을 때 height:400px로 트랜지션을 구현하였습니다. 또한, 애니메이션으로 banner-title과 banner-content를 설정하였지만 실제 코드에서는 쓰이지 않습니다.

## 갤러리 구현
1. 먼저, html파일에 div를 container속성으로 선언하여 이미지 4개를 삽입하였습니다.
2. gallery.css파일을 설명하면 먼저 container 속성에 display:grid로 각 요소들의 크기가 다르더라도 빈 부분이 존재하지 않도록 채우며 구현하도록 하였습니다.
3. grid-template-columns에서 150px씩 5줄을 구현하도록 하였고 grid의 rows의 크기는 100px, grid-auto-flow:row dense로 설정하여 그리드 아이템의 크기에 따라 빈 공간을 먼저 채우도록 하였지만 때문에 순서가 뒤바뀌어 접근성이 떨어질 수 있습니다. 
4. 이미지의 트랜지션 효과를 넣어 hover를 했을 때, opacity:1로 완전불투명을 구현함과 동시에 요소의 크기를 기존의 1.1배로 하고 z-index를 1로 설정하여 앞에 튀어나오는 듯한 효과를 설정하였습니다.
5. 추가로 big속성을 설명하면 기존의 grid의 폭, 높이 둘 다 2배로 하였지만 디자인적 요소를 위해 이 코드에서는 사용하지 않았습니다.

## 마지막 아이템 박스에 배경화면 설정
1. 기존 내용은 gray색 120px박스였지만 background-image:url로 배경화면을 이미지로 설정하였고 item box의 속성으로 flex가 적용되어 배경화면을 채우고 남은 부분을 모두 빈틈없이 배경화면 이미지를 반복하여 채우도록 하였습니다.

비고 및 고찰
==============
#### 지금까지 html을 바탕으로 뼈대를 만드는 방법과 기본적인 css디자인을 배워 웹에 있어 기초적인 지식을 다뤘지만 이번 transition, transform, animation기능을 배워 웹의 생기와 특색있는 디자인을 만들 수 있는 방법을 알게 되어 제가 만들고자 하는 해외직구 웹사이트에 도움을 줄 수 있는 지식을 배울 수 있던 아주 유용한 시간이었고 keyframes를 더 많이 사용하여 animation을 활용해야겠다는 생각을 했습니다.
#### 웹 응용 프로그래밍 과목을 기회로 Git 및 GitHub를 활용하는 시간을 더 많이 가질 수 있는 것에 큰 의미가 있다고 생각하는 소중한 시간이었습니다.
#### 처음 트랜지션, 트랜스폼, 애니메이션 기능을 배워 4주차 과제에서 사용하던 코드에 바로 적용하는 것이 쉽지는 않았지만 모르는 부분을 구글링하며 강의자료를 통해 학습하여 실력을 기를 수 있었던 시간이었습니다.
#### 아쉬운 점은 다양한 애니메이션을 적용하지 못한 것이 가장 아쉬웠고 더욱 실력을 쌓아 여러 기능을 사용해야겠다는 생각을 했습니다.
