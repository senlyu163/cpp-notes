//
// Created by sen on 11/14/20.
//

#ifndef CPP_NOTES_MEM_POOL_V3_H
#define CPP_NOTES_MEM_POOL_V3_H

// static allocator

#include <stddef.h>

class allocator {
private:
    struct obj {
        struct obj *next;  // embedded pointer
    };

public:
    void *allocate(size_t);

    void deallocate(void *, size_t);

private:
    obj* freeStore = nullptr;
    const int CHUNK = 5;  // 这里设置小一些方便观察，标准库中为20
};


#endif //CPP_NOTES_MEM_POOL_V3_H
