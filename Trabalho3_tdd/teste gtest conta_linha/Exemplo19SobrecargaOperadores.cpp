//Exemplo de Sobrecarga de Operadores
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Produto
{
    int numero;
public:
    char *nome;
    Produto(const char *argNome, int argNumero)
    {
        nome = new char[50];
        strcpy(nome,argNome);
        numero = argNumero;
        //cout << "Construtor de " << nome << " chamado." << endl;
    }
    ~Produto()
    {
        //cout << "Destrutor de " << nome << " chamado." << endl;
        delete nome;
    }

    //sobrecarga do operado pré-fixado unário ++, exemplo: ++produto;
    Produto &operator++() //(void)
    {
        numero++;
        cout << "Operador pre-fixado ++ usado (unario)." << endl;
        return *this; //retornamos este objeto
    }

    //sobrecarga do operado pos-fixado unário ++, exemplo: produto++;
    Produto &operator++(int) //o int indica que é pós-fixado.
    {
        numero++;
        cout << "Operador pos-fixado ++ usado (unario)." << endl;
        return *this; //retornamos este objeto
    }

    //sobrecarregado o <<, usado pelo cout
    //temos que usar uma função externa (neste caso friend)
    //pois o Produto é o segundo parâmetro, não o primeiro
    //Note que o uso do friend é útil para deixar claro que este operador está
    //sendo sobrecarregado e que a função amiga terá acesso aos membro privados e protegidos
    //desta classe.
    friend ostream &operator<<(ostream &stream, const Produto &produto);

    //sobrecarregados o >>, usado pelo cin
    //temos que usar uma função externa (neste caso friend)
    //pois o Produto é o segundo parâmetro, não o primeiro
    friend istream &operator>>(istream &stream, Produto &produto);

    //sobrecarga do operador []
    char operator[](int indice)
    {
        return nome[indice];
    }

    //construtor de cópia
    //O construtor de cópia é chamado quando um novo objeto é
    //CRIADO com base em um objeto existente
    Produto(const Produto &produto)
    {
        nome = new char[50];
        strcpy(nome,produto.nome);
        numero = produto.numero;
        cout<<"Construtor de copia usado em " << this->nome << "."<<endl;
    }

    //sobrecarga do operador =
    //o operador = é chamado quando um objeto já existente
    //é associado a outro objeto através do =.
    Produto &operator=(const Produto &produto)
    {
        cout << "Operador = usado em " << this->nome << " para " << produto.nome << "." <<  endl;
        strcpy(nome,produto.nome);
        numero = produto.numero;
        return *this;
    }

    //sobrecarga do operador + (recebendo um produto)
    Produto operator+(const Produto &produto)
    {
        Produto produtoTmp("Soma de dois produtos", numero + produto.numero);
        cout << "Operador + usado para somar dois produtos: " << this->nome << " e " << produto.nome << "." <<  endl;
        return produtoTmp;
    }
    //sobrecarga do operador + (recebendo um inteiro)
    Produto operator+(const int argNumero)
    {
        Produto produtoTmp("Soma de um produto com um inteiro", numero + argNumero);
        cout << "Operador + usado para somar um produto com um inteiro: " << this->nome << " e " << argNumero << "." <<  endl;
        return produtoTmp;
    }
    //sobrecarga do operador + (recebendo um inteiro e um produto)
    //friend Produto operator+(const int argNumero, Produto produto);
};
//sobrecarga do operador + (recebendo um inteiro e um produto)
/*
Produto operator+(const int argNumero, Produto produto)
{
    Produto produtoTmp("Soma de um produto com um inteiro", produto.numero + argNumero);
    cout << "Operador + usado para somar um inteiro com um produto: " << produto.nome << " e " << argNumero << "." <<  endl;
    return produtoTmp;
}//*/
ostream &operator<<(ostream &stream, const Produto &produto)
{
    stream << "Operador << usado (binario): ";
    stream << produto.nome << " , " << produto.numero << endl;
    return stream;
}

istream &operator>>(istream &stream, Produto &produto)
{
    cout << "Operador >> usado (binario)." << endl;
    fflush(stdin);
    stream.getline(produto.nome,50);
    stream >> produto.numero;
    return stream;
}
int main()
{
    int a = 1;
    int &b = a;
    cout << "Endereco de a: " << &a << endl;
    cout << "Endereco de b: " << &b << endl;

    Produto produto("Computador", 10);
    /*
    //Usamos agora diversos tipos de operadores sobrecarregados
    cout << "1) " << produto; //sobrecarga do <<
    //////////////////////////////////////
    ++produto; //sobrecarga do ++ pré-fixado
    cout << "2) " <<produto; //sobrecarga do <<
    ///////////////////////////////////////
    produto++; //sobrecarga do ++ pós-fixado
    cout << "3) " <<produto; //sobrecarga do <<
    ///////////////////////////////////////
    cout << "4) " <<produto[0] << produto[1] << produto[2] << produto[3] << endl; //sobrecarga do []
*/
    Produto produtoB("Computador Usando Operador=", 10);
    /*
    produtoB = produto; //o operador = é chamado quando um objeto já existente é associado a outro objeto através do =.
    ++produtoB;
    cout << "5) " << produtoB;
    */
    ///////////////////////////////////////
    Produto produtoC = produto; //O construtor de cópia é chamado quando um novo objeto é CRIADO com base em um objeto existente
    /*
    produtoC++;
    cout << "6) " << produtoB;
    */
    ///////////////////////////////////////
    Produto produtoD = produtoC + produtoB;
    /*
    cout << "7) " << produtoD; //sobrecarga do <<
    ///////////////////////////////////////
    Produto produtoE = produtoC + 10;
    cout << "8) " << produtoE; //sobrecarga do <<
    ///////////////////////////////////////
    cin >> produto; //sobrecarga do >>
    cout << "9) " <<produto; //sobrecarga do <<

    //Erro! Qual o motivo?
    //Produto produtoF = 10 + produtoC;
    */
	return 0;
}
