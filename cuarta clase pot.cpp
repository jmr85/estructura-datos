
#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura


int potencia(int base, int exp);
int pot_rec(int base, int exp);
float pot_rec_neg(float base, float exp);
void mostrar(int n);
void mostrar_rec_1(int n);
void mostrar_rec_2(int n);

int main (void)
{
    int a,b;
    
    pedir_nros(a,b);
   	
   	//mostrar_rec_1(a);	
    //mostrar_rec_2(a);
    //pedir_nros_float(a,b);
    
      printf(" %d base, %d exp = %d \n", a,b, pot_rec(a, b));
      printf(" %d base, %d exp = %d \n", a,b, potencia(a, b));
    //printf(" %.2f base, %.2f exp = %.2f \n", a,b, pot_rec_neg(a, b));
    
    system("pause");
    
    return(0);
}

int potencia(int base, int exp){
  int res;
  int i;
  res=1;
  
  for(i=1; i<=exp;i++){
    res = res * base;
  }
  return(res);
}
int pot_rec(int base, int exp){
  int res;
  if(exp == 0){
      res = 1;
  }else{
      res = base * pot_rec(base, exp - 1);
  }
  return(res);
}

float pot_rec_neg(float base, float exp){
  float res;
  if(exp == 0){
      res = 1;
  }else{
      res = base * pot_rec(base, abs(exp) - 1);
  }
  if(exp < 0){
     res = 1 / res;
  }
  return(res);
}

//Mostrar desde numero ingresado hasta cero secuencialmente 
void mostrar(int n){
    int i;
    for (i=n; i>=0; i--){
        printf("\n %d \n", i);
    }
}

//si ingreso numero negativo hace bucle infinito
void mostrar_rec_1(int n){
    int i;
    if(n == 0){
      printf("\n %d", n);
    }else{
        printf("\n %d \n", n);
        mostrar_rec_1(n-1);
    }
}

/**Esta funcion es superior por tener menos codigo y no hace loop infinito por ingresar numero negativo **/ 
void mostrar_rec_2(int n){
   if(n >= 0){//si no es igual a cero no hace nada
         printf("\n %d \n", n);
         mostrar_rec_2(n - 1);
   }
}       




