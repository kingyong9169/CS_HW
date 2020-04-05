/*
 * ap1.c
 *
 *  Created on: 2020. 4. 5.
 *      Author: kingyong
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int list[5]; //정수형 배열 선언
	int *plist[5]={NULL,}; //포인터 배열 선언

	plist[0]=(int*)malloc(sizeof(int)); //포인터 배열 첫 번째 원소에 동적할당

	list[0]=1; //값 대입
	list[1]=100; //값 대입

	*plist[0]=200; //값 대입

	printf("value of list[0]        =%d\n",list[0]); //list[0]값 출력
	printf("address of list[0]      =%p\n",&list[0]); //list[0]주소 출력
	printf("value of list           =%p\n",list); //list[0]주소 출력
	printf("address of list (&list) =%p\n",&list); //list 배열 포인터의 값
	printf("==========[김동용]  [2017038064]==========\n");
	printf("======================================\n\n");
	printf("value of list[1]       =%d\n",list[1]); //list[1]값 출력
	printf("address of list[1]     =%p\n",&list[1]); //list[1]주소 출력
	printf("value of *(list+1)     =%d\n",*(list+1)); //list[1]값 출력
	printf("address of list list+1 =%p\n",list+1); //list[1]주소 출력

	printf("======================================\n\n");

	printf("value of *plist[0]=%d\n",*plist[0]); //*plist[0]값 출력
	printf("&plist[0]         =%d\n",&plist[0]); //plist[0]의 주소 출력
	printf("&plist            =%d\n",&plist); //plist 배열 포인터의 값
	printf("plist             =%d\n",plist); //plist[0]의 주소 출력
	printf("plist[0]          =%d\n",plist[0]); //plist[0]의 주소 출력
	printf("plist[1]          =%d\n",plist[1]); //plist[1]의 주소 출력
	printf("plist[2]          =%d\n",plist[2]); //plist[2]의 주소 출력
	printf("plist[3]          =%d\n",plist[3]); //plist[3]의 주소 출력
	printf("plist[4]          =%d\n",plist[4]); //plist[4]의 주소 출력

	free(plist[0]); //동적할당 해제
}





