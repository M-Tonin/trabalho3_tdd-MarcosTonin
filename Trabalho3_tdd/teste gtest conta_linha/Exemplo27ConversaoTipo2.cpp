#include <iostream>

using namespace std;

class A { public: int x; int x1; };
class B {
    public:
    B() : y(15)
    {
    }
    int y;
};

class C : public A, public B
{
    public:
    C() : z(16)
    {
    }
    int z;
};

int main()
{
  C c;
  // Tentando reinterpretar c como B (isso é ruim, pois a posição de memória de B dentro de c não é a mesma da posição da memória de C).
  B *bReinterpretCast = reinterpret_cast<B *>(&c);

  //Equivalente ao reinterpret_cast, uma vez que primeiro convertemos para um ponteiro genérico e depois para o novo ponteiro
  void *v = (void*)&c;
  B *bVoidB = (B*)v;

  // primeiro tenta static_cast<B*>(&c) (e outros), para só por último tentar reinterpret_cast.
  //neste caso, static_cast é o método usado.
  B *bExplicitCast = (B*)(&c);

  //Método mais indicado para conversão nesta situação.
  B *bStaticCast = static_cast<B *>(&c);


  cout << "reinterpret_cast:\t" << bReinterpretCast << "\n";
  cout << "de void* para B*:\t" << bVoidB << "\n";
  cout << "C-style cast:\t\t" << bExplicitCast << "\n";
  cout << "static_cast:\t\t" << bStaticCast << "\n";
  cout << "sem cast:\t\t" << &c << "\n";
  cout << "&(c->x), &(c->x1), &(c->y), &(c->z) :\t" << &(c.x) << ", " << &(c.x1) << ", " << &(c.y) << ", " << &(c.z) << "\n";
  //Informação incorreta
  cout << "bReinterpretCast->y: \t\t" << bReinterpretCast->y << endl;
  //Informação incorreta
  cout << "bVoidB->y: \t\t" <<  bVoidB->y << endl;
  //Informação correta
  cout << "bExplicitCast->y: \t\t" <<  bExplicitCast->y << endl;
  //Informação correta
  cout << "bStaticCast->y: \t\t" <<  bStaticCast->y << endl;

}
