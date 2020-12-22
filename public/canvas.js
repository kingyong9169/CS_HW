var ok = false; //ok변수를 false로 둔다
ctx.lineCap = "round"; //선 끝 부분의 스타일을 round로 지정
ctx.lineJoin = "round"; //선이 꺾이는 부분의 스타일 지정 round로 지정
 
let undoStack = []; //실행취소를 했던 것들을 리스트로 저장
let redoStack = []; //실행취소 했던 것들을 다시 꺼내어 다시 실행할 것들을 리스트로 저장
board.addEventListener("mousedown",function(e){ //보드에 마우스를 눌렀다가 떼지 않았을 때
    ok = true; //ok를 true로 바꾼다.
    ctx.beginPath(); //새로운 경로를 만든다. 
    ctx.moveTo(e.clientX-rect.x,e.clientY-rect.y); //펜을 지정한 좌표로 옮긴다.
    let point = {
        x : e.clientX-rect.x,
        y : e.clientY-rect.y,
        identifier : "mousedown", //식별자를 mousedown으로 한다
        color : ctx.strokeStyle, //선 색 지정
        width : ctx.lineWidth, //선 두께 지정
    }
    socket.emit("drawMouseDown",point); //소켓으로 이벤트 전달
    undoStack.push(point); //undostack에 좌표 푸쉬
});
board.addEventListener("mousemove",function(e){ //보드에 마우스가 움직일 때
    if(ok){ //보드에 마우스를 눌렀는데 움직일 때
        ctx.lineTo(e.clientX-rect.x,e.clientY-rect.y); //현재 드로잉 위치에서 좌표까지 선을 그린다
        ctx.stroke(); //윤곽선을 이용하여 도형을 그린다
        let point = {
            x : e.clientX-rect.x,
            y : e.clientY-rect.y,
            identifier : "mousemove", //식별자를 mousemove로 한다
            color : ctx.strokeStyle, //선 색 지정
            width : ctx.lineWidth, //선 두께 지정
        }
        undoStack.push(point); //undostack에 좌표 푸쉬
        socket.emit("drawMouseMove",point); //소켓으로 이벤트 전달
    }
});

board.addEventListener("mouseup",function(e){ //mouseup 이벤트가 발생하면
    ok = false; //false로 바꾸고
    socket.emit("drawMouseUp"); //소켓으로 이벤트 전달
});

// ---------- Undo/Redo-------------------
const undo = document.querySelector(".undo");
const redo = document.querySelector(".redo");

undo.addEventListener("mousedown",function(e){ //undo버튼이 눌렸을 때
    ctx.clearRect(0,0,board.width,board.height); //보드의 특정 부분을 지우는 직사각형을 설정한다
    let point = undoStack.pop(); //point를 undostack에서 팝한 것으로 초기화한다
    redoStack.push(point); //redostack에 point를 푸쉬한다
    redraw(); //redraw 함수 호출
    socket.emit("undoMouseDown"); //소켓으로 이벤트 전달
});

redo.addEventListener("mousedown",function(e){ //redo버튼이 눌렸을 때
    ctx.clearRect(0,0,board.width,board.height); //보드의 특정 부분을 지우는 직사각형을 설정한다
    let point = redoStack.pop(); //point를 redostack에서 팝한 것으로 초기화한다
    undoStack.push(point); //undostack에 point를 푸쉬한다
    redraw(); //redraw 함수 호출
    socket.emit("redoMouseDown"); //소켓으로 이벤트 전달
});

function redraw(){ //redraw 함수
    console.log("here1"); //콘솔창에 출력한다.
    for(let i = 0; i < undoStack.length ; i++){ //i가 0부터 undostack의 길이까지 반복
        let {x,y,identifier,color,width} = undoStack[i]; //undostack[i]를 x, y, identifier, color, width로 지정
        console.log(undoStack[i]); //콘솔에 출력
        ctx.strokeStyle = color; //선의 색을 color로 지정
        ctx.lineWidth = width; //선의 두께를 width로 지정

        if(identifier == "mousedown"){ //식별자가 mousedown일 때
            ctx.beginPath(); //새로운 경로를 만든다
            ctx.moveTo(x,y); //해당 좌표로 이동한다
        }else if(identifier == "mousemove"){ //식별자가 mousemove일 때
            ctx.lineTo(x,y); //현재 드로잉 위치에서 좌표까지 선을 그린다
            ctx.stroke(); //윤곽선을 이용하여 도형을 그린다
        }
    }
}