//
// Created by sen on 11/3/20.
//
#include <memory>

#define SIMPLE_FACTORY

#ifdef SIMPLE_FACTORY
#include "./simple_factory.h"
#endif

#ifdef TEMPLATE_FACTORY
#include "./template_factory.h"
#endif

#ifdef REGESTER_SINGLE_FACTORY
#include "./regester_single_factory.h"
#endif

int main () {
#ifdef SIMPLE_FACTORY
    // factory
    ShoesFactory ShoesFactory;
    Shoes* nike = ShoesFactory.CreateShoes(NIKE);
//    nike->show();

//    std::shared_ptr<Shoes> pAdidas(ShoesFactory.CreateShoes(ADIDAS));
//    pAdidas.get()->show();
#endif

#ifdef TEMPLATE_FACTORY
    ConcreteFactory<Shoes, NikeShoes> nikeFactory;
//    Shoes *pNikeShoes = nikeFactory.CreateProduct();
    std::shared_ptr<Shoes> pNikeShoes(nikeFactory.CreateProduct());
    pNikeShoes->Show();
    ConcreteFactory<Cloth, UniqloCloth> uniqloFactory;
    std::shared_ptr<Cloth> pUniqloCloth(uniqloFactory.CreateProduct());
    pUniqloCloth->Show();
#endif

#ifdef REGESTER_SINGLE_FACTORY
    ProductRegister<Shoes, NikeShoes> nikeShoes("nike");
    Cloth *pUniqloCloth = ProductFactory<Cloth>::Instance().GetProduct("uniqlo");
    pUniqloCloth->Show();
    if (pUniqloCloth) {
        delete pUniqloCloth;
    }
    Shoes *pNikeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");
    pNikeShoes->Show();
//    if (pNikeShoes) {
//        delete pNikeShoes;
//    }
#endif
}