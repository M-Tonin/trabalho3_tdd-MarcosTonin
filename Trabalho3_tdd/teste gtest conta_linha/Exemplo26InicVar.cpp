#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class ExemploInicializacao
{
public:
    //Este construtor fará que o construtor padrão não seja criado, não "zerando" automaticamente os atributos
    //ExemploInicializacao() { cout << "Objeto ExemploInicializacao criado.\n"; }

    //Este construtor irá explicitamente zerar o vetor valores.
    //ExemploInicializacao() : valores() { cout << "Objeto ExemploInicializacao criado.\n"; }
    //ExemploInicializacao() : valores({50,51}) { cout << "Objeto ExemploInicializacao criado.\n"; }

    int valores[50];
    static int staticSempreZero[50];
};
int ExemploInicializacao::staticSempreZero[50];
static int staticSempreZero[50];
int sempreZero;

int main()
{
    //o objeto "objetoSempreZero" será zerado se não existir um construtor definido
    ExemploInicializacao *objetoSempreZero = new ExemploInicializacao(); //com as (), você está indicando que quer que os dados sejam inicializados pelo construtor
    ExemploInicializacao *objetoQualquerValor = new ExemploInicializacao; //sem as (), você está indicando que não se importa se o construtor padrão será chamado ou não
    int qualquerValor[50];

    cout << "ExemploInicializacao::staticSempreZero: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << ExemploInicializacao::staticSempreZero[i];

    cout << "\nobjetoSempreZero->valores: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << objetoSempreZero->valores[i];

    cout << "\nobjetoQualquerValor.valores";
    for(int i = 0; i < 50; i++)
        cout  << " " << objetoQualquerValor->valores[i];

    //variáveis locais primitivas não são zeradas automaticamente
    int valoresNaoZerados[50];
    cout << "\nvaloresNaoZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << valoresNaoZerados[i];

    //o indicar um elemento (ou simplesmente {}), forçamos que os dados sejam zerados
    int valoresZerados[50] = {0};
    cout << "\nvaloresZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << valoresZerados[i];

    //valores static são inicializados zerados.
    static int staticValoresZerados[50];
    cout << "\nstaticValoresZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << staticValoresZerados[i];

    //Qual será a saída? O ponteiro, se não fosse atribuido quaisquer valores seria nulo,
    //mas os dados internos da classe obedecem as outras regras descritas acima.
    static ExemploInicializacao *staticObjetoQualquerValor = new ExemploInicializacao;
    //static ExemploInicializacao *staticObjetoQualquerValor = new ExemploInicializacao();

    cout << "\nstaticObjetoQualquerValor->valores";
    for(int i = 0; i < 50; i++)
        cout  << " " << staticObjetoQualquerValor->valores[i];

    delete objetoSempreZero;
    delete objetoQualquerValor;
    return 0;
}
