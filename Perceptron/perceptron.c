#include <stdio.h>
#include <stdlib.h>

double soma(double vetor[]);

int main () {

    double eta = 0.5;                       // Taxa de aprendizado desejada
    double w[] = {1, 0, 0};                 // Definindo os pesos para as entradas (bias, w1, w2)
    double entrada1[] = {0, 0, 1, 1};       // Definindo as entradas
    double entrada2[] = {0, 1, 0, 1};
    double D[] = {0, 0, 0, 1};              // Definindo a saída desejada
    double erro_esperado = 1;               // Erro desejado
    double erro_atual[4] = {0, 0, 0, 0};    // Erro gerado a cada saída
    double y;                               // Resultado da função f(x)
    double saida[4];                        // Vetor de saída 
    int epoca = 1;                          // Contador de épocas necessárias

    while(erro_esperado != 0 && epoca <= 100) 
    {
        for(size_t p = 0; p < 4; p++) 
        {
            y = w[0] + w[1] * entrada1[p] + w[2] * entrada2[p];     // Calculando a f(x)

            if(y > 0) 
                saida[p] = 1;
            else
                saida[p] = 0;

            if(y != D[p])                                           // Verifica se é necessário atualizar parâmetros
            {
                erro_atual[p] = D[p] - saida[p];
                w[0] += eta * erro_atual[p];
                w[1] += eta * erro_atual[p] * entrada1[p];
                w[2] += eta * erro_atual[p] * entrada2[p];
            }
        }

        erro_esperado = soma(erro_atual);

        printf("\n=======================");
        printf("\nEpoca: %d", epoca);
        printf("\nBias: %.2lf", w[0]);
        printf("\nW1: %.2lf", w[1]);
        printf("\nW2: %.2lf", w[2]);
        printf("\nErro: %.2lf", erro_esperado);
        printf("\nSaida: [%lf] [%lf] [%lf] [%lf]", saida[0], saida[1], saida[2], saida[03]);

        epoca++;
    }

    return EXIT_SUCCESS;

}

double soma(double vetor[]) 
{
    double soma = 0;

    for(size_t i = 0; i < 4; i++) 
    {
        soma += vetor[i];
    }

    return soma;
}