//Exemplo de vector
#include <iostream>
#include <vector>
using namespace std; //o vector está no namespace STD
const int NUMERONOTAS = 4;

int main()
{
    vector<float> notas(NUMERONOTAS);
    float soma = 0;

    notas[0] = 89.0f;
    notas[1] = 29.0f;
    notas[2] = 59.0f;
    notas[3] = 79.0f;
    for(int indice = 0; indice < notas.size(); indice++)
        soma += notas[indice];
    cout << "A media e " << soma/NUMERONOTAS << endl;
	return 0;
}

