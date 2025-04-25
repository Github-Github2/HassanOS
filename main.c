#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8888

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("IP_ADDRESS_OF_RECEIVER");
    server_addr.sin_port = htons(PORT);

    // Message to send
    char message[] = "Hello from sender!";

    // Send message
    if (sendto(sockfd, message, strlen(message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully\n");

    // Close socket
    close(sockfd);

    return 0;
}
