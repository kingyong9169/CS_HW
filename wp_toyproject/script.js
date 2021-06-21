const API_URL = 'https://www.juso.go.kr/addrlink/addrLinkApiJsonp.do'; //API의 URL
const API_KEY = 'devU01TX0FVVEgyMDIwMTEzMDIyMDUzNzExMDQ3OTY='; //API의 KEY
const form = document.querySelector('#form'); //form으로 선택될 수 있는 요소
const addressList = document.querySelector('#address-list'); //address-list로 선택될 수 있는 요소

form.addEventListener('submit', async e => { //콜백함수 전체가 async 함수이다.
    e.preventDefault(); //기본적인 동작을 막아준다
    const keyword = encodeURIComponent(form.keyword.value); //keyword의 값을 인코딩하여 keyword에 넣어준다
    try {
    const response = await search(keyword); //keyword를 인자로 search라는 함수 호출하여 결과를 response에 넣는다
    const txt = await response.text(); //response를 text로 받는다
    const result = JSON.parse(txt.replace(/^\(/, '').replace(/\)$/, '')).results; //JSON에서 양쪽의 ( )를 제거하여 results에 넣어준다
    display(result); //results를 출력
    form.reset(); //리셋을 한다
    //addEventForAddressList();
    }
    catch (e) { //에러가 발생하면
        console.error(e); //에러 메시지 출력
    }
});

function search(keyword, currentPage = 1, countPerPage = 10) { //1페이지 당 10개씩 보여준다
    const data = { //data안에 있는 정보
        confmKey: API_KEY, //API_KEY
        keyword, //keyword
        currentPage, //현재페이지
        countPerPage, //페이지 당 몇 개인지
        resultType: 'json' //json형식으로 결과를 받는다
    };

    const body = Object.keys(data).map(key => `${key}=${data[key]}`).join('&'); //data를 (key & key의 값)형식으로 묶어서 맵핑하여 문자열로 가져온다

    const options = {
        method: 'POST', //POST방법으로
        body, //body
        headers: { //headers의 콘텐츠 타입은 다음과 같다
            'Content-Type': 'application/x-www-form-urlencoded;charset=UTF-8'
        }
    };

    return fetch(API_URL, options); //API_URL로 options의 형태로 요청을 보낸다.
}

function display(results) { //results를 출력하는 함수
    addressList.innerHTML = ''; //innerHTML을 초기화
    results.juso.forEach(item => { //결과 중 주소 하나씩
        const li = document.createElement('li'); //li에서 가져와서 하나의 요소로 만들고 li변수에 저장
        li.className = 'address-li' //li의 클래스이름을 address-li로 설정한다
        li.innerHTML = `${item.zipNo}) ${item.roadAddr}`; //li의 innerHTML에 "우편번호 도로명주소"로 저장한다
        addressList.appendChild(li); //이렇게 만들어진 li를 addressList에 차례대로 저장한다.
    });
}