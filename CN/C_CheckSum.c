#include <stdio.h>
void print_binary16(int num) {
	int i;
// printf("Binary: ");
	for (i = 15; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i == 15 || i == 7) printf(" ");
	}
	printf("\n");
}
int sender(int arr[10], int n) {
	int checksum, sum = 0, i;
	printf("\n****SENDER SIDE****\n");
	for (i = 0; i < n; i++)
		sum += arr[i];
	printf("SUM IS: ");
	print_binary16(sum);
	checksum = ~sum;
	printf("CHECKSUM IS: ");
	print_binary16(checksum);
	return checksum;
}
void receiver(int arr[10], int n, int sch) {
	int checksum, sum = 0, i;
	printf("\n****RECEIVER SIDE****\n");
	for (i = 0; i < n; i++)
		sum += arr[i];
	printf("SUM IS: ");
	print_binary16(sum);
	sum += sch;
	printf("SUM+CHECKSUM: ");
	print_binary16(sum);
	checksum = ~sum;
	printf("FINAL CHECKSUM: ");
	print_binary16(checksum);
	if (checksum == 0 && sum == -1)
		printf("No error detected.\n");
	else
		printf("Error detected!\n");
}
int main() {
	int n, sch;
	printf("Enter number of data segments: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d data values: \n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sch = sender(arr, n);
	receiver(arr, n, sch);
	return 0;
}


/* Enter number of data segments: 2
Enter 2 data values:
1011 1000
****SENDER SIDE****
SUM IS: 0 00001111 1011011
CHECKSUM IS: 1 11110000 0100100
****RECEIVER SIDE****
SUM IS: 0 00001111 1011011
SUM+CHECKSUM: 1 11111111 1111111
FINAL CHECKSUM: 0 00000000 0000000
No error detected*/