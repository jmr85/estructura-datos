#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 8) Cargar una pila. Mostrar su contenido. Luego mostrar su contenido en orden inverso al dado, dejando la pila como estaba originalmente. */

int main(void){
    struct pila *a, *b;
    int n;
  
    crear_pila(a);
    crear_pila(b);
    
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
    sacar_pila(a, n);
    insertar_pila(b, n);
  }
  
  printf("Pila B\n");
  mostrar_pila(b);
  
   while(pila_vacia(b) == 1){
    sacar_pila(b, n);
    insertar_pila(a, n);
  }
  
  system("pause");
  return(0);
}
