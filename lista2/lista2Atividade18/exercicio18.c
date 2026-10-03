/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio18.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 10:54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Programa que recebe uma matriz e obtém o maior valor da matriz (indicando sua posição - linha e coluna); 
 */
int main(int argc, char** argv) {
    unsigned linhas, colunas, l, c, coordenadaXMaior, coordenadaYMaior;
    int valor, maior;
    
    scanf("%d %d", &linhas, &colunas);
    
    for(l = 0; l < linhas; l++) {
        for(c = 0; c < colunas; c++) {
            scanf("%d", &valor);
            
            if (((l == 0) && (c == 0)) || (valor > maior)) {
                maior = valor;
                coordenadaXMaior = l;
                coordenadaYMaior = c;
            }
        }
    }
    
    printf("%d (%d, %d)", maior, (coordenadaXMaior + 1), (coordenadaYMaior + 1));

    return (EXIT_SUCCESS);
}

