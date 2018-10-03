//Exemplo de String
#include <iostream>
#include <string>


using namespace std;

int main()
{

    string str1;
    //string str2 = 'e'; //erro, não se pode atribuir um char ao criar a string
    string str2;
    //
    basic_string<char> str3;


    str2 = 'e'; //Ok
    cout << "size e length geram a mesma saida: " << str3.length() << "," << str3.size() << endl;

    str1 = "Primeira";
    str2 = "Segunda";
    str2 = str1; //copia a string da primeira na segunda
    str1 = "Nova";
    cout << str1 << "," << str2 << endl;
    cout << "Capacidade e tamanho máximo de str1: " << str1.capacity() << " , " << str1.max_size() << endl;
    str1 = "12345";
    cout << "Capacidade e tamanho máximo de str1: " << str1.capacity() << " , " << str1.max_size() << endl;
    str1 = "123456789";
    cout << "Capacidade e tamanho máximo de str1: " << str1.capacity() << " , " << str1.max_size() << endl;

    str2 = "123456789";
    if(str1.compare(str2) == 0)
        cout << "str1 e str2 sao iguais." << endl;
    str3 = str1 + " " + str2;
    cout << "str3:" << str3 << endl;
	return 0;
}

