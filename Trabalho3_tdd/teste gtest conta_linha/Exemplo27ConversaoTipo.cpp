#include <iostream>
#include <string.h>
#include <stdio.h>
#include <typeinfo>

using namespace std;
class Pessoa
{
public:
    //se a classe não conter nenhum método virtual, ela é considerada como "não polimófica" pelo compilador
    //e o dynamic cast não funciona (nem o typeid funciona corretamente)
    virtual void mostrar()
    {
        cout << "É uma Pessoa.\n";
    }
};
class Engenheiro : public Pessoa
{
public:
    void mostrar()
    {
        cout << "É um Engenheiro.\n";
    }
};
class Medico : public Pessoa
{
public:
    void mostrar()
    {
        cout << "É um Medico.\n";
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

    //Conversão Explícita: não verifica em tempo de compilação/execução a conversão. Seja o que deus quiser :).
    //Este cast tenta diversos casts (static_cast, const_cast e reinterpret_cast) assim, se nenhum outro funcionar, utiliza o reinterpret_cast.
    //Coisa *coisa = (Coisa*)(pessoa); //não gera erros em tempo de compilação.

    //static_cast: verifica  em tempo de compilação se é possível que a conversão esteja correta (um objeto para onde pessoa aponta PODERIA ser um médico?)
    //Medico *c = static_cast<Medico*>(pessoa);  //não gera erro em tempo de compilação, pois essa conversão poderia ser válida.
    //Coisa *coisa = static_cast<Coisa*>(pessoa);  //gera erro em tempo de compilação, pois em todas as situações isso é impossível.


    //dynamic_cast: verifica em tempo de execução se é possível converter um tipo em outro, retornando nulo caso contrário.
    //Engenheiro * p = dynamic_cast<Engenheiro *>(pessoa);

    //const_cast: é usado para converter uma váriável que originalmente era não era const para ser tipo original.
    //int i = 0;
    //const int* ptr = &i;
    //*const_cast<int*>(ptr) = 3;

    //reinterpret_cast: utilizado para reinterpretar a memória de uma maneira diferente. Exemplo:
    //float a = 12;
    //int b = *reinterpret_cast<int*>(&a);


    //Assim,
    //enquanto Medico *c = static_cast<Medico*>(pessoa); não verifica o tipo em tempo de execução, e sim em tempo de compilação (é possível que uma pessoa seja um médico)
    //Medico *c = dynamic_cast<Medico*>(pessoa); verifica em tempo de execução, retornando nulo caso não seja possível a conversão.


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

    //typeid irá identificar apenas a classe exata, e não a superclasse.
    //note que a superclasse deve ter ao menos um método virtual para isso funcionar corretamente.
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
