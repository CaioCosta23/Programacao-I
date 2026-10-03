/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File: exercicio13.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 14:35
 */

#include <stdio.h>
#include <stdlib.h>

int CalculaValorPalavra();
int EhPrimo(int n);
int ProximoPrimo(int n);

int EhLetraMaiuscula(char letra) {
    return ((letra >= 'A') && (letra <= 'Z'));
}

int EhLetraMinuscula(char letra) {
    return ((letra >= 'a') && (letra <= 'z'));
}

/*
 * Programa que lê uma sequência de letras do alfabeto (sejam elas maiúsculas ou minúsculas e soma os seus valores 
 * (com minúsculas indo de 1 até 26 e maiúsculas de 27 até 52). Caso a soma seja um valor primo, imprime a informação na tela e, caso contrário,
 * imprime a informação de que o mesmo não é junto do pŕoximo número após o mesmo que seja primo;
 */
int main(int argc, char** argv) {
    unsigned int valorPalavra;
    
    while(1) {
        valorPalavra = CalculaValorPalavra();
        
        if (valorPalavra == 0)
            break;
        
        if (EhPrimo(valorPalavra))
            printf("E primo\n");
        else
            printf("Nao e primo %d\n", ProximoPrimo(valorPalavra));
    }
    return (EXIT_SUCCESS);
}

int CalculaValorPalavra() {
    char caractere;
    unsigned int valor = 0;
    const char CARACTERE_BASE_MINUSCULO = 'a', CARACTERE_BASE_MAIUSCULO = 'A';
    const unsigned short int VALOR_BASE_LETRA_MINUSCULA = 1, VALOR_BASE_LETRA_MAIUSCULA = 27;
    
    while(scanf("%c", &caractere) == 1){
        if (caractere == '\n')
            break;
        if (EhLetraMaiuscula(caractere))
            valor += (caractere - CARACTERE_BASE_MAIUSCULO) + VALOR_BASE_LETRA_MAIUSCULA;
        else if (EhLetraMinuscula(caractere))
            valor += (caractere - CARACTERE_BASE_MINUSCULO) + VALOR_BASE_LETRA_MINUSCULA;
    }
    return valor;
}

int EhPrimo(int n) {
    int p;
    unsigned int quantidadeDivisores = 0;
    
    for(p = 1; p <= n; p++)
        if (n % p == 0)
            quantidadeDivisores += 1;
    
    return (quantidadeDivisores == 2);
}

int ProximoPrimo(int n) {
    do {
        n += 1;
    } while(!(EhPrimo(n)));
    
    return n;
}


