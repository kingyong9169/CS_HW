const express = require("express"); //
const app = express(); //express Application객체 생성
const server = require("http").Server(app); //express로 웹 서버 실행
const io = require("socket.io")(server); //socket.io서버 생성

app.use(express.static("public")); //미들웨어 사용 : 정적 파일 제공하기

io.on("connection",function(socket){ //실시간 데이터 송수신
    socket.on("color",function(color){ //소켓이 컬러이면
        socket.broadcast.emit("handleColorChange",color); //선택한 컬러로 바꾸는 이벤트 전달.
    });

    socket.on("size",function(size){ //소켓이 사이즈이면
        socket.broadcast.emit("handleSizeChange",size); //선택한 사이즈로 바꾸는 이벤트 전달.
    });

    socket.on("drawMouseDown",function(point){ //소켓이 마우스를 누르고 있음을 감지하면
        socket.broadcast.emit("handleDrawMouseDown",point); //좌표 이벤트 전달
    });

    socket.on("drawMouseMove",function(point){ //소켓이 마우스를 움직이고 있음을 감지하면
        socket.broadcast.emit("handleDrawMouseMove",point); //좌표를 따라가서 선을 그리는 이벤트 전달
    });

    socket.on("drawMouseUp",function(){ //소켓이 마우스를 뗐음을 감지하면
        socket.broadcast.emit("handleDrawMouseUp"); //선을 그만 그리는 이벤트 전달
    })

    socket.on("undoMouseDown",function(){ //소켓이 이전으로 버튼을 감지했을 때
        socket.broadcast.emit("handleUndoMouseDown"); //되돌리기 모듈을 실행하는 이벤트 전달
    });

    socket.on("redoMouseDown",function(){ //소켓이 되돌리기 버튼을 감지했을 때
        socket.broadcast.emit("handleRedoMouseDown"); //되돌리기 모듈을 실행하는 이벤트 전달
    });

});
const port = process.env.PORT || 3000; //process.env객체에 port라는 설정이 있다면 사용 없다면 3000사용
server.listen(port,function(req,res){ //listen메소도를 호출하면 서버는 요청을 기다린다.
    console.log("Server has started at port 3000");
});