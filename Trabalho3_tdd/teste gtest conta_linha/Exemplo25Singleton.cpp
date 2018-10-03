#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


 class ClasseSingleton
 {
    private:
       static ClasseSingleton *instance;
       //construtor privado, n�o pode ser utilizado fora da classe
       ClasseSingleton() {  cout << "Objeto Singleton criado.\n"; }
       ~ClasseSingleton() {  cout << "Objeto Singleton destruido.\n"; }
    public:
       int valor;
       // Fun��o-membro que retorna sempre a mesma inst�ncia do objeto
       static ClasseSingleton* getInstance()
       {
          if (!instance)
            instance = new ClasseSingleton; //sem os (), voc� est� indicando que n�o necessariamente voc� se importa se as vari�veis ser�o inicializadas
          return instance;
       }
       static void destroyInstance() {
            if(instance != 0)
                delete instance;
            instance = 0;
       }
 };
 //Vari�veis globais e est�ticas s�o inicializadas como 0.
 //Vari�veis locais n�o s�o inicializadas a n�o ser que seja claramente especificado.
ClasseSingleton *ClasseSingleton::instance = NULL; //ainda sim, deixar como NULL � recomendado para deixar o c�digo mais claro.
// � equivalente a: ClasseSingleton *ClasseSingleton::instance;

int main()
{
    //ClasseSingleton *meuObjeto = new ClasseSingleton(); //Erro.
    ClasseSingleton *meuObjeto = ClasseSingleton::getInstance();
    ClasseSingleton *meuObjeto2 = ClasseSingleton::getInstance();

    meuObjeto->valor = 10;
    cout << meuObjeto2->valor << endl;

    ClasseSingleton::destroyInstance();
    return 0;
}
