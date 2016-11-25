#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 19) Cargar dos pilas. Mostrar su contenido. Luego cargar una pila con el contenido de ambas de la siguiente manera: una de la primera y otra de la segunda. 
Si quedaran elementos de alguna pasarlas a la pila resultado en el tope de la misma. */

int main(void){
    struct pila *a, *b, *r;
    int n;
    
    crear_pila(a);
    crear_pila(b);
    crear_pila(r);
    
    /**************************** Carga pila A **********************************/

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
    
    /************************** Carga pila B ****************************************/
    
    
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
    
    
    while(pila_vacia(a) == 1 && pila_vacia(b) == 1){
    	sacar_pila(a, n);
    	insertar_pila(r, n);
    	  
    	sacar_pila(b,n);
    	insertar_pila(r,n);
	}
	while(pila_vacia(a) == 1){
		sacar_pila(a, n);
		insertar_pila(r,n);
	}
    while(pila_vacia(b) == 1){
    	sacar_pila(b,n);
    	insertar_pila(r,n);
	} 
	
	printf("\nPila R\n");
    mostrar_pila(r);
	
  system("pause");
  return(0);
}
