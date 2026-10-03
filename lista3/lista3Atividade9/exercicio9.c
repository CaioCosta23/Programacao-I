/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio9.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 11:13
 */

#include <stdio.h>
#include <stdlib.h>

#define PH_NEUTRO 0
#define PH_ACIDO 1
#define PH_BASICO 2

#define PONTO_MAXIMO_ACIDES 0;
#define PONTO_MAXIMO_BASICO 14
#define PONTO_NEUTRALIDADE 7

#define INDICE_ACIDEZ 5.7

int verificapH(float ph);
int verificaGotaChuvaAcida(float ph);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

/*
 * Programa que verifica os dados de de uma chuva em área (contendo informações de area, densidade - quantidade de gotas - e o tempo que ela durou).
 * Em seguida o programa analisa se a chuva foi ácida ou básica ou neutra (com índícios de acidez) e imprime na tela, quantidade de gotas consideradas ácidas, 
 * a quantidade de hotas consideradas básicas e a quantidade de gotas consideradas neutras, a gota mais ácida, a mais básica, a mais neutra, e a porcentagem de ácidez
 * da chuva;
 */
int main(int argc, char** argv) {
    unsigned int area, densidade, tempo, a, d, t;
    unsigned int quantidadeGotasPhAcido = 0, quantidadeGotasPhBasico = 0, quantidadeGotasPhNeutro = 0, quantidadeGotasChuvaAcida = 0;
    float gota, phMaisAcido, phMaisBasico, phMaisNeutro, diferencaAcidez, diferencaBasica, diferencaNeutralidade,
          menorDiferencaAcidez, menorDiferencaBasica, menorDiferencaNeutralidade;
    
    scanf("%d %d %d\n", &area, &densidade, &tempo);
    
    for (a = 0; a < area; a++) {
        for(t = 0; t < tempo; t++) {
            for(d = 0; d < densidade; d++) {
                scanf("%f", &gota);

                diferencaAcidez = gota - PONTO_MAXIMO_ACIDES;
                diferencaBasica = PONTO_MAXIMO_BASICO - gota;
                diferencaNeutralidade = PONTO_NEUTRALIDADE - gota;

                if (diferencaNeutralidade < 0)
                        diferencaNeutralidade = diferencaNeutralidade * (-1);

                if ((a == 0) && (t == 0) && (d == 0)) {
                    phMaisAcido = gota;
                    phMaisBasico = gota;
                    phMaisNeutro = gota;

                    menorDiferencaAcidez = diferencaAcidez;
                    menorDiferencaBasica = diferencaBasica;
                    menorDiferencaNeutralidade = diferencaNeutralidade;
                }

                if (diferencaAcidez < menorDiferencaAcidez) {
                    phMaisAcido = gota;
                    menorDiferencaAcidez = diferencaAcidez;
                }
                if (diferencaBasica < menorDiferencaBasica) {
                    phMaisBasico = gota;
                    menorDiferencaBasica = diferencaBasica;
                }

                if (diferencaNeutralidade < menorDiferencaNeutralidade) {
                    phMaisNeutro = gota;
                    menorDiferencaNeutralidade = diferencaNeutralidade;
                }

                if (verificapH(gota) == PH_NEUTRO)
                    quantidadeGotasPhNeutro += 1;
                else if (verificapH(gota) == PH_ACIDO)
                    quantidadeGotasPhAcido += 1;
                else if (verificapH(gota) == PH_BASICO)
                    quantidadeGotasPhBasico += 1;

                if (verificaGotaChuvaAcida(gota))
                    quantidadeGotasChuvaAcida += 1;
            }
        }
    }
    printf("%d %d %d %.2f %.2f %.2f\n", quantidadeGotasPhAcido, quantidadeGotasPhBasico, quantidadeGotasPhNeutro, phMaisAcido, phMaisBasico, phMaisNeutro);
    imprimeResultadosAnalise(porcentagem((a * d * t), quantidadeGotasChuvaAcida), porcentagem((a * d * t), ((a * d * t) - quantidadeGotasChuvaAcida)));

    return (EXIT_SUCCESS);
}

int verificapH(float ph) {
    if (ph > PONTO_NEUTRALIDADE)
        return PH_BASICO;
    else if (ph < PONTO_NEUTRALIDADE)
        return PH_ACIDO;
    
    return PH_NEUTRO;
}
int verificaGotaChuvaAcida(float ph) {
    return ph < INDICE_ACIDEZ;
}
float porcentagem(float total, float valor) {
    return (valor / total);
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {
    if (porcentagemGotasChuvaAcida > porcentagemGotasChuvaNormal)
        printf("Chuva Acida %.2f%% %.2f%%",(porcentagemGotasChuvaAcida * 100), (porcentagemGotasChuvaNormal * 100));
    else if (porcentagemGotasChuvaAcida < porcentagemGotasChuvaNormal)
        printf("Chuva Normal %.2f%% %.2f%%",(porcentagemGotasChuvaAcida * 100), (porcentagemGotasChuvaNormal * 100));
    else
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%",(porcentagemGotasChuvaAcida * 100), (porcentagemGotasChuvaNormal * 100));
}

