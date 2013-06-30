/* 
 * Arquivo: t3-arthurps.c
 * Autor: Arthur Pessoa de Souza
 * RA: 380075 
 * Professor: José Guimarães
 * Created on 18 de Janeiro de 2013, 09:55
 */

#include <stdio.h>
#include <stdlib.h>

int ContaEstrela(register unsigned int N);

int main(){
    unsigned int N,x; //como a limitaçao é pra entradas com até 2^16, vou usar unsigned e escovar bits pra tentar melhorar (e de fato melhorou!)
    do {
        x=scanf("%d", &N);
        if(x != EOF){
            unsigned int i, Estrelas=0;
            printf("%d\n",ContaEstrela(N));           
        }
    } while (x != EOF);

    return 0;
}

/*Nessa função eu reaproveitei o algoritmo de listar primos do T1, a diferença é que agora eu 
faço para os primos em relação de N, então conto quantos coprimos eu tenho até N/2 e retorno*/
int ContaEstrela(register unsigned int N) {
    unsigned int *vetor = malloc(((N/2) + 1) * sizeof (unsigned int)); //Como eu só preciso marcar metade dos coprimos, posso alocar só metade de N
    unsigned int i, primo, multiplo;

    for (i = 2; i <= N/2; i++) {
        vetor[i] = 1; //limpo o vetor de checagem, assumindo que todos no intervalo são coprimos de N
    }
    /*agora verifico quem não é co-primo de N*/
    for (primo = 2; primo <= N/2; primo++){
        if (vetor[primo]) {
            if(N%primo==0){ //se o primo é multiplo de N, então ela não é coprimo de N
                vetor[primo] = 0;
                for (multiplo = 2 * primo; multiplo <= N/2; multiplo += primo) { //e todos os multiplos de N também não serão!
                    if (vetor[multiplo]) {
                        vetor[multiplo] = 0; //excluo ele da minha lista de primos
                    }
                }
            }
        }
    }

    /*Agora todos os que não foram marcados não são numeros */
    int Estrelas=0;
    if(N%1==0)Estrelas++;

    for (i = 2; i <= N/2; ++i) {
        if (vetor[i] && i <= N/2){ //vejo se o numero é primo e está dentro do intervalo
            Estrelas++;
        }
    }
    free(vetor); //libero o vetor alocado
    return Estrelas;
}