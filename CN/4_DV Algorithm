#include <stdio.h>

#define INF 999

int main() {
    int n, i, j, k, ch, u, v, cost;
    int d[10][10], via[10][10];

    printf("enter the value of no. of nodes\n");
    scanf("%d", &n);

    printf("Enter the routing table : \n\t|");
    for(i = 0; i < n; i++) printf("%c\t", i + 'a');
    printf("\n");
    for(i = 0; i <= n; i++) printf("-------");
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("%c |", i + 'a');
        for(j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
            via[i][j] = j;
        }
    }

    while(1) {

        // core DV logic (shortest path update)
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    if(d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        via[i][j] = k;
                    }

        // output (same format)
        for(i = 0; i < n; i++) {
            printf("table for router %c\n", i + 'a');
            for(j = 0; j < n; j++)
                printf("%c:: %d via %c\n",
                       j + 'a', d[i][j], via[i][j] + 'a');
        }

        printf("do you want to change the cost(1/0)\n");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("enter the vertices which you want to change the cost\n");
            scanf("%d %d", &u, &v);

            printf("enter the cost\n");
            scanf("%d", &cost);

            d[u-1][v-1] = d[v-1][u-1] = cost;
        }
        else break;
    }

    return 0;
}