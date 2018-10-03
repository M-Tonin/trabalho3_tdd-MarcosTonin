//Exemplo de Enum 2
#include <iostream>
namespace Paises {
    enum Pais {
        BRASIL,
        ITALIA,
        ALEMANHA
    };
}
namespace Uvas
{
    enum Uva
    {
        ITALIA,
        RUBI,
        MERLOT
    };
}
//*...*//

using namespace std;
using namespace Uvas;
int main()
{
    cout<< ITALIA << endl;
    cout<< Uvas::ITALIA << endl;
    cout<< Paises::ITALIA << endl;

    //Pais pais = Paises::BRASIL;// Erro: 'Pais' was not declared in this scope
    Paises::Pais pais = Paises::BRASIL;
    Uvas::Uva uva = Uvas::ITALIA;
	return 0;
}
