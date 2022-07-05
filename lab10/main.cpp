#include <cstdlib>
#include <iostream>
#include "BinaryRelation.hpp"

bool foo(size_t a, size_t b){
    return (a * 2 + b)%7 == 0;
}


int main()
{
    BinaryRelation test(foo, 11);
    test.printMatrix();
    for(auto &i : test){
        std::cout << '(' << i.first << ',' << i.second << ')' << ' ';
        i.first = 5;
    }
    std::cout << "\n";
    auto iter = test.begin();
    iter = --(test.end());
    test.printMatrix();
    return 0;
}
