#include <iostream>
#include <string.h>
#include <stdio.h>
/*
1. Crie uma classe "Produto" contendo seu nome e quantidade.
Sobrecarregue o operador + para que seja possível somar dois produtos.
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
	//produto1++; //se usarmos "Produto operator++(int)", o construtor de cópia será chamado para retornar o produto
                //se usarmos "Produto &operator++(int)", nenhum construtor será chamado pois o retorno é o próprio objeto

    //& é chamado de operador referência


    //Se utilizarmos "Produto operator++(int)", a linha abaixo irá retornar um erro, pois estamos criando uma referência de uma variável
    //temporária criada para retornar a função.
    //Se utilizarmos "Produto &operator++(int)", a linha abaixo irá funcionar normalmente, entendo que o retorno da função é o próprio
    //produto1, e que produto2 é um sinônimo de produto1. Não será chamado então o construtor de cópia.
	Produto &produto2 = produto1++;

    //Independente de utilizamos "Produto operator++(int)" ou "Produto &operator++(int)", o contrutor de cópia será chamado.
    //na primeira situação, ele será chamado pois seria necessário retornar um novo objeto.
    //Na segunda situação, ele será chamado pois produto3 é um novo objeto com base em um já existente.
	Produto produto3 = produto1++;

	cout << &produto1 << endl;
	cout << &produto2 << endl;
	cout << &produto3 << endl;
	cout << produto2.quantidade << endl;
	cout << produto3.quantidade << endl;

	return 0;
}
