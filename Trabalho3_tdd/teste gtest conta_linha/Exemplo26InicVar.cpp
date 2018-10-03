#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class ExemploInicializacao
{
public:
    //Este construtor far� que o construtor padr�o n�o seja criado, n�o "zerando" automaticamente os atributos
    //ExemploInicializacao() { cout << "Objeto ExemploInicializacao criado.\n"; }

    //Este construtor ir� explicitamente zerar o vetor valores.
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
    //o objeto "objetoSempreZero" ser� zerado se n�o existir um construtor definido
    ExemploInicializacao *objetoSempreZero = new ExemploInicializacao(); //com as (), voc� est� indicando que quer que os dados sejam inicializados pelo construtor
    ExemploInicializacao *objetoQualquerValor = new ExemploInicializacao; //sem as (), voc� est� indicando que n�o se importa se o construtor padr�o ser� chamado ou n�o
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

    //vari�veis locais primitivas n�o s�o zeradas automaticamente
    int valoresNaoZerados[50];
    cout << "\nvaloresNaoZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << valoresNaoZerados[i];

    //o indicar um elemento (ou simplesmente {}), for�amos que os dados sejam zerados
    int valoresZerados[50] = {0};
    cout << "\nvaloresZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << valoresZerados[i];

    //valores static s�o inicializados zerados.
    static int staticValoresZerados[50];
    cout << "\nstaticValoresZerados: ";
    for(int i = 0; i < 50; i++)
        cout  << " " << staticValoresZerados[i];

    //Qual ser� a sa�da? O ponteiro, se n�o fosse atribuido quaisquer valores seria nulo,
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
