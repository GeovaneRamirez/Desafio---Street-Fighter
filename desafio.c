#include <stdio.h>

int main()
{
    // Geovane Silva Ramirez        RA:2760482211001
    // Glauco Gomes Martins Neto    RA:2760482211039

    /* Desafio - Street Fighter
    Professor: Alexandre Ferreira
    Análise e Desenvolvimento de Sistemas - FATEC Campinas

    A entrada consiste de uma sequência de inteiros, um em cada linha, representando os valores dos golpes aplicados (valores positivos) e recebidos (valores negativos) por Ryu. Cada round será caracterizado por uma sequência de inteiros positivos seguida por uma sequência de inteiros negativos. Vence o round o combatente que tiver a maior soma dos valores de golpes aplicados no round.
    Nesta versão da simulação de um combate, levaremos em consideração os golpes de combos de ataques. Estes golpes são mais poderosos e causam maiores danos no adversário.

    Nesta simulação do jogo, os combos serão determinados pela propriedade númerica do valor de um golpe (caso o valor seja negativo, ou seja, é o valor de um golpe de Ken, deve-se considerar o módulo do seu valor).
    Se o valor de um golpe for um número perfeito, este terá seu valor multiplicado por 3;
    Se o valor de um golpe for um número triangular mas não perfeito, este terá seu valor multiplicado por 2;
    Um número n ∈ ℤ⁺ é dito perfeito se a soma de seus divisores próprios é igual ao próprio número. Por exemplo, 6 é um número perfeito, pois seus divisores próprios são 1, 2 e 3 e 1 + 2 + 3 = 6.
    Um número n ∈ ℤ⁺ é dito triangular se é igual à soma de todos os números inteiros de 1 até m, onde m é um número pertencente a ℤ⁺ tal que m ≤ n. Por exemplo, 6 = 1 + 2 + 3 e 10 = 1 + 2 + 3 + 4 são números triangulares.

    O objetivo deste laboratório é simular uma luta entre Ryu e Ken e determinar quem ganhou a luta, considerando os multiplicadores de danos.

    A entrada consiste de uma sequência de inteiros, um em cada linha, representando os valores dos golpes aplicados (valores positivos) e recebidos (valores negativos) por Ryu. Cada round será caracterizado por uma sequência de inteiros positivos seguida por uma sequência de inteiros negativos. Vence o round o combatente que tiver a maior soma dos valores de golpes aplicados no round. Um novo round inicia logo quando acabam os valores dos golpes recebidos do round anterior (valores negativos). Você pode assumir que em cada round, Ryu e Ken sempre aplicam pelo menos um golpe cada. A luta termina quando, ao final de um round, o próximo número da sequência seja igual a 0.

    A saída deverá conter apenas uma linha, contendo somente Ryu venceu, Ken venceu ou empatou de acordo com o resultado geral da luta.

    */

    int pontosRyu = 0, pontosKen = 0; //variáveis que contabilizarão os pontos em cada round
    int vezDoJogador = 0; //Variável que irá verificar para qual lutaror o golpe irá contabilizar ou se o jogo acabou
    int golpe = 1; //Varivável que receberá cada ataque realizado
    int soma = 0; //Varivável que contabilizará a somatória dos ataques realizados
    int verificacao = 0; //variável que irá auxiliar na verificação dos bonus (se o golpe for um número perfeito ou triangular)


// Verificando qual jogador irá contabilizar os pontos
    while (golpe != 0) { //quanto o valor do golpe for zero o programa sairá do laço while e a luta termina
        scanf("%d", &golpe);
        if (golpe > 0) {  //se o valor for positivo os pontos vão para o Ryu (jogador 1)
            vezDoJogador = 1;
           verificacao = 0; //ativa a possibilidade de verificar se o número é perfeito e triangular
    }
        else if (golpe < 0) { //se o valor for negativo os pontos vão para o Ken (jogador 2)
            vezDoJogador = 2;
           verificacao = 0;//ativa a possibilidade de verificar se o número é perfeito e triangular
            golpe = golpe * (-1); //nesse caso os pontos serão convertidos para positivo para depois serem contabilizados
    }

// Verificando se o golpe é um número é perfeito (soma de seus divisores próprios é igual ao próprio número)
    for (int x = 1; x <= golpe/2; x++) { //o laço começa em "um" e vai até o valor da metade do golpe
        if (golpe % x == 0) { //verifica se o valor do golpe é divisível por x
            soma = soma + x; // se for divisível irá realizar a soma
            if (soma < golpe) {
                continue; //se o valor da soma for menor que o valor do golpe, o programa volta no laço e testa próximo número
            } else if (soma == golpe) { //se o valor da soma for igual ao do golpe, significa que o golpe é um número perfeito
                golpe = golpe * 3; //se o número for perfeito será multiplicado por 3
                verificacao = 1; // e esse valor muda para que a verificação "triangular" não seja realizada
                break; //nesse caso o laço será finalizado
            } else { //caso a soma seja maior que o valor do golpe o laço será interrompido
                break;
            }
        }
    }

// se o golpe não for um número perfeito, o programa verificará se ele é um número triangular
    if (verificacao == 0) {
        soma = 0;
        for (int y = 1; y <= golpe; y++) { //o laço for começará em "um" e terminará quando chegar no valor do golpe
            soma = soma + y; //soma o número verificado
            if (soma < golpe) {
                continue; //se a soma for menor que o golpe o laço é retomado para somar o próximo número do laço
            } else if (soma == golpe) { //se a soma for igual ao golpe significa que o número é triangular
                golpe = golpe * 2; //nesse caso o valor do golpe será dobrado (multiplicado por 2)
                break; // e o programa sairá do laço
            } else { // caso a soma seja maior que o golpe significa que o número não é triangular
                break; // e o programa sairá do laço
            }
        }
    }

// Contabilizando os pontos
        if (vezDoJogador == 1) { //se for a vez do Jogador 1
            pontosRyu = pontosRyu + golpe; //os pontos são contabilizados para o Ryu
        } else { //caso seja a vez do Jogador 2
            pontosKen = pontosKen + golpe; //os pontos vão para o Ken
        }
    }

    // Verificando e Informando o ganhador da luta
    if (pontosRyu > pontosKen) { //verificando se o Ryu venceu mais rounds
        printf("Ryu ganhou\n"); //nesse caso o Ryu será o vencedor
    } else if (pontosKen > pontosRyu) { // verificando se o Ken venceu mais rounds
        printf("Ken ganhou\n"); //nesse caso o Ken será o vencedor
    } else { //caso os dois tenham vencido a mesma quantidade de rouns
        printf("Empate\n"); //significa que os dois empataram
    }

    printf("Pontos Ryu: %d \nPontos Ken: %d", pontosRyu, pontosKen); //imprimindo a quantidade total de pontos que cada joogador adiquiriu durante a luta
}
