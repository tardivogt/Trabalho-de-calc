#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define log10(x) log(x)/log(10);

int main1();

int main2();

int main (void )
{
  int valor;
  
  printf ("Escolher um Metodo para chamar 1 para funcao da Bisseccao e 2 para metodo de Newton: ");
  scanf("%d", &valor);
  fflush(stdin);
  switch ( valor )
  {
            case 1: // chama funcao da biseccao
                printf("chama a funcao Bisseccao: ");
          			main1();
			break;
                case 2: // chama a funcao de newton
                printf("chama a funcao de Newton: ");
          			main2();
			break;
    
    default :
    printf ("Valor invalido!\n");
  }
  
  return 0;
}


float f(float x) {
   return pow(x,2)-4; // Função a qual a raiz deve ser determinada
}

//Método da Bissecção

int main1() {
   
   // erro: erro
   // a0 e b0: pontos iniciais
   // tamint: tamanho do intervlao
   // pm: ponto médio
   // ni: número de interações
   
   float erro, a0, b0, tamint, pm, ni; 
   int bolzano_ok = 0; //teorema dos valores intermediarios
   
   printf("Digite a precisão requerida: \n");
   scanf("%f",&erro);

   printf("Digite o intervalo onde deve se buscar a raiz (ex. [0;5] = digite 0 5): \n");
   scanf("%f %f",&a0,&b0);

   // O teorema dos valores intermediarios foi satisfeito? 
   // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado, no entanto, existe raiz nele?
    bolzano_ok = (f(a0)*f(b0) > 0?0:1);

   // Não? Fazer um novo intervalo inicial.
   while(bolzano_ok == 0) {
      printf("\nIntervalo [%f;%f] não satisfaz as condições do teorema dos valores intermediarios. Tente outro.\n Intervalo: ",a0,b0);
      scanf("%f %f", &a0, &b0);
      bolzano_ok = (f(a0)*f(b0) > 0?0:1);
   }

   // Iteraçõs necessárias

   ni = log10(b0 - a0);
   ni -= log10(erro);
   ni /= log(2);

   printf("Serão necessárias %.0f interações.\n",ceil(ni));

   // Um dos ex do intervalo é a raiz
   if(f(a0) == 0 || f(b0) == 0)  {
      printf("O valor %f é zero da expressão. \n", f(a0)==0?a0:b0);
      return 0;
   }

   //Método da bisecção


  while(tamint > erro) {
    tamint = b0-a0;
    pm = (a0+b0)/2;
    if(f(pm) == 0) {
        printf("SOLUÇÃO EXATA ENCONTRADA!! x = %f\n",pm);   
        return 0;
    }

    if(f(a0)*f(pm) < 0)  b0 = pm; //resolução está a esquerda
    else a0 = pm;  //resolução está a direita
    
  }
   
   printf("Intervalo final: [%f,%f]\n Solução aproximada: %f",a0,b0,(a0+b0)/2);

   return 0;
}


  //Metodo de Newton
	float Abs( float x ){

	x = ( x * x ) / -(x);
    return x;

	}
int main2(){

  float solucao = 0., xinicio = 0., xinicial = 0., Fxinicial = 0., 
  Fdxinicial = 0., E = 0.;// Fdxinicio = derivada de Fxinicio
  int k = 0;

  printf( "Digite o x inicial: " );
  scanf( "%f", &xinicial );
  printf( "Digite a precisao: " );
  scanf( "%f", &E );
  
    do{
        
        xinicio = xinicial;
        Fxinicial = ( xinicio * xinicio * xinicio ) - 9. * xinicio + 3.; //colocar a função principal
        Fdxinicial = 3. * ( xinicio * xinicio ) - 9.; //colocar derivada da função principal
        xinicial = xinicio - ( Fxinicial / Fdxinicial );
        k += 1;
        printf( "\niteracao = %d", k );
        printf( "\nxinicio = %f\nxinicial = %f", xinicio, xinicial );

    } while( Abs( xinicial - xinicio ) >= E || Abs( Fxinicial ) >= E );
	
  printf( "\n\nxinicial - xinicio = %f\n", xinicial - xinicio);
  printf( "A solucao final eh: %f\n", xinicial );
  
  return 0;
}
