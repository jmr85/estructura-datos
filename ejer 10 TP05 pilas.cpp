#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 10) Cargar una pila. Mostrar su contenido. Luego leer un número y eliminarlo todas las veces que aparece en la pila. Mostrar como quedó la pila. */

int main(void){
    struct pila *a, *b;
    int n;
  
    crear_pila(a);
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
    
    pedir_nro(n);
    eliminar_ocurrencia(a,n);
    printf("\nAsi queda la Pila A\n");
    mostrar_pila(a);
    
  
   
  system("pause");
  return(0);
}
