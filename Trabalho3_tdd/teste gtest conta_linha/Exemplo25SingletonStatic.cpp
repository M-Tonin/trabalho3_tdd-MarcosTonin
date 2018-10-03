#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


 class ClasseSingleton
 {
    private:
       //construtor privado, não pode ser utilizado fora da classe
       ClasseSingleton() {  cout << "Objeto Singleton criado.\n"; }
       ~ClasseSingleton() {  cout << "Objeto Singleton destruido.\n"; }
    public:
       int valor;
       // Função-membro que retorna sempre a mesma instância do objeto
       static ClasseSingleton* getInstance()
       {
          static ClasseSingleton instance;
          return &instance;
       }
 };

int main()
{
    //ClasseSingleton *meuObjeto = new ClasseSingleton(); //Erro.
    ClasseSingleton *meuObjeto = ClasseSingleton::getInstance();
    ClasseSingleton *meuObjeto2 = ClasseSingleton::getInstance();

    meuObjeto->valor = 10;
    cout << meuObjeto2->valor << endl;

    return 0;
}
