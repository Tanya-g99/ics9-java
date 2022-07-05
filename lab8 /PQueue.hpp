#ifndef PQUEUE_H
#define PQUEUE_H

#include <cstdlib>
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class my_priority_queue: public std::priority_queue<T, Container, Compare>{
public:
    void print(){
        int i = 0, x = 1;
        for(auto elem : this->c){
            i++;
            if (i == x){
                std::cout<< "\n";
                std::cout<< std::string(16 - 3*i, ' ');
                x *= 2;
            }
            elem.print();
        }
    std::cout<< "\n\n";
    }

    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};

template <typename T, size_t N>
class PQueue
{
    struct Elem
    {
        T value;
        int priority;
        void print(){
            std::cout << " "<< priority << "(" << value << ") ";
        }
        friend bool operator< (Elem const& lhs, Elem const& rhs) {
            return lhs.priority < rhs.priority;
        }
        friend bool operator> (Elem const& lhs, Elem const& rhs) {
            return lhs.priority > rhs.priority;
        }
        friend bool operator== (Elem const& lhs, Elem const& rhs) {
            return (lhs.priority == rhs.priority) && (lhs.value == rhs.value);
        }
    };
private:
    size_t count;
    my_priority_queue<Elem> PQueueMax;
    my_priority_queue<Elem,std::vector<Elem>, std::greater<Elem> > PQueueMin;
    std::vector<Elem> vClearMax;
    std::vector<Elem> vClearMin;
public:
    PQueue();
    T extractMax();
    T extractMin();
    void insert(T v, int p);
    void print();
};

template <typename T, size_t N> 
PQueue<T, N>::PQueue(){
    PQueueMax = {};
    PQueueMin = {};
    vClearMax = {};
    vClearMin = {};
    count = 0;
}

template <typename T, size_t N> 
T PQueue<T, N>::extractMin(){
    Elem res = PQueueMin.top();
    PQueueMin.pop();
    vClearMax.push_back(res);
    //PQueueMax.remove(res);
    count--;
    return res.value;
}

template <typename T, size_t N> 
T PQueue<T, N>::extractMax(){
    Elem res = PQueueMax.top();
    vClearMin.push_back(res);
    PQueueMax.pop();
    //PQueueMin.remove(res);
    count--;
    return res.value;
}

template <typename T, size_t N>
void PQueue<T, N>::insert(T v, int p){
    Elem temp = {v, p};


    for (int i = vClearMin.size() - 1; i >= 0; i--)
    {
        auto m = vClearMin[i];
        vClearMin.pop_back();
        PQueueMin.remove(m);
    }

    for (int i = vClearMax.size() - 1; i >= 0; i--)
    {
        auto m = vClearMax[i];
        vClearMax.pop_back();
        PQueueMax.remove(m);
    }

    PQueueMax.push(temp);
    PQueueMin.push(temp);
    count++;
}

template<typename T, size_t N>
void PQueue<T, N>::print(){
    for (int i = vClearMax.size() - 1; i >= 0; i--)
    {
        auto m = vClearMax[i];
        vClearMax.pop_back();
        PQueueMax.remove(m);
    }
    
    PQueueMax.print();
}

template <size_t N>
class PQueue<bool, N>{
    struct Elem
    {
        bool value;
        int priority;
        void print(){
            std::cout << " "<< priority << "(" << value << ") ";
        }
        friend bool operator< (Elem const& lhs, Elem const& rhs) {
            return lhs.priority < rhs.priority;
        }
        friend bool operator> (Elem const& lhs, Elem const& rhs) {
            return lhs.priority > rhs.priority;
        }
        friend bool operator== (Elem const& lhs, Elem const& rhs) {
            return (lhs.priority == rhs.priority) && (lhs.value == rhs.value);
        }
    };
private:
    std::multiset<Elem, std::greater<Elem> > PQueueB;
public:
    PQueue();
    bool extractMax();
    bool extractMin();
    void insert(bool v, int p);
    void print();
};


template <size_t N>
PQueue<bool, N>::PQueue(){
    PQueueB = {};
}

template <size_t N>
void PQueue<bool, N>::insert(bool v, int p){
    PQueueB.insert(Elem{v, p});
}

template <size_t N>
bool PQueue<bool, N>::extractMax(){
    typename std::multiset<Elem>::iterator iter;
    iter = PQueueB.begin();
    bool max = (*iter).value;
    PQueueB.erase(*iter);
    return max;
}

template <size_t N>
bool PQueue<bool, N>::extractMin(){
    typename std::multiset<Elem>::reverse_iterator iter;
    iter = PQueueB.rbegin();
    bool min = (*iter).value;
    PQueueB.erase(*iter);
    return min;
}

template <size_t N>
void PQueue<bool, N>::print(){
    int i = 0, x = 1;
    for(auto elem : PQueueB){
        i++;
        if (i == x){
            std::cout<< "\n";
            std::cout<< std::string(16 - 3*i, ' ');
            x *= 2;
        }
        elem.print();
    }
    std::cout<< "\n\n";

}


#endif