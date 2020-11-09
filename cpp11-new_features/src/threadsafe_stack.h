//
// Created by sen on 10/29/20.
//

#ifndef CPP_NOTES_THREADSAFE_STACK_H
#define CPP_NOTES_THREADSAFE_STACK_H

#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception {
    const char* what() const throw() {
        return "empty stack!";
    }
};

template<typename T>
class threadsafe_stack {
public:
    threadsafe_stack() : data(std::stack<T>()) {};
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> l(m);
        data = other.data;
    }

    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value);

    std::shared_ptr<T> pop();

    void pop(T& value);

    bool empty() const;
private:
    std::stack<T> data;
    mutable std::mutex m;
};




#endif //CPP_NOTES_THREADSAFE_STACK_H
