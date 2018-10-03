//Exemplo de vector
#include <iostream>
#include <vector>
using namespace std; //o vector está no namespace STD
const int NUMERONOTAS = 4;
class Coisa
{
public:
    string val;
    Coisa()
    {
        cout << "Coisa Criada" << endl;
    }
    Coisa(const Coisa& coisa)
    {
        //swap(this->val, coisa.val);
        cout << "const Coisa &Criada" << endl;
    }
    Coisa(Coisa&& coisa)
    {
        cout << "const Coisa &&Criada" << endl;

        cout << "&coisa.val = " << coisa.val << endl;
        cout << "&this->val = " << this->val << endl;
        swap(this->val, coisa.val);
        cout << "&coisa.val = " << coisa.val << endl;
        cout << "&this->val = " << this->val << endl;
    }
};
vector<Coisa> vetor;
void funcao()
{
    Coisa varFuncao;
    //varFuncao.val = 10;
    vetor.push_back(move(varFuncao));
    //cout << "&varFuncao.val = " << varFuncao.val << endl;
    //vetor.push_back(Coisa());
}
int main()
{
    funcao();
    cout << "Depois da funcao" << endl;
    Coisa novaCoisa = vetor.front();
    //cout << "&novaCoisa.val = " << novaCoisa.val << endl;
    //cout << "novaCoisa.val[0] = " << novaCoisa.val[0] << endl;

	return 0;
}

