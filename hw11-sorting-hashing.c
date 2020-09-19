/*
 * hw11-sorting-hashing.c
 *
 *  Created on: 2020. 5. 27.
 *      Author: kingyong
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE	13	//배열 크기 정의
#define MAX_HASH_TABLE_SIZE MAX_ARRAY_SIZE //해시테이블사이즈를 배열 크기로 정의

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a); //초기화 함수
int freeArray(int *a); //free함수
void printArray(int *a); //배열 출력 함수

int selectionSort(int *a); //선택정렬
int insertionSort(int *a); //삽입정렬
int bubbleSort(int *a); //버블정렬
int shellSort(int *a); //쉘정렬
/* recursive function으로 구현 */
int quickSort(int *a, int n); //퀵 정렬


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key); //해시코드

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht); //해싱함수

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key); //서치함수


int main() //메인
{
	char command; //명령
	int *array = NULL; //배열 선언
	int *hashtable = NULL; //해시테이블 선언
	int key = -1; //key초기화
	int index = -1; //index초기화

	srand(time(NULL)); //rand함수를 사용할 때 매 번 값이 달라지도록 하는 구문

	do{
		printf("----------------------------------------------------------------\n");
		printf(" Sorting & Hashing \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize = z Quit = q\n");
		printf(" Selection Sort = s Insertion Sort = i\n");
		printf(" Bubble Sort = b Shell Sort = l\n");
		printf(" Quick Sort = k Print Array = p\n");
		printf(" Hashing = h Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //명령할 값 입력

		switch(command) {
			case 'z': case 'Z':
				initialize(&array); //정렬 초기화
				break;
			case 'q': case 'Q':
				freeArray(array); //정렬 free
				break;
			case 's': case 'S':
				selectionSort(array); //선택정렬
				break;
			case 'i': case 'I':
				insertionSort(array); //삽입정렬
				break;
			case 'b': case 'B':
				bubbleSort(array); //버블정렬
				break;
			case 'l': case 'L':
				shellSort(array); //쉘 정렬
				break;
			case 'k': case 'K':
				printf("Quick Sort: \n");
				printf("----------------------------------------------------------------\n");
				printArray(array); //정렬 전 배열 출력
				quickSort(array, MAX_ARRAY_SIZE); //퀵정렬
				printf("----------------------------------------------------------------\n");
				printArray(array); //정렬 후 배열 출력
				break;

			case 'h': case 'H':
				printf("Hashing: \n");
				printf("----------------------------------------------------------------\n");
				printArray(array); //배열 출력
				hashing(array, &hashtable); //배열과 헤시테이블을 인자로 해싱함수 호출
				printArray(hashtable); //해시테이블 출력
				break;

			case 'e': case 'E':
				printf("Your Key = ");
				scanf("%d", &key);
				printArray(hashtable); //해시테이블 출력
				index = search(hashtable, key); //인덱스에 해시테이블에서 찾은 키값의 인덱스 대입
				printf("key = %d, index = %d, hashtable[%d] = %d\n", key, index, index, hashtable[index]); //키, 인덱스, 해시테이블의 키값 출력
				break;

			case 'p': case 'P':
				printArray(array); //배열 출력
				break;
			default: //나머지
				printf("\n >>>>> Concentration!! <<<<< \n"); //오류 출력
				break;
		}

	}while(command != 'q' && command != 'Q'); //q가 입력되기 전까지 지속

	return 1;
}

int initialize(int** a) //초기화 함수
{
	int *temp = NULL; //temp변수를 선언하고 초기화

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) { //배열에 아무것도 없으면
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); //temp를 배열크기만큼 동적할당한다
		*a = temp; /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	}
	else //NULL이 아니면
		temp = *a; //*a를 temp에 대입해준다

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) //배열크기만큼 반복
		temp[i] = rand() % MAX_ARRAY_SIZE; //0~12까지의 랜덤값을 temp배열에 넣어준다
	return 0;
}

int freeArray(int *a)
{
	if(a != NULL) //a가 NULL이 아니면
		free(a); //동적할당 해제
	return 0;
}

void printArray(int *a)
{
	if (a == NULL) { //a가 NULL이면
		printf("nothing to print.\n"); //출력
		return; //종료
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) //배열크기만큼
		printf("a[%02d] ", i); //배열의 인덱스 출력
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++) //배열크기만큼
		printf("%5d ", a[i]); //배열의 값 출력
	printf("\n");
}


