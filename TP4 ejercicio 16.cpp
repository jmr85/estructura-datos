#include<stdio.h>
#include<stdlib.h>

/*Un ARBOL guarda una estructura de datos ordenada, descartando izq o der, 
en cambio una LISTA es secuencial. Se usa de fondo 
para guardar el id (o PK) de las bases de datos.*/

struct arbol{
    int num;
    struct arbol *izq;//menor
    struct arbol *der;//mayor
};

void pedir_nro(int &a);
void crear_arbol(struct arbol *&r);//ejer hecho en clase
int esta_en_arbol(struct arbol *r, int n);//ejer hecho en clase 
void insertar_en_arbol(struct arbol *&r, int n);
void recorrer_arbol_ird(struct arbol *r);//ordenado menor a mayor
void eliminar_arbol(struct arbol *&r, int n);//primero buscar y luego eliminar, depende de la funcion borrar_delarbol() de abajo
void borrar_delarbol(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);//depende de las funciones borrar_nodo_hoja(),borrar_nodo_un_hijo(),borrar_nodo_dos_hijos()
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);//solo r lleva &, siempre devuelve nodo raiz
void borrar_nodo_un_hijo(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
void borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
/*18) Codificar un procedimiento  que recorra el árbol y muestre solamente los múltiplos de 3.   
       void mostrar_3 _arbol (struct árbol *raíz).*/
void mostrar_3_arbol(struct arbol *raiz);   
/*19) Codificar un procedimiento  que recorra el árbol y muestre solamente los múltiplos de 3 ordenado de mayor a menor.  
       void mostrar_3.1 _arbol (struct árbol *raíz).*/    
void mostrar_31_arbol(struct arbol *raiz);       
/*20) Leer 20 nros e intentar insertarlos en  árbol vacío. Contar y mostrar  cuantos ingresaron a la estructura  y 
cuantos estaban repetidos. Luego leer nros hasta que aparezca un 9 y por cada uno intentar eliminarlos del árbol. 
Contar y mostrar cuantos se pudo o no eliminar del mismo.*/       

int main(void){
   /*******************************Ejercicio 20 TP4 Arboles**********************************/
   struct arbol *raiz;
   int n, i, contIng=0, contRep=0;
   crear_arbol(raiz);
   printf("\nIngresar elementos\n");

   for(i=1;i<=5;i++){
       pedir_nro(n);                 
       if(esta_en_arbol(raiz, n)==0){
            insertar_en_arbol(raiz, n);
            contIng++;
       }else{
            printf("\nEsta repetido\n");
            contRep++;
       }
    }
    printf("\n\nNumeros ingresados en la estructura: %d, Repetidos: %d\n", contIng, contRep);
    
    printf("\n\nIngresar elementos hasta que el numero sea 9\n");   
    struct arbol *raiz2;
    crear_arbol(raiz2);
	int contIng2=0;
	    
    do{
       pedir_nro(n);
       if(n==9) break;//agregue break para que el 9 no se inserte en el nodo antes de salir de la iteracion.
	   if(esta_en_arbol(raiz2, n)==0){
            insertar_en_arbol(raiz2, n);
            contIng2++;
       }else{
            printf("\nEsta repetido\n");
       }
	}while(n != 9);
    
    recorrer_arbol_ird(raiz2);
    
	printf("\nEliminar elementos\n");
	int contElim=0, contNoelim=0;
	for(i=1;i<=contIng2;i++){
   		pedir_nro(n);
   		if(esta_en_arbol(raiz2, n)==1){
        	eliminar_arbol(raiz2, n);
        	contElim++;
   		}else{
         	printf("NO existe");
         	contNoelim++;
   		}
	}
	printf("\n\nNumeros eliminados de la estructura: %d, NO eliminados: %d", contElim, contNoelim);
	/***************************FIN Ejercicio 20 TP4 Arboles******************************************/
    
    printf("\n\nIRD (Menor a Mayor): ");
    recorrer_arbol_ird(raiz);
    
    printf("\n\nMultiplo de 3: ");
    mostrar_3_arbol(raiz);//ejer 18 TP4
	printf("\n\nMultiplo de 3 Mayor a menor: ");
    mostrar_31_arbol(raiz);//ejer 19 TP4  
   
    printf("\nEliminar elementos\n");
	for(i=1;i<=2;i++){
   		pedir_nro(n);
   		if(esta_en_arbol(raiz, n)==1){
        	eliminar_arbol(raiz, n);//chequear porque no imprime todos los nmeros cuando elimino primero y ultimo
   		}else{
         	printf("NO existe");
   		}
	}
	
	printf("\n\nIRD (Menor a Mayor): ");
    recorrer_arbol_ird(raiz);

   system("pause");
   return(0);
}
void pedir_nro(int &a){
  printf("\n Ingrese numero: ");
  scanf("%d", &a);
}
void crear_arbol(struct arbol *&r){
    r = NULL;
}
int esta_en_arbol(struct arbol *r, int n){
    int res = 0;
    struct arbol *p = r;
    while(p != NULL && res == 0){// 0 si lo encontro
        if(p->num == n){
            res = 1;
        }else{
            if(n > p->num){
                p = p->der;
            }else{
                p = p->izq;
            }
        }
    }
    return(res);
}
//llenar hasta q encuentre nulo y enlazar
void insertar_en_arbol(struct arbol *&r, int n){
    struct arbol *p, *ant, *nuevo;
    p = r;
    ant = r;
    nuevo = new struct arbol;
    nuevo->num = n;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    while(p != NULL){
        ant = p;
        if(p->num < n){
            p = p->der;
        }else{
            p = p->izq;
        }
    }
    if(r != NULL){
        if(ant->num < n){
            ant->der = nuevo;
        }else{
            ant->izq = nuevo;
        }
    }else{
        r = nuevo;//enlaza si el nodo de entrada es vacio o nulo o NULL
    }
}
void recorrer_arbol_ird(struct arbol *r){//Ordenado menor a mayor
    if(r != NULL){
        recorrer_arbol_ird(r->izq);
        printf("%d ", r->num);
        recorrer_arbol_ird(r->der);
    }
}
void mostrar_3_arbol(struct arbol *raiz){//ejer 18 TP4
	 if(raiz != NULL){
        mostrar_3_arbol(raiz->izq);
        if(raiz->num % 3 == 0){
        	printf("%d ", raiz->num);
		}
        mostrar_3_arbol(raiz->der);
    }
}
void mostrar_31_arbol(struct arbol *raiz){//ejer 19 TP4 - muestre solamente los múltiplos de 3 ordenado de mayor a menor.
	if(raiz != NULL){
        mostrar_31_arbol(raiz->der);
        if(raiz->num % 3 == 0){
        	printf("%d ", raiz->num);
		}
        mostrar_31_arbol(raiz->izq);
    }
}
void eliminar_arbol(struct arbol *&r, int n){
    struct arbol *p, *ant;
    p = r;
    ant = p;
    while(p->num != n){
        if(n > p->num){
            p = p->der;
        }else{
            p = p->izq;
        }
    }
    borrar_delarbol(r, p, ant, n);
}
void borrar_delarbol(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
    if(p->izq == NULL && p->der == NULL){
       borrar_nodo_hoja(r, p, ant, n);    
    }else{
       if(p->der !=NULL & p->izq != NULL){
           borrar_nodo_dos_hijos(r, p, ant, n);
       }else{
           borrar_nodo_un_hijo(r, p, ant, n);
       }
    }
}
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){//r es raiz, ant es padre de p
         if(p != r){   
               if(ant->num > p->num ){
                           ant->izq = NULL;
               }else{
                           ant->der = NULL;
               }        
               delete(p);
         }else{
               r = NULL;
               delete(p);
         }      
}
void borrar_nodo_un_hijo(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
  if(p != NULL){ 
     if(ant->izq == p){//padre lo apunta al hijo p por la izquierda
                 if(p->der != NULL){//1)hijo esta a la derecha
                         ant->izq = p->der;               
                 }else{
                         ant->izq = p->der;//2)hijo esta a la izq
                 }
     }else{//padre lo apunta por la derecha
           if(p->izq != NULL){
                ant->der = p->izq; //3)hijo por izquierda
           }else{
                 ant->der = p->der;//4)hijo por derecha      
           }
     }
      //delete(p);se deja para el final, es lo mismo
  }else{//p es raiz
        if(p->izq != NULL){
             r = p->izq;
        }else{
             r = p->der;
        }
        //delete(p); se deja para el final, es lo mismo
  }
  delete(p);   
}
void  borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
      struct arbol *i, *d, *anterior;//punt izq
      i = p->izq;//me movi un lugar a la izq
      d = i;
      anterior = d;
      while(d->der != NULL){
         anterior = d;
         d = d->der;
      }
      if(i->der != NULL){//sirve para cuando D no tiene hijo o tiene un solo izq
                p->num = d->num;//reemplazo
                anterior->der = d->izq;//enlace
      }else{
                p->num = i->num;//solo me puede correr un hijo a la izq
                p->izq = i->izq;
                delete(i);
      }
}
