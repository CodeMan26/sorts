#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
///////////QUICK SORT CERTO-----------------

void troca(int *x, int i, int j){
	int aux;
	aux = x[i];
	x[i] = x[j];
	x[j] = aux;
}

int particao(int *x, int p, int r){
	int pivo, i, j;
	pivo = x[(p+r)/2];
	i = p - 1;
	j = r + 1;
	while (i < j){
		do{
			j--;
		}while(x[j] > pivo);
		do{
			i++;
		}while (x[i] < pivo);
		if (i < j) {
			troca(x, i, j);
		}
	}
	return j;
}

void quicksort(int *x, int p, int r){
	int q;
	if (p < r){
		q = particao(x, p, r);
		quicksort(x, p, q);
		quicksort(x, q+1, r);
	}
}

///////////EXERCÍCIO 2 -----------------
int part (int v[], int p, int r) {
    int q, i, j, t;
    i = p; 
	q = (p + r) / 2; 
	j = r;
do {
     while (v[i] < v[q]) {
     	i++;
	 }
     while (v[j] > v[q]) {
     	j--;
	 }
     if (i <= j) {
         t = v[i];
         v[i] = v[j];
         v[j] = t;
         i++;
         j--;
        }
    } while (i <= j);
return i;
}

int main(){
	int v[3], p, r, i;
	
	v[0] = 6;
	v[1] = 3;
	v[2] = 1;
	
	p = 3;
	r = 6;
	int g = 0;
	g = part(v, p, r);
	printf("%d\n", &g);
	
	int tam = sizeof(v)/sizeof(int);
	quicksort(v,0,tam-1);
	
	for (i = 0; i < 4; i++){
		printf("%d\n", v[i]);
	}
	printf("FIM");
	
}

