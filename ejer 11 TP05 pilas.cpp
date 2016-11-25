#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 
#include "pila_lib.h"

/* (OK) 11) Cargar una pila. Mostrar su contenido. Luego intercambiar el tope con la base de la misma. Mostrar como quedó la pila.*/

int main(void){
    struct pila *a, *b, *c, *aux;
    int n;
  
    crear_pila(a);
    crear_pila(b);
    crear_pila(c);
    crear_pila(aux);
    
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
	
	
	/* Paso el tope de A al C*/
	if(pila_vacia(a) == 1){
      sacar_pila(a, n);
      printf("\nEl tope es: %d\n", n);
      insertar_pila(c, n);
    }else{
      printf("Pila vacia");
    }

/*Todo lo que queda de A al B (sin el tope)*/
  while(pila_vacia(a) == 1){
  	sacar_pila(a,n);
  	insertar_pila(b,n);
  }
  /*Tope de B (la Base original de A) al AUX*/
  if(pila_vacia(b) == 1){
  		sacar_pila(b, n);
  		insertar_pila(aux, n);
  }
  
  /*Todo lo que queda de B al C (parte media original de A)*/
  while(pila_vacia(b) == 1){
  		sacar_pila(b, n);
  		insertar_pila(c, n);
  }
  /*Luego al final paso el tope y unico valor de AUX (base original de A) al tope de C*/
  if(pila_vacia(aux) == 1){
  	sacar_pila(aux, n);
  	insertar_pila(c, n);
  }
  /* Como quedo armado el C lo vuelco al B */
  while(pila_vacia(c) == 1){
  		sacar_pila(c, n);
  		insertar_pila(b, n);
  }
  
  /*Finalmente vuelco todo lo del B al A como resultado final*/
  while(pila_vacia(b) == 1){
  		sacar_pila(b, n);
  		insertar_pila(a, n);
  }
  
  printf("\nAsi queda la Pila A:\n");
  mostrar_pila(a); 
  
  system("pause");
  return(0);
}
