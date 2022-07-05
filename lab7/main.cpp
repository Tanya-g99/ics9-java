#include <iostream>
#include "declaration.h"

using namespace std;

void printEq(EquasionsSet::Equasion* eq){
    eq->printA();
    std::cout<<" = ";
    eq->printB();
}

void display(EquasionsSet eqSet){
    size_t i = 0;
    std::cout<<"\x1b[1m⎧ \x1b[0m";
    printEq(eqSet[i++]);
    for (;i < eqSet.getN()/2; i++){
        std::cout<<"\n\x1b[1m⎪ \x1b[0m";
        printEq(eqSet[i]);
    }
    std::cout<<"\n\x1b[1m⎨ \x1b[0m";
    printEq(eqSet[i++]);
    for (;i < eqSet.getN() - 1; i++){
        std::cout<<"\n\x1b[1m⎪ \x1b[0m";
        printEq(eqSet[i]);
    }
    std::cout<<"\n\x1b[1m⎩ \x1b[0m";
    printEq(eqSet[i]);
    std::cout<<"\n\n";
}

void foo(EquasionsSet set){
    if (set.EquasionsSet::checkForSolution()){
        std::cout<<"\x1b[32;1mрешение системы существует\x1b[0m\n\n";
    }else{
        std::cout<<"\x1b[31;1mрешение системы не существует\x1b[0m\n\n";
    }
}

void foo1(EquasionsSet set){
    EquasionsSet::Equasion f("var1", "var2");
    set[0] = &f;
    display(set);
}

int main()
{
    EquasionsSet test(3);
    EquasionsSet::Equasion a("num2", "num1");
    EquasionsSet::Equasion b("num1", 1);
    EquasionsSet::Equasion b2("num1", 2);
    EquasionsSet::Equasion c(2, 2);
    EquasionsSet::Equasion d(2, "num2");
    EquasionsSet::Equasion e(10, 15);
    EquasionsSet::Equasion f(10, "num3");
    test[0] = &a;
    test[1] = &b;
    test[2] = &c;
    std::cout<<"\x1b[1;4mпроверка существования решения системы:\x1b[0m\n\n";
    display(test);
    foo(test); //проверка существования решения системы
    
    test.add(f);
    test.add(d);
    display(test);
    foo(test);

    test[1] = &b2;
    display(test);
    foo(test);

    test[3] = &e;
    display(test);
    foo(test);

    std::cout<<"\x1b[1;4mпроверка работы конструктора копий:\x1b[0m\n\n";
    foo1(test); //проверка работы конструктора копий
    display(test);
    
    EquasionsSet t(2);
    std::cout<<"\x1b[1;4mоперация присваивания:\x1b[0m\n\n";
    t = test;   //операция присваивания
    display(t);
    return 0;
}