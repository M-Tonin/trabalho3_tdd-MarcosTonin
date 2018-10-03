//Exemplo de Modelo de Função
#include <iostream>

using namespace std;

class MinhaClasse
{
public:
    int numero;
    MinhaClasse(int argNumero) : numero(argNumero) { }
    //sobrecarga do operado pos-fixado unário ++, exemplo: produto++;
    MinhaClasse &operator++(int) //o int indica que é pós-fixado.
    {
        numero++;
        return *this; //retornamos este objeto
    }
};

//o modelo de função faz com que a função possa usar livremente o tipo genérico T.
template<class T> //ou template<typename T>
void adicionaUm(T &valor)
{
    cout << "Usou T &adicionaUm(T &t)." << endl;
    valor++;
}

//repare que neste caso, o compilador irá usar a função mais específica.
void adicionaUm(int &valor)
{
    cout << "Usou int &adicionaUm(int &t)." << endl;
    valor++;
}

int main()
{
    int numeroMainInt = 2;
    adicionaUm(numeroMainInt);
    cout << "numeroMainInt: " << numeroMainInt << endl;

    float numeroMainFloat = 2.2;
    adicionaUm(numeroMainFloat);
    cout << "numeroMainFloat: " << numeroMainFloat << endl;

    MinhaClasse minhaClasse(10);

    adicionaUm(minhaClasse);
    cout << "MinhaClasse.numero: " << minhaClasse.numero << endl;

	return 0;
}
