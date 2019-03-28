#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//alocou, testou
float **CriaEleMatriz(int n, int m){
	float **matriz;
	int i, l , c;

	
	if(n < 1 || m < 1){ //CASO OS TAMANHOS SEJAM MENORES QUE 1 JA RETORNA NULL
		printf("ERRO NO TAMANHO DA MATRIZ");
		return NULL;
	}
	matriz = (float**)malloc(n * sizeof(float*)); // alocando linhas do ponteiro
	if(matriz == NULL){
		printf("\nERRO NA ALOCACAO DE LINHAS");
		return NULL;
	}
	for(i = 0; i < m; i++){
		matriz[i] = (float**)malloc(n * sizeof(float*));// em cada linha criada , criar uma coluna
		if(matriz[i] == NULL){
			printf("\nERRO NA ALOCACAO DE COLUNAS");
			return NULL;
		}
	}
	srand(time(NULL));
	for(l = 0; l < n; l++){
		for(c = 0; c < m; c++){
			matriz[l][c] = rand() % 100;
		}
	}
	return matriz;
}
int main(){
	int n ,m, l, c;
	float **matriz;
	
	n = 4;
	m = 4;
	
	matriz = CriaEleMatriz(n, m);
	
	if (matriz == NULL){
		printf("\nERRO DE ALOCACAO");
	}
	
	for(l = 0; l < n; l++){
		for(c = 0; c < m; c++){
			printf("\t%.1f ",matriz[l][c]);
		}
		printf("\n");
	}

	return 0;
}

