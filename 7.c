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
				//MatrizV[k*i+j] = rand()%10;
				printf("[%i,%i]:",i,j);
				scanf("%f*c",&MatrizV[k*i+j]);
		
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
float *MultABT(int n,int m,int p,int q,float *Vma,float *Vmb){//Mc = Ma * MbTransposta
	float *Mc;
	int i, j, l, k;
	k = m;

	Mc = (float*)malloc(m*q*sizeof(float));
	if(Mc != NULL){
		Vmb = Transposta(p,q,Vmb);//retorna agora q como linha e p como coluna
		if(Vmb != NULL){
			printf("\n============================\n");
			printf("MbT\n");
			for(i = 0; i < m; i++){
				for(j = 0;j < q; j++){
					printf("\t %.0f",Vmb[k*i+j]);
				}
				printf("\n");
			}
			if(m == q){
				for(i = 0;i < n;i++){
					for(j = 0; j < p; j++){
						Mc[k*i+j] = 0.0;
						for(l = 0;l < m; l++){
							Mc[k*i+j] += Vma[k*i+l] * Vmb[k*l+j];
						}
					}
				}
				return Mc;
			}
			else{
				printf("Numero de colunas de Ma é diferente do numero de linhas da transposta Mb");
				return NULL;
			}
		}
		printf("ERRO NA TRANSPOSICAO DE Mb");
		return NULL;
	}
	printf("ERRO NA ALOCACAO DO Mc");
	return NULL;
}

int main(){
	float *MaV, *MbV, *McV;
	int n = 3 ,m = 3 ,p = 3,q = 3;
	int i , j;
	int k, x;
	k = m;
	x = q; 
	MaV = CriaMatrizV(n,m);
	MbV = CriaMatrizV(p,q);
	McV = (float*)malloc(m*p*sizeof(float));
	if(MaV != NULL && MbV != NULL && McV != NULL){
		printf("=================================");
		printf("\nMatriz Ma\n");
		for(i = 0; i < n; i++){
			for(j = 0;j  < m;j++){
				printf("\t%.0f ",MaV[k*i+j]);
		
			}
			printf("\n");
		}
		printf("\n==================================");
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
	McV = MultABT(n,m,p,q,MaV,MbV);
	if(McV != NULL){
		printf("\n=================================\n");
		for(i = 0; i < m; i++){
			for(j = 0; j< q;j++){
				printf("\t%0.f ",McV[m*i+j]);
			}
			printf("\n");
		}	
		
	}
	return 0;
}
