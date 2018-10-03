//Exemplo de Fila (FIFO) (queue)
#include <iostream>
#include <queue>

using namespace std; //o queue está no namespace STD
int main()
{
    //criamos uma fila
    queue<int> numeros;
    int elemento;
    //adicionamos elementos na fila
    numeros.push(10);
    numeros.push(20);
    numeros.push(30);

    cout << "Exemplo de Fila:" << endl;
    elemento = numeros.front();
    cout << "O primeiro a sair e o: " << elemento << endl;
    numeros.pop();
    elemento = numeros.front();
    cout << "O segundo a sair e o: " << elemento << endl;
    numeros.pop();
    elemento = numeros.front();
    cout << "O terceiro a sair e o: " << elemento << endl;
    numeros.pop();
	return 0;
}

