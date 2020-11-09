//
// Created by sen on 11/1/20.
//
#include "threadsafe_stack.h"
#include<vector>

int main() {

    int a = 0;
    std::vector<decltype(a)> via;

    threadsafe_stack<int> *tT = new threadsafe_stack<int>();
    tT->pop();
}