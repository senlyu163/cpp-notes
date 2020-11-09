//
// Created by sen on 11/4/20.
//

#include "./customer_hash.h"

using std::unordered_set;
using std::cout;
using std::endl;

int main() {
    //unordered_set<int,std::hash<int>>myset;
    unordered_set<Customer, CustomerHash, mycompare> myset;
    /*
    template<
    class Key,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<Key>
    > class unordered_set;
    */
    myset.insert(Customer("Xiao", "Shen", 1));
    myset.insert(Customer("Xiao", "Li", 2));
    myset.insert(Customer("Xiao", "Wang", 3));
    myset.insert(Customer("Xiao", "Zhao", 4));
    myset.insert(Customer("Xiao", "Wu", 5));
    myset.insert(Customer("Xiao", "Liu", 6));
    myset.insert(Customer("Xiao", "Tang", 7));
    myset.insert(Customer("Xiao", "Lin", 8));
    myset.insert(Customer("Xiao", "He", 9));
    cout << "哈希表的篮子个数" << myset.bucket_count() << endl;//64

    //经过自定义的hash function编码后各个对象会落在哪个篮子里
    cout << "No1:" << CustomerHash()(Customer("Xiao", "Shen", 1)) % 64 << endl;
    cout << "No2:" << CustomerHash()(Customer("Xiao", "Li", 2)) % 64 << endl;
    cout << "No3:" << CustomerHash()(Customer("Xiao", "Wang", 3)) % 64 << endl;
    cout << "No4:" << CustomerHash()(Customer("Xiao", "Zhao", 4)) % 64 << endl;
    cout << "No5:" << CustomerHash()(Customer("Xiao", "Wu", 5)) % 64 << endl;
    cout << "No6:" << CustomerHash()(Customer("Xiao", "Liu", 6)) % 64 << endl;
    cout << "No7:" << CustomerHash()(Customer("Xiao", "Tang", 7)) % 64 << endl;
    cout << "No8:" << CustomerHash()(Customer("Xiao", "Lin", 8)) % 64 << endl;
    cout << "No9:" << CustomerHash()(Customer("Xiao", "He", 9)) % 64 << endl;

#include <tuple>
    auto t = std::make_tuple(1, 2, "aa");
    typedef std::tuple<int, float, double> TupleType;
    std::cout << std::tuple_size<decltype(t)>::value << std::endl;
    int* idx;
    for (int i = 0; i < std::tuple_size<decltype(t)>::value; ++i) {
        int &iref = i;
        const int& ciref = static_cast<const int&>(iref);
        std::cout << std::get<2>(t) << std::endl;
    }
    return 0;
}