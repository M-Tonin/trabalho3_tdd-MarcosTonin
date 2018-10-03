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

    //sobrecarga do operado pr�-fixado un�rio ++, exemplo: ++produto;
    Produto &operator++() //(void)
    {
        numero++;
        cout << "Operador pre-fixado ++ usado (unario)." << endl;
        return *this; //retornamos este objeto
    }

    //sobrecarga do operado pos-fixado un�rio ++, exemplo: produto++;
    Produto &operator++(int) //o int indica que � p�s-fixado.
    {
        numero++;
        cout << "Operador pos-fixado ++ usado (unario)." << endl;
        return *this; //retornamos este objeto
    }

    //sobrecarregado o <<, usado pelo cout
    //temos que usar uma fun��o externa (neste caso friend)
    //pois o Produto � o segundo par�metro, n�o o primeiro
    //Note que o uso do friend � �til para deixar claro que este operador est�
    //sendo sobrecarregado e que a fun��o amiga ter� acesso aos membro privados e protegidos
    //desta classe.
    friend ostream &operator<<(ostream &stream, const Produto &produto);

    //sobrecarregados o >>, usado pelo cin
    //temos que usar uma fun��o externa (neste caso friend)
    //pois o Produto � o segundo par�metro, n�o o primeiro
    friend istream &operator>>(istream &stream, Produto &produto);

    //sobrecarga do operador []
    char operator[](int indice)
    {
        return nome[indice];
    }

    //construtor de c�pia
    //O construtor de c�pia � chamado quando um novo objeto �
    //CRIADO com base em um objeto existente
    Produto(const Produto &produto)
    {
        nome = new char[50];
        strcpy(nome,produto.nome);
        numero = produto.numero;
        cout<<"Construtor de copia usado em " << this->nome << "."<<endl;
    }

    //sobrecarga do operador =
    //o operador = � chamado quando um objeto j� existente
    //� associado a outro objeto atrav�s do =.
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
    ++produto; //sobrecarga do ++ pr�-fixado
    cout << "2) " <<produto; //sobrecarga do <<
    ///////////////////////////////////////
    produto++; //sobrecarga do ++ p�s-fixado
    cout << "3) " <<produto; //sobrecarga do <<
    ///////////////////////////////////////
    cout << "4) " <<produto[0] << produto[1] << produto[2] << produto[3] << endl; //sobrecarga do []
*/
    Produto produtoB("Computador Usando Operador=", 10);
    /*
    produtoB = produto; //o operador = � chamado quando um objeto j� existente � associado a outro objeto atrav�s do =.
    ++produtoB;
    cout << "5) " << produtoB;
    */
    ///////////////////////////////////////
    Produto produtoC = produto; //O construtor de c�pia � chamado quando um novo objeto � CRIADO com base em um objeto existente
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
