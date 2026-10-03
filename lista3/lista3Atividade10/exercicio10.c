/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio10.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 12:54
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_ALFABETO 26

char Codifica(char letra, int n);
char Decodifica(char letra, int n);

int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);

/*
 * Programa que codifica uma sequência de caracteres;
 */
int main(int argc, char** argv) {
    unsigned short int opcao, codigoAlteracao;
    char caractere;
    const unsigned short int CODIFICAR = 1, DECODIFICAR = 2;
    const char CARACTERE_ENCERRAMENTO = '.';
    
    scanf("%hd %hd ", &opcao, &codigoAlteracao);
    
    if (opcao == CODIFICAR) {
        while(1) {
            scanf("%c", &caractere);

            if (EhLetra(caractere))
                caractere = Codifica(caractere, codigoAlteracao);

            printf("%c", caractere);

            if (caractere == CARACTERE_ENCERRAMENTO)
                break;
        }
    }else if (opcao == DECODIFICAR) {
        while(1) {
            scanf("%c", &caractere);

            if (EhLetra(caractere))
                caractere = Decodifica(caractere, codigoAlteracao);

            printf("%c", caractere);

            if (caractere == CARACTERE_ENCERRAMENTO)
                break;
        }
    }else {
        printf("Operacao invalida.");
    }

    return (EXIT_SUCCESS);
}

char Codifica(char letra, int n) {
    if (EhLetraMaiuscula(letra)){
        letra = letra + (2 * (n % TAMANHO_ALFABETO));
        
        if (letra > 'Z')
            letra -= TAMANHO_ALFABETO;
    }else if (EhLetraMinuscula(letra)) {
        letra = letra + (n % TAMANHO_ALFABETO);
        
        if (letra > 'z')
            letra -= TAMANHO_ALFABETO;
    }
    
    return letra;
}

char Decodifica(char letra, int n) {
    if (EhLetraMaiuscula(letra)){
        letra = letra - ((n % TAMANHO_ALFABETO) / 2);
        
        if (letra > 'z')
            letra -= TAMANHO_ALFABETO;
    }else if (EhLetraMinuscula(letra)) {
        letra = letra - (n % TAMANHO_ALFABETO);
        
        if (letra < 'a')
            letra += TAMANHO_ALFABETO;
    }
    return letra;
}

int EhLetra(char c) {
    return ((EhLetraMaiuscula(c)) || (EhLetraMinuscula(c)));
}
int EhLetraMaiuscula(char c) {
    return ((c >= 'A') && (c <= 'Z'));
}
int EhLetraMinuscula(char c) {
    return ((c >= 'a') && (c <= 'z'));
}