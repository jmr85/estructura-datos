#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 

struct pila{
  int num;
  struct pila *sig;
};

void crear_pila(struct pila *&pil);
int pila_vacia(struct pila *pil);
int pila_llena(struct pila *pil);
void insertar_pila(struct pila *&pil, int n);//(PUSH)
void sacar_pila(struct pila *&pil, int &n);//(POP)devuelve los dos paremetros
void mostrar_pila(struct pila *pil);// ejer 7 TP05 Pilas

int MAXPILA = 5;

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
    
    mostrar_pila(a);
  /** Tope **/    
  if(pila_vacia(a) == 1){
      sacar_pila(a, n);
      printf("\nEl tope es: %d\n", n);
     // insertar_pila(a, n); 
  }else{
      printf("Pila vacia\n");
  } 
  mostrar_pila(a);
  system("pause");
  return(0);
}
void crear_pila(struct pila *&pil){
  pil = NULL;
}
int pila_vacia(struct pila *pil){
    if(pil == NULL)
        return(0);// o res = 0
    else
        return(1);// o res = 1
}
int pila_llena(struct pila *pil){
  struct pila *p = pil;
  int cont = 0;
  while(p != NULL){
    cont++;
    p = p->sig;
  }
  if(cont == MAXPILA)
    return(1);
  else
    return(0);  
}
void insertar_pila(struct pila *&pil, int n){
  struct pila *nuevo = new struct pila;
  nuevo->num = n;
  nuevo->sig = NULL;
  nuevo->sig = pil;
  pil = nuevo;
}
void sacar_pila(struct pila *&pil, int &n){
  struct pila *p;
  n = pil->num;
  p = pil;
  pil = pil->sig;
  delete(p);
}
void mostrar_pila(struct pila *pil){
    struct pila *p;int n;
    crear_pila(p);
    while(pila_vacia(pil)==1){
        sacar_pila(pil,n);                      
        printf("\n  %d\n", n);
        insertar_pila(p,n);
    }
    while(pila_vacia(p)==1){
        sacar_pila(p,n);                      
        insertar_pila(pil,n);
    }
}
