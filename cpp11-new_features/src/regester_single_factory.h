//
// Created by sen on 11/3/20.
//

#ifndef CPP_NOTES_REGESTER_SINGLE_FACTORY_H
#define CPP_NOTES_REGESTER_SINGLE_FACTORY_H

#include <string>
#include <map>

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

template <class ProductType_t>
class IProductRegister {
public:
    virtual ProductType_t *CreateProduct() = 0;

protected:
    IProductRegister() {};
    virtual ~IProductRegister() {};

private:
    IProductRegister(const IProductRegister &);
    const IProductRegister &operator=(const IProductRegister &);
};

template <class ProductType_t>
class ProductFactory {
public:
    static ProductFactory<ProductType_t> &Instance() {
        static ProductFactory<ProductType_t> instance;
        return instance;
    }

    // product register
    void RegisterProduct(IProductRegister<ProductType_t> *register_param, std::string name);

    // base on name, get the product object
    ProductType_t *GetProduct(std::string name);
private:
    ProductFactory() {}
    ~ProductFactory() {}

    ProductFactory(const ProductFactory &);
    const ProductFactory &operator=(const ProductFactory &);

    // save registered products
    std::map<std::string, IProductRegister<ProductType_t> *> m_ProductRegistry;
};

template <class ProductType_t, class ProductImpl_t>
class ProductRegister : public IProductRegister<ProductType_t> {
public:
    explicit ProductRegister(std::string name) {
        ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
    }

    ProductType_t *CreateProduct() {
        return new ProductImpl_t();
    }
};


#endif //CPP_NOTES_REGESTER_SINGLE_FACTORY_H
