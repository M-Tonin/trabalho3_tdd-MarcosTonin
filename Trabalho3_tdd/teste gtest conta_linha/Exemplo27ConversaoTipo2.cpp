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
  // Tentando reinterpretar c como B (isso � ruim, pois a posi��o de mem�ria de B dentro de c n�o � a mesma da posi��o da mem�ria de C).
  B *bReinterpretCast = reinterpret_cast<B *>(&c);

  //Equivalente ao reinterpret_cast, uma vez que primeiro convertemos para um ponteiro gen�rico e depois para o novo ponteiro
  void *v = (void*)&c;
  B *bVoidB = (B*)v;

  // primeiro tenta static_cast<B*>(&c) (e outros), para s� por �ltimo tentar reinterpret_cast.
  //neste caso, static_cast � o m�todo usado.
  B *bExplicitCast = (B*)(&c);

  //M�todo mais indicado para convers�o nesta situa��o.
  B *bStaticCast = static_cast<B *>(&c);


  cout << "reinterpret_cast:\t" << bReinterpretCast << "\n";
  cout << "de void* para B*:\t" << bVoidB << "\n";
  cout << "C-style cast:\t\t" << bExplicitCast << "\n";
  cout << "static_cast:\t\t" << bStaticCast << "\n";
  cout << "sem cast:\t\t" << &c << "\n";
  cout << "&(c->x), &(c->x1), &(c->y), &(c->z) :\t" << &(c.x) << ", " << &(c.x1) << ", " << &(c.y) << ", " << &(c.z) << "\n";
  //Informa��o incorreta
  cout << "bReinterpretCast->y: \t\t" << bReinterpretCast->y << endl;
  //Informa��o incorreta
  cout << "bVoidB->y: \t\t" <<  bVoidB->y << endl;
  //Informa��o correta
  cout << "bExplicitCast->y: \t\t" <<  bExplicitCast->y << endl;
  //Informa��o correta
  cout << "bStaticCast->y: \t\t" <<  bStaticCast->y << endl;

}
