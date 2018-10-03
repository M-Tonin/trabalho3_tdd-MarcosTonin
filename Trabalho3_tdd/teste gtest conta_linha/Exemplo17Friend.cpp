//Exemplo de Friend
#include <iostream>
#include <string.h>

using namespace std;
class Pessoa;
class Turma
{

public:
    void metodo(Pessoa *pessoa);
    //void metodoNaoFriend(Pessoa *pessoa);
};
class Pessoa {
    char nome[30];
    int idade;
public:
    Pessoa()
    {
        nome[0] = '\0';
        idade = 0;
    }
    Pessoa(const char *argNome, int argIdade)
    {
        strcpy(nome, argNome);
        idade = argIdade;
    }
    //como calcularMedia está declarada como friend dentro de Pessoa, esta função pode acessar os membros privados da classe Pessoa
    friend void calcularMedia(Pessoa *pessoas,  int tamanhoVetor);
    //note que você pode tormar métodos de classes como friend
    friend void Turma::metodo(Pessoa *pessoa);
    //Ou ainda, uma classe inteira como friend.
    friend Turma;
};
void Turma::metodo(Pessoa *pessoa)
{
    cout << "Nome: " << pessoa->nome << ", idade: " << pessoa->idade << endl;
}
//Só funciona se a classe ou o método for friend.
//void Turma::metodoNaoFriend(Pessoa *pessoa)
//{
//    cout << "Nome: " << pessoa->nome << ", idade: " << pessoa->idade << endl;
//}
void calcularMedia(Pessoa *pessoas,  int tamanhoVetor)
{
    float media;

    for(int i = 0; i < tamanhoVetor; i++)
        media += pessoas[i].idade;
    media /= tamanhoVetor;
    cout << "Idade media: " << media << endl;
}


int main()
{
    //Compatível apenas com o C++2011,  e depende de existir um construtor com os argumentos utilizados.
    Pessoa pessoas[5] = {{ "Pessoa 1", 20}, { "Pessoa 2", 25}, { "Pessoa 3", 30}, { "Pessoa 4", 35}, { "Pessoa 5", 40}};
    calcularMedia(pessoas, 5);

    Turma turma;
    turma.metodo(&pessoas[3]);
    return 0;
}
