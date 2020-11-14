//
// Created by sen on 11/14/20.
//

#ifndef CPP_NOTES_MEM_POOL_V2_H
#define CPP_NOTES_MEM_POOL_V2_H

#include <stddef.h>

class Airplane {
private:
    struct AirplaneRep {
        unsigned long miles;
        char type;
    };

private:
    union {
        AirplaneRep rep;
        Airplane *next;
    };

public:
    unsigned long getMiles() {
        return rep.miles;
    }

    char getType() {
        return rep.type;
    }

    void set(unsigned long m, char t) {
        rep.miles = m;
        rep.type = t;
    }

public:
    static void *operator new(size_t size);

    static void operator delete(void *deadObject, size_t size);

private:
    static const int BLOCK_SIZE;
    static Airplane *headOfFreeList;
};


#endif //CPP_NOTES_MEM_POOL_V2_H
