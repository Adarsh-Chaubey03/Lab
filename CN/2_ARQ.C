#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024

// Frame structure
struct Frame {
    int frame_id;
    char data[100];
};

// Sender function
void sender() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    struct Frame frame;
    int frame_id = 0;

    printf("\nSender Side\n");
    printf("Enter data to send (max 99 characters, 'exit' to quit): ");

    while (1) {
        scanf(" %s", frame.data);

        if (strcmp(frame.data, "exit") == 0) {
            break;
        }

        frame.frame_id = frame_id;

        send(sock, &frame, sizeof(frame), 0);

        printf("Sent frame %d with data: %s\n", frame_id, frame.data);

        int valread = read(sock, buffer, MAX_BUFFER);
        if (valread > 0) {
            if (strcmp(buffer, "ACK") == 0) {
                printf("Acknowledgment received. Frame %d sent successfully.\n", frame_id);
                frame_id = 1 - frame_id;
            } else {
                printf("Negative acknowledgment. Resending...\n");
            }
        }

        sleep(1);
    }

    close(sock);
    printf("Sender finished transmission.\n");
}

// Receiver function
void receiver() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    struct Frame received_frame;
    int expected_id = 0;

    printf("\nReceiver Side\n");
    printf("Receiver ready to receive frames...\n");

    while (1) {
        int valread = read(new_socket, &received_frame, sizeof(received_frame));
        if (valread <= 0) {
            printf("Connection closed by sender.\n");
            break;
        }

        printf("Received frame %d with data: %s\n", received_frame.frame_id, received_frame.data);

        if (received_frame.frame_id == expected_id) {
            send(new_socket, "ACK", 3, 0);
            expected_id = 1 - expected_id;
        } else {
            send(new_socket, "NAK", 3, 0);
        }

        sleep(1);
    }

    close(new_socket);
    close(server_fd);
    printf("Receiver finished.\n");
}

int main() {
    printf("Stop and Wait Protocol Simulation\n");
    printf("1. Sender\n");
    printf("2. Receiver\n");

    printf("Choose your role (1 or 2): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        sender();
    } else if (choice == 2) {
        receiver();
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}