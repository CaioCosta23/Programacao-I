/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio12.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 14:17
 */

#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

/*
 * Programa que lê um valor e determina se o mesmo é par ou ímpar e se é primo ou não;
 */
int main(int argc, char** argv) {
    int numero;
    
    scanf("%d", &numero);
    
    do {
        numero = somaDigitos(numero);
        
        printf("%d ", numero);
        
        parImpar(numero);
        valorPrimo(numero);
        
        printf("\n");
        
        // Enquanto ele for um valor com mais de 2 digítos;
    } while ((numero >= 10) || (numero <= -10));

    return (EXIT_SUCCESS);
}

int somaDigitos(int n) {
    int soma = 0;
    
    while(n != 0) {
        soma += n % 10;
        n = n / 10;
    }
    return soma;
}

void parImpar(int n) {
    if (n % 2 == 0)
        printf("Par ");
    else
        printf("Impar ");
}

void valorPrimo(int n) {
    int p;
    unsigned int quantidadeDivisores = 0;
    
    for (p = 1; p <= n; p++) 
        if (n % p == 0)
            quantidadeDivisores += 1;
    
    if (quantidadeDivisores == 2)
        printf("Primo");
    else
        printf("Nao e primo");
}