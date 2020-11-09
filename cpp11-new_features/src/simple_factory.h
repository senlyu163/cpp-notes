//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_SIMPLE_FACTORY_H
#define CPP_NOTES_SIMPLE_FACTORY_H


class Shoes {
public:
    virtual void show() = 0;
    virtual ~Shoes() {}
};

class NikeShoes : public Shoes {
public:
    virtual void show();
};

class AdidasShoes : public Shoes {
public:
    virtual void show();
};

class LiNingShoes : public Shoes {
public:
    virtual void show();
};

enum SHOES_TYPE { NIKE, LINING, ADIDAS };

// shoes factory class
class ShoesFactory {
public:
    Shoes* CreateShoes(SHOES_TYPE type) {
        switch (type) {
            case NIKE:
                return new NikeShoes();
            case ADIDAS:
                return new AdidasShoes();
            case LINING:
                return new LiNingShoes();
            default:
                return nullptr;
        }
    }
};

#endif //CPP_NOTES_SIMPLE_FACTORY_H
