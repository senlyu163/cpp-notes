//
// Created by sen on 11/5/20.
//

#include <array>
#include <string>
#include <iostream>
#include <algorithm>



int main() {
    std::string str = "abcdefads";
    std::array<char, 120> arr= {{0,}};
    int idx = 0;
    for (auto &e : str) {
        std::cout << e << std::endl;
        arr[idx] = e;
        idx++;
    }

//    arr[0] = 'b';
//    arr[1] = 'c';
    std::cout << arr.data() << std::endl;


    return 0;
}