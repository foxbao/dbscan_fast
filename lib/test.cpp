#include "include/test.hpp"

auto test::add(int a,int b)->decltype(a+b)
{
    return a+b;
}