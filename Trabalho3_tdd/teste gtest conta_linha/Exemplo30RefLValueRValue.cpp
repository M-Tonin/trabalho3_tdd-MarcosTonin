#include <string>
#include <iostream>
#include <utility>

//Operador(ou declarador) de refer�ncia Lvalue: &
//Operador(ou declarador) de refer�ncia Rvalue: &&

//ATEN��O: Para utilizar o operador &&, voc� deve habilitar "Have g++ follow the C++11  ISO language standard."
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

   // Atualizamos o meu amigo original atrav�s da refer�ncia.
   refMeuAmigo.nome = "Philip J. Fry";
   refMeuAmigo.idade = 1025; //logo ap�s ele ser descongelado (depois disso fica muito confuso saber sua idade exata).

   cout << meuAmigo.nome << " tem " << meuAmigo.idade << " anos. " << endl;
   //Erro! Estamos tentando passar um RValue para uma fun��o que recebe uma Ref LValue
   //recebeRefLValue(Pessoa());

   //Ok. Estamos passando para a fun��o um LValue, e a fun��o recebe um Ref. LValue.
   recebeRefLValue(refMeuAmigo);

   //Se n�o existir a vers�o "void sobreCarga(Pessoa&& refValue)", a linha abaixo retornar� erro.
   //sobreCarga(Pessoa());

   //Se n�o existir a vers�o "void sobreCarga(const Pessoa& refValue)", a linha abaixo retornar� erro.
   sobreCarga(meuAmigo);

   //Ser� compat�vel com qualquer uma das 2 vers�es de sobrecarga.
   //Se ambas estiverem definidas, ele ir� chamar a vers�o com &&.

   //O std::move � usado para indicar que os dados de meuAmigo podem ser movidos, permitindo uma transfer�ncia eficiente do recursos de meuAmigo para outro objeto.
   sobreCarga(move(meuAmigo));

    //Pessoa &p = pegaValor(); // ERRO!, pois o valor retornado � um RValue.
    Pessoa p = pegaValor();
    cout << p.idade << endl;
}
