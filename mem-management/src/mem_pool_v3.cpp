//
// Created by sen on 11/14/20.
//

#include "mem_pool_v3.h"
#include <stdlib.h>

void *allocator::allocate(size_t size) {
    obj *p;

    if (!freeStore) {
        // linked list为空，于是申请一大块内存
        size_t chunk = CHUNK * size;
        freeStore = p = (obj *) malloc(chunk);

        // 将分配得来的一大块当作linked list一样，小块小块串接起来
        for (int i = 0; i < (CHUNK - 1); ++i) {
            p->next = (obj *) ((char *) p + size);
            p = p->next;
        }

        p->next = nullptr;  // last
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void allocator::deallocate(void *p, size_t) {
    // 将×p收回插入free list前端
    ((obj *) p)->next = freeStore;
    freeStore = (obj *) p;
}