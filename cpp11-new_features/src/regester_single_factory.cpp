//
// Created by sen on 11/3/20.
//

#include "regester_single_factory.h"

#include <iostream>

void NikeShoes::Show()  {
    std::cout << "Nike shoes, just do it" << std::endl;
}

void UniqloCloth::Show()  {
    std::cout << "Uniqlo cloth, I am Uniqlo" << std::endl;
}

template<class ProductType_t>
void ProductFactory<ProductType_t>::RegisterProduct(IProductRegister<ProductType_t> *register_param,
                                                    std::string name)  {
    m_ProductRegistry[name] = register_param;
}

template<class ProductType_t>
ProductType_t * ProductFactory<ProductType_t>::GetProduct(std::string name)  {
    if (m_ProductRegistry.find(name) != m_ProductRegistry.end()) {
        return m_ProductRegistry[name]->CreateProduct();
    }

    // have not registered, output info
    std::cout << "No product found for " << name << std::endl;
    return nullptr;
}


