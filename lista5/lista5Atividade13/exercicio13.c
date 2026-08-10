/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio13.c
 * Author: Caio Costa Lopes
 *
 * Created on 10 de agosto de 2026, 16:39
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PADRAO 1000

int comparaStrings(char string1[], char string[2]);

/*
 * Programa que lê e compara duas strings; 
 */
int main(int argc, char** argv) {
    char string1[TAMANHO_PADRAO], string2[TAMANHO_PADRAO];
    
    while((scanf("%s", string1) == 1) && (scanf("%s", string2) == 1)){
        if(comparaStrings(string1, string2))
            printf("IGUAL\n");
        else
            printf("DIFERENTE\n");
    }

    return (EXIT_SUCCESS);
}

int comparaStrings(char string1[], char string2[]) {
    unsigned int s = 0;
    unsigned short int iguais = 1;
    
    while(1){
        if ((string1[s] == '\0') || (string2[s] == '\0')){
            if ((string1[s] != '\0') || (string2[s] != '\0'))
                iguais = 0;
            
            return iguais;
        }else if(string1[s] != string2[s]){
            iguais = 0;
            
            return iguais;
        }
        s++;
    }
}

