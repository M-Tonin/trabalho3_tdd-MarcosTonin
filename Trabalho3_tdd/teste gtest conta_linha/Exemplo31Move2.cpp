// MemoryBlock.h
#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:
   // Construtor simples para inicializar os recursos
   MemoryBlock(size_t length)
      : _length(length)
      , _data(new int[length])
   {
      std::cout << "No MemoryBlock(size_t). length = "
                << _length << "." << std::endl;
   }

   // Destrutor.
   ~MemoryBlock()
   {
      std::cout << "No ~MemoryBlock(). length = "
                << _length << ".";

      if (_data != nullptr)
      {
         std::cout << " Deletando recurso.";
         // Deletando o Recurso
         delete[] _data;
      }

      std::cout << std::endl;
   }
/*
   // Construtor de cópia.
   MemoryBlock(const MemoryBlock& other)
      : _length(other._length)
      , _data(new int[other._length])
   {
      std::cout << "No MemoryBlock(const MemoryBlock&). length = "
                << other._length << ". Copiando recurso." << std::endl;

      std::copy(other._data, other._data + _length, _data);
   }

   // Operador de associação.
   MemoryBlock& operator=(const MemoryBlock& other)
   {
      std::cout << "No operator=(const MemoryBlock&). length = "
                << other._length << ". Copiando recurso." << std::endl;

      if (this != &other)
      {
         // Free the existing resource.
         delete[] _data;

         _length = other._length;
         _data = new int[_length];
         std::copy(other._data, other._data + _length, _data);
      }
      return *this;
   }
*/
    // Construtor de movimentação.
    MemoryBlock(MemoryBlock&& other)
       : _data(nullptr)
       , _length(0)
    {
       std::cout << "No MemoryBlock(MemoryBlock&&). length = "
                 << this->_length << " para " << other._length << ". Movendo recurso." << std::endl;

       // Copiamos o ponteiro e o tamanho do objeto.
       _data = other._data;
       _length = other._length;

       // Liberamos o ponteiro do objeto original para que o destrutor não destrua os ponteiros.
       other._data = nullptr;
       other._length = 0;
    }

    // Operador de associação utilizando referência para rvalue
    MemoryBlock& operator=(MemoryBlock&& other)
    {
       std::cout << "In operator=(MemoryBlock&&). length = "
                 << other._length << "." << std::endl;

       if (this != &other)
       {
          // Free the existing resource.
          delete[] _data;

          // Copy the data pointer and its length from the
          // source object.
          _data = other._data;
          _length = other._length;

          // Release the data pointer from the source object so that
          // the destructor does not free the memory multiple times.
          other._data = nullptr;
          other._length = 0;
       }
       return *this;
    }
   // Pega o tamanho do vetor
   size_t Length() const
   {
      return _length;
   }

private:
   size_t _length; // tamanho do recurso
   int* _data; // Recurso
};
using namespace std;

int main()
{
   // Criamos o vetor e adicionamos alguns objetos a ele.
   vector<MemoryBlock> v;
   std::cout << "Criou o vetor" << endl;
   v.push_back(MemoryBlock(75)); // Passa por referencia de rvalue para o construtor
   v.push_back(MemoryBlock(50)); // Passa por referencia de rvalue para o construtor
   v.push_back(MemoryBlock(25)); // Passa por referencia de rvalue para o construtor
}
