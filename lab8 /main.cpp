#include <iostream>
#include "PQueue.hpp"

int main()
{
    PQueue<int, 10> test;
    test.insert(4, 3);
    test.insert(1, 5);
    test.insert(1, 8);
    test.insert(22, 7);
    test.insert(4, 9);
    test.insert(99, 10);
    test.print();
    std::cout<< "min : "<< test.extractMin()<<"\n";
    test.print();
    std::cout<< "max: " <<test.extractMax()<<"\n";
    test.print();

    PQueue<bool, 10> test_bool;
    test_bool.insert(false, 10);
    test_bool.insert(true, 0);
    test_bool.insert(true, 20);
    test_bool.insert(true, 30);
    test_bool.print();
    //std::cout<< "max: " <<test_bool.extractMax()<<"\n";
    std::cout<< "min: " <<test_bool.extractMin()<<"\n";
    test_bool.print();
    std::cout<< "max: " <<test_bool.extractMax()<<"\n";
    test_bool.print();
    return 0;
}
