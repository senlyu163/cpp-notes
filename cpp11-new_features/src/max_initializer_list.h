//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_MAX_INITIALIZER_LIST_H
#define CPP_NOTES_MAX_INITIALIZER_LIST_H

#include<initializer_list>

struct _Iter_less_iter {
    template<typename _Iterator1, typename _Iterator2>
    bool operator()(_Iterator1 __it1, _Iterator2 __it2) const {
        return *__it1 < *__it2;
    }
};

inline _Iter_less_iter __iter_less_iter() {
    return _Iter_less_iter();
}

template<typename _ForwardIterator, typename _Compare>
_ForwardIterator __max_element(_ForwardIterator __first, _ForwardIterator __last, _Compare __comp) {
    if (__first == __last) return __first;
    _ForwardIterator __result = __first;
    while (++__first != __last) {
        if (__comp(__result, __first)) {
            __result = __first;
        }
    }
    return __result;
}

template<typename _ForwardIterator>
inline _ForwardIterator max_element(_ForwardIterator __first, _ForwardIterator __last) {
    return __max_element(__first, __last, __iter_less_iter());
}

template<typename _Tp>
inline _Tp max(std::initializer_list<_Tp> __I) {
    return *max_element(__I.begin(), __I.end());
}


/**
 *
 *  not initializer list version
 *
 * */

#include <algorithm>

int maximum(int n) {
    return n;
}

template<typename... Args>
int maximum(int n, Args... args) {
    return std::max(n, maximum(args...));
}

#endif //CPP_NOTES_MAX_INITIALIZER_LIST_H