int selectionSort(int *a) //선택정렬
{
	int min; //최소값
	int minindex; //최소 인덱스
	int i, j; //인덱스

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //정렬 전 a출력

	for (i = 0; i < MAX_ARRAY_SIZE; i++) //배열 크기만큼 반복
	{
		minindex = i; //i를 최소인덱스로 놓고
		min = a[i]; //i인덱스에 있는 값을 최소값으로 놓는다
		for(j = i+1; j < MAX_ARRAY_SIZE; j++) //j는 i+1번째부터 배열크기까지 반복
		{
			if (min > a[j]) //최소값이 j인덱스의 값보다 크면
			{
				min = a[j]; //최소값은 j인덱스의 값이고
				minindex = j; //최소 인덱스는 j이다
			}
		}
		a[minindex] = a[i]; //최소인덱스에 해당하는 값은 i인덱스에 해당하는 값이다
		a[i] = min; //i인덱스에 해당하는 값은 최소값이다
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 정렬 출력
	return 0;
}

int insertionSort(int *a) //삽입정렬
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //정렬 전 배열 출력

	for(i = 1; i < MAX_ARRAY_SIZE; i++) //배열 크기만큼
	{
		t = a[i]; //t에 i인덱스에 해당하는 값을 대입
		j = i; //j에 i대입
		while (a[j-1] > t && j > 0) //t가 j-1인덱스에 해당하는 값보다 크고 j가 양수이면
		{
			a[j] = a[j-1]; //j인덱스에 해당하는 값에 j-1에 해당하는 값 대입
			j--; //j--
		}
		a[j] = t; //t값을 j인덱스에 해당하는 값에 대입
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배렬 출력

	return 0;
}

int bubbleSort(int *a) //버블 정렬
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //정렬이 안 된 배열 출력

	for(i = 0; i < MAX_ARRAY_SIZE; i++) //배열 크기만큼 반복
	{
		for (j = 1; j < MAX_ARRAY_SIZE; j++) //배열 크기만큼 반복
		{
			if (a[j-1] > a[j]) //j-1에 해당하는 값보다 j에 해당하는 값이 작으면
			{
				t = a[j-1]; //t에 j-1에 해당하는 값 대입
				a[j-1] = a[j]; //j-1에 해당하는 값에 j에 해당하는 값 대입
				a[j] = t; //j에 해당하는 값에 t대입
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배열 출력

	return 0;
}

int shellSort(int *a) //쉘 정렬
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a); //정렬 전 배열 출력

	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) //h는 배열 크기의 반, h>0까지, h에 h의 반값 대입
	{
		for (i = 0; i < h; i++) //h만큼 반복
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h) //j=i+h부터 배열 크기까지 h만큼씩 증가
			{
				v = a[j]; //v에 j인덱스에 해당하는 값 대입
				k = j; //k에 j대입
				while (k > h-1 && a[k-h] > v) //k가 h-1보다 크고 k-h에 해당하는 값이 v보다 크면 반복
				{
					a[k] = a[k-h]; //k에 해당하는 값에 k-h가 해당하는 값 대입
					k -= h; //k에 k-h대입
				}
				a[k] = v; //k에 해당하는 값에 v 대입
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a); //정렬된 배열 출력

	return 0;
}

int quickSort(int *a, int n) //퀵 정렬
{
	int v, t;
	int i, j;

	if (n > 1) //n>1이면
	{
		v = a[n-1]; //v에 n-1에 해당하는 값 대입
		i = -1; //i에 -1대입
		j = n - 1; //j에 n-1 대입

		while(1) //무한루프
		{
			while(a[++i] < v); //v가 ++i에 해당하는 값보다 크면 ++i 반복
			while(a[--j] > v); //v가 --j에 해당하는 값보다 작으면 --j 반복

			if (i >= j) break; //i가 j보다 크거나 같으면
			t = a[i]; //t에 i에 해당하는 값 대입
			a[i] = a[j]; //i에 해당하는 값에 j에 해당하는 값 대입
			a[j] = t; //j에 해당하는 값에 t대입
		}
		t = a[i]; //t에 i에 해당하는 값 대입
		a[i] = a[n-1]; //i에 해당하는 값에 n-1에 해당하는 값 대입
		a[n-1] = t; //n-1에 해당하는 값에 t대입

		quickSort(a, i); //a와 i를 인자로 함수호출
		quickSort(a+i+1, n-i-1); //a+i+1과 n-i-1을 인자로 함수호출
	}
	return 0;
}

int hashCode(int key) {
	return key % MAX_HASH_TABLE_SIZE; //키값을 해시테이블의 크기로 나눈 나머지 리턴
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL; //해시테이블 배열을 NULL로 초기화

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) { //*ht가 NULL이면
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); //해시테이블을 동적할당
		*ht = hashtable; /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	}
	else { //*ht가 NULL이 아니면
		hashtable = *ht; /* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++) //해시테이블의 크기만큼
		hashtable[i] = -1; //해시테이블의 원소 초기화

	int key = -1; //모든 값 -1로 초기화
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) //배열크기만큼 반복
	{
		key = a[i]; //키에 a배열의 값 대입
		hashcode = hashCode(key); //해시코드함수호출하여 해시코드에 넣어준다
		if (hashtable[hashcode] == -1) //해시테이블의 배열이 -1이면
		{
			hashtable[hashcode] = key; //해시테이블의 배열에 키값을 넣어준다
		}
		else //-1이 아니면
		{
			index = hashcode; //인덱스에 해시코드를 넣어주고
			while(hashtable[index] != -1) //해시코드[인덱스]가 -1이 아닐 때까지
			{
				index = (++index) % MAX_HASH_TABLE_SIZE; //인덱스에 1증가한 인덱스를 해시테이블크기로 나눈 값 대입
			}
			hashtable[index] = key; //해시테이블[인덱스]에 키 값을 넣어준다
		}
	}
	return 0; //종료
}

int search(int *ht, int key) //서치함수
{
	int index = hashCode(key); //인덱스는 키를 인자로한 해시코드함수의 리턴값이다

	if(ht[index] == key) //해시테이블[인덱스]가 키값이면
		return index; //인덱스를 리턴

	while(ht[++index] != key) //해시테이블[인덱스]가 키값이 아닐 때, 이 구문으로 내려와서 해시테이블[++인덱스]가 키값이면 반복문 종료
		index = index % MAX_HASH_TABLE_SIZE; //인덱스는 인덱스를 해시테이블크기로 나눈나머지 값
	return index; //인덱스를 리턴
}
