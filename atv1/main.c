/*
    Nome: Luiz Henrique Benedito
    nUSP: 12563814

    SSC0503 - Algoritimos de Estruturas de Dados 2
    Profª.: Maria Cristina

    ATIVIDADE 1 

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50

struct Cadlivros{
    int id;
    char titulo[100];
    char autor[50];
};


int main(){
    struct Cadlivros livros[SIZE];    
    int r, m, i;
    FILE *arquivo;


    printf("Digite o numero de registros: ");
    scanf("%d", &r);

    for(i=0; i<r; i++){
        livros[i].id = i+1;
        printf("ID: %d\n");
        printf("Titulo: ");
        scanf(" %[^(\r|\n)]", livros[i].titulo); 
        printf("Autor: ");
        scanf(" %[^(\r|\n)]", livros[i].autor); 
    }

    arquivo = fopen("livros.bin", "wb");
    if(arquivo == NULL){
        printf("Não foi possivel abLrir o arquivo!");
        return 0;
    }
    
    fwrite(livros, sizeof(struct Cadlivro), r, arquivo);
    fclose(arquivo);

    printf("quais o ultimos dados quer exibir: ");
    scanf("%d", &m);


    fclose(arquivo);
}