/*
 * padding.c
 *
 *  Created on: 2020. 4. 5.
 *      Author: kingyong
 */

#include <stdio.h>

struct student {
	char lastName[13]; //13byte
	int studentId; //4byte
	short grade; //2byte
};

int main()
{
	struct student pst; //struct student 타입의 구조체 변수 pst 선언

	printf("size of student = %ld\n",sizeof(struct student)); //struct student 타입의 크기 출력
	//본래 struct student 타입의 크기는 19바이트지만 패딩처리를 통해 24바이트 출력
	printf("==========[김동용]  [2017038064]==========\n");
	printf("size of int = %ld\n",sizeof(int)); //int 타입의 크기 출력
	printf("size of short = %ld\n",sizeof(short)); //short 타입의 크기 출력

	return 0;
}

