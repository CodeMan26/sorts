#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/////////////////////////////BUBBLE SORT/////////////////////////////

int bubblesort(int x[], int t) {
	
	int n, i, aux, troca, cont = 0;
	
	n = 1;
	troca = 1;
	while (n <= t && troca ==1){
		troca = 0;
		for (i = 0; i <= 3; i++){
			if (x[i] < x[i+1]){
				troca = 1;
				aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
				cont++;
			}
		}
		n++;
	}
	
	return cont;
}

/////////////////////////////INSERTION SORT/////////////////////////////

int insertionsort(int x[], int t){
	
	int i, j, eleito, cont;
	
	for (i = 1; i < t; i++){
		eleito = x[i];
		j = i - 1;
		while (j >= 0 && x[j] > eleito){
			x[j+1] = x[j];
			j = j - 1;
			cont++;
		}
		x[j+1] = eleito;
	}
	
	return cont;
}

/////////////////////////////SELECTION SORT/////////////////////////////

int selectionsort(int x[], int t) {
	int i, j, eleito, menor, pos, cont;
	
	for (i = 0; i < t; i++) {
		eleito = x[i];
		menor = x[i+1];
		pos = i+1;
		for (j = i+2; j < t; j++) {
			if (x[j] < menor) {
				menor = x[j];
				pos = j;
				cont++;
			}
		}
		
		if (menor < eleito) {
			x[i] = x[pos];
			x[pos] = eleito;
			cont++;
		}
	}
	
	return cont;
}

/////////////////////////////MERGE SORT/////////////////////////////

int mergecont;

void intercala(int x[], int inicio, int fim, int meio) {
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[10];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio+1;
	poslivre = inicio;
	
	while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){
		if (x[inicio_vetor1] <= x[inicio_vetor2]){
			aux[poslivre] = x[inicio_vetor1];
			inicio_vetor1++;
			mergecont++;
		}else{
			aux[poslivre] = x[inicio_vetor2];
			inicio_vetor2++;
			mergecont++;
		}
		poslivre++;
	}
	
	for (i = inicio_vetor1; i <= meio; i++){
		aux[poslivre] = x[i];
		poslivre++;
	}
	
	for (i = inicio_vetor2; i <= fim; i++){
		aux[poslivre] = x[i];
		poslivre++;
	}
	
	for (i = inicio; i <= fim; i++){
		x[i] = aux[i];
	}
}

void merge(int x[], int inicio, int fim) {
	int meio;
	if (inicio < fim){
		meio = (inicio+fim)/2;
		merge(x, inicio, meio);
		merge(x, meio+1, fim);
		intercala(x, inicio, fim, meio);
	}
}

int mergesort(int x[], int t){
	int i;
	merge(x,0,t);
}

/////////////////////////////HEAP SORT/////////////////////////////

int heapcont;

void troca(int x[], int i, int j){
	int aux;
	aux = x[i];
	x[i] = x[j];
	x[j] = aux;
	heapcont++;
}

void fila_prioridade(int x[], int i, int qtde){
	int f_esq, f_dir, maior, aux;
	maior = i;
	if (2*i+1 <= qtde){
		f_esq = 2*i+1;
		f_dir = 2*i;
		
		if (x[f_esq] >= x[f_dir] && x[f_esq] > x[i])
		maior = 2*i+1;
		else if (x[f_dir] > x[f_esq] && x[f_dir] > x[i])
		maior = 2*i;
	} else if (2*i <= qtde){
		f_dir = 2*i;
		if (x[f_dir] > x[i]){
			maior = 2*i;
		}
	}
	if (maior != i){
		troca(x, i, maior);
		fila_prioridade(x, maior, qtde);
	}
}

void transforma_heap(int x[], int qtde){
	int i;
	for (i = qtde/2; i >=1; i--){
		fila_prioridade(x, i, qtde);
	}
}

void heapsort(int x[], int qtde){
	int i, ultima_pos, aux;
	for(i = qtde; i >= 2; i--){
		troca(x, 1, i);
		ultima_pos = i - 1;
		fila_prioridade(x, 1, ultima_pos);
	}
}

