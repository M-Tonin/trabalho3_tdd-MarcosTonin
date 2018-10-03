//Exemplo de Modelo de Classe
#include <iostream>
//#include <typeinfo> //para usar o typeid(VarGen).name(), mas não é garantido que o resultado será legível.

using namespace std;

class MinhaClasse
{
public:
    int numero;
    MinhaClasse(){}
    MinhaClasse(int argNumero) : numero(argNumero) { }
    //sobrecarga do operado pos-fixado unário ++, exemplo: produto++;
    MinhaClasse &operator++(int) //o int indica que é pós-fixado.
    {
        numero++;
        return *this; //retornamos este objeto
    }

    //sobrecarregados o <<, usado pelo cout
    //temos que usar uma função externa (neste caso friend) pois o Produto é o segundo parâmetro, não o primeiro
    friend ostream &operator<<(ostream &stream, const MinhaClasse &minhaClasse);
};

ostream &operator<<(ostream &stream, const MinhaClasse &minhaClasse)
{
    stream << minhaClasse.numero;
    return stream;
}

//Template de classe
template<class VarGen, typename VarGen2> //ou template<typename VarGen, typename VarGen2>
class ModeloClasse
{
    VarGen variavelGenerica;
    static int contador;
    //VarGen2 variavelGenerica2; //não usado nesta classe, apenas para ilustrar que é possível 2 tipos
public:
    ModeloClasse(VarGen &argVariavel)
    {
        variavelGenerica = argVariavel;
        contador++;
        cout << "contador: " << contador << endl;
    }

    void imprime()
    {
        cout << "Valor da variavel generica: " << variavelGenerica << "." << endl;
        variavelGenerica++;
        cout << "Valor da variavel generica + 1: " << variavelGenerica << "." << endl;
    }
};

template<class VarGen, typename VarGen2>
int ModeloClasse<VarGen, VarGen2>::contador = 0;

int main()
{
    //criamos as variáveis.
    int numeroMainInt = 2;
    float numeroMainFloat = 2.2;
    MinhaClasse minhaClasse(10);


    ModeloClasse<int, int> modeloIntInt(numeroMainInt);
    modeloIntInt.imprime();

    ModeloClasse<int, int> modeloIntInt2(numeroMainInt);
    modeloIntInt.imprime();

    ModeloClasse<float, int> modeloFloatFloat(numeroMainFloat);
    modeloFloatFloat.imprime();

    ModeloClasse<MinhaClasse, int> modeloMinhaClasseInt(minhaClasse);
    modeloMinhaClasseInt.imprime();

	return 0;
}
