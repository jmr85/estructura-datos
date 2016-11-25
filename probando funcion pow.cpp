
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pedir_nros(double &a, double &b);

int main (void){
    double a,b, resul;
    int i;
    
    for(i=1;i<=2;i++){
       pedir_nros(a, b);
       resul = pow(a,b);
       printf("\n La potencia es %f\n", resul);	
    }
    system("pause");
    
    return(0);
}
void pedir_nros(double a, double b){
  printf("\n Ingrese un numero: ");
  scanf("%f", &a);
  printf("\n Ingrese segundo numero: ");
  scanf("%f", &b);
}


