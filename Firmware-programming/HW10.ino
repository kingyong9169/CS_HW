#include "IRSendRev.h"
#include <TM1637Display.h>

#define IR_OUT_PIN 2 // IR 수신기를 D2에 연결. D3을 제외한 핀 사용 가능
#define DIO 11
#define CLK 10

TM1637Display FND(CLK, DIO); // FND객체 생성 및 초기화
String input = ""; // 리모콘에서 입력한 값을 저장할 공간
unsigned char dta[20]; // 수신한 데이터를 저장할 공간

void setup() {
  IR.Init(IR_OUT_PIN); // IR을 수신할 핀을 입력으로 설정하고, TIMER2 초기화
  FND.setBrightness(0x04); // FND의 밝기 조정
}

void loop(){
  if(IR.IsDta()) { // IR이 데이터를 가져오면
    IR.Recv(dta); // 수신한 데이터(패킷)를 dta에 리턴한다.
    if(dta[D_DATA + 2] == 176 && dta[D_DATA + 3] == 79) input = ""; // 리모콘에서 C를 입력하면 input에 빈 문자열로 초기화한다.
    else if(input.toInt() + 1 <= 9999 && dta[D_DATA + 2] == 2 && dta[D_DATA + 3] == 253) // 리모콘에서 +를 입력하고 input을 정수로 바꾼 값에 1을 더한 값이 9999보다 작거나 같으면
      input = String(input.toInt() + 1); // input을 정수로 바꾼 값에 1을 더한 값을 문자열로 하여 input에 대입한다.
    else if(input.toInt() - 1 >= -999 && dta[D_DATA + 2] == 152 && dta[D_DATA + 3] == 103)// 리모콘에서 -를 입력하고 input을 정수로 바꾼 값에 1을 뺀 값이 -999보다 크거나 같으면
      input = String(input.toInt() - 1); // input을 정수로 바꾼 값에 1을 뺀 값을 문자열로 하여 input에 대입한다.
    
    if(input.length() <= 3){ // input의 길이가 3이하이면
      if(dta[D_DATA + 2] == 104 && dta[D_DATA + 3] == 151) input += '0'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 0과 일치하면 input에 0을 더한다.
      else if(dta[D_DATA + 2] == 48 && dta[D_DATA + 3] == 207) input += '1'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 1과 일치하면 input에 1을 더한다.
      else if(dta[D_DATA + 2] == 24 && dta[D_DATA + 3] == 231) input += '2'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 2과 일치하면 input에 2을 더한다.
      else if(dta[D_DATA + 2] == 122 && dta[D_DATA + 3] == 133) input += '3'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 3과 일치하면 input에 3을 더한다.
      else if(dta[D_DATA + 2] == 16 && dta[D_DATA + 3] == 239) input += '4'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 4과 일치하면 input에 4을 더한다.
      else if(dta[D_DATA + 2] == 56 && dta[D_DATA + 3] == 199) input += '5'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 5과 일치하면 input에 5을 더한다.
      else if(dta[D_DATA + 2] == 90 && dta[D_DATA + 3] == 165) input += '6'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 6과 일치하면 input에 6을 더한다.
      else if(dta[D_DATA + 2] == 66 && dta[D_DATA + 3] == 189) input += '7'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 7과 일치하면 input에 7을 더한다.
      else if(dta[D_DATA + 2] == 74 && dta[D_DATA + 3] == 181) input += '8'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 8과 일치하면 input에 8을 더한다.
      else if(dta[D_DATA + 2] == 82 && dta[D_DATA + 3] == 173) input += '9'; // 수신한 데이터의 3번째 4번째 값이 리모콘에서 입력한 9과 일치하면 input에 9을 더한다.
    }
  }
  
  FND.showNumberDec(input.toInt()); // FND에 input을 정수로 바꾼 값을 출력한다.
}