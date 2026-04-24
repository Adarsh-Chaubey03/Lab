#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct frame {
    int seq, len, flag;
    char data[20];
} n[20], m[20], temp;

int main() {
    int i, j, count = 0, total = 0, size, num, ch;
    char val[100];

    srand(time(0));

    printf("\nEnter The Data : ");
    scanf("%s", val);

    int tsize = strlen(val);

    // --- segmentation ---
    printf("\nSegmented Frames at Sender:\n");
    while(total < tsize) {
        n[count].seq = count + 1;
        size = rand() % 5 + 1;
        if(total + size > tsize) size = tsize - total;

        n[count].len = size;
        n[count].flag = 0;

        for(i = 0; i < size; i++)
            n[count].data[i] = val[total + i];

        n[count].data[size] = '\0';

        total += size;
        count++;
    }

    printf("\nFSeq No.\tFLen\tFlag\tFData\n");
    for(i = 0; i < count; i++)
        printf(" %d\t\t %d\t %d\t%s\n",
               n[i].seq, n[i].len, n[i].flag, n[i].data);

    num = count;

    printf("\nEnter 1 to continue (0 to exit): ");
    scanf("%d", &ch);
    if(ch == 0) return 0;

    // --- random order ---
    count = 0;
    printf("\nFrames Received in Random Order:\n");

    while(count < num) {
        i = rand() % num;
        if(n[i].flag == 0) {
            m[count] = n[i];
            n[i].flag = 1;
            count++;
        }
    }

    printf("\nFSeq No.\tFLen\tFlag\tFData\n");
    for(i = 0; i < count; i++)
        printf(" %d\t\t %d\t %d\t%s\n",
               m[i].seq, m[i].len, m[i].flag, m[i].data);

    printf("\nTotal No. of frames: %d\n", count);

    printf("\nEnter 1 to continue (0 to exit): ");
    scanf("%d", &ch);
    if(ch == 0) return 0;

    // --- sorting ---
    for(i = 0; i < count-1; i++)
        for(j = i+1; j < count; j++)
            if(m[i].seq > m[j].seq) {
                temp = m[i];
                m[i] = m[j];
                m[j] = temp;
            }

    printf("\nSorted Frames at Receiver:\n");
    printf("\nFSeq No.\tFLen\tFlag\tFData\n");

    for(i = 0; i < count; i++)
        printf(" %d\t\t %d\t %d\t%s\n",
               m[i].seq, m[i].len, m[i].flag, m[i].data);

    return 0;
}