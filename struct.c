/*
 * struct.c
 *
 *  Created on: 2020. 4. 5.
 *      Author: kingyong
 */

#include <stdio.h> //표준입출력 전처리기 선언
#include <string.h> //문자열 전처리기 선언

struct student1 { //구조체 선언
	char lastName; //이름의 성을 저장하는 변수 선언
	int studentId; //학번을 저장하는 변수 선언
	char grade; //학년을 저장하는 변수 선언
};

typedef struct { //typedef 형 구조체 선언
	char lastName; //이름의 성을 저장하는 변수 선언
	int studentId; //학번을 저장하는 변수 선언
	char grade; //학년을 저장하는 변수 선언
}student2; //구조체 타입은 student2입니다.

int main(){

	struct student1 st1 ={'A', 100,'A'}; //struct student1타입의 구조체 변수 st1선언 및 초기화

	printf("st1.lastName=%c\n",st1.lastName); //구조체변수st1의 lastName에 A출력
	printf("st1.studentId=%d\n",st1.studentId); //구조체변수st1의 studentId에 100출력
	printf("st1.grade=%c\n\n",st1.grade); //구조체변수st1의 grade에 A출력
	printf("==========[김동용]  [2017038064]==========\n");
	student2 st2={'B',200,'B'}; //student2타입의 구조체 변수 st2선언 및 초기화

	printf("st2.lastName=%c\n",st2.lastName); //구조체변수st2의 lastName에 B출력
	printf("st2.studentId=%d\n",st2.studentId); //구조체변수st2의 studentId에 200출력
	printf("st2.grade=%c\n\n",st2.grade); //구조체변수st2의 grade에 B출력

	student2 st3; //student2타입의 구조체 변수 st3선언

	st3=st2; //구조체 변수st3에 구조체 변수st2의 데이터 대입

	printf("st3.lastName=%c\n",st3.lastName); //구조체변수st3의 lastName에 B출력
	printf("st3.studentId=%d\n",st3.studentId); //구조체변수st3의 studentId에 200출력
	printf("st3.grade=%c\n\n",st3.grade); //구조체변수st3의 grade에 B출력

	if(st2.lastName==st3.lastName&&st2.studentId==st3.studentId
			&&st2.lastName==st3.lastName) //만약 구조체변수 st3,st2의 멤버의 값이 같다면
		printf("st2와 st3가 같습니다."); //내용 출력
	else //아니라면
		printf("st2와 st3가 다릅니다."); //내용 출력
	return 0;
}




