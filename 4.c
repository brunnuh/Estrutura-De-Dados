#include <stdio.h>
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
float *DiagPrin(int n, int m, float **Ma){
	int l,c;
	float *v;
	if(n != m){
		printf("Matriz nao eh quadrada");
		return NULL;
	}
	
	v = (float*)malloc(n * sizeof(float));
	if(v == NULL){
		printf("Erro na alocacao de v");
		return NULL;
	}
	
	for(l = 0; l < n; l++){
		for(c = 0; c < m; c++){
			if(l == c){
				v[l] = Ma[l][c];
			}
		}
	}
	printf("Diagonal principal\n");
	for(l = 0; l < n; l++){
		printf("%.0f ",v[l]);
	}
	return v;
}

int main(){
	srand(time(NULL));
	float **Ma;
	float v[3];
	int i,n = 3,m = 3, l , c;
	Ma = CriaMatriz(n,m);
		for(l = 0; l < n; l++){//preenchendo matriz
		for(c = 0; c < m; c++){
			Ma[l][c] = rand() % 5;
		}
	}
	printf("Matriz Ma\n");
	for(l = 0; l < n; l++){
		for(c = 0; c < m; c++){
			printf("\t %.0f ",Ma[l][c]);
		}
		printf("\n");
	}
	
	DiagPrin(m,m,Ma);
	
	return 0;
}

