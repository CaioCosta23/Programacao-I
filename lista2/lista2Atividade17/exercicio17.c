/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio17.c
 * Author: Caio Costa Lopes
 *
 * Created on 19 de setembro de 2026, 17:45
 */

#include <stdio.h>
#include <stdlib.h>

#define CODIFICACAO 1
#define DECODIFICACAO 2

/*
 * Programa que codifica um conjunto de caracteres (alterando apenas as letras minúsculas na codificaçao;
 */
int main(int argc, char** argv) {
    unsigned short int opcao;
    int alteracaoCodigo;
    const unsigned short int TAMANHO_ALFABETO = 26;
    
    scanf("%hd %d ", &opcao, &alteracaoCodigo);
    
    if ((opcao == CODIFICACAO) || (opcao == DECODIFICACAO)) {
        char caractere;
        
        if (opcao == CODIFICACAO) {
            while(1) {
                scanf("%c", &caractere);
                
                if (caractere == '.'){
                    printf("%c", caractere);
                    break;
                }
                
                if ((caractere >= 'a') && (caractere <= 'z')) {
                    caractere += (alteracaoCodigo % TAMANHO_ALFABETO);
                    
                    if (caractere > 'z')
                        caractere -= TAMANHO_ALFABETO;
                }
                printf("%c", caractere);
            }
        }else if (opcao == DECODIFICACAO) {
            while(1) {
                scanf("%c", &caractere);
                
                if (caractere == '.'){
                    printf("%c", caractere);
                    break;
                }
                
                if ((caractere >= 'a') && (caractere <= 'z')) {
                    caractere -= (alteracaoCodigo % TAMANHO_ALFABETO);
                    
                    if (caractere < 'a')
                        caractere -= TAMANHO_ALFABETO;
                }
                
                printf("%c", caractere);
            }
        }
    }else {
        printf("Operacao invalida.");
    }

    return (EXIT_SUCCESS);
}

