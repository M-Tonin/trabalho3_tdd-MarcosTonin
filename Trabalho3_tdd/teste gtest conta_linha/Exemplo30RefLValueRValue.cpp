#include <string>
#include <iostream>
#include <utility>

//Operador(ou declarador) de referência Lvalue: &
//Operador(ou declarador) de referência Rvalue: &&

//ATENÇÃO: Para utilizar o operador &&, você deve habilitar "Have g++ follow the C++11  ISO language standard."
//localizado em Setting->Compiler
using namespace std;

class Pessoa
{
public:
    string nome;
    short idade;
    Pessoa() : nome("Nenhum"){}
};

void recebeRefLValue(Pessoa &refValue)
{
    //...
}


void sobreCarga(Pessoa&& refValue)
{
    cout << "sobreCarga(Pessoa &&refValue)" << endl;
}
void sobreCarga(const Pessoa &refValue)
{
    cout << "sobreCarga(Pessoa &refValue)" << endl;
}
Pessoa pegaValor()
{
    Pessoa pessoaSeraDestruida;
    pessoaSeraDestruida.idade = 10;
    //return move(pessoaSeraDestruida);
    return pessoaSeraDestruida;
}
int main()
{
   Pessoa meuAmigo;

   // Refferencia para meuAmigo
   Pessoa &refMeuAmigo = meuAmigo;

   // Atualizamos o meu amigo original através da referência.
   refMeuAmigo.nome = "Philip J. Fry";
   refMeuAmigo.idade = 1025; //logo após ele ser descongelado (depois disso fica muito confuso saber sua idade exata).

   cout << meuAmigo.nome << " tem " << meuAmigo.idade << " anos. " << endl;
   //Erro! Estamos tentando passar um RValue para uma função que recebe uma Ref LValue
   //recebeRefLValue(Pessoa());

   //Ok. Estamos passando para a função um LValue, e a função recebe um Ref. LValue.
   recebeRefLValue(refMeuAmigo);

   //Se não existir a versão "void sobreCarga(Pessoa&& refValue)", a linha abaixo retornará erro.
   //sobreCarga(Pessoa());

   //Se não existir a versão "void sobreCarga(const Pessoa& refValue)", a linha abaixo retornará erro.
   sobreCarga(meuAmigo);

   //Será compatível com qualquer uma das 2 versões de sobrecarga.
   //Se ambas estiverem definidas, ele irá chamar a versão com &&.

   //O std::move é usado para indicar que os dados de meuAmigo podem ser movidos, permitindo uma transferência eficiente do recursos de meuAmigo para outro objeto.
   sobreCarga(move(meuAmigo));

    //Pessoa &p = pegaValor(); // ERRO!, pois o valor retornado é um RValue.
    Pessoa p = pegaValor();
    cout << p.idade << endl;
}
