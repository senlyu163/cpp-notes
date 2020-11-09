//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_TEMPLATE_FACTORY_H
#define CPP_NOTES_TEMPLATE_FACTORY_H


class Shoes {
public:
    virtual void Show() = 0;
    virtual ~Shoes() {}
};

class NikeShoes : public Shoes {
public:
    void Show();
};

class Cloth {
public:
    virtual void Show() = 0;
    virtual ~Cloth() {};
};

class UniqloCloth : public Cloth {
public:
    void Show();
};

// abstract template factory class
template <class AbstractProduct_t>
class AbstractFactory {
public:
    virtual AbstractProduct_t *CreateProduct() = 0;
    virtual ~AbstractFactory(){}
};

// concrete template factory class
template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t> {
public:
    AbstractProduct_t *CreateProduct() {
        return new ConcreteProduct_t();
    }
};


#endif //CPP_NOTES_TEMPLATE_FACTORY_H
