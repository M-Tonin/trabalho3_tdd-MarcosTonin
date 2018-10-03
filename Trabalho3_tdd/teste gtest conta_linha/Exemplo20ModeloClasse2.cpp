//Exemplo de Modelo de Classe 2
#include <iostream>
//#include <typeinfo> //para usar o typeid(VarGen).name(), mas não é garantido que o resultado será legível.

using namespace std;


//Template de classe
template<class VarGen>
class ModeloPai
{
    VarGen variavelGenerica;
public:
    ModeloPai(VarGen &argVariavel);

    void imprime()
    {
        cout << "Pai Generico: Valor da variavel generica: " << variavelGenerica << "." << endl;
    }
};
//Exemplo de definição do método fora da classe
template<class VarGen>
ModeloPai<VarGen>::ModeloPai(VarGen &argVariavel)
{
    variavelGenerica = argVariavel;
}


//Especialização do template de classe
template<>
class ModeloPai<float>
{
    int variavelFloat;
public:
    ModeloPai(float argVariavel);
    void imprime()
    {
        cout << "Pai Especializado: Valor da variavel float: " << variavelFloat << "." << endl;
    }
};
//Exemplo de definição do método (de classe especializada) fora da classe
ModeloPai<float>::ModeloPai(float argVariavel)
{
    variavelFloat = argVariavel;
}


//Filha Genérica, Pai genérico
template<class VarGen>
class ClasseFilha1 : public ModeloPai<VarGen>
{
    public:
    ClasseFilha1(VarGen &varGen) : ModeloPai<VarGen>::ModeloPai(varGen)
    {
        cout << "Filha Generica." << endl;
    };
};


//Filha especializada, pai genérico
template<>
class ClasseFilha1<int> : public ModeloPai<int>
{
    public:
    ClasseFilha1(int &varGen) : ModeloPai<int>::ModeloPai(varGen)
    {
        cout << "Filha Especializada." << endl;
    };
};



//Filha especializada, pai especializado
template<>
class ClasseFilha1<float> : public ModeloPai<float>
{
    public:
    ClasseFilha1(float &varGen) : ModeloPai<float>::ModeloPai(varGen)
    {
        cout << "Filha Especializada." << endl;
    };
};

int main()
{
    //criamos as variáveis.
    int numeroMainInt = 2;
    float numeroMainFloat = 2.2;
    double numeroMainDouble = 2002.2;

    //Usa a classe ModeloPai
    ModeloPai<int> modeloIntInt(numeroMainInt);
    modeloIntInt.imprime();
    cout << endl;

    //Usa a versão especializada de ModeloPai
    ModeloPai<float> espModeloClasse(15.0f);
    espModeloClasse.imprime();
    cout << endl;

    numeroMainInt += 100;
    //Usa a versão especializada da classe Filha, mas a versão genérica da classe pai.
    ClasseFilha1<int> filhaInt(numeroMainInt);
    filhaInt.imprime();
    cout << endl;

    //Usa filha genérica e pai genérico.
    ClasseFilha1<double> filhaDouble(numeroMainDouble);
    filhaDouble.imprime();
    cout << endl;

    //Usa filha especializada e pai especializado.
    ClasseFilha1<float> filhaFloat(numeroMainFloat);
    filhaFloat.imprime();

	return 0;
}
