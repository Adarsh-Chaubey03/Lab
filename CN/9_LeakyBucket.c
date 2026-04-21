#include <stdio.h>

int main() {
    int bucket_size, rate, seconds;
    int incoming[100];

    int bucket = 0, time = 0;

    printf("Enter The Bucket Size: ");
    scanf("%d", &bucket_size);

    printf("Enter The Operation Rate: ");
    scanf("%d", &rate);

    printf("Enter The No. Of Seconds You Want To Simulate: ");
    scanf("%d", &seconds);

    for (int i = 0; i < seconds; i++) {
        printf("Enter The Size Of The Packet Entering At %d sec: ", i + 1);
        scanf("%d", &incoming[i]);
    }

    printf("\nSecond | Packet Received | Packet Sent | Packet Left | Packet Dropped\n");
    printf("---------------------------------------------------------------------\n");

    while (time < seconds || bucket > 0) {

        int received = (time < seconds) ? incoming[time] : 0;

        bucket += received;

        int dropped = 0;
        if (bucket > bucket_size) {
            dropped = bucket - bucket_size;
            bucket = bucket_size;
        }

        int sent = (bucket >= rate) ? rate : bucket;
        bucket -= sent;

        printf("%-6d | %-15d | %-11d | %-11d | %-15d\n",
               time + 1, received, sent, bucket, dropped);

        time++;
    }

    return 0;
}
