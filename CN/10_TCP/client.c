#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int sock;
    struct sockaddr_in server;
    char filename[100], buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    printf("Enter file name: ");
    scanf("%s", filename);

    send(sock, filename, strlen(filename), 0);

    printf("\nFile contents received:\n");

    while(read(sock, buffer, sizeof(buffer)) > 0)
    {
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}
