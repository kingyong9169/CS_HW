/*
 * matrix.c
 *
 *  Created on: 2020. 4. 6.
 *      Author: kingyong
 */
#include <stdio.h> //전처리기 선언
#include <stdlib.h> //rand함수를 사용하기 위한 헤더파일 선언
#include <time.h> //time함수를 사용하기 위한 헤더파일 선언

int** create_matrix(int row, int col); //함수 원형 선언
int fill_data(int** matrix, int row, int col); //함수 원형 선언
int free_matrix(int** matrix,int row, int col); //함수 원형 선언
void print_data(int** matrix, int row, int col); //함수 원형 선언
int addition_matrix(int** matrix_a,int** matrix_b, int** matrix_sum,int row, int col); //함수 원형 선언
int subtraction_matrix(int** matrix_a,int** matrix_b, int** matrix_sub,int row, int col); //함수 원형 선언
int transpose_matrix(int** matrix_a,int** matrix_t,int row, int col); //함수 원형 선언
int multiply_matrix(int** matrix_a,int** matrix_t,int** matrix_axt,int row, int col); //함수 원형 선언

int i,j,k; //반복문에 사용할 전역변수 선언
int **matrix_a,**matrix_b,** matrix_sum,** matrix_sub,** matrix_axt,** matrix_t; //행렬의 주소를 저장할 이중포인터변수 선언
int free_a,free_b,free_sum,free_sub,free_axt,free_t; //free_matrix함수의 반환값을 저장하기 위한 변수 선언

int main()
{
	int row,column,fill1,fill2,add,sub,axt,t; //행과 열을 저장하는 변수, 각 함수의 반환값을 저장하기 위한 변수 선언
	printf("row와 column을 입력하세요 : ");
	scanf("%d %d",&row,&column); //row,column 입력
	printf("\n");
	matrix_a=create_matrix(row,column); //row를 행 column을 열로 하는 a행렬을 만든다
	matrix_b=create_matrix(row,column); //row를 행 column을 열로 하는 b행렬을 만든다
	matrix_sum=create_matrix(row,column); //row를 행 column을 열로 하는 sum행렬을 만든다
	matrix_sub=create_matrix(row,column); //row를 행 column을 열로 하는 sub행렬을 만든다
	matrix_t=create_matrix(column,row); //column을 행 row를 열로 하는 t행렬을 만든다
	matrix_axt=create_matrix(row,row); //row를 행 row를 열로 하는 axt행렬을 만든다

	if(matrix_a==0&&matrix_b==0&&matrix_sum==0&&matrix_sub==0&&matrix_t==0&&matrix_axt==0){ //만약 각 행렬을 만드는 함수의 반환값이 모두 0이면
		printf("잘못된 입력입니다.\n");
		return 0; //위와 같이 출력하고 프로그램을 마친다.
	}
	fill1=fill_data(matrix_a,row,column); //행렬a에 데이터를 저장
	srand(time(NULL)); //시드값을 다르게 조정하면서 값을 항상 다르게 저장하도록 함
	fill2=fill_data(matrix_b,row,column); //행렬b에 데이터를 저장

	if(fill1&&fill2){ //두 행렬의 데이터를 저장하는 일이 성공적으로 일어났을 때
		printf("A행렬\n");
		print_data(matrix_a,row,column); //행렬a를 프린트한다
		printf("=========[김동용]  [2017038064]=========\n\n");
		printf("B행렬\n");
		print_data(matrix_b,row,column); //행렬b를 프린트한다
	}
	add=addition_matrix(matrix_a,matrix_b,matrix_sum,row,column); //행렬a와 행렬b를 더한 행렬sum을 만든다
	if(add){ //행렬sum이 성공적으로 만들어졌을 때
		printf("A+B행렬\n");
		print_data(matrix_sum,row,column); //행렬sum을 출력한다
	}
	sub=subtraction_matrix(matrix_a,matrix_b,matrix_sub,row,column); //행렬a에서 행렬b를 뺀 행렬sub을 만든다
	if(sub){ //행렬sub이 성공적으로 만들어졌을 때
		printf("A-B행렬\n");
		print_data(matrix_sub,row,column); //행렬sub을 출력한다
	}
	t=transpose_matrix(matrix_a,matrix_t,row,column); //행렬a의 역행렬 행렬t를 만든다
	if(t){ //행렬t가 성공적으로 만들어졌을 때
		printf("TRANSPOSE행렬\n");
		print_data(matrix_t,row,column); //행렬t를 출력한다
	}
	axt=multiply_matrix(matrix_a,matrix_t,matrix_axt,row,column); //행렬a와 행렬t를 곱한 행렬axt를 만든다
	if(axt){ //행렬axt가 성공적으로 만들어졌을 때
	 	printf("A*TRANSPOSE A행렬\n");
		print_data(matrix_axt,row,column); //행렬axt를 출력한다
	}
	free_a=free_matrix(matrix_a,row,column); //행렬a를 만든 메모리를 해제한다
	free_b=free_matrix(matrix_b,row,column); //행렬b를 만든 메모리를 해제한다
	free_sum=free_matrix(matrix_sum,row,column); //행렬sum를 만든 메모리를 해제한다
	free_sub=free_matrix(matrix_sub,row,column); //행렬sub를 만든 메모리를 해제한다
	free_t=free_matrix(matrix_t,column,row); //행렬t를 만든 메모리를 해제한다
	free_axt=free_matrix(matrix_axt,row,row); //행렬axt를 만든 메모리를 해제한다
	if(free_a&&free_b&&free_sum&&free_sub&&free_t&&free_axt) //메모리해제작업이 모두 성공적으로 마치면
		printf("free작업을 마칩니다."); //출력한다
	return 0;
}

