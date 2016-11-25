#include<stdio.h>
#include<stdlib.h>

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
int cont_pila(struct pila *pil);
int numero_pila(struct pila *&pil, int n);// ejer 9 TP05 
void eliminar_ocurrencia(struct pila *&pil, int x);


int MAXPILA = 10;


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
    struct pila *p;
	int n;
    crear_pila(p);
    
    while(pila_vacia(pil)==1){
        sacar_pila(pil,n);                      
        printf("\n\n  %d\n\n", n);
        insertar_pila(p,n);
    }
    while(pila_vacia(p)==1){
        sacar_pila(p,n);                      
        insertar_pila(pil,n);
    }
}
int cont_pila(struct pila *pil){
	struct pila *p;
	int resul=0, n;
	crear_pila(p);
	while(pila_vacia(pil)==1){
        sacar_pila(pil,n);                      
        insertar_pila(p,n);
        resul++;
    }
    while(pila_vacia(p)==1){
        sacar_pila(p,n);                      
        insertar_pila(pil,n);
    }
	return(resul);
}
/*Muestra cuantas  veces el numero ingresado esta en la pila */
int numero_pila(struct pila *&pil, int x){
	struct pila *p;
	int resul=0;
	int n;
	
	crear_pila(p);
	
	while(pila_vacia(pil)==1){
        sacar_pila(pil,n);  
		if(x == n){
        	resul++;
	    }                    
        insertar_pila(p,n);
    }
    while(pila_vacia(p)==1){
        sacar_pila(p,n);                      
        insertar_pila(pil,n);
    }
	return(resul);
}
/* 10) Cargar una pila. Mostrar su contenido. Luego leer un número y eliminarlo todas las veces que aparece en la pila. Mostrar como quedó la pila. */
void eliminar_ocurrencia(struct pila *&pil, int x){
	struct pila *p, *aux;
	int resul=0;
	int n;
	
	crear_pila(p);
	crear_pila(aux);
	
	while(pila_vacia(pil)==1){
        sacar_pila(pil,n); 
		if(x == n){
        	insertar_pila(aux, n);
	    }else{
	    	insertar_pila(p,n);
		}                       
    }
    while(pila_vacia(p)==1){
        sacar_pila(p,n);                    
        insertar_pila(pil,n);
    }
}
