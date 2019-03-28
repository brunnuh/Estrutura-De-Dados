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
				MatrizV[k*i+j] = rand()%20;
		
			}
			
		}
		return MatrizV;
	}
	return NULL;
}


int main(){
	float *MaV, *MbV;
	int n = 5 ,m = 2 ,p = 2,q = 5;
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