int** create_matrix(int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
		return NULL; //NULL을 반환한다
	int **matrix; //행렬을 저장할 이중포인터변수 선언
	matrix=malloc(sizeof(int *)*row); //행렬의 행인 row만큼 메모리 할당
	for(i=0;i<row;i++)
		matrix[i]=malloc(sizeof(int)*col); //행렬의 열인 col만큼 메모리 할당
	if(matrix!=NULL) //후처리 검사
		return matrix; //행렬의 주소 반환
}

int free_matrix(int** matrix,int row, int col)
{
	if(matrix==NULL) //전처리 검사(행렬의 주소가 없다면)
		return 0;
	for(i=0;i<row;i++)
		free(matrix[i]); //행렬의 열에 해당하는 부분 메모리 해제
	free(matrix); //행렬의 행에 해당하는 부분 메모리 해제
	if(matrix!=NULL) //후처리 검사(행렬의 주소가 NULL이 아니면)
		return 1;
}


int fill_data(int** matrix, int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
		return 0; //함수를 끝낸다
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			matrix[i][j]=rand()%20; //0~19의 숫자를 임의로 저장
	if(row>0&&col>0) //row나col 둘 다 0보다 크면 ->후처리 검사
		return 1;
}

void print_data(int** matrix, int row, int col)
{
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%2d ",matrix[i][j]); //행렬의 원소를 출력
		printf("\n"); //행에 대한 출력이 끝나면 다음 행을 출력하기 위해 개행
	}
	printf("\n");
}

int addition_matrix(int** matrix_a,int** matrix_b, int** matrix_sum,int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
			return 0; //함수를 끝낸다
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j]; //행렬sum에 행렬a와 행렬b에 각각 해당되는 원소를 더해서 저장한다
	if(row>0&&col>0) //row나col 둘 다 0보다 크면 ->후처리 검사
			return 1;
}

int subtraction_matrix(int** matrix_a,int** matrix_b, int** matrix_sub,int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
				return 0; //함수를 끝낸다
	for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j]; //행렬sub에 각각의 원소에 해당하는 행렬a에서 행렬b를 뺀 값을 저장한다
	if(row>0&&col>0) //row나col 둘 다 0보다 크면 ->후처리 검사
				return 1;
}

int transpose_matrix(int** matrix_a,int** matrix_t,int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
					return 0; //함수를 끝낸다
	for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				matrix_t[j][i]=matrix_a[i][j]; //행렬a의 역행렬을 저장한다
	if(row>0&&col>0) //row나col 둘 다 0보다 크면 ->후처리 검사
				return 1;
}

int multiply_matrix(int** matrix_a,int** matrix_t,int** matrix_axt,int row, int col)
{
	if(row<=0||col<=0) //row나col 둘 중 하나라도 0보다 작거나 같으면 ->전처리 검사
					return 0; //함수를 끝낸다
	int sum; //각각의 곱을 더하기 위한 변수를 선언
	for(i=0;i<row;i++) //이중반복문을 사용하면 값을 저장하는 한계에 부딪히기 때문에
			for(j=0;j<row;j++){ //삼중반복문을 사용하여 모든 원소를 검사하도록 구현한다
				sum=0; //변수를 초기화 해서 다음 값에 지장이 없도록 한다
				for(k=0;k<col;k++)
					sum+=matrix_a[i][k]*matrix_t[k][j]; //각 원소를 곱한 값을 변수에 저장한다
				matrix_axt[i][j]=sum; //변수에 저장된 값을 행렬axt에 저장한다
			}
	if(row>0&&col>0) //row나col 둘 다 0보다 크면 ->후처리 검사
					return 1;
}
