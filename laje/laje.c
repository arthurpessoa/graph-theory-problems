#include <stdio.h>
#include <stdlib.h>

/*
* Arthur Pessoa de Souza 380075
* Professor José Guimarães, Matemática discreta
*/

int mdc(int a,int b);

int main()
{
	int a,b;
	do{
		scanf("%d%d",&a,&b);
		int result=mdc(a,b);//Atribuo o valor do MDC entre os 2 valores
		if(!(a==0 && b==0))printf("%d\n",mdc(a,b)); //imprime caso não seja 0, 0
	}while(!(a==0 && b==0)); 
	return 0;
}
//Algoritmo de euclides
int mdc(int a,int b)
{
	while(b!=0){
		if(a<b){//troca se o primeiro numero é menor que o segundo
			int aux=a;
			a=b;
			b=aux;
		}
		int aux=b; //então aplica o algorítmo denovo pra mdc(b,a%b)
		b=a%b;
		a=aux;
	}
	return a; //retorna o mdc
}