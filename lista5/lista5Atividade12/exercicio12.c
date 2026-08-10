/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio12.c
 * Author: Caio Costa Lopes
 *
 * Created on 8 de agosto de 2026, 02:57
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_PADRAO 1000

void concatenaNomes(char nome[], char sobrenome[], char completo[]);

/*
 * Programa que recebe sobrenome e nome (nesta orde) e concatena os dois na ordem comum (nome e sobrenome);
 */
int main(int argc, char** argv) {
    char nome[TAMANHO_PADRAO], sobrenome[TAMANHO_PADRAO], completo[TAMANHO_PADRAO + TAMANHO_PADRAO];
    
    while((scanf("%s", sobrenome) == 1) && (scanf("%s", nome) == 1)) {
        
        concatenaNomes(nome, sobrenome, completo);
        
        printf("%s\n", completo);
    }

    return (EXIT_SUCCESS);
}


void concatenaNomes(char nome[], char sobrenome[], char completo[]) {
    unsigned int c;
    unsigned int n = 0;
    
    c = 0;
    
    while(nome[c] != '\0') {
        completo[n] = nome[c];
        c++;
        n++;
    }
    
    c = 0;
    
    while(sobrenome[c] != '\0') {
        completo[n] = sobrenome[c];
        c++;
        n++;
    }
    
    // Última posição do string do nome completo (que deve receber o '\0' para encerra-la (e configurar que também é uma string);
    completo[n] = '\0';
    
    
}