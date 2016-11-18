
#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" //Libreria propia de lectura

int sumarial(int n);
int sumarial_rec(int n);

int main (void){
    int a;
    
    pedir_nro(a);
    
    printf("El sumarial de %d es: %d \n", a , sumarial(a));
  
    system("pause");
    return(0);
}


    
//sumar desde el numero ingresado hasta el 1 secuencialmente
int sumarial(int n){
	int i; 
	int sum = 0;
	
    for(i=n; i>=1; i--){
        sum = sum +i;
    }
    return(sum);
}
int sumarial_rec(int n){
	int sum = 0;
	
	if(n>0){
		sum = n + sumarial_rec(n-1);
	}
    return(sum);
}

void mostrar_impares(int n){
    if(n>0){
        if(n%2!=0){
            printf("\n %d", n);
        }
        mostrar_impares(n-1);
    }
}
void mostrar_impares2(){
    if(n>0){
        if(n%2!=0){
            printf("\n %d", n);
            mostrar_impares(n-2);
        }else{
            mostrar_impares(n-1);
        }
        
    }
}        

int fibo(int n){
        int i;
        int a = 1;
        int b = 1;
        int sum = 1;
        
    for(i=3; i<=n; i++){
        sum = a + b;
        a = b;
        b = sum;
    }
    return(sum);
}
int fibo_rec(int n){
        int resul;
        if(n <= 2){
                resul = 1;
        }else{
                resul = fibo_rec(n-1) + fibo_rec(n-2);
        }
        return(resul);
}




