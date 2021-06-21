const uploadInput = document.querySelector(".UploadInput"); //uploadinput요소를 선택하여 uploadinput에 대입
const uploadTool = document.querySelector(".UploadTool"); //uploadtool요소를 선택하여 uploadintool에 대입
uploadTool.addEventListener("click",function(){ //uploadtool을 클릭했을 때
    uploadInput.click(); //uploadinput을 클릭
})
uploadInput.addEventListener("change",function(){ //uploadinput에 변경사항을 줬을 때
    const uploadImg = document.createElement("img"); //uploadimg에 img요소를 대입
    const uploadImgData = uploadInput.files[0]; //uploadimgdata에 blob주소 변환

    uploadImg.src = URL.createObjectURL(uploadImgData); //uploadimgdata 즉, blob주소를 img src에 변환
    
    uploadImg.setAttribute("class","UploadImage"); //class(속성 이름)와 uploadimage(속성 값)을 uploadimg에 넣어줌
    
    const body = document.querySelector("body"); //body요소를 선택하여 body에 넣어줌
    body.appendChild(uploadImg); //uploadimg를 body에 추가

//----------Image Move-------------------------   
    let isImageDown = false; //image가 붙여졌는지 검사
    let initialX = null; //초기x값을 null
    let initialY = null; //초기y값을 null
    uploadImg.addEventListener("mousedown",function(e){ //image를 마우스로 누르면
        initialX = e.clientX-rect.x; //초기x값에 clientX를 대입
        initialY = e.clientY-rect.y; //초기y값에 clientY를 대입
        isImageDown = true; //isimagedown을 true로 바꿈
    });
    
    uploadImg.addEventListener("mousemove",function(e){ //image를 마우스로 움직이면
        if(!isImageDown) return; //isstickydown을 false이면 return
        let finalX = e.clientX-rect.x; //마지막x값에 clientX를 대입
        let finalY = e.clientY-rect.y; //마지막y값에 clientY를 대입
        let diffX = finalX-initialX; //x값의 차에 마지막x값-초기x값 대입
        let diffY = finalY-initialY; //y값의 차에 마지막y값-초기y값 대입
        const {top,left} = uploadImg.getBoundingClientRect(); //image의 높이, 폭를 top, left로 놓는다
        uploadImg.style.top = top + diffY + "px"; //image의 top에 top과 diffY와 px를 더한 값을 넣는다
        uploadImg.style.left = left + diffX + "px"; //image의 left에 left과 diffY와 px를 더한 값을 넣는다
        initialX = finalX; //초기Y값에 마지막Y값을 대입
        initialY = finalY; //초기X값에 마지막X값을 대입
    });
    
    uploadImg.addEventListener("mouseup",function(e){ //image에서 마우스를 뗐을 때
        isImageDown = false; //isimagedown이 false가 된다
    })
    
    uploadImg.onload = function(){ //image가 로드되면
        URL.revokeObjectURL(uploadImg.src); //생성한 기존의 URL폐기
    }
});