//Exemplo de Interface
#include <iostream>
#include <string.h>

using namespace std;

class ClassePai {
public:
     virtual ~ClassePai() { cout << "~ClassePai()" << endl; } //Embora nenhum m�todo seja implementado pela classe, � recomand�vel implementar o destrutor virtual
};
class ClasseFilha : public ClassePai
{
public:
    ~ClasseFilha() {
        cout << "~ClasseFilha()" << endl;
    }
    int vect[1000000];
};
int main()
{
    int pause;
    cout << "0)" << endl;
    cin >> pause;
    ClasseFilha *classeFilha = new ClasseFilha();
    ClassePai *classePai = classeFilha;
    cout << "1)" << endl;
    cin >> pause;
    delete classePai; //comportamente n�o definido se o destrutor da classe pai n�o for virtual.
    cout << "2)" << endl;
    cin >> pause;
    int *vect = new int[10000000];
    for(int i =0; i < 10000000; i++)
        vect[i] = 'a';
    cout << "3)" << endl;
    cin >> pause;
    delete[]vect; //comportamento n�o definido
    cout << "4)" << endl;
    cin >> pause;
    return 0;
}
