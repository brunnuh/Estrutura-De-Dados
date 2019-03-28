#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
float *CriaMatrizV(int linhas, int colunas){
	float *MatrizV;
	int i,j,m;
	m = colunas;
	if(m < linhas){
		m = linhas;
	}
	MatrizV = (float*)malloc(linhas*colunas*sizeof(float));
	if(MatrizV != NULL){
		for(i = 0; i < linhas; i++){
			for(j = 0; j < colunas; j++){
				printf("\nposicao [%i,%i]:",i,j);
				scanf("%f*c",&MatrizV[m*i+j]);
			}
		}
		return MatrizV;
	}
	return NULL;
}
//********************************************************** 6
float *Transposta(int m, int n, float *MatrizV){
	float *MatrizVtrans;
	int i, j;
	int k = m;
	if(k < n){
		k = n;
	}
	MatrizVtrans = (float*)malloc(m*n*sizeof(float));
	if(MatrizVtrans != NULL){
		for(i = 0;i < n; i++){
			for(j = 0;j < m; j++){
				MatrizVtrans[k*i+j] = MatrizV[k*j+i];
			}
		}
		return MatrizVtrans;	
	}
	return NULL;
}
//********************************************************** end
int main(){
	float *VetorM;
	int n = 4, m = 2, i, j, k;//problemas nas transformadas de linhas maiores que colunas (3x2 por exemplo)
	k = n;
	if(k < m){
		k = m;
	}
	VetorM = CriaMatrizV(m,n);
	if(VetorM != NULL){
		printf("\n=============================\n");
		printf("Matriz Original\n");
		for(i = 0; i < n*m; i++){
			printf(" %.0f" ,VetorM[i]);
		}
		printf("\n==================\n");
		for(i = 0; i < m; i++){
			for(j = 0;j < n; j++){
				printf(" %.0f ",VetorM[k*i+j]);
			}
			printf("\n");
		}
		printf("\n=============================\n");
		VetorM = Transposta(m,n,VetorM);
		
		if(VetorM != NULL){
			printf("\nMatriz Transposta\n");
			for(i = 0; i < n*m; i++){
				printf(" %.0f" ,VetorM[i]);
			}
			printf("\n==================\n");
			for(i = 0; i < n; i++){
				for(j = 0;j < m; j++){
					printf(" %.0f ",VetorM[k*i+j]);
				}
				printf("\n");
			}
			printf("\n=============================\n");
		}else{
			printf("Erro na transposicao");
		}
	}else{
		printf("Erro na alocacao");
	}
	
	
	return 0;
}

