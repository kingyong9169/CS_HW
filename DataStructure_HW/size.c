/*
 * size.c
 *
 *  Created on: 2020. 4. 5.
 *      Author: kingyong
 */

#include <stdio.h> //표준입출력 전처리기 선언
#include <stdlib.h> //표준라이브러리 전처리기 선언

void main()
{
	int **x; //이중포인터 변수선언
	printf("==========[김동용]  [2017038064]==========\n");
	printf("sizeof(x) = %lu\n",sizeof(x)); //x는 주소이므로 8바이트 출력
	printf("sizeof(*x) = %lu\n",sizeof(*x)); //*x는 주소이므로 8바이트 출력
	printf("sizeof(**x) = %lu\n",sizeof(**x)); //**x는 int형 값이므로 4바이트 출력
}



