#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


 class ClasseSingleton
 {
    private:
       static ClasseSingleton *instance;
       //construtor privado, não pode ser utilizado fora da classe
       ClasseSingleton() {  cout << "Objeto Singleton criado.\n"; }
       ~ClasseSingleton() {  cout << "Objeto Singleton destruido.\n"; }
    public:
       int valor;
       // Função-membro que retorna sempre a mesma instância do objeto
       static ClasseSingleton* getInstance()
       {
          if (!instance)
            instance = new ClasseSingleton; //sem os (), você está indicando que não necessariamente você se importa se as variáveis serão inicializadas
          return instance;
       }
       static void destroyInstance() {
            if(instance != 0)
                delete instance;
            instance = 0;
       }
 };
 //Variáveis globais e estáticas são inicializadas como 0.
 //Variáveis locais não são inicializadas a não ser que seja claramente especificado.
ClasseSingleton *ClasseSingleton::instance = NULL; //ainda sim, deixar como NULL é recomendado para deixar o código mais claro.
// é equivalente a: ClasseSingleton *ClasseSingleton::instance;

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
