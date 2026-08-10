/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   exercicio14.c
 * Author: Caio Costa Lopes
 *
 * Created on 10 de agosto de 2026, 17:11
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 21

typedef struct{
    int codigo, idade, nota;
    char nome[TAMANHO_NOME], sobrenome[TAMANHO_NOME];
}Candidato;


int comparaStrings(char string1[], char string2[]) {
    int s = 0;
    unsigned short int iguais = 1;
    
    while(1) {
        if ((string1[s] == '\0') || (string2[s] == '\0')) {
            if ((string1[s] != '\0') || (string2[s] != '\0'))
                iguais = 0;
            
            break;
        }else if (string1[s] != string2[s]){
            iguais = 0;
            break;
        }
        s++;
    }
    return iguais;
}

void trocaOrdem(Candidato candidatos[], int indiceCandidato1,int indiceCandidato2) {
    Candidato auxiliar;
    
    auxiliar = candidatos[indiceCandidato1];
    candidatos[indiceCandidato1] = candidatos[indiceCandidato2];
    candidatos[indiceCandidato2] = auxiliar;
}

void ordenaCandidatosPorSobrenome(Candidato candidatos[], int quantidadeCandidatos){
    int c1, c2, p;
    int basePosicao = 0;
    
    for (c1 = 0; c1 < quantidadeCandidatos - 1; c1++){
        // Caso uma parte já esteja ordenada, vai saltando até achar índice à partir do qual os sobrenomes ainda não estão ordenados;
        if (basePosicao > c1)
            continue;
        // Verifica a posição do sobrenome do qual se está comparando atualmente;
        basePosicao = c1;
        for (c2 = c1 + 1; c2 < quantidadeCandidatos; c2++) {
            if (comparaStrings(candidatos[c1].sobrenome, candidatos[c2].sobrenome)){
                // Ordena um seguido do outro os sobrenomes iguais (por ordem de leitura de dados);
                basePosicao += 1;
                // Ordena pela ordem de leitura (sobe o sobrenome repetido poição à posição a té o lugar onde o mesmo deve ficar;
                for (p = c2; p > basePosicao; p--) {
                    trocaOrdem(candidatos, p, (p - 1));
                }
            }
        }
    }
}

int verificaSobrenomeRepetido(Candidato candidatos[], Candidato candidato, int quantidadeCandidatos) {
    int c;
    unsigned short int repetido = 0;
    
    for (c = 0; c < quantidadeCandidatos; c++){
        if (candidato.codigo == candidatos[c].codigo)
            continue;
        
        if (comparaStrings(candidatos[c].sobrenome, candidato.sobrenome)){
            repetido = 1;
            break;
        }
    }
    return repetido;
}

Candidato leCandidato();
void imprimeCandidato(Candidato candidatos);

/*
 * Programa que lê dados de candidatos e imprime na tela os candidatos (os dados do mesmo) caso tenham mesmo sobrenome dos outros,
 * Em ordem de leitura; 
 */
int main(int argc, char** argv) {
    int quantidadeCandidatos, c, i;
    
    scanf("%d", &quantidadeCandidatos);
    
    Candidato candidatos[quantidadeCandidatos];
    
    for(c = 0; c < quantidadeCandidatos; c++) {
        candidatos[c] = leCandidato();
    }
    
    ordenaCandidatosPorSobrenome(candidatos, quantidadeCandidatos);
    
    for(i = 0; i < quantidadeCandidatos; i++) {
        if (verificaSobrenomeRepetido(candidatos, candidatos[i], quantidadeCandidatos))
            imprimeCandidato(candidatos[i]);
    }

    return (EXIT_SUCCESS);
}

Candidato leCandidato() {
    Candidato candidato;
    
    // Lê e "joga fora" tudo lido até encontrar a abertura de chaves;
    scanf("%*[^{]");
    // Lê e "joga fora" todas as senteças que são iguais a abertura de chave acompanhada por um espaço ("{ ");
    scanf("%*[{ ]");
    // Lê o código do candidato e armazena no atributo da estrutura;
    scanf("%d", &candidato.codigo);
    // Lê e "joga fora" todas as sentenças que são iguais a sentença vírgula acompanhada de espaço (", ");
    scanf("%*[, ]");
    // Lê tudo e armazena no atributo do sobrenome do candidato, até encontrar uma vírgula e em seguida lê a virgula (mas não a armazena em lugar nenhum);
    scanf("%20[^,],", candidato.sobrenome);
    // Lê e joga fora todos os espaços;
    scanf("%*[ ]");
    // Mesma lógica do sobrenome, mas agora, armazenando a informação no atributo nome do candidato;
    scanf("%20[^,],", candidato.nome);
    // Lê a nota do candidato e armazena no atributo de mesmo nome na estrutura de dados do candidato;
    scanf("%d", &candidato.nota);
    // Mesma lógica de consumir tudo que é vírgula e espaço, feito mais acima;
    scanf("%*[, ]");
    // Lê a idade do candidato e armazena no atributo de mesmo nome na estrutura de dados do candidato;
    scanf("%d", &candidato.idade);
    // Lê e "joga fora" tudo até o '\n';
    scanf("%*[^\n]");
    // Lê e "joga fora" o próximo caractere;
    scanf("%*c");
    
    /*
     * Este úlimo é necessário porque ao chegar a leitura do último dado, caso não haja mais nada a ser lido, ele continuará esperando
     * algo ser digitado, pelo falo do "%d" desconsiderar o qaulquer caractere que represente quebra ou espaços de qualquer tipo;
    */
    
    // OBS: Adicionado "20" na frente das leituras dos strings (nome e sobrenome) para evitar o estouro do tamanho defunido no vetor de caracteres;
    
    return candidato;
}

void imprimeCandidato(Candidato candidato) {
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}

