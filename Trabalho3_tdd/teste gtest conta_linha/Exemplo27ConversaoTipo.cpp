#include <iostream>
#include <string.h>
#include <stdio.h>
#include <typeinfo>

using namespace std;
class Pessoa
{
public:
    //se a classe n�o conter nenhum m�todo virtual, ela � considerada como "n�o polim�fica" pelo compilador
    //e o dynamic cast n�o funciona (nem o typeid funciona corretamente)
    virtual void mostrar()
    {
        cout << "� uma Pessoa.\n";
    }
};
class Engenheiro : public Pessoa
{
public:
    void mostrar()
    {
        cout << "� um Engenheiro.\n";
    }
};
class Medico : public Pessoa
{
public:
    void mostrar()
    {
        cout << "� um Medico.\n";
    }
};
class Coisa
{

};
int main()
{
    Pessoa *pessoa;
    Engenheiro engenheiro;
    Medico medico;

    pessoa = &engenheiro;

    //Convers�o Expl�cita: n�o verifica em tempo de compila��o/execu��o a convers�o. Seja o que deus quiser :).
    //Este cast tenta diversos casts (static_cast, const_cast e reinterpret_cast) assim, se nenhum outro funcionar, utiliza o reinterpret_cast.
    //Coisa *coisa = (Coisa*)(pessoa); //n�o gera erros em tempo de compila��o.

    //static_cast: verifica  em tempo de compila��o se � poss�vel que a convers�o esteja correta (um objeto para onde pessoa aponta PODERIA ser um m�dico?)
    //Medico *c = static_cast<Medico*>(pessoa);  //n�o gera erro em tempo de compila��o, pois essa convers�o poderia ser v�lida.
    //Coisa *coisa = static_cast<Coisa*>(pessoa);  //gera erro em tempo de compila��o, pois em todas as situa��es isso � imposs�vel.


    //dynamic_cast: verifica em tempo de execu��o se � poss�vel converter um tipo em outro, retornando nulo caso contr�rio.
    //Engenheiro * p = dynamic_cast<Engenheiro *>(pessoa);

    //const_cast: � usado para converter uma v�ri�vel que originalmente era n�o era const para ser tipo original.
    //int i = 0;
    //const int* ptr = &i;
    //*const_cast<int*>(ptr) = 3;

    //reinterpret_cast: utilizado para reinterpretar a mem�ria de uma maneira diferente. Exemplo:
    //float a = 12;
    //int b = *reinterpret_cast<int*>(&a);


    //Assim,
    //enquanto Medico *c = static_cast<Medico*>(pessoa); n�o verifica o tipo em tempo de execu��o, e sim em tempo de compila��o (� poss�vel que uma pessoa seja um m�dico)
    //Medico *c = dynamic_cast<Medico*>(pessoa); verifica em tempo de execu��o, retornando nulo caso n�o seja poss�vel a convers�o.


    cout << "1) pessoa = &engenheiro;" << endl;
    if(dynamic_cast<Engenheiro *>(pessoa) != NULL)
    {
       cout << "1) Esta pessoa e um Engenheiro." << endl;
       //p->mostrar();
    } else
    {
       cout << "1) Esta pessoa nao e um Engenheiro." << endl;
    }

    pessoa = &medico;
    //Engenheiro * p = dynamic_cast<Engenheiro *>(pessoa);

    cout << "2) pessoa = &medico;" << endl;
    if(dynamic_cast<Medico *>(pessoa) != NULL)
    {
       cout << "2) Esta pessoa e um Medico." << endl;
       //p->mostrar();
    } else
    {
       cout << "2) Esta pessoa nao e um Medico." << endl;
    }

    if(dynamic_cast<Pessoa *>(pessoa) != NULL)
    {
       cout << "3) Esta pessoa e uma Pessoa." << endl;
       //p->mostrar();
    } else
    {
       cout << "3) Esta pessoa nao e uma Pessoa." << endl;
    }

    //typeid ir� identificar apenas a classe exata, e n�o a superclasse.
    //note que a superclasse deve ter ao menos um m�todo virtual para isso funcionar corretamente.
    if(typeid(*pessoa) == typeid(Pessoa))
    {
       cout << "4) typeid(pessoa) == typeid(Pessoa)." << endl;
       //p->mostrar();
    } else if(typeid(*pessoa) == typeid(Engenheiro))
    {
       cout << "4) typeid(pessoa) == typeid(Engenheiro)." << endl;
       //p->mostrar();
    } else if(typeid(*pessoa) == typeid(Medico))
    {
       cout << "4) typeid(pessoa) == typeid(Medico)." << endl;
       //p->mostrar();
    }
    return 0;
}
