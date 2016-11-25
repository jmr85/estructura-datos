#include<stdio.h>
#include<stdlib.h>
#include "lect_lib.h" 

//fibonacci
int fibo(int n);
int fibo_rec(int n);

int main (){
    int a;
    
    pedir_nro(a);
    
    printf("Resultado del fibona  de %d es: %d \n", a, fibo_rec(a));
  
    system("pause");
    
    return (0);
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




