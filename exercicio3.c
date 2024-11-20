#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//variáveis globais de controle
#define NMAX 100
#define NUM_CORDAS 4

//Construtor classe nota recebe um char corda e um int casa 
typedef struct nota{
    char corda;      
    int casa;   
} Nota;

//Variavel musica que recebe um vetor de notas resolvi usar ponteiro para treino e uma quantidade de notas para ter mais controle
typedef struct musica{
    Nota* notas;
	int quantidade;      
} Musica;

void musica_print_tab(Musica musica);

int main()
{
	int quantidade;
	scanf("%d", &quantidade);
	
	Musica musica;
    musica.quantidade = quantidade;

	musica.notas = (Nota*)malloc(quantidade * sizeof(Nota));
	
	for (int i = 0; i < quantidade; i++) {
        scanf(" %c %d", &musica.notas[i].corda, &musica.notas[i].casa);
    }
	
	musica_print_tab(musica);

    free(musica.notas);

	return 0;
}

//Essa função recebe uma classe musica que possui cordas e notas e monta uma tablatura com ela
void musica_print_tab(Musica musica){
	//aqui eu faço um vetor de cordas para comparação
    char cordas[NUM_CORDAS] = {'A', 'E', 'C', 'G'};
	//e uma matriz de char para montar de maneira mais facil a tablatura 
    char tablatura[NUM_CORDAS][NMAX];

	//prencho a matriz tablatura com - 
    for (int i = 0; i < NUM_CORDAS; i++) {
        for (int j = 0; j < NMAX; j++) {
            tablatura[i][j] = '-';
        }
    }

	//nesse for ele vai percorrer o vetor musica com as notas e cordas
	for (int i = 0; i < musica.quantidade; i++) {
        
		char corda = toupper(musica.notas[i].corda); // crio uma variável que recebe a nota como maiscula 
        int casa = musica.notas[i].casa; // e uma que recebe a casa
        int corda_index = -1; //variavel de comparação
        
		// aqui eu verifico qual é o numero da casa 0 para A, 1 para E, 2 para C e assim vai 
		for (int j = 0; j < NUM_CORDAS; j++) {
            
			if (cordas[j] == corda) {
                corda_index = j;
                break;
				// break para eu guardar o index da corda
            }
        }
	
	//adicionando os valores na tablatura de acordo com o for e o corda index
	if (corda_index != -1 && casa >= 0) {
            
        	tablatura[corda_index][i] = (casa < 10) ? '0' + casa : '*';
        }
    }

	//printando a tablatura no modelo pedido
	for (int i = 0; i < NUM_CORDAS; i++) {
        printf("%c|-", cordas[i]); 
        for (int j = 0; j < musica.quantidade; j++) {
            printf("%c", tablatura[i][j] ? tablatura[i][j] : '-');
			printf("-");
        }
		printf("|");
        printf("\n");
    }
}