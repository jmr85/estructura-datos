#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 16) Cargar dos pilas. Mostrar su contenido. Luego intercambiar su base y su tope. Mostrarlas. */

int main(void){
    struct pila *a, *b, *aux_a, *aux_b;
    int tope_a, tope_b;
	int base_a, base_b;
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
    
    /** Saco tope de A **/
    if(pila_vacia(a) == 1){
    	sacar_pila(a,n);
    	tope_a = n;
	}
    while(pila_vacia(a) == 1){
    	sacar_pila(a,n);
    	insertar_pila(aux_a, n);
	}
	/** Saco base de A **/
	if(pila_vacia(aux_a) == 1){
		sacar_pila(aux_a,n);
		base_a = n;
	}
	
	/** Saco tope de B **/
	if(pila_vacia(b) == 1){
    	sacar_pila(b,n);
    	tope_b = n;
	}
	
	while(pila_vacia(b) == 1){
		sacar_pila(b,n);
		insertar_pila(aux_b,n);
	}
	
	/** Saco base de B **/
	if(pila_vacia(aux_b) == 1){
		sacar_pila(aux_b,n);
		base_b = n;
	}
	
	/** Vuelco el resultado de intercambio en pila A **/
	if(pila_llena(a) == 0){
		insertar_pila(a, base_b);	
	}
	
	while(pila_vacia(aux_a) == 1){
		sacar_pila(aux_a,n);
		insertar_pila(a,n);
	}
	if(pila_llena(a) == 0){
		insertar_pila(a, tope_b);	
	}
	/** Termina llenado de pila A **/
	
	/** Vuelco el resultado de intercambio en pila B **/
	if(pila_llena(b) == 0){
		insertar_pila(b, base_a);	
	}
	
	while(pila_vacia(aux_b) == 1){
		sacar_pila(aux_b,n);
		insertar_pila(b,n);
	}
	if(pila_llena(b) == 0){
		insertar_pila(b, tope_a);	
	}
	/** Termina llenado de pila A **/
	
	printf("\n**** Asi quedan las dos PILAS luego de intercambiar Tope y Base ****\n");
	printf("\nPila A\n");
    mostrar_pila(a);
    printf("\nPila B\n");
    mostrar_pila(b); 
     
  system("pause");
  return(0);
}
