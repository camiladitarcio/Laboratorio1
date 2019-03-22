#include <stdio.h>
#include <stdlib.h>

int pedirNumero();

int main()
{

    pedirNumero();
    return 0;
}

int pedirNumero(){
    int num;
    int maximo;
    int minimo;
    int contador = 0;

    do{
    printf("Ingrese un numero:\n");
    scanf("%d",&num);

        if(contador == 0){
            maximo = num;
            minimo = num;
        }

        if(num < minimo){
        minimo = num;
        }

        else if(num > maximo){
        maximo = num;
        }



    contador++;
    }while(num != -1);

    printf("El mayor numero ingresado es: %d\n",maximo);
    printf("El menor numero ingresado es: %d\n",minimo);
    return 0;
}
