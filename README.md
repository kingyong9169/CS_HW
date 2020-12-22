프로젝트 주제 설명
================
#### term project : 처음에 게시판 만들기를 생각하다가 실시간 온라인 낙서장 즉 화이트보드를 만들어보고 싶어 이 주제를 선정하였고 그 과정에서 socket, node.js, express 등 처음 접해보는 기능들을 활용하면서 실력을 늘릴 수 있었고 개발에 있어 어려운 것은 있어도 불가능은 없다는 것을 깨달았습니다. 모든 코드는 주석을 통해 설명을 추가하였습니다. 프로그램에서 사용한 언어는 html, css, js이며 node.js, express를 통해 서버를 구축하였습니다.

프로젝트 구조 설명
================
#### NewIcons파일에는 웹사이트 프론트엔드에서 사용할 이미지 파일들이 들어 있고 node_modules는 .gitignore로 제외해주었습니다. public에는 실제 프로젝트에서 사용할 여러 js, css, html파일이 있고 json파일에는 서버에서 사용할 express, socket.io정보가 들어있습니다. server.js파일은 서버 구현을 위한 js파일이며 이렇게 프로젝트를 구성하였습니다.

프로젝트 웹사이트 사용 방법
================
#### 웹사이트 상단에 pencil, eraser, sticky, undo, redo, upload 이렇게 메뉴가 구성되어 있습니다. download와 search는 아직 구현하지 못했습니다. 
1. 처음 화이트보드에 마우스 왼쪽버튼을 누른채로 마우스를 움직이면 선을 그릴 수 있는 것을 확인할 수 있습니다. pencil을 누르면 선의 굵기, 색을 선택할 수 있고 이에 따라 선의 두께, 색상이 변하는 것을 확인할 수 있습니다.
2. eraser를 선택하면 지우개의 굵기 또한 변경할 수 있습니다. 말그대로 화이트보드에 그린 그림을 지울 수 있습니다.
3. sticky는 스티커로 메모를 남길 수 있습니다. 노란색 부분을 클릭하면 커서가 들어오는 것을 확인할 수 있고 글을 입력할 수 있습니다. 또한, 스티커를 자유롭게 이동할 수 있으며 빨간색 버튼을 누르면 스티커를 제거하고 하늘색 버튼을 누르면 스티커를 최소화할 수 있습니다.
4. undo버튼은 redo로 되돌렸던 것들을 다시 원위치로 복귀시키는 기능입니다. 
5. redo버튼은 뒤로 되돌아가기 기능입니다.
6. upload버튼은 pc에서 사진을 업로드할 수 있는 기능입니다. 또한, 사진을 자유롭게 이동할 수 있습니다.

