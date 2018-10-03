//Exemplo de Pilha (LIFO) (stack)
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std; //o stack está no namespace STD
int main()
{
    //criamos uma pilha
    stack<int> numeros;
    int elemento;
    //adicionamos elementos na pilha
    numeros.push(10);
    numeros.push(20);
    numeros.push(30);

    cout << "Exemplo de Pilha:" << endl;
    elemento = numeros.top();
    cout << "O primeiro a sair e o: " << elemento << endl;
    numeros.pop();
    elemento = numeros.top();
    cout << "O segundo a sair e o: " << elemento << endl;
    numeros.pop();
    elemento = numeros.top();
    cout << "O terceiro a sair e o: " << elemento << endl;
    numeros.pop();
	return 0;
}

