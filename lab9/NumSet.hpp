#ifndef NUMSET_H
#define NUMSET_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

template <typename T>
class NumSet{

    struct Interval
    {
        T begin, end;
        Interval& operator=(const Interval& obj) {
            begin = obj.begin;
            end = obj.end;
            return *this;
        }
        friend bool operator< (Interval const& lhs, Interval const& rhs) {
            return lhs.begin < rhs.begin;
        }
    };

private:
    std::vector<Interval> numset;
    
public:
    NumSet(T a, T b){
        numset.emplace_back(Interval{a, b});
    };

    NumSet(){
        numset = {};
    };

    NumSet& operator=(const NumSet& obj){
        this->numset = obj.numset;
        return *this;
    };

    NumSet operator*(const NumSet obj){
        NumSet res;
        for (auto a : this->numset)
        {
            for (auto b : obj.numset){
                if (!(a.end < b.begin || a.begin > b.end)){
                    if (a.begin <= b.begin && a.end >= b.begin && a.end <= b.end){res.numset.push_back(Interval{b.begin, a.end});}
                    if (a.begin >= b.begin && a.end <= b.end){res.numset.push_back(Interval{a.begin, a.end});}
                    if (a.begin <= b.begin && a.end >= b.end){res.numset.push_back(Interval{b.begin, b.end});}
                    if (a.begin >= b.begin && a.begin <= b.end && a.end >= b.end){res.numset.push_back(Interval{a.begin, b.end});}
                }
            }
        }
        return res;
    };

    NumSet operator+(const NumSet obj){
        NumSet res;
        std::vector<Interval> r;
        res.numset = this->numset;
        for (auto b : obj.numset)
        {
            bool flag = true;
            for (auto &a : res.numset){
                if (!(a.end < b.begin || a.begin > b.end)){
                    if (a.begin <= b.begin && a.end >= b.begin && a.end <= b.end){a = Interval{a.begin, b.end};}
                    if (a.begin >= b.begin && a.end <= b.end){a = Interval{b.begin, b.end};}
                    if (a.begin <= b.begin && a.end >= b.end){a = Interval{a.begin, a.end};}
                    if (a.begin >= b.begin && a.begin <= b.end && a.end >= b.end){a = Interval{b.begin, a.end};}
                    flag = false;
                }
            }
            if (flag){r.push_back(b);}
        }
        for (auto b : r){
            res.numset.push_back(b);
        }
        sort(res.numset.begin(), res.numset.end());
        return res;
    };

    bool operator()(T num){
        for (auto interval : this->numset)
        {
            if (num >= interval.begin && num <= interval.end){return true;}
        }
        return false;
        
    };

    void print();
};

template <typename T>
void NumSet<T>::print(){
    int i = 0;
    for (auto interval : numset)
    {
        if (i++ != 0){std::cout << " ⋃ ";}
        std::cout << "[" << interval.begin << ',' << interval.end << "]";
    }
    
}


#endif
