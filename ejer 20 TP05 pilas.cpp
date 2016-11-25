#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 20) Cargar una pila con cantidad de elementos impar. Mostrar su contenido. Luego generar tres pilas ARRIBA, ABAJO y MEDIO. En la pila MEDIO ira el elemento que esta en el medio de la pila original. En la pila ARRIBA, los elementos que estan por arriba del medio. En la pila ABAJO, los elementos que estan por abajo del medio.

Aclaracion: NO SE PUEDE CONTAR.
*/

int main(void){
    struct pila *original, *aux, *arriba, *medio, *abajo;
    int n;
    
    crear_pila(original);
    crear_pila(aux);
    crear_pila(arriba);
    crear_pila(medio);
    crear_pila(abajo);
    
    /**************************** Carga pila ORIGINAL **********************************/

    printf("\nCargar Pila A\n");
    pedir_nro(n);
    while(n != 0){
        if(pila_llena(original) == 1){
            printf("\nPila llena\n");
        }else{
            insertar_pila(original, n);
        }    
        pedir_nro(n);
    }
    printf("\nPila ORIGINAL\n");
    mostrar_pila(original);
    
    while(pila_vacia(original) == 1){
    	sacar_pila(original, n);
    	insertar_pila(abajo, n);//abajo
    	while(pila_vacia(original) == 1){
    		sacar_pila(original,n);
    		insertar_pila(aux, n);
		}  
    	if(pila_vacia(aux) == 1){
    		sacar_pila(aux,n);
    		insertar_pila(arriba,n);
    		while(pila_vacia(aux) == 1){
    			sacar_pila(aux,n);
    			insertar_pila(original,n);
			}
		}
	}
	if(pila_vacia(arriba) == 1){
		sacar_pila(abajo, n);
		insertar_pila(medio, n);
	}
	
	while(pila_vacia(arriba) == 1){
		sacar_pila(arriba, n);
		insertar_pila(aux, n);
	}
	
	while(pila_vacia(aux) == 1){
		sacar_pila(aux, n);
		insertar_pila(original, n);
	}
	while(pila_vacia(original) == 1){
		sacar_pila(original, n);
		insertar_pila(arriba,n);
	}
	
	printf("\nPila ARRIBA\n");
    mostrar_pila(arriba);
    printf("\nPila MEDIO\n");
    mostrar_pila(medio);
    printf("\nPila ABAJO\n");
    mostrar_pila(abajo);
	
    system("pause");
    return(0);
}
