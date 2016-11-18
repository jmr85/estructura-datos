struct arbol{
    int num;
    struct arbol *izq;
    struct arbol *der;
};

void crear_arbol(struct arbol *&r);
void insertar_en_arbol(struct arbol *&r, int n);
int esta_en_arbol(struct arbol *r, int n);
void mostrar_arbol(struct arbol *r);
void eliminar_arbol(struct arbol *&r, int n);
void borrar_delarbol(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
void borrar_nodo_un_hijo(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);
void borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n);


void crear_arbol(struct arbol *&r){
    r = NULL;
}
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
        r = nuevo;
    }
}
int esta_en_arbol(struct arbol *r, int n){
    int res = 0;
    struct arbol *p = r;
    while(p != NULL && res == 0){
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
void mostrar_arbol(struct arbol *r){
     if(r != NULL){
        recorrer(r->der);
        printf("\n %d, ", r->num);
        recorrer(r->izq);
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
void borrar_nodo_hoja(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
               
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
     if(ant->izq == p){
                 if(p->der != NULL){
                         ant->izq = p->der;               
                 }else{
                         ant->izq = p->der;
                 }
     }else{
           if(p->izq != NULL){
                ant->der = p->izq;
           }else{
                 ant->der = p->der;     
           }
     }
  }else{
        if(p->izq != NULL){
             r = p->izq;
        }else{
             r = p->der;
        }
  }
  delete(p);   
}
void  borrar_nodo_dos_hijos(struct arbol *&r, struct arbol *p, struct arbol *ant, int n){
      struct arbol *i, *d, *anterior;
      i = p->izq;
      d = i;
      anterior = d;
      while(d->der != NULL){
         anterior = d;
         d = d->der;
      }
      if(i->der != NULL){
                p->num = d->num;
                anterior->der = d->izq;
      }else{
                p->num = i->num;
                p->izq = i->izq;
                delete(i);
      }
}
