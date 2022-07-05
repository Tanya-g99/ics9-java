#include <cstdlib>
#include <iostream>
#include "NumSet.hpp"

template <typename T>
void printAdd(NumSet<T> a, NumSet<T> b, NumSet<T> c){
    std::cout<< "Объединение множеств";
    a.print();
    std::cout<< " и ";
    b.print();
    std::cout<<"\nРезультат: ";
    c.print();
    std::cout<<"\n";
}

template <typename T>
void printMul(NumSet<T> a, NumSet<T> b, NumSet<T> c){
    std::cout<< "Пересечение множеств";
    a.print();
    std::cout<< " и ";
    b.print();
    std::cout<<"\nРезультат: ";
    c.print();
    std::cout<<"\n";
}

template <typename T>
void printIs(NumSet<T> a, T elem){
    std::cout<< "Проверка принадлежности числа " << elem;
    std::cout<< " множеству ";
    a.print();
    if (a(elem)){
        std::cout<<":\nПринадлежит\n";
    }else{std::cout<<":\nНе принадлежит\n";}
}

int main()
{   
    NumSet<int> test1(2, 5);
    NumSet<int> test2(1, 3);
    NumSet<int> test3(-1, 106);
    NumSet<int> test4(109, 120);
    NumSet<int> test5(-57, -23);

    std::cout<<"Примеры объединений:\n";
    NumSet<int> test6 = test1+test2;
    printAdd(test1, test2, test6);
    NumSet<int> test7 = test2+test5;
    printAdd(test2, test5, test7);
    NumSet<int> test8 = test3+test4;
    printAdd(test3, test4, test8);
    NumSet<int> test9 = test7+test8;
    printAdd(test7, test8, test9); 

    std::cout<<"\nПримеры пересечения:\n";
    NumSet<int> test10 = test1*test2;
    printMul(test1, test2, test10);
    NumSet<int> test_1(-40, -10);
    NumSet<int> test_2(99, 118);
    NumSet<int> test_3(-2, 0);
    NumSet<int> test_4 = test_1+test_2;
    NumSet<int> test_5 = test9*test_4;

    printMul(test9, test_4, test_5);

    std::cout<<"\nПримеры проверки принадлежности:\n";
    printIs(test9, -4);
    printIs(test9, 28);
    

    return 0;
}
