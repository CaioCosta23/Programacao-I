/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio11.c
 * Author: Caio Costa Lopes
 *
 * Created on 3 de outubro de 2026, 13:58
 */

#include <stdio.h>
#include <stdlib.h>

int EhPar(int x);
void PrintaPares(int N);
void PrintaImpares(int N);

/*
 * Programa que recebe dois numeros e contabiliza uma determinada quantidade de números do tipo especificado (par ou ímpar);
 */
int main(int argc, char** argv) {
    const unsigned short int PAR = 0, IMPAR = 1;
    unsigned short int tipo;
    int n;
    unsigned int quantidade = 0, contador = 1;
    
    scanf("%hd %d", &tipo, &n);
    
    if (tipo == PAR){
        while(quantidade != n){
            if (EhPar(contador)){
                quantidade += 1;
                
                PrintaPares(contador);
            }
            contador++;
        }
    }else if (tipo == IMPAR){
        while(quantidade != n){
            if (!(EhPar(contador))){
                quantidade += 1;
 
                PrintaImpares(contador);
            }
            
            contador++;
        }
    }

    return (EXIT_SUCCESS);
}

int EhPar(int x) {
    return (x % 2 == 0);
}
void PrintaPares(int N) {
    printf("%d ", N);
}
void PrintaImpares(int N) {
    printf("%d ", N);
}

