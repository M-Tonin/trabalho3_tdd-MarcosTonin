#include <string>
#include <iostream>
#include <utility>
//Uma express�o em C++ ou � um l-value ou um r-value.
//Enquanto o l-value faz refer�ncia a um objeto que persiste ap�s uma �nica express�o, um r-value � um valor tempor�rio que n�o persiste
//al�m da express�o que o utiliza.
//Pode-se pensar em um l-value como objeto que tem um nome.

int main()
{
   int i, j, *p;

   // i � um lvalue, 7 � um rvalue
   i = 7;

   // Uso incorreto, pois o operando � esquerda � um rvalue, e ele deve ser um lvalue
   7 = i; // C2106
   j * 4 = 7; // C2106

   // *p � um lvalue.
   *p = i;

   const int ci = 7;
   // Uso incorreto, pois o operando � esquerda � um lvalue n�o modific�vel.
   ci = 9; // C3892

   // Uso correto, pois a condicional (utilizando o operador tern�rio) retorna um lvalue.
   ((i < 3) ? i : j) = 7;
}
