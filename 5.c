	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	#include <time.h>
	//********************************************************************************//
	float **CriaMatriz(int n, int m){
		int i, j;
		
		float **matriz;
	
	
		if(n < 1 || m < 1){
			return NULL;
		}
		matriz = (float**)malloc(n*sizeof(float* ));// criando as linha dinamicamente
		if(matriz == NULL){
			return NULL;
		}
		for(i = 0; i < m; i++){// criando as colunas dinamicamente
			matriz[i] = (float*)malloc(m * sizeof(float));
			if(matriz == NULL){
				return NULL;
			}
		}
		srand(time(NULL));
		
		for(i = 0 ; i < n; i++){
			for(j = 0;j < m; j++){
				matriz[i][j] = rand() % 10;
			}
		}
		return matriz;
	}
	
	
	//********************************************************************************//
	float *RetornaLinha(int n, int m, float **Ma, int k){
		float *VetorLinha;
		int i, j;
		if(k >= n){
			printf("\nLINHAS REQUERIDAS MAIORES DO QUE A NA MATRIZ");
		}
		VetorLinha = (float*)malloc(n * sizeof(float));
		
		if(VetorLinha == NULL){
			return NULL;
		}
		for(i = 0; i < n; i++){
			VetorLinha[i] = Ma[k][i];
		}
	
		return VetorLinha;
	}
	float *RetornaCol(int n, int m, float **Ma, int k){
		float *VetorCol;
		int i, j;
		if(k >= n){
			printf("\nLINHAS REQUERIDAS MAIORES DO QUE A NA MATRIZ");
		}
		VetorCol = (float*)malloc(n * sizeof(float));
		
		if(VetorCol == NULL){
			return NULL;
		}
		for(i = 0; i < n; i++){
			VetorCol[i] = Ma[i][k];
		}
	
		return VetorCol;
	}
	float RetornaSomaEmColk(int n, int m, float *c,int k){
		float somacol = 0;
		int i;
		
		for(i = 0; i < m; i++){
			somacol = somacol + c[i];
		}
	
		return somacol;
	}
	float RetornaSomaEmLinhak(int n, int m, float *l,int k){
		float somali = 0;
		int i;
		
		for(i = 0; i < m; i++){
			somali  = somali + l[i];
		}
	
		return somali;
	}
	int main(){
		int n = 3 ,m = 3 , k = 2, i , j;
		float **Ma;
		float *v, *c; 
		float somacol,somali;
		Ma = CriaMatriz(n, m);
		if(Ma == NULL)
			printf("\nERRO DE ALOCACAO\n");
			
		v = (float*)malloc(n * sizeof(float));
		if(v != NULL){
			v = RetornaLinha(n,m,Ma,k);
			if(v == NULL){
				printf("\nERRO DE ALOCACAO\n");
			}
			printf("========================");
			printf("\n\nLinha %i\n\n", k + 1);
			for(i = 0; i < n; i++){
				printf(" %.0f ",v[i]);
			}
			printf("\n\n");
			printf("=======================\n");
		}
		
		c = (float*)malloc(n * sizeof(float));
			if(c != NULL){
			c = RetornaCol(n,m,Ma,k);
			if(c == NULL){
				printf("\nERRO DE ALOCACAO\n");
			}
			printf("========================");
			printf("\n\nColuna %i\n\n", k + 1);
			for(i = 0; i < n; i++){
				printf(" %.0f ",c[i]);
			}
			printf("\n\n");
			printf("=======================\n");
		}
		somacol = RetornaSomaEmColk(n,m,c,k);
		
		printf("\na soma da coluna %i eh igual a %.0f\n",k+1,somacol);
		
		somali = RetornaSomaEmColk(n,m,v,k);
		
		printf("\na soma da coluna %i eh igual a %.0f\n",k+1,somali);
		
		
		for(i = 0 ; i < n; i++){
			for(j = 0;j < m; j++){
			
				printf(" %.0f ",Ma[i][j]);
			}
			printf("\n");
		}
		
	
		return 0;
	}

