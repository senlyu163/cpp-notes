//
// Created by sen on 11/10/20.
//

#include "mem_pool_v1.h"

Screen *Screen::freeStore = 0;
const int Screen::screenChunk = 24;

void *Screen::operator new(size_t size) {
    Screen *p;
    if (!freeStore) {
        // linked list is empty, so alloc a huge piece of mem
        size_t chunk = screenChunk * size;
        freeStore = p = reinterpret_cast<Screen *>(new char[chunk]);
        // split the huge piece of mem into small, and link them to be linked list
        for (; p != &freeStore[screenChunk - 1]; ++p) {
            p->next = p + 1;
        }
        p->next = 0;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void Screen::operator delete(void *p, size_t size) {
    // insert deleted object into free list
    (static_cast<Screen *>(p))->next = freeStore;
    freeStore = static_cast<Screen *>(p);
}
