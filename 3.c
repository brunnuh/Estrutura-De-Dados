#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
float **CriaMatriz(int n, int m){
	int i, j;
	float **matriz;

	
	if(n < 1 || m < 1){
		return NULL;
	}
	matriz = (float**)malloc(n * sizeof(float*));// criando as linha dinamicamente
	if(matriz == NULL){
		return NULL;
	}
	for(i = 0; i < m; i++){// criando as colunas dinamicamente
		matriz[i] = (float**)malloc(m * sizeof(float*));
		if(matriz == NULL){
			return NULL;
		}
	}
	
	return matriz;
}
float **MultMat(int n, int m, int p, int q, float **Ma, float **Mb){
	int l,c,i,j,num ;
	float **Mc;
	if(n != q){
		return NULL;
	}

	Mc = CriaMatriz(n,q);
	if(Mc == NULL){
		return NULL;
	}

	for(l = 0; l < n;l++){ // l = 0 ; n = 2
		for(c = 0;c < q; c++){// c = 0 ; c = 1
			Mc[l][c] = 0;
			for(i = 0; i < m; i++){ // i = 0 ; i = 1
				num = Ma[l][i] * Mb[i][c];// num = -4 ; num =  ; num = 
				Mc[l][c] = Mc[l][c] + num;//Mc = -4
			}
		}
	}
	return Mc;
}

int main(){
	srand(time(NULL));
	int n, m , p , q;
	int l, c;
	n = 2;
	m = 2;
	p = 2;
	q = 2;
	float **Ma;
	float **Mb;
	float **Mc;
	
	Ma = CriaMatriz(n,m);
	Mb = CriaMatriz(p,q);
	if(Ma == NULL && Mb == NULL){
		printf("ERRO DE ALOCACAO");
	}
	for(l = 0; l < n; l++){//preenchendo matriz
		for(c = 0; c < m; c++){
			Ma[l][c] = rand() % 5;
			
		}
	}
	for(l = 0; l < p; l++){//preenchendo matriz
		for(c = 0; c < q; c++){
			Mb[l][c] = rand() % 5;
			
		}
	}
	printf("Matriz Ma\n");
	for(l = 0; l < n; l++){
		for(c = 0; c < m; c++){
			printf("\t %.0f ",Ma[l][c]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("Matriz Mb\n");
	for(l = 0; l < p; l++){
		for(c = 0; c < q; c++){
			printf("\t %.0f ",Mb[l][c]);
		}
		printf("\n");
	}
	Mc = MultMat(n, m , p , q , Ma, Mb);
	if(Mc == NULL){
		printf("Erro de alocacao");
	}
	printf("\n\n");
	printf("Matriz Mc\n");
	for(l = 0; l < p; l++){
		for(c = 0; c < q; c++){
			printf("\t %.0f ",Mc[l][c]);
		}
		printf("\n");
	}

	return 0;
}

