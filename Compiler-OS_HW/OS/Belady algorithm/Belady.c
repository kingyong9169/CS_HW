#include <stdio.h>

typedef struct Belady {
    int vpn;
    int pos;
}Belady;

int page[50000];
int num_access = 0;
int num_read = 0;
int num_write = 0;
int num_hits = 0;
int num_faults = 0;
int num_frame = 0;
int frame_pos = 0;
int num = 0;
int count = 0;
int max = 0;
double rate = 0;
char file[6];
int page_num;

void Belady_not_full(Belady* frame, int i);
void Belady_is_full(Belady* frame, int i);

int main() {
    int i = 0;
    int j = 0;
    scanf("%d", &num_frame);
    Belady* frame = (Belady*)malloc(sizeof(Belady) * num_frame);
    FILE* fp;
    fp = fopen("access.list", "r");
    while (fscanf(fp, "%d %s", &page_num, file) != EOF) {
        if (file[0] == 'r')
            num_read++;
        else if (file[0] == 'w')
            num_write++;
        num_access++;
        page[j++] = page_num;
    }
    for (i = 0; i < 50000; i++)
    {
        Belady_not_full(frame, i);
        Belady_is_full(frame, i);
        
        for (j = 0; j < num_frame; j++)
            frame[j].pos--;
    }
    rate = ((double)num_faults / (double)num_access) * 100;
    printf("Total number of access: %d\n", num_access);
    printf("Total number of read: %d\n", num_read);
    printf("Total number of write: %d\n", num_write);
    printf("Number of page hits: %d\n", num_hits);
    printf("Number of page faults: %d\n", num_faults);
    printf("Page fault rate: %d/%d = %.03lf %%\n", num_faults, num_access, rate);
    fclose(fp);
    return 0;
}

void Belady_not_full(Belady* frame, int i) {
    for (frame_pos = 0; frame_pos < num_frame; frame_pos++)
    {
        if (frame[frame_pos].vpn == page[i])
        {
            for (num = i + 1; num < 50000; num++)
            {
                if (page[num] == page[i])
                    break;
            }
            frame[frame_pos].pos = num - i;
            num_hits++;
            break;
        }
    }
}

void Belady_is_full(Belady* frame, int i) {
    int j = 0;
    if (frame_pos >= num_frame) {
        if (count < num_frame) {
            for (num = i + 1; num < 50000; num++)
            {
                if (page[num] == page[i])
                    break;
            }
            frame[count].pos = num - i;
            frame[count].vpn = page[i];
            num_faults++;
            count++;
        }
        else if (count >= num_frame) {
            max = 0;
            for (j = 0; j < num_frame; j++)
                if (frame[j].pos > frame[max].pos)
                    max = j;
            for (num = i + 1; num < 50000; num++)
                if (page[num] == page[i])
                    break;
            frame[max].pos = num - i;
            frame[max].vpn = page[i];
            num_faults++;
        }
    }
}