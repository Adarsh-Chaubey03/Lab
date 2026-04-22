#include <stdio.h>

int a[100], b[100], received[100];
int gen[17] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int len, i, j;

void div_crc(int data[], int length) {
    for (i = 0; i < length; i++) {
        if (data[i] == 1) {
            for (j = 0; j < 17; j++)
                data[i + j] ^= gen[j];
        }
    }
}

int main() {
    printf("Enter the length of data frame: ");
    scanf("%d", &len);

    printf("Enter the message bits (separated by space): ");
    for (i = 0; i < len; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < len; i++)
        b[i] = a[i];

    for (i = len; i < len + 16; i++)
        b[i] = 0;

    div_crc(b, len);

    for (i = 0; i < len; i++)
        b[i] = a[i];

    int temp[200];

    for (i = 0; i < len; i++)
        temp[i] = a[i];

    for (i = len; i < len + 16; i++)
        temp[i] = b[i];

    printf("\nTransmitted Data: ");
    for (i = 0; i < len + 16; i++)
        printf("%d ", temp[i]);

    printf("\n\n--- Receiver Side ---\n");

    printf("Enter the received data bits (%d bits): ", len + 16);
    for (i = 0; i < len + 16; i++)
        scanf("%d", &received[i]);

    for (i = 0; i < len + 16; i++)
        temp[i] = received[i];

    div_crc(temp, len);

    int error = 0;

    for (i = len; i < len + 16; i++) {
        if (temp[i] != 0) {
            error = 1;
            break;
        }
    }

    if (error)
        printf("\nStatus: ERROR in Received Data");
    else
        printf("\nStatus: Data Received is ERROR FREE");

    printf("\nRemainder: ");
    for (i = len; i < len + 16; i++)
        printf("%d", temp[i]);

    printf("\n");
    return 0;
}