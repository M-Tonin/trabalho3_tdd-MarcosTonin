#include <string>
#include <iostream>
#include <utility>


class A
{
public:
    std::string s;
    A() : s("test") {std::cout << "A()\n"; }
    A(const A& o)  { std::cout << "Construtor de Copia const A&" << std::endl; }
    A(A&& o) : s(std::move(o.s))  { std::cout << "Construtor de Copia com move const A&&" << std::endl; }
    A& operator=(const A& other)
    {
         s = other.s;
         std::cout << "Operador = com copia" << std::endl;
         return *this;
    }
    A& operator=(A&& other)
    {
         s = std::move(other.s);
         std::cout << "Operador = com move" << std::endl;
         return *this;
    }
};

A&& f(A &a)
{
    std::cout << "Dentro da funcao f(A &a)" << std::endl;
    //O std::move é usado para indicar que os dados de "a" podem ser movidos, permitindo uma transferência eficiente do recursos de "a" para outro objeto.
    return std::move(a);
}

int main()
{
    A a1, a2;
    a1 = a2; //utiliza o operador =
    A a3 = a1; //utiliza o construtor de cópia
    A a4 = std::move(A()); //utiliza o construtor de cópia com referência a rvalue
    A a5 = f(a1); //utiliza o construtor de cópia com referência a rvalue
}
