#include <stdio.h>
#define MAX 100

int main()
{
    int pontos_ryu=0, pontos_ken=0, luta[MAX], i;

    printf("Digite a sequencia de golpes da partida:\n");


    for (i=0; i<=MAX; i++) {

        scanf("%d", &luta[i]);

        if (luta[i]==0) {break;}

    }

    return 0;
}