## index.html
1. 웹페이지 상단에 menu를 생성하였고 먼저 pencil 툴을 넣었습니다. pencil이미지를 삽입하고 pencil을 클릭하면 handletoolchange이벤트가 발생하도록하여 tool options으로 pencil의 사이즈를 5~30까지 변화시키며 이 값을 size1으로 지정하였습니다. 또한, pencil의 컬러를 변화시키는 이벤트인 handlecolorchange이벤트를 지정하였고 각 버튼을 구성하였습니다.
2. eraser 툴을 넣어 이미지를 삽입하고 클릭 이벤트가 발생하면 handletoolchange이벤트를 전달하여 eraser의 크기를 50~300까지 변화를 주었고 이를 size2로 지정하였습니다.
3. sticky 툴을 넣어 이미지를 삽입하고 클릭 이벤트가 발생하면 handletoolchange이벤트를 전달하도록 하였습니다.
4. tool로 redo, undo의 이미지를 넣어주었고 undo, redo클래스로 지정하여 canvas.js에서 이미지를 클릭하면 이벤트가 발생하도록 하였습니다.
5. uploadtool을 선택하면 type : file로 지정하고 accept: file_extension|image/*로 지정하여 이미지 파일만을 업로드할 수 있도록 하였습니다.
6. download, search기능은 아직구현하지 못하여 이미지만 업로드하였습니다.
7. board를 canvas타입으로 하였고 socket.io사용을 위해 lib위치를 선언해주고 crossorigin속성을 사용하여 정적 미디어에 대해 별도의 도메인으로 사용하는 사이트의 오류 기록을 허용하도록 하였습니다. 
8. 마지막으로 javascript사용을 위해 script, canvas, sticky, upload, receiver js파일을 script요소로 지정하였습니다.

## style.css
1. 상단 메뉴에 각 툴이 포함되도록 display : flex요소를 넣어주었고 각 툴들의 이미지, 옵션에 따라 다르도록 설정하였고 pencil-size, pencil-color, eraser-size, sticky-note, sticky-nav, sticky-writingpad, sticky-textarea, sticky-close, sticky-minimize 속성을 지정하여 버튼들의 색상과 높이, 둥근모양, 폭을 설정하여 UI디자인을 하였습니다.
2. hidden 즉 숨기는 버튼을 눌렀을 때 보이지 않도록 해주었고 uploadimage의 크기와 위치를 지정해주었습니다.

## package.json
1. 강의에서 배운 내용들을 토대로 npm init을 통해 name, version, description, main, author, license를 정해줍니다.
2. express를 설치하여 서버를 구축하고 socket.io를 설치하여 실시간으로 데이터가 반영될 수 있도록 합니다.
3. package.json으로부터 만들어진 express, socket.io의 정보가 package-lock.json에 담겨져 있습니다.

## canvas.js
1. 이 js파일은 프로젝트의 main파일로 화이트보드에 선을 그리고 undo, redo기능을 담당하는 파일입니다.
2. undostack, redostack을 선언하고 선 끝 부분, 꺾이는 부분의 스타일을 round로 지정합니다.
3. 보드에 mousedown 이벤트가 감지되면 펜을 마우스 위치로 옮기고 x,y좌표, 식별자를 mousedown으로 지정해줍니다. 그리고 소켓으로 이벤트를 전달해주고 undostack에 좌표를 푸쉬합니다.
4. 보드에 mousemove 이벤트가 감지되면 펜을 현재 드로우 위치에서 마우스가 움직이는 위치로 선을 그리며 식별자를 mousemove로 지정하고 소켓으로 이벤트를 전달합니다. 마지막으로 undostack에 좌표를 푸쉬합니다.
5. 보드에 mouseup 이벤트가 감지되면 그리는 것을 중단하는 의미로 ok=false를 지정하고 소켓으로 이벤트를 전달합니다.
6. undo, redo선택자를 선택하여 각 변수에 저장하고 undo버튼이 눌리면 보드의 특정부분을 지우고 undostack에서 팝한 것을 redostack에 푸쉬하고 redraw함수를 통해 다시 그리기를 합니다. 마지막으로 소켓으로 이벤트를 전달합니다.
7. redo버튼이 눌리면 보드의 특정 부분을 지우는 작업을 하며 redostack에서 팝한 것을 undostack에 푸쉬하고 redraw함수를 호출합니다. 마지막으로 소켓으로 이벤트를 전달합니다.
8. redraw함수는 undostack의 크기까지 반복하며 선을 다시 그리는 작업을 합니다.

## server.js
1. express모듈을 사용하여 express application객체를 생성하고 express로 웹서버를 실행합니다. 또한, socket.io서버를 생성합니다.
2. 미들웨어를 사용하여 정적 파일을 제공해줍니다.
3. 실시간 데이터 송수신을 위해 socket.io를 사용하며 color, size, drawmousedown, drawmousemove, drawmouseup, undomousedown, redomousedown의 식별자들을 감지하면 각각에 대한 이벤트를 전달합니다.
4. 마지막으로 process.env객체에 port라는 설정이 있다면 사용하고 없다면 3000을 사용하여 listen메소드 호출하면 서버는 요청을 기다리고 정상 실행된다면 콘솔에 문구를 출력합니다.

## script.js
1. herokuapp으로 부터 만든 웹사이트를 연결하여 socket이라는 변수에 넣어줍니다. board선택자를 선택하여 board에 넣어주고 윈도우의 높이, 폭을 board의 높이, 폭으로 설정합니다. 마지막으로 선에 board의 캔버스2D컨텍스트를 설정하여 넣어줍니다.
2. size1선택자를 선택하여 inputpen, size2선택자를 선택하여 inputeraser에 넣어주고 선의 두께를 inputpen의 value로 설정합니다.
3. inputpen의 이벤트가 발생하면 inputpen의 value값을 선의 두께로 하며 이 정보를 소켓을 통해 서버로 전달합니다. inputeraser도 마찬가지로 동작합니다.
4. activetool을 pencil로 설정하고 pencil, eraser클래스를 선택자로 선택하여 각 변수에 넣어주고 클릭카운트를 초기화합니다.
5. toolchange함수를 선언하여 툴이 pencil일 때 카운트가 1, 2, 0에 따라 실행되는 제어문이 다르며 1, 0일 때 pencil설정메뉴를 띄우고 2일 때 제거하며 나머지 경우에 eraseroptions을 제거하고 선의 색을 파란색으로 바꾸며 카운트를 1로 초기화합니다.
6. tool이 eraser일때 클릭카운트가 0, 1, 2인 경우에 따라 다르며 0, 1일 때 옵션을 띄우고 2일때 옵션을 제거하고 지우개 색을 하얀색으로 바꾸어 지우는 기능을 합니다.
7. tool이 sticky이면 지우개, 연필 옵션을 모두제거하고 createsticky를 통해 함수호출을 합니다.
8. 마지막으로 컬러체인지 함수를 통해 선의 색을 바꾸고 소켓으로 정보를 전달합니다.

## receiver.js
1. 소켓에 이벤트가 전달되면 handlecolorchange, handlesizechange, handledrawmousedown, handledrawmousemove, handledrawmouseup, handleundomousedown, handleredomousedown이벤트를 통해 선의 색을 바꾸고 선의 두께를 지정하며 선을 그리고 undo, redo기능을 수행하는 역할을 합니다.

## sticky.js
1. body클래스 선택자로 선택하여 body에 넣어주고 div를 sticky, stickynav, stickywritingpad, close, minimize, stickytextarea 선택자로 선택하여 각 변수에 넣어줍니다.
2. 그리고 속성이름과 속성 값을 각 변수에 속성으로 지정합니다.
3. stickywritingpad에 stickytextarea를 추가하고 stickynav에 close, minimize를 추가하고 stickynote에 stickynav, stickywritingpd를 추가하고 마지막으로 body에 stickynote를 추가하여 완성합니다.
4. minimize버튼(하늘색)을 누르면 stickywritingpad를 숨기며 close버튼(노란색)을 누르면 stickynote를 제거합니다.
5. stickynote를 이동할 수 있는 기능을 설명하면 stickynav 즉 스티커의 상단 초록색 부분을 클릭하면 초기좌표를 설정하고 마우스를 움직이며 마지막 좌표를 설정하고 그 차이만큼 이동하며 마우스를 떼거나 leave했을 때 움직이지 않도록 합니다.

## upload.js
1. uploadinput, uploadtool클래스 선택자로 선택하여 각 변수에 넣어줍니다.
2. uploadtool을 클릭하여 uploadinput을 클릭함수를 호출합니다.
3. uploadinput이 change이벤트가 실행되면 img를 새로운엘리먼트로 uploadimg에 넣어주고 uploadimgdata에 blob주소를 변환하고 그 주소를 uploadimg.src에 변환합니다. 또한, 속성 이름과 속성 값을 uploadimg에 넣어줍니다. 
4. body 선택자를 선택하여 body에 넣어주고 body에 uploadimg를 추가합니다.
5. uploadimg를 이동할 수 있는 기능을 설명하면 uploadimg를 클릭하면 초기좌표를 설정하고 마우스를 움직이며 마지막 좌표를 설정하고 그 차이만큼 이동하며 마우스를 떼거나 leave했을 때 움직이지 않도록 합니다.
6. 마지막으로 img가 로드되면 생성한 기존의 URL을 폐기합니다.

비고 및 고찰
==============
#### 지금까지 강의에서 배운 내용을 기반으로 socket.io기능까지 추가하여 html, css를 바탕으로 뼈대 UI를 만들어 웹의 시각적인 부분을 익히고 기초적인 지식을 활용하였고 웹서버 구축까지 해볼 수 있는 아주 소중한 기회였습니다. 비록 바쁜 시간에도 불구하고 더 나은 프로젝트를 수행하기 위해 구글링 검색을 통해 공부를 게을리 하지 않았고 그 과정에서 제 실력을 발전시킬 수 있었습니다.
#### 처음 웹프로그래밍을 수강할 때 "내가 이것을 할 수 있을까?"라는 의문을 던졌지만 나날이 과제와 프로젝트를 수행하며 실력이 늘고 있는 제 자신을 발견할 수 있었습니다. 특히, node.js, express, socket.io부분을 구글링 검색을 하며 그 기능을 이해할 수 있었고 이것을 적용할 수 있는 능력도 얻게 되었습니다.
#### 이 프로젝트를 수행하며 언어를 완벽히 숙달하는 것은 굉장히 어려운 일이며 적재적소에 어떤 기능을 사용할 수 있는지 익히는 것이 가장 중요하다고 생각했고 오픈소스를 통해 그 소스를 제 것으로 만드는 것이 가장 중요하다는 것을 느낄 수 있었습니다. 또한, github를 통해 협업을 할 수 있는 기초 틀을 다질 수 있었다고 생각합니다.
#### 아쉬운 점은 시험기간으로 인해 많은 시간을 이 프로젝트에 투자하지 못하여 데이터베이스를 구축하지 못했다는 점이 가장 아쉬우며 더 발전시켜 "캐치마인드"비슷하게 실시간으로 다른 사람의 메모까지 볼 수 있는 프로그램을 만들고 싶다는 생각을 했습니다.