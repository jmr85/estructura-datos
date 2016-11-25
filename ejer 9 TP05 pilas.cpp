#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 9) Cargar una pila. Mostrar su contenido. Luego leer un número y mostrar cuantas veces dicho número estaba en la pila,  dejando la pila como estaba originalmente. */

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
    printf("\nEl %d esta en la pila %d veces/ez \n", n, numero_pila(a, n));
    
  
   
  system("pause");
  return(0);
}
