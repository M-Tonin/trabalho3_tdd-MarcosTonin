//Exemplo de Vector (sort)
#include <iostream>
#include <vector>
#include <algorithm> //usado pelo sort()

using namespace std; //o vector está no namespace STD

class Pessoa
{
    int idade;
public:
    string nome;
    void mostrar()
    { cout << "Nome: " << nome << ", idade: " << idade << endl; }
    Pessoa(const string n, int id)
    { nome = n; idade = id; }
    //compara 2 objetos do tipo Pessoa
    //esta função é usada pelo algoritmo sort.
    friend bool operator<(const Pessoa &pessoa1, const Pessoa &pessoa2);
};
//compara 2 objetos do tipo Pessoa
//esta função é usada pelo algoritmo sort.
bool operator<(const Pessoa &pessoa1, const Pessoa &pessoa2) {
    if(pessoa1.idade < pessoa2.idade)
        return true;
    else
        return false;
}


int main()
{
    vector<Pessoa> pessoas;
    // Criamos um iterador do contêiner vector
    vector<Pessoa>::iterator itr;
    pessoas.push_back(Pessoa("Aluno1", 30));
    pessoas.push_back(Pessoa("Aluno2", 20));
    pessoas.push_back(Pessoa("Aluno3", 25));
    //ordenamos, que utiliza a sobrecarga do operador < do objeto.
    sort(pessoas.begin(), pessoas.end());

    for(itr = pessoas.begin(); itr != pessoas.end(); itr++)
        cout << "Informacao: " << (itr)->nome << endl;

	return 0;
}

