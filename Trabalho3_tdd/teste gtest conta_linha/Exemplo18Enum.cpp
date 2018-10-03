//Exemplo de Enum
#include <iostream>

using namespace std;

enum Semana {
    Domingo, //por padrão, começa do 0.
    Segunda,
    Terca,
    Quarta,
    Quinta,
    Sexta,
    Sabado
};


int main()
{
    //enum Semana diaSemana = Segunda; //a forma usada no C ainda funciona
    Semana diaSemana = Segunda;

    switch(diaSemana)
    {
        case Sexta:
            cout << "Sexta-feira :D\n";
            break;
        case Sabado:
            cout << "Sabado :D\n";
            break;
        case Domingo:
            cout << "Domingo :D\n";
            break;
        default:
            cout << "Dia de importancia questionavel.\n";
    }
/*
 teste de comentario multiplas linhas
sdadasfa 
hahhaah
*/
	return 0;
}
