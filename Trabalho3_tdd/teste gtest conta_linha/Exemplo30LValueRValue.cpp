#include <string>
#include <iostream>
#include <utility>
//Uma expressão em C++ ou é um l-value ou um r-value.
//Enquanto o l-value faz referência a um objeto que persiste após uma única expressão, um r-value é um valor temporário que não persiste
//além da expressão que o utiliza.
//Pode-se pensar em um l-value como objeto que tem um nome.

int main()
{
   int i, j, *p;

   // i é um lvalue, 7 é um rvalue
   i = 7;

   // Uso incorreto, pois o operando à esquerda é um rvalue, e ele deve ser um lvalue
   7 = i; // C2106
   j * 4 = 7; // C2106

   // *p é um lvalue.
   *p = i;

   const int ci = 7;
   // Uso incorreto, pois o operando à esquerda é um lvalue não modificável.
   ci = 9; // C3892

   // Uso correto, pois a condicional (utilizando o operador ternário) retorna um lvalue.
   ((i < 3) ? i : j) = 7;
}
