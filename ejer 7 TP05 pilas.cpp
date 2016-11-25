#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 7) Armar un programa  usando los procedimientos y funciones definidas que lea varios nros (con cualquier criterio) y intente insertarlos en una pila que comenzará vacía.
 Se deben descartar los que hagan desbordar la pila. Luego mostrar su contenido. Usar un procedimiento. 
 Luego intentar eliminar el tope de la pila, mostrar su contenido. Luego intentar eliminar la base de la pila, mostrar su contenido. 
 Finalmente mostrar cuantos elementos quedaron en la pila. Esto último hacerlo con una función.  */

int main(void){
    struct pila *a, *b;
    int n;
  
    crear_pila(a);
    crear_pila(b);
    
    pedir_nro(n);
  
  /**** Carga de la Pila ****/
    while(n != 0){
        if(pila_llena(a) == 1){
            printf("\nPila llena\n");
        }else{
            insertar_pila(a, n);
        }    
        pedir_nro(n);
    }
    
    printf("\nPila A:\n");
	mostrar_pila(a);
    

  /**** Tope de la Pila ****/    
  if(pila_vacia(a) == 1){
      sacar_pila(a, n);
      printf("\nEl tope es: %d\n", n);
  }else{
      printf("Pila vacia\n");
  } 
  
   while(pila_vacia(a) == 1){//si no esta vacia
    sacar_pila(a, n);
    insertar_pila(b, n);
  }
  
  /**** Base de la Pila ****/ 
  if(pila_vacia(b) == 1){
      sacar_pila(b, n);
      printf("\nLa base es: %d", n);
      while(pila_vacia(b) == 1){
          sacar_pila(b, n);
          insertar_pila(a, n);
      }
  }
  
  
  printf("\nCantidad elementos de la pila (Luego de sacar Tope y Base): %d\n", cont_pila(a));
  printf("\nAsi queda la Pila A:\n");
  mostrar_pila(a); 
  
  system("pause");
  return(0);
}
