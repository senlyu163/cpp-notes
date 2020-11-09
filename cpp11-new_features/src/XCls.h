//
// Created by sen on 11/1/20.
//

#ifndef CPP_NOTES_XCLS_H
#define CPP_NOTES_XCLS_H

/**
 *  template template parameter + alias template
 *
 */

#define SIZE 100

#include <utility>
#include <vector>
#include <list>
#include <deque>

template<typename T>
using Vec = std::vector<T, std::allocator<T>>;

template<typename T>
using Lst = std::list<T, std::allocator<T>>;

template<typename T>
using Deq = std::deque<T, std::allocator<T>>;

template<typename T, template<class> class Container>
class XCls {
private:
    Container<T> c;
public:
    XCls();
};


#endif //CPP_NOTES_XCLS_H
