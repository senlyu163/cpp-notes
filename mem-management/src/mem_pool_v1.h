//
// Created by sen on 11/10/20.
//

#ifndef CPP_NOTES_MEM_POOL_V1_H
#define CPP_NOTES_MEM_POOL_V1_H

#include <cstddef>

class Screen {
public:
    Screen(int x) : i(x) {};

    void *operator new(size_t);

    void operator delete(void *, size_t);

private:
    Screen *next;
    static Screen *freeStore;
    static const int screenChunk;
private:
    int i;
};


#endif //CPP_NOTES_MEM_POOL_V1_H
