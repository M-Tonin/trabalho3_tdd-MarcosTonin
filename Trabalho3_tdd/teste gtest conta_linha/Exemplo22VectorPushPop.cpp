//Exemplo de Vector (push e pop)
#include <iostream>
#include <vector>
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
};

int main()
{
    vector<Pessoa> notas;
    // Criamos um iterador do contêiner vector
    vector<Pessoa>::iterator itr;
    notas.push_back(Pessoa("Aluno1", 19));
    notas.push_back(Pessoa("Aluno2", 20));
    //adicionamos um aluno ao começo do vector
    notas.insert(notas.begin(),Pessoa("Aluno0", 18));
    //adicionamos um aluno ao final do vector
    notas.insert(notas.end(),Pessoa("Aluno3", 22));

    itr = notas.begin();
    notas.erase(itr+2); //remove o elemento na terceira posição
    for(itr = notas.begin(); itr != notas.end(); itr++)
        cout << "Informacao: " << (itr)->nome << endl;
	return 0;
}

