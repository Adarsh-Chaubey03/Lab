#include <stdio.h>
#include <string.h>

struct arp_entry {
    char ip[20];
    char mac[25];
};

int main() {
    int choice;
    
    // Static ARP table (demo purpose)
    struct arp_entry table[] = {
        {"192.168.10.17", "A1_B1_00_C1_D1_E1"},
        {"192.168.10.18", "A1_B1_00_C1_D1_E2"},
        {"192.168.10.19", "A1_B1_00_C1_D1_E3"}
    };

    int n = 3;
    char ip[20], mac[25];
    int found;

    while (1) {
        printf("\nChoose Option: 1.ARP 2.RARP 3.EXIT\n");
        printf("enter the choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // ARP: IP → MAC
                printf("enter ip address:");
                scanf("%s", ip);
                found = 0;

                for (int i = 0; i < n; i++) {
                    if (strcmp(ip, table[i].ip) == 0) {
                        printf("Ethernet address is:%s\n", table[i].mac);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("IP address not found\n");
                }
                break;

            case 2: // RARP: MAC → IP
                printf("enter ethernet address:");
                scanf("%s", mac);
                found = 0;

                for (int i = 0; i < n; i++) {
                    if (strcmp(mac, table[i].mac) == 0) {
                        printf("IP address is: %s\n", table[i].ip);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Ethernet address not found\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}