#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<stdlib.h>
const int max = 1000;

int i,j,opcion,aux,cn,n[max];

/*funcion para intercambiar los valores de dos elementos*/
void intercambio(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
	}
	
	/*funcion recursiva quicksort para ordenar el arreglo*/	
		void quicksort(int* izq, int* der) {
    if (der < izq)
        return;
    int pivote = *izq;
    int* ult = der;
    int* pri = izq;
    while (izq < der) {
        while (*izq <= pivote && izq < der+1)
            izq++;
        while (*der > pivote && der > izq-1)
            der--;
        if (izq < der)
            intercambio(izq, der);
    }
    intercambio(pri, der);
    quicksort(pri, der-1);
    quicksort(der+1, ult);
}


int main(int argc, char** argv)


{
	printf("Ingrese el tamano del arreglo:  ");scanf("%d",&cn);
	for(i=0;i<cn;i++)
	{
		printf("Ingrese valores para el arreglo:");	scanf("%d",&n[i]);
	}
	
		printf("Cual de los 7 algoritmos de ordenamientos quiere utilizar\n");
			printf("1.- Burbuja\n");
			printf("2.- Seleccion\n");
			printf("3.- Insercion\n");
			printf("4.- Rapido\n");
			printf("5.- Salir\n");
		
    	scanf("%d",&opcion);
 
    switch (opcion) {
    
	case 1:
		//Burbuja
	for(i=1; i<cn; i++)
	{
		for(j=0; j<cn-i; j++)
		{
			if(n[j]>n[j+1])
			{
			    aux    = n[j+1];
				n[j+1] = n[j];
				n[j]   = aux;
				
			}
		}
	}
	 
	 break;
	 
	case 2:
	//Selección
	int k;
	for (k = 0; k < cn-1; k++) {
		i = k;
		aux = n[k];
		for (j = k + 1; j < cn; j++) {
			if (n[j] < aux) {
				i = j;
				aux = n[i];
			}
		}
		n[i] = n[k];
		n[k] = aux;
	}
	break;
	
	case 3: 
	//Inserción
	int clave;

   //Recorrer el arreglo
	for (i = 1; i < cn; i++){	   
		clave = *(n+i);
		j = i-1;
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 0 && *(n+j) > clave){
			//Insertar el valor donde corresponda
			*(n+j+1) = *(n+j);
			j = j-1;
		}
		*(n+j+1) = clave;
		
	}    
  
	break;
	
	case 4:
	//Rapido	
		
	/*hacemos el llamado a la funcion quicksort
      para que ordene el arreglo*/

	quicksort(&n[0], &n[cn-1]);
	break;
	
	
	case 5:
		
		 exit(0);

	}
    
    /*mostramos el arreglo ordenado*/
    printf("Arreglo Ordenado\n");
    for (i = 0; i < cn; i++){
    
        printf("%d ", n[i]);
    printf("\n\n");
	}

}

	
	


	
	
	
	













