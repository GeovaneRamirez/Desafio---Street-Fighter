#include <stdio.h>

int main()
{
    // Geovane Silva Ramirez RA:	2760482211001

    /* Desafio - Street Fighter Professor: Alexandre Ferreira
    Análise e Desenvolvimento de Sistemas - FATEC Campinas

    A entrada consiste de uma sequência de inteiros, um em cada linha, representando os valores dos golpes aplicados (valores positivos) e recebidos (valores negativos) por Ryu. Cada round será caracterizado por uma sequência de inteiros positivos seguida por uma sequência de inteiros negativos. Vence o round o combatente que tiver a maior soma dos valores de golpes aplicados no round.
    Nesta versão da simulação de um combate, levaremos em consideração os golpes de combos de ataques. Estes golpes são mais poderosos e causam maiores danos no adversário.

    Nesta simulação do jogo, os combos serão determinados pela propriedade númerica do valor de um golpe (caso o valor seja negativo, ou seja, é o valor de um golpe de Ken, deve-se considerar o módulo do seu valor).
    Se o valor de um golpe for um número perfeito, este terá seu valor multiplicado por 3;
    Se o valor de um golpe for um número triangular mas não perfeito, este terá seu valor multiplicado por 2;
    Um número n ∈ ℤ⁺ é dito perfeito se a soma de seus divisores próprios é igual ao próprio número. Por exemplo, 6 é um número perfeito, pois seus divisores próprios são 1, 2 e 3 e 1 + 2 + 3 = 6.
    Um número n ∈ ℤ⁺ é dito triangular se é igual à soma de todos os números inteiros de 1 até m, onde m é um número pertencente a ℤ⁺ tal que m ≤ n. Por exemplo, 6 = 1 + 2 + 3 e 10 = 1 + 2 + 3 + 4 são números triangulares.
    */

    int pontosRyu = 0, pontosKen = 0; //variáveis que contabilizarão os pontos em cada round
    int vezDoJogador = 0;
    int golpe = 1, soma, bonus;

    while (golpe != 0) {
        scanf("%d", &golpe);
        if (golpe > 0) {
            vezDoJogador = 1;
    } else if (golpe < 0) {
            vezDoJogador = 2;
            golpe = golpe * (-1);
    }

        // Verificando se o golpe é um número é perfeito
    bonus = 0;
    soma = 0;

        for (int a = 1; a <= golpe / 2; a++) {
            if (golpe % a == 0) {
                soma = soma + a;
                if (soma < golpe) {
                    continue;
                } else if (soma == golpe) {
                    golpe = golpe * 3;
                    bonus = 1;
                    break;
                } else {
                    break;
                }
            }
        }

        // Verificando se o numero é um triangular
        if (bonus == 0) {
            soma = 0;
            for (int i = 1; i <= golpe; i++) {
                soma += i;
                if (soma < golpe) {
                    continue;
                } else if (soma == golpe) {
                    // Se o número for triangular
                    golpe = golpe * 2;
                    break;
                } else {
                    // O numero não é triangular
                    break;
                }
            }
        }

        // verificação de quem foi o golpe e adiciona os pontos para ele
        if (vezDoJogador == 1) {
            pontosRyu = pontosRyu + golpe;
        } else {
            pontosKen = pontosKen + golpe;
        }
    }

    // Informar o ganhador da luta
    if (pontosRyu > pontosKen) {
        printf("Ryu ganhou\n");
    } else if (pontosKen > pontosRyu) {
        printf("Ken ganhou\n");
    } else {
        printf("Empate\n");
    }

    printf("Pontos Ryu: %d \nPontos Ken: %d", pontosRyu, pontosKen);
}
