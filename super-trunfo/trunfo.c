#include <stdio.h>
#include <string.h> /*biblioteca usada para capturar string composta, ou seja com espaço ou mais de uma palavra*/
#include <stdlib.h> /*bibliotaca usada para limpar o terminal*/

/*Variaveis da carta do super trunfo*/
struct carta {
    char Estado[3]; 
    unsigned long int populacao;
    float area;
    float PIB;
    int turist;
    float densidade;
    float PIBC;
    float Super;
};

int main() {
    struct carta cart[2];/*linkando as variaves com o main*/
    char cidade[50];
    char cidade2[50];

    /*captura das informações das cartas*/
    for (size_t i = 0; i < 2; i++) {

        printf("---------- Cadastro da carta %d: -------------\n", i + 1);

        /*if e else para capturar o nome da cidade mesmo se for uma string composta*/
        if (i == 0) /*carta 1*/
            {
                printf("Nome do Cidade: ");
                fgets(cidade, sizeof(cidade), stdin); /*captura do nome da cidade*/
                if (cidade[strlen(cidade) - 1] == '\n') cidade[strlen(cidade) - 1] = '\0';/*retirar o "\n" ou o "enter" da variavel cidade*/
            } else /*carta 2*/
            {
                printf("Nome do Cidade: ");
                fgets(cidade2, sizeof(cidade2), stdin);/*captura do nome da cidade*/
                if (cidade2[strlen(cidade2) - 1] == '\n') cidade2[strlen(cidade2) - 1] = '\0';/*retirar o "\n" ou o "enter" da variavel cidade*/
            }

        printf("Nome do Estado: ");
        scanf("%2s", cart[i].Estado);  

        printf("Quantidade da Populacao: ");
        scanf("%lu", &cart[i].populacao);  

        printf("Quantidade de Area: ");
        scanf("%f", &cart[i].area);

        printf("Quantidade de PIB: ");
        scanf("%f", &cart[i].PIB);

        printf("Quantidade de pontos turisticos: ");
        scanf("%d", &cart[i].turist);  

        /*Calculos das variaves adicionais*/
        cart[i].densidade = cart[i].populacao / cart[i].area;
        cart[i].PIBC = cart[i].PIB / cart[i].populacao;
        cart[i].Super = cart[i].populacao + cart[i].area + cart[i].PIB + cart[i].turist + cart[i].PIBC + 1 / cart[i].densidade;
        getchar(); /*função utilizada para limpar o fgets, para não bugar na captura da segunda carta*/
    }

    system("cls"); /*limpeza do terminal*/

    /*comparação/apresentação das informações das cartas, já com o resultado, 0 para perdeu e 1 para ganhou*/
    for (size_t u = 0; u < 2; u++) {
        printf("\n----------- Carta %d ------------\n", u + 1); 

        printf("Nome do Estado: %s\n", cart[u].Estado);
        printf("Nome da Cidade: ");
        printf((u == 0) ? "%s", cidade : "%s", cidade2);
        printf("\n");
        printf("Numero da carta: A0%d \n", u + 1);
        printf((cart[u].populacao > cart[(u + 1) % 2].populacao) ? "Populacao: %lu(1)\n" : "Populacao: %lu(0)\n", cart[u].populacao);
        printf((cart[u].area > cart[(u + 1) % 2].area) ? "Area: %f(1)\n" : "Area: %f(0)\n", cart[u].area);
        printf((cart[u].PIB > cart[(u + 1) % 2].PIB) ? "PIB: %f(1)\n" : "PIB: %f(0)\n", cart[u].PIB);
        printf((cart[u].turist > cart[(u + 1) % 2].turist) ? "Pontos Turisticos: %d(1)\n" : "Pontos Turisticos: %d(0)\n", cart[u].turist);
        printf((cart[u].densidade < cart[(u + 1) % 2].densidade) ? "Densidade: %f(1)\n" : "Densidade: %f(0)\n", cart[u].densidade);
        printf((cart[u].PIBC > cart[(u + 1) % 2].PIBC) ? "PIB per capita: %f(1)\n" : "PIB per capita: %f(0)\n", cart[u].PIBC);
        printf((cart[u].Super > cart[(u + 1) % 2].Super) ? "Super poder: %f(1)\n" : "Super poder: %f(0)\n", cart[u].Super);
    }

    /*comparação das variaveis e apresentação dos resultados de maneira mais clara*/
    printf("\n--------- Resultado ---------\n");

    printf((cart[0].populacao > cart[1].populacao) ? "Populacao: Carta 1 venceu\n" : "Populacao: Carta 2 venceu\n");
    printf((cart[0].area > cart[1].area) ? "Area: Carta 1 venceu\n" : "Area: Carta 2 Venceu\n");
    printf((cart[0].PIB > cart[1].PIB) ? "PIB: Carta 1 venceu\n" : "PIB: Carta 2 venceu\n");
    printf((cart[0].turist > cart[1].turist) ? "Pontos turísticos: Carta 1 Venceu\n" : "Pontos turísticos: Carta 2 Venceu\n" );
    printf((cart[0].densidade < cart[1].densidade) ? "Densidade: Carta 1 venceu\n" : "Densidade: Carta 2 Venceu\n");
    printf((cart[0].PIBC > cart[1].PIBC) ? "PIB per capita: Carta 1 venceu\n" : "PIB per capita: Carta 2 venceu\n"); 
    printf((cart[0].Super > cart[1].Super) ? "Super poder: Carta 1 vanceu \n" : "Super poder: Carta 2 venceu\n");

    printf("--------- Fim Do Jogo ------------\n");
    printf("\n");
    printf("Obrigado por jogar.");

    return 0;
}
