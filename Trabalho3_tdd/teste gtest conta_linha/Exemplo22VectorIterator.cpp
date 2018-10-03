//Exemplo de Vector com Iterator
#include <iostream>
#include <vector>
using namespace std; //o vector está no namespace STD
const int NUMERONOTAS = 4;


int main()
{
    vector<float> notas(NUMERONOTAS);
    // Criamos um iterador do contêiner vector
    vector<float>::iterator itr;

    float soma = 0;
    notas[0] = 89.0f;
    notas[1] = 29.0f;
    notas[2] = 59.0f;
    notas[3] = 79.0f;
    //para adicionar elementos além do tamanho definido, use push_back
    notas.push_back(79.0f);

    cout << "Número de notas: " << notas.size() << endl;
    for(itr = notas.begin(); itr != notas.end(); itr++)
        cout << "Informacao: " << *itr << endl;

    for(itr = notas.begin(); itr != notas.end(); itr++)
        soma += *itr;

    cout << "A media e " << soma/NUMERONOTAS << endl;
	return 0;
}

