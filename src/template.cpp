#include "template.hpp"

example::ExampleClass::ExampleClass(const int arg1, const int arg2)
    : example::BaseClass{arg1}, m_var{arg2}
{
}

int example::ExampleClass::exampleMethod(const int arg)
{
    return arg > this->m_var ? 1 : 0;
}