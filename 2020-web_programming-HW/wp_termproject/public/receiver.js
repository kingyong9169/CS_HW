socket.on("handleColorChange",function(color){ //소켓에 컬러가 바뀌는 것이 전달되면
    ctx.strokeStyle = color; //선의 색을 color로 지정
});
socket.on("handleSizeChange",function(size){ //소켓에 사이즈가 바뀌는 것이 전달되면
    ctx.lineWidth = size; //선의 두께을 size로 지정
});
socket.on("handleDrawMouseDown",function(point){ //소켓에 마우스가 눌린 것이 전달되면
    ok = true; //true로 바꾸고
    ctx.beginPath(); //새로운 경로를 만든다.
    ctx.moveTo(point.x,point.y); //펜을 지정한 좌표로 옮긴다.
    undoStack.push(point); //undostack에 point를 푸쉬한다
});
socket.on("handleDrawMouseMove",function(point){ //소켓에 마우스가 움직이는 것이 전달되면
    if(ok){ //true이면
        ctx.lineTo(point.x,point.y); //현재 드로잉 위치에서 좌표까지 선을 그린다
        ctx.stroke(); //윤곽선을 이용하여 도형을 그린다
        undoStack.push(point); //undostack에 point를 푸쉬한다
    }
});
socket.on("handleDrawMouseUp",function(){ //소켓에 마우스를 뗀 것이 전달되면
    ok = false; //false로 바꾸고
});

socket.on("handleUndoMouseDown",function(){ //소켓에 undo버튼을 클릭한 것이 전달되면
    ctx.clearRect(0,0,board.width,board.height); //보드의 특정 부분을 지우는 직사각형을 설정한다
    let point = undoStack.pop(); //point를 undostack에서 팝한 것으로 초기화한다
    redoStack.push(point); //redostack에 point를 푸쉬한다
    redraw(); //redraw함수 호출
});

socket.on("handleRedoMouseDown",function(){ //소켓에 redo버튼을 클릭한 것이 전달되면
    ctx.clearRect(0,0,board.width,board.height); //보드의 특정 부분을 지우는 직사각형을 설정한다
    let point = redoStack.pop();  //point를 redostack에서 팝한 것으로 초기화한다
    undoStack.push(point); //undostack에 point를 푸쉬한다
    redraw(); //redraw함수 호출
});