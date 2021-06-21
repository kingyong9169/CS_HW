#include <pthread.h>
#include <stdio.h>

void* sum_num(void* num);
void* fact_num(void* num);

int fact=1;
int sum;

int main() {
	int num;
	scanf("%d", &num);
	

	pthread_t threadID[2];

	pthread_create(threadID, NULL, sum_num, (void *)num);
	pthread_create(threadID+1, NULL, fact_num, (void*)num);

	pthread_join(threadID[0], NULL);
	pthread_join(threadID[1], NULL);
}

void* sum_num(void* num) {
	for (int i = 0; i < (int)num; i++)
		sum += i;
	sum += (int)num;
	printf("sum = %d\n", sum);
	pthread_exit(NULL);
}

void* fact_num(void* num) {
	if ((int)num < 1) {
		fact = 1;
		return;
	}
	for (int i = 1; i <= (int)num; i++)
		fact *= i;
	printf("factorial = %d", fact);
	pthread_exit(NULL);
}