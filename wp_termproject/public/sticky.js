function createSticky(){ //sticky함수
    const body = document.querySelector("body"); //body를 선택하여 body에 넣어줌
    
    const stickyNote = document.createElement("div"); //div를 선택하여 stickynote에 넣어줌
    const stickyNav = document.createElement("div"); //div를 선택하여 stickynav에 넣어줌
    const stickyWritingPad = document.createElement("div"); //div를 선택하여 stickywritingpad에 넣어줌
    const close = document.createElement("div"); //div를 선택하여 close에 넣어줌
    const minimize = document.createElement("div"); //div를 선택하여 minimize에 넣어줌
    const stickyTextArea = document.createElement("textarea") //textarea를 선택하여 stickytextarea에 넣어줌

    stickyNote.setAttribute("class","Sticky-note"); //class(속성 이름)와 sticky-note(속성 값)을 stickynote에 넣어줌
    stickyNav.setAttribute("class","Sticky-nav"); //class(속성 이름)와 sticky-nav(속성 값)을 stickynav에 넣어줌
    stickyWritingPad.setAttribute("class","Sticky-writingpad"); //class(속성 이름)와 sticky-writingpad(속성 값)을 stickywritingpad에 넣어줌
    close.setAttribute("class","Sticky-close"); //class(속성 이름)와 close(속성 값)을 close에 넣어줌
    minimize.setAttribute("class","Sticky-minimize"); //class(속성 이름)와 sticky-minimize(속성 값)을 minimize에 넣어줌
    stickyTextArea.setAttribute("class","Sticky-textarea"); //class(속성 이름)와 sticky-textarea(속성 값)을 stickytextarea에 넣어줌

    stickyWritingPad.appendChild(stickyTextArea); //stickywritingpad에 stickytextarea를 추가
    stickyNav.appendChild(close); //stickynav에 close를 추가
    stickyNav.appendChild(minimize); //stickynav에 minimize를 추가
    stickyNote.appendChild(stickyNav); //stickynote에 stickynav를 추가
    stickyNote.appendChild(stickyWritingPad); //stickynote에 stickywritingpad를 추가
    body.appendChild(stickyNote); //body에 stickynote를 추가

    let flag = true; //flag를 true로 초기화
    minimize.addEventListener("click",function(){ //minimize가 클릭되는 이벤트가 발생하면
        if(flag){ //true이면
            stickyWritingPad.classList.add("Hidden"); //stickywritingpad를 숨긴다
        }else{ //아니면
            stickyWritingPad.classList.remove("Hidden"); //stickywritingpad를 보인다
        }
        flag = (!flag); //flag에 !flag를 넣는다
    });
    close.addEventListener("click",function(){ //close가 클릭되는 이벤트가 발생하면
        stickyNote.remove(); //stickynote를 제거한다
    });
//---------------------------- Move -------------
    let isStickyDown = false; //sticky가 붙여졌는지 검사
    let intialX = null; //초기x값을 null
    let intialY = null; //초기y값을 null
   stickyNav.addEventListener("mousedown", function (e) { //stickynav를 마우스로 누르면
       intialX = e.clientX; //초기x값에 clientX를 대입
       intialY = e.clientY; //초기y값에 clientY를 대입
       isStickyDown = true; //isstickydown을 true로 바꿈
    });
   stickyNav.addEventListener("mousemove", function (e) { //stickynav를 마우스로 움직이면
        if (isStickyDown == true){ //isstickydown을 true이면
            let finalX = e.clientX; //마지막x값에 clientX를 대입
            let finalY = e.clientY; //마지막y값에 clientY를 대입
            let diffX = finalX - intialX; //x값의 차에 마지막x값-초기x값 대입
            let diffY = finalY - intialY; //y값의 차에 마지막y값-초기y값 대입
            let { top,left } = stickyNote.getBoundingClientRect(); //stickynote의 높이, 폭를 top, left로 놓는다
            stickyNote.style.top = top + diffY + "px"; //stickynote의 top에 top과 diffY와 px를 더한 값을 넣는다
            stickyNote.style.left = left + diffX + "px"; //stickynote의 left에 left와 diffX와 px를 더한 값을 넣는다
            intialY = finalY; //초기Y값에 마지막Y값을 대입
            intialX = finalX; //초기X값에 마지막X값을 대입
        }

    });
   stickyNav.addEventListener("mouseup", function (e) { //stickynav에서 마우스를 뗐을 때
        isStickyDown = false; //stickydown이 false가 된다
    });
    stickyNav.addEventListener("mouseleave", function (e) { //stickynav에서 마우스가 떨어졌을 때
        isStickyDown = false; //stickydown이 false가 된다
    });

}