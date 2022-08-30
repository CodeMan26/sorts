#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(){

    int x[10], n, i, aux, flag;

    for (i = 0; i < 10; i++){
        printf("Digite um valor:");
        scanf("%d", &x[i]);
    }

    n = 1;
    flag = 1;
    while(n <= 10 && flag == 1){
        flag = 0;
        for  (i = 0;i < 10; i++){
            if (x[i] < x[i+1]){
                flag = 1;
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
            }
        }
        n++;
    }

    for (i = 0; i < 10; i++){
        printf("\n%d", x[i]);
    }

    getch();
}