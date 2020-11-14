//
// Created by sen on 11/14/20.
//

#include "mem_pool_v2.h"

Airplane *Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void *Airplane::operator new(size_t size) {
    // 如果大小有误，转交给::operator new(). 当继承发生时，可能会有误
    if (size != sizeof(Airplane)) {
        return ::operator new(size);
    }

    Airplane *p = headOfFreeList;
    if (p) {
        headOfFreeList = p->next;
    } else {
        // free list
        Airplane *newBlock = static_cast<Airplane *>(::operator new(BLOCK_SIZE * sizeof(Airplane)));

        // 将小块串成一个free list
        // 但跳过#0, 因为它将被传回作为本次成果
        for (int i = 1; i < BLOCK_SIZE; ++i) {
            newBlock[i].next = &newBlock[i + i];
        }
        newBlock[BLOCK_SIZE - 1].next = 0;  // 结束
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

void Airplane::operator delete(void *deadObject, size_t size) {
    if (deadObject == 0) return;
    if (size != sizeof(Airplane)) {
        ::operator delete(deadObject);
        return;
    }

    Airplane* carcass = static_cast<Airplane*>(deadObject);

    carcass->next = headOfFreeList;
    headOfFreeList = carcass;
}
