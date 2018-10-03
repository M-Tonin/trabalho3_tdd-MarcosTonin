#include <iostream>
#include <string.h>
#include <stdio.h>
/*
1. Crie uma classe "Produto" contendo seu nome e quantidade.
Sobrecarregue o operador + para que seja poss�vel somar dois produtos.
*/




using namespace std;


class Produto {
public:
	int quantidade;
	Produto(const Produto &p)
	{
	    this->quantidade = p.quantidade;
	    cout << "(const Produto &p) " << this << endl;
	}
	Produto () { cout << "() " << this << endl; }
	Produto(int _quantidade) {
	    cout << "(char *_nome, int _quantidade) " << this << endl;
		quantidade = _quantidade;
	}
	Produto &operator++(int) {
	    quantidade++;
	    return *this;
	}
    Produto &operator=(const Produto &produto)
    {
        cout << "Operador = usado." <<  endl;
        quantidade = produto.quantidade;
        return *this;
    }
};

int main()
{
	Produto produto1(10);
	//produto1++; //se usarmos "Produto operator++(int)", o construtor de c�pia ser� chamado para retornar o produto
                //se usarmos "Produto &operator++(int)", nenhum construtor ser� chamado pois o retorno � o pr�prio objeto

    //& � chamado de operador refer�ncia


    //Se utilizarmos "Produto operator++(int)", a linha abaixo ir� retornar um erro, pois estamos criando uma refer�ncia de uma vari�vel
    //tempor�ria criada para retornar a fun��o.
    //Se utilizarmos "Produto &operator++(int)", a linha abaixo ir� funcionar normalmente, entendo que o retorno da fun��o � o pr�prio
    //produto1, e que produto2 � um sin�nimo de produto1. N�o ser� chamado ent�o o construtor de c�pia.
	Produto &produto2 = produto1++;

    //Independente de utilizamos "Produto operator++(int)" ou "Produto &operator++(int)", o contrutor de c�pia ser� chamado.
    //na primeira situa��o, ele ser� chamado pois seria necess�rio retornar um novo objeto.
    //Na segunda situa��o, ele ser� chamado pois produto3 � um novo objeto com base em um j� existente.
	Produto produto3 = produto1++;

	cout << &produto1 << endl;
	cout << &produto2 << endl;
	cout << &produto3 << endl;
	cout << produto2.quantidade << endl;
	cout << produto3.quantidade << endl;

	return 0;
}
