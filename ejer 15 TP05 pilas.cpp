#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 15) Cargar dos pilas. Mostrar su contenido. Luego intercambiar su contenido y mostrarlas. */

int main(void){
    struct pila *a, *b, *aux_a, *aux_b;
    int n;
    
    crear_pila(a);
	crear_pila(b);
	crear_pila(aux_a);
	crear_pila(aux_b);
	
	
	printf("\nCargar Pila A\n");
	
    pedir_nro(n);
    while(n != 0){
        if(pila_llena(a) == 1){
            printf("\nPila llena\n");
        }else{
            insertar_pila(a, n);
        }    
        pedir_nro(n);
    }
    printf("\nPila A\n");
    mostrar_pila(a);
    
    printf("\nCargar Pila B\n");
    pedir_nro(n);
    while(n != 0){
        if(pila_llena(b) == 1){
            printf("\nPila llena\n");
        }else{
            insertar_pila(b, n);
        }    
        pedir_nro(n);
    }
    printf("\nPila B\n");
    mostrar_pila(b);  
    
    while(pila_vacia(a) == 1){
    	sacar_pila(a,n);
    	insertar_pila(aux_a, n);
	}
	while(pila_vacia(b) == 1){
    	sacar_pila(b,n);
    	insertar_pila(aux_b, n);
	}
   
	while(pila_vacia(aux_a) == 1){
    	sacar_pila(aux_a,n);
    	insertar_pila(b, n);
	}
	while(pila_vacia(aux_b) == 1){
    	sacar_pila(aux_b,n);
    	insertar_pila(a, n);
	}
   
   	printf("\nAsi queda la Pila A luego de intercambiar con B\n");
    mostrar_pila(a);
    printf("\nAsi queda la Pila B luego de intercambiar con A\n");
    mostrar_pila(b); 
     
  system("pause");
  return(0);
}
