#include <stdio.h>

int VarrerVetor(int *vetor, int tamanho, int key){
	int i;
	for(i = 0; i < tamanho; i++){
		if(vetor[i] == key){
			return i;
		}
	}
	return -1;
}

int main(){
	int v[5] = {4,5,2,6,8};
	int key, posicao;
	/*for(i = 0; i < 5; i++){
		printf("\n%i",v[i]);
	}*/
	printf("Key: ");
	scanf("%i*c",&key);
	posicao = VarrerVetor(v, 5, key);
	if(posicao != -1)
		printf("posicao: %i", posicao);
	else
		printf("Nao esta no vetor");
	return 0;
}

