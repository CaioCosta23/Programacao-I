/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio15.c
 * Author: Caio Costa Lopes
 *
 * Created on 10 de agosto de 2026, 19:29
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO_MAXIMO 1000
#define TAMANHO_NOME 21

#define IGUAIS 0
#define NOME_1_MAIOR 1
#define NOME_2_MAIOR 2

typedef struct {
    int codigo, nota, idade;
    char nome[TAMANHO_MAXIMO], sobrenome[TAMANHO_MAXIMO];
}Candidato;

Candidato leCandidato();
void ordenaCrescenteCandidatosPorNome(Candidato candidatos[], int quantidadeCandidatos);
void imprimeCandidato(Candidato candidato);

void trocaOrdem(Candidato candidatos[], int indiceCandidato1, int indiceCandidato2) {
    Candidato auxiliar;
    
    auxiliar = candidatos[indiceCandidato1];
    candidatos[indiceCandidato1] = candidatos[indiceCandidato2];
    candidatos[indiceCandidato2] = auxiliar;
}

int verificaLetraMaiuscula(char letra) {
    return ((letra >= 'A') && (letra <= 'Z'));
}

char transformaMaiusculaEmMinuscula(char letra) {
    // Distância para o seu equivalente minúsculo na tabela ASCII;
    return letra + 32;
}

int comparaNomeMaiorQueOutro(char string1[], char string2[]) {
    int n = 0;
    unsigned short int resultado = IGUAIS;
    char letraString1, letraString2;
    
    while((string1[n] != '\0') && (string2[n] != '\0')) {
        letraString1 = string1[n];
        letraString2 = string2[n];
        
        if(verificaLetraMaiuscula(letraString1))
            letraString1 = transformaMaiusculaEmMinuscula(letraString1);
        
        if(verificaLetraMaiuscula(letraString2))
            letraString2 = transformaMaiusculaEmMinuscula(letraString2);
        
        if (letraString1 != letraString2) {
            
            if (letraString1 > letraString2)
                resultado = NOME_1_MAIOR;
            else
                resultado = NOME_2_MAIOR;
            break;
        }
        n++;
    }
    return resultado;
}

int verificaNomeMaiorQueOutro(Candidato candidato1, Candidato candidato2) {
    unsigned short int comparacao;
    unsigned short int deveTrocar = 0;
    
    comparacao = comparaNomeMaiorQueOutro(candidato1.nome, candidato2.nome);
    
    if (comparacao == IGUAIS) {
        comparacao = comparaNomeMaiorQueOutro(candidato1.sobrenome, candidato2.sobrenome);
        
        if (comparacao == NOME_1_MAIOR)
            deveTrocar = 1;
    }else{
        if (comparacao == NOME_1_MAIOR)
            deveTrocar = 1;
    }
    
    return deveTrocar;
}

/*
 * Programa que lê uma sequência de informações de candidatos e os ordena, de maneira crescente, pelo nome;
 */
int main(int argc, char** argv) {
    int quantidadeCandidatos, c, i;
    
    scanf("%d", &quantidadeCandidatos);
    
    Candidato candidatos[quantidadeCandidatos];
    
    for (c = 0; c < quantidadeCandidatos; c++) {
        candidatos[c] = leCandidato();
    }
    
    ordenaCrescenteCandidatosPorNome(candidatos, quantidadeCandidatos);
    
    for (i = 0; i < quantidadeCandidatos; i++) {
        imprimeCandidato(candidatos[i]);
    }

    return (EXIT_SUCCESS);
}


Candidato leCandidato() {
    Candidato candidato;
    
    // Lê e "joga fora" tudo até encontrar uma abertira de chaves;
    scanf("%*[^{]");
    // Lê tudo que for igual a uma abertura de colchetes e "joga fora";
    scanf("%*[{ ]");
    // Lê o dado do código e insere no atributo de mesmo nome, na estrutura de dados do candidato;
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    // Lê todos os caracteres até encontrar uma vírgula (e aramzena apenas os 20 primeiros caracteres achados nesse intervalo) e em seguida "joga fora" essa vírgula  
    scanf("%20[^,],", candidato.sobrenome);
    // Lê tudo o que for igual a um espaço e "joga fora";
    scanf("%*[ ]");
    // Lê todos os caracteres até encontrar uma vírgula (e aramzena apenas os 20 primeiros caracteres achados nesse intervalo) e em seguida "joga fora" essa vírgula  
    scanf("%20[^,],", candidato.nome);
    // Lê o dado da nota e insere no atributo de mesmo nome, na estrutura de dados do candidato;
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    // Lê o dado da idade e insere no atributo de mesmo nome, na estrutura de dados do candidato;
    scanf("%d", &candidato.idade);
    // Lê e "joga fora" tudo até encontrar um '\n' no buffer de leitura;
    scanf("%*[^\n]");
    // Lê e "joga fora" o próximo caractere;
    scanf("%*c");
    
    return candidato;
}

void ordenaCrescenteCandidatosPorNome(Candidato candidatos[], int quantidadeCandidatos) {
    int c1, c2;
    
    for (c1 = 0; c1 < quantidadeCandidatos - 1; c1++){
        for (c2 = c1 + 1; c2 < quantidadeCandidatos; c2++){
            if (c1 == c2)
                continue;
            // Verifica se o nome do candidato 1 é maior (ou vem depois em ordem alfabética) que o do candidato 2;
            if (verificaNomeMaiorQueOutro(candidatos[c1], candidatos[c2])){
                trocaOrdem(candidatos, c1, c2);
            }
        }
    }
}

void imprimeCandidato(Candidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}