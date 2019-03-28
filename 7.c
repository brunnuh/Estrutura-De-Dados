#include <stdio.h>
float *CriaMatrizV(int l, int c){
	int k,i,j;
	float *MatrizV;
	k = c;
	if(l > k){
		k = l;
	}
	MatrizV = (float*)malloc(sizeof(float)*l*c);
	if(MatrizV != NULL){
		for(i = 0; i < l; i++){
			for(j = 0; j < c;j++){
				printf("posicao: [%i,%i]:",i,j);
				scanf("%f*c",&MatrizV[k*i+j]);
			}
		}
		return MatrizV;
	}
	return NULL;
}


int main(){
	float *MaV, *MbV;
	int n = 3 ,m = 0 ,p ,q;
	int i , j;
	int k, x;
	k = n;
	if(k < m){
		k = m;
	}
	MaV = CriaMatrizV(n,m);
	if(MaV != NULL){
		for(i = 0; i < n; i++){
			for(j = 0;j  < m;j++){
				printf("\t%.0f ",MaV[k*i+j]);
			}
			printf("\n");
		}
	}
	else{
		printf("ERRO");
	}
	return 0;
}
