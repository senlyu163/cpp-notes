//
// Created by sen on 11/4/20.
//

#ifndef CPP_NOTES_CUSTOMER_HASH_H
#define CPP_NOTES_CUSTOMER_HASH_H

#include<iostream>
#include<string>
#include<unordered_set>

using std::string;

class Customer {
public:
    string fname;
    string lname;
    long no;

    Customer(const string _fname, const string _lname, long _no) : fname(_fname), lname(_lname), no(_no) {}//constructor

};


class mycompare {//由于放入unordred_set中的是类类型，所以要自定义==函数，否则会报错
public:
    bool operator()(const Customer &c1, const Customer &c2) const {
        if (c1.no == c2.no) {
            if (c1.fname == c2.fname)
                return c1.lname == c2.lname;
            return false;
        }
        return false;

    }
};

template<typename T>
inline void my_hash_combine(size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) //调用标准库的hash仿函数模板（找到T对应的特化版本）
            + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void my_hash_val(size_t &seed, const T &val) {
    my_hash_combine(seed, val);
}

template<typename T, typename...Types>
//C++11中最新支持的可变参数模板（variadic template）
inline void my_hash_val(size_t &seed, const T &val, const Types &...args) {
    my_hash_combine(seed, val);
    my_hash_val(seed, args...);
}

template<typename...Types>
//C++11中最新支持的可变参数模板（variadic template）
inline size_t my_hash_val(const Types &...args) {
    size_t seed = 0;
    my_hash_val(seed, args...);//递归
    return seed;
}

class CustomerHash//自定义functor
{
public:
    size_t operator()(const Customer &c) const {
        return my_hash_val(c.fname, c.lname, c.no);

    }
};

#endif //CPP_NOTES_CUSTOMER_HASH_H
