#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int page;
char read_write[6];
int insert_count = 0;
int num_access = 0;
int num_read = 0;
int num_write = 0;
int num_hits = 0;
int num_faults = 0;
float fault_rate = 0;
int num_frame=0;



typedef struct LRU {
	int vpn;
	char* r_w;
}LRU;

void LRU_OPER(LRU* frame);
int LRU_full(LRU* frame);

int main() {
	int i = 0;
	double rate;
	scanf("%d", &num_frame);
	LRU* frame = (LRU*)malloc(sizeof(LRU) * num_frame);
	FILE* fp;
	fp= fopen("access.list", "r");

	while (fscanf(fp, "%d %s", &page, read_write)!=EOF) {
		if (read_write[0] == 'r')
			num_read++;
		else
			num_write++;
		num_access++;
		if (LRU_full(frame) !=-1) {
		}
		else {
			LRU_OPER(frame);
		}
		continue;
	}
	rate = ((double)num_faults / (double)num_access) * 100;
	printf("Total number of access: %d\n", num_access);
	printf("Total number of read: %d\n", num_read);
	printf("Total number of write: %d\n", num_write);
	printf("Number of page hits: %d\n", num_hits);
	printf("Number of page faults: %d\n", num_faults);
	printf("Page fault rate: %d/%d = %.03lf %%\n", num_faults, num_access,rate);
	fclose(fp);
}

int LRU_full(LRU* frame) {
	int i = 0;
	int search = 0;
	if (insert_count < num_frame) {
		for (i = 0; i < insert_count; i++) {
			if (frame[i].vpn==page) {
				num_hits++;
				for (search=i; search < insert_count-1; search++) {
					frame[search].vpn = frame[search + 1].vpn;
					frame[search].r_w = frame[search + 1].r_w;
				}
				frame[insert_count-1].vpn = page;
				frame[insert_count-1].r_w = read_write;
				return search;
			}
		}
		num_faults++;
		frame[insert_count].vpn = page;
		frame[insert_count].r_w = read_write;
		insert_count++;
		return 0;
	}
	else {
		return -1;
	}
}

void LRU_OPER(LRU* frame) {
	int i = 0;
	for (i = 0; i < num_frame; i++) {
		if (page == frame[i].vpn) {
			num_hits++;
			for (; i < num_frame - 1; i++) {
				frame[i].vpn = frame[i + 1].vpn;
				frame[i].r_w = frame[i + 1].r_w;
			}
			frame[num_frame - 1].vpn = page;
			frame[num_frame - 1].r_w = read_write;
			return;
		}
	}

	num_faults++; //hit X
	for (i = 0; i < num_frame - 1; i++) {
		frame[i].vpn = frame[i + 1].vpn;
		frame[i].r_w = frame[i + 1].r_w;
	}
	frame[num_frame - 1].vpn = page;
	frame[num_frame - 1].r_w = read_write;
}