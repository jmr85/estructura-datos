#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (todavia NO resuelto ) 18) Cargar dos pilas. Mostrar su contenido. 
Luego sin contar mostrar una leyenda aclaratoria dependiendo si 
la cantidad de elementos de ambas pilas es igual o no. */

int main(void){
    struct pila *a, *b, *aux_A1, *aux_A2, *aux_B1, *aux_B2;
    int n;
    
    crear_pila(a);
    crear_pila(b);
    crear_pila(aux_A1);
    crear_pila(aux_A2);
	crear_pila(aux_B1);
    crear_pila(aux_B2);
    
    
    /**** Carga pila A ****/
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
    
    /**** Carga pila B ****/
    
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
    
    while(pila_vacia(a)==1){
        sacar_pila(a,n);
        insertar_pila(aux_A1,n);                      
        if(pila_vacia(a) == 1){
            sacar_pila(a, n);
            insertar_pila(aux_A2, n);     
        }
    }
    
    
    
    
    /*****************  A  ***********************/  
    while(pila_vacia(a)==1){
        sacar_pila(a,n);
        insertar_pila(aux_A1,n);                      
        if(pila_vacia(a) == 1){
            sacar_pila(a, n);
            insertar_pila(aux_A2, n);     
        }
    }
    while(pila_vacia(aux_A2) == 1 && pila_vacia(aux_A1) == 1){
        sacar_pila(aux_A1, n);
        insertar_pila(a, n);
          
        sacar_pila(aux_A2,n);
        insertar_pila(a,n);
                      
    }
    /***********************************************/
    
    /*****************  B  ***********************/
    while(pila_vacia(b)==1){
        sacar_pila(b,n);
        insertar_pila(aux_B1,n);                      
        if(pila_vacia(a) == 1){
            sacar_pila(a, n);
            insertar_pila(aux_B2, n);     
        }
    }
    while(pila_vacia(aux_B2) == 1 && pila_vacia(aux_B1) == 1){
        sacar_pila(aux_B1, n);
        insertar_pila(a, n);
          
        sacar_pila(aux_B2,n);
        insertar_pila(a,n);               
    }
    /***********************************************/
    
    
    if(pila_vacia(a) == 1 && pila_vacia(b) == 1){
        printf("\n CANTIDAD DE ELEMENTOS IGUAL \n");          
    }else{
        printf("\n CANTIDAD DE ELEMENTOS DIFERENTE \n");
    }
     
  system("pause");
  return(0);
}
