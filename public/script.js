const socket = io.connect("https://mydrawboard.herokuapp.com/"); //io에 허로쿠로 만든 주소를 연결하여 socket에 넣어준다
const board = document.querySelector(".board"); //board선택자를 선택하여 board에 저장
var rect = board.getBoundingClientRect(); //rect에 뷰포트에서 상대적인 엘리먼트의 크기를 리턴한 값을 저장
board.height = window.innerHeight; //board의 높이에 window의 창 틀을 뺀 내용의 높이를 넣는다 
board.width = window.innerWidth; //board의 폭에 window의 창 틀을 뺀 내용의 폭을 넣는다 

const ctx = board.getContext("2d"); //선에 board의 캔버스2D컨텍스트를 설정하여 넣는다.

const inputPen = document.querySelector("#size1"); //size1선택자를 선택하여 inputpen에 넣어줌
const inputEraser = document.querySelector("#size2"); //size2선택자를 선택하여 inputeraser에 넣어줌
ctx.lineWidth = inputPen.value; //선의 두께는 inputpen의 value값

inputPen.addEventListener("change",function(){ //inputpen의 이벤트가 생기면
    ctx.lineWidth = inputPen.value; //선의 두께는 inputpen의 value값
    socket.emit("size",ctx.lineWidth); //선의 두께에 size로 서버에 전달
});

inputEraser.addEventListener("change",function(){ //inputeraser의 이벤트가 생기면
    ctx.lineWidth = inputEraser.value; //선의 두께는 inputeraser의 value값
    socket.emit("size",ctx.lineWidth); //선의 두께에 size로 서버에 전달
});

let ActiveTool = "Pencil"; //ActiveTool을 pencil로 설정
const pencilOptions = document.querySelector(".Pencil"); //pencil을 선택하여 penciloptions에 넣어줌
const eraserOptions = document.querySelector(".Eraser"); //eraser를 선택하여 eraseroptions에 넣어줌
var clickCnt = 0; //클릭카운트를 0으로 초기화
function handleToolChange(tool){ //toolchange함수를 선언
    if(tool == "Pencil"){ //툴이 pencil이면
        if(ActiveTool == "Pencil" && clickCnt == 1){ //activetool이 pencil이고 클릭카운트가 1이면
            pencilOptions.classList.add("show"); //penciloptions에 show를 추가
            clickCnt = 2; //클릭카운트를 2로 초기화
        }else if(ActiveTool == "Pencil" && clickCnt == 2){ //activetool이 pencil이고 클릭카운트가 2이면
            pencilOptions.classList.remove("show"); //penciloptions에 show를 제거
            eraserOptions.classList.remove("show"); //eraseroptions에 show를 제거
            ActiveTool = "Pencil"; //ActiveTool을 pencil로 설정
            clickCnt = 0; //클릭카운트를 0으로 초기화
        }else if(ActiveTool == "Pencil" && clickCnt == 0){ //activetool이 pencil이고 클릭카운트가 0이면
            pencilOptions.classList.add("show"); //penciloptions에 show를 추가
            clickCnt = 2; //클릭카운트를 2로 초기화
        }
        else{ //나머지 경우에
            eraserOptions.classList.remove("show"); //eraseroptions에 show를 제거
            ctx.strokeStyle = "blue"; //선의 색을 파란색으로 설정
            ctx.lineWidth = inputPen.value; //선의 두께를 inputpen의 value값으로 설정
            ActiveTool = "Pencil"; //ActiveTool을 pencil로 설정
            clickCnt = 1; //클릭카운트를 1로 초기화
        }
    }else if(tool == "Eraser"){ //툴이 eraser이면
        if(ActiveTool == "Eraser" && clickCnt == 1){ //activetool이 eraser이고 클릭카운트가 1이면
            eraserOptions.classList.add("show"); //eraseroptions에 show를 추가
            clickCnt = 2;
        }else if(ActiveTool == "Eraser" && clickCnt == 2){ //activetool이 eraser이고 클릭카운트가 2이면
            pencilOptions.classList.remove("show"); //penciloptions에 show를 제거
            eraserOptions.classList.remove("show"); //eraseroptions에 show를 제거
            ctx.strokeStyle = "white"; //선의 색을 하얀색으로 설정
            ActiveTool = "Eraser"; //ActiveTool을 eraser로 설정
            clickCnt = 0; //클릭카운트를 0으로 설정
        }else if(ActiveTool == "Eraser" && clickCnt == 0){ //activetool이 eraser이고 클릭카운트가 0이면
            eraserOptions.classList.add("show"); //eraseroptions에 show를 추가
            clickCnt = 2; //클릭카운트를 2로 설정
        }
        else{ //나머지 경우에
            ctx.strokeStyle = "white"; //선의 색을 하얀색을 설정
            pencilOptions.classList.remove("show"); //penciloptions에 show를 제거
            ctx.lineWidth = inputEraser.value; //선의 두께를 inputpen의 value값으로 설정
            ActiveTool = "Eraser"; //ActiveTool을 eraser로 설정
        }
    }else if(tool == "Sticky"){ //툴이 sticky이면
        pencilOptions.classList.remove("show"); //penciloptions에 show를 제거
        eraserOptions.classList.remove("show"); //eraseroptions에 show를 제거
        ActiveTool = "Sticky"; //ActiveTool을 Sticky로 설정
        clickCnt = 0; //클릭카운트를 0으로 설정
        createSticky(); //함수호출
    }
}

function handleColorChange(color){ //컬러체인지 함수 선언
    ctx.strokeStyle = color; //선의 색을 컬러로 설정
    socket.emit("color",ctx.strokeStyle); //선의 색을 소켓으로 전달
}