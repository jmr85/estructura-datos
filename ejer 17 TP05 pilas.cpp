#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 17) Cargar una pila. Mostrar su contenido. Sin contar mostrar una leyenda aclaratoria dependiendo si la cantidad de elementos es par o impar. */

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
    
    
    while(pila_vacia(a)==1){
        sacar_pila(a,n);
        insertar_pila(b,n);                      
        if(pila_vacia(a) == 1){
                sacar_pila(a, n);
                insertar_pila(c, n);     
        }
    }
    while(pila_vacia(c) == 1 && pila_vacia(b) == 1){
          sacar_pila(b, n);
          insertar_pila(a, n);
          
          sacar_pila(c,n);
          insertar_pila(a,n);
                      
    }
    
    if(pila_vacia(b) == 0 && pila_vacia(c) == 0){
           printf("\n PAR \n");          
    }else{
          printf("\n IMPAR \n");
    }
     
  system("pause");
  return(0);
}
