#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 14) Cargar una pila. Mostrar su contenido. Luego dar vuelta su contenido y mostrarla. */

int main(void){
    struct pila *a, *b, *c;
    int n;
    
    crear_pila(a);
	crear_pila(b);
	crear_pila(c);

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
    
   while(pila_vacia(a) == 1){
   		sacar_pila(a,n);
   		insertar_pila(b,n);
   }
   while(pila_vacia(b) == 1){
   		sacar_pila(b,n);
   		insertar_pila(c,n);
   }
   while(pila_vacia(c) == 1){
   		sacar_pila(c,n);
   		insertar_pila(a,n);
   }
   
   printf("\nAsi queda la Pila A luego de darla vuelta\n");
   mostrar_pila(a);
     
   system("pause");
   return(0);
}
