#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
float *CriaMatrizV(int l, int c){
	int k,i,j;
	float *MatrizV;
	srand(time(NULL));
	k = c;
	MatrizV = (float*)malloc(sizeof(float)*l*c);
	if(MatrizV != NULL){
		for(i = 0; i < l; i++){
			for(j = 0; j < c;j++){
				MatrizV[k*i+j] = rand()%10;
		
			}
			
		}
		return MatrizV;
	}
	return NULL;
}
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


int main(){
	float *MaV, *MbV;
	int n = 3 ,m = 3 ,p = 2,q = 2;
	int i , j;
	int k, x;
	k = m;
	x = q; 
	MbV = CriaMatrizV(p,q);
	MaV = CriaMatrizV(n,m);
	if(MaV != NULL && MbV != NULL){
		printf("=================================");
		printf("\nMatriz Ma\n");
		for(i = 0; i < n; i++){
			for(j = 0;j  < m;j++){
				printf("\t%.0f ",MaV[k*i+j]);
		
			}
			printf("\n");
		}
		printf("\n=================================");
		printf("\nMatriz Mb\n");
		for(i = 0; i < p; i++){
			for(j = 0;j  < q;j++){
				printf("\t%.0f ",MbV[x*i+j]);
		
			}
			printf("\n");
		}
		printf("\n=================================\n");
	}
	else{
		printf("ERRO NA ALOCACAO DA FUNCAO/nVERIFICAR Funcao CriaMatrizV");
	}
	return 0;
}