/////////////////////////////QUICK SORT/////////////////////////////

int quickcont;

void troca2(int *x, int i, int j){
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
			troca2(x, i, j);
			quickcont++;
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

/////////////////////////////////////////////////////////////////////

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int vetorA[6] = {2, 4, 6, 8, 10, 12};
    int vetorB[6] = {11, 9, 7, 5, 3, 1};
    int vetorC[6] = {5, 7, 2, 8, 1, 6};
    int vetorD[12] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    int vetorE[12] = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
    int vetorF[10] = {8, 9, 7, 9, 3, 2, 3, 8, 4, 6};
    int vetorG[10] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};
    int tamA = 6;
    int tamB = 6;
    int tamC = 6;
    int tamD = 12;
    int tamE = 12; 
    int tamF = 10;
    int tamG = 10;
    int tam;
    
    // VETOR A)
    printf("VETOR A) {2, 4, 6, 8, 10, 12}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorA, tamA));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorA, tamA));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorA, tamA));
    mergecont = 0;
    mergesort(vetorA, tamA);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorA, tamA);
	heapsort(vetorA, tamA);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorA)/sizeof(int);
    quickcont = 0;
	quicksort(vetorA,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR B)
    printf("VETOR B) {11, 9, 7, 5, 3, 1}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorB, tamB));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorB, tamB));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorB, tamB));
    mergecont = 0;
    mergesort(vetorB, tamB);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorB, tamB);
	heapsort(vetorB, tamB);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorB)/sizeof(int);
    quickcont = 0;
	quicksort(vetorB,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR C)
    printf("VETOR C) {5, 7, 2, 8, 1, 6}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorC, tamC));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorC, tamC));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorC, tamC));
    mergecont = 0;
    mergesort(vetorC, tamC);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorC, tamC);
	heapsort(vetorC, tamC);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorC)/sizeof(int);
    quickcont = 0;
	quicksort(vetorC,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR D)
    printf("VETOR D) {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorD, tamD));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorD, tamD));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorD, tamD));
    mergecont = 0;
    mergesort(vetorD, tamD);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorD, tamD);
	heapsort(vetorD, tamD);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorD)/sizeof(int);
    quickcont = 0;
	quicksort(vetorD,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR E)
    printf("VETOR E) {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorE, tamE));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorE, tamE));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorE, tamE));
    mergecont = 0;
    mergesort(vetorE, tamE);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorE, tamE);
	heapsort(vetorE, tamE);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorE)/sizeof(int);
    quickcont = 0;
	quicksort(vetorE,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR F)
    printf("VETOR F) {8, 9, 7, 9, 3, 2, 3, 8, 4, 6}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorF, tamF));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorF, tamF));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorF, tamF));
    mergecont = 0;
    mergesort(vetorF, tamF);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorF, tamF);
	heapsort(vetorF, tamF);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorF)/sizeof(int);
    quickcont = 0;
	quicksort(vetorF,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
    printf("\n");
    printf("\n");
    // VETOR G)
    printf("VETOR G) {89, 79, 32, 38, 46, 26, 43, 38, 32, 79}\n");
    printf("BUBBLE SORT: %d TROCAS\n", bubblesort(vetorG, tamG));
    printf("INSERTION SORT: %d TROCAS\n", insertionsort(vetorG, tamG));
    printf("SELECTION SORT: %d TROCAS\n", selectionsort(vetorG, tamG));
    mergecont = 0;
    mergesort(vetorG, tamG);
    printf("MERGE SORT: %d TROCAS\n", mergecont);
    heapcont = 0;
	transforma_heap(vetorG, tamG);
	heapsort(vetorG, tamG);
    printf("HEAP SORT: %d TROCAS\n", heapcont);
    tam = sizeof(vetorG)/sizeof(int);
    quickcont = 0;
	quicksort(vetorG,0,tam-1);
	printf("QUICK SORT: %d TROCAS\n", quickcont);
}
