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
    
  /********** Muestra el tope **************/  
  /*Elimina el tope y muestra el tope (Asi lo saca, lo muestra y lo vuelve a meter. Asi funciona el solo mostrar)*/
  //saca el tope de la estructura ´A´ y muestra
  if(pila_vacia(a) == 1){
      sacar_pila(a, n);
      printf("\nEl tope es: %d\n", n);
      insertar_pila(a, n); 
  }else{
      printf("Pila vacia");
  } 
  /******* Mostrar *************/
  /*Saca de una e inserta en otra, luego saca de esa, muestra y vuelve a  la pila original*/ 
  //saca la base y muestra
  //crear_pila(b);
  while(pila_vacia(a) == 1){//si no esta vacia
    sacar_pila(a, n);
    insertar_pila(b, n);
  }
  
  /*
  sacar_pila(a, n);
  printf("");
  insertar_pila(a, n);
   */ 
   
  /****** Muestra base ****/ 
  if(pila_vacia(a) == 1){
      sacar_pila(b, n);
      printf("\nLa base es: %d", n);
      insertar_pila(a, n);//lo saco y no lo muestro
      while(pila_vacia(b) == 1){
          sacar_pila(b, n);
          insertar_pila(a, n);
      }
  }
  
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
