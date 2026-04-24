#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server;
    char filename[100], buffer[1024];
    FILE *fp;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&server, sizeof(server));
    listen(server_fd, 5);

    printf("Server listening on port 8080...\n");

    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, filename, sizeof(filename));
    printf("Client requested file: %s\n", filename);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        strcpy(buffer, "File not found\n");
        send(client_fd, buffer, strlen(buffer), 0);
    }
    else
    {
        while(fgets(buffer, sizeof(buffer), fp))
        {
            send(client_fd, buffer, strlen(buffer), 0);
        }
        fclose(fp);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
