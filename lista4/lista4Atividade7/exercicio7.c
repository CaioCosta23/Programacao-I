/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio7.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 15:25
 */

#include <stdio.h>
#include <stdlib.h>

#define SOBRE_EIXO 0
#define QUADRANTE_1 1
#define QUADRANTE_2 2
#define QUADRANTE_3 3
#define QUADRANTE_4 4

typedef struct {
    int coordenadaX, coordenadaY;
}Ponto;

typedef struct {
    Ponto pontoInicial, pontoFinal; 
}Reta;

Reta LeReta(Reta reta);
Ponto LePonto(Ponto ponto);
int VerificaPosicaoRetaQuadranteUnico(Reta reta);

int ObtemQuadrante(Ponto ponto) {
    if ((ponto.coordenadaX > 0) && (ponto.coordenadaY > 0))
        return QUADRANTE_1;
    else if ((ponto.coordenadaX < 0) && (ponto.coordenadaY > 0))
        return QUADRANTE_2;
    else if ((ponto.coordenadaX < 0) && (ponto.coordenadaY < 0))
        return QUADRANTE_3;
    else if ((ponto.coordenadaX > 0) && (ponto.coordenadaY < 0))
        return QUADRANTE_4;
    else
        return SOBRE_EIXO;
}

int EhMesmoQuadrante(Ponto ponto1, Ponto ponto2) {
    if ((ObtemQuadrante(ponto1) == 0) || (ObtemQuadrante(ponto1) == 0))
        return 0;
    return (ObtemQuadrante(ponto1) == ObtemQuadrante(ponto2));
}

/*
 * Programa que verifia se uma reta está totalmente contida em um quadrante;
 */
int main(int argc, char** argv) {
    unsigned int quantidadeRetas, r;
    Reta reta;
    
    scanf("%d\n", &quantidadeRetas);
    
    for(r = 0; r < quantidadeRetas; r++) {
        reta = LeReta(reta);
    
        if (VerificaPosicaoRetaQuadranteUnico(reta))
            printf("MESMO\n");
        else
            printf("DIFERENTE\n");
    }

    return (EXIT_SUCCESS);
}

Reta LeReta(Reta reta) {
    reta.pontoInicial = LePonto(reta.pontoInicial);
    reta.pontoFinal = LePonto(reta.pontoFinal);
    
    return reta;
}

Ponto LePonto(Ponto ponto) {
    scanf("%d %d", &ponto.coordenadaX, &ponto.coordenadaY);
    
    return ponto;
}

int VerificaPosicaoRetaQuadranteUnico(Reta reta) {
    return (EhMesmoQuadrante(reta.pontoInicial, reta.pontoFinal));
}