#include <string>
#include <climits>

class EquasionsSet
{
public:
    class Equasion {
        private:
            int a, b;
            std::string str_a, str_b;
        public:
        Equasion(std::string a, int b);        //
        Equasion(int a, std::string b);        // конструктор
        Equasion(int a, int b);                //   равенства
        Equasion(std::string a, std::string b);//
        Equasion& operator=(const Equasion& obj);
        Equasion(const Equasion& obj);
        void printA();
        void printB();
        int aGet();
        int bGet();
        std::string str_aGet();
        std::string str_bGet();
        std::string* str_aG();
        std::string* str_bG();

    };
private:
    size_t n;
    EquasionsSet::Equasion** array;
public:
    size_t getN();
    //Equasion** getArray();
    EquasionsSet(size_t n);//конструктор системы         +
    EquasionsSet(const EquasionsSet& obj);// конструктор копий    +
    virtual ~EquasionsSet();//деструктор    
    EquasionsSet& operator=(const EquasionsSet& obj);//операция присваивания   +
    EquasionsSet::Equasion*& operator[](int i);//полученте ссылки на i-тое равенство  
    void add(Equasion& eq);//добавление нового равенства
    bool checkForSolution(); //проверка существует ли решение системы
};

