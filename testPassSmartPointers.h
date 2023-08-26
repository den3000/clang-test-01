#ifndef TESTPASSSMARTPOINTERS_H
#define TESTPASSSMARTPOINTERS_H

#include "model.h"

void fooSharedPtrTest(std::shared_ptr<Model> spm) {
    std::cout << "spm.useCount = " << spm.use_count() << std::endl;
    std::cout << spm.get()->details("shared") << std::endl;
}

void fooWeakPtrTest(std::weak_ptr<Model> wpm) {
    std::cout << "wpm.useCount = " << wpm.use_count() << std::endl;
    std::cout << wpm.lock().get()->details("weak") << std::endl;
}

void fooUniquePtrTest(std::unique_ptr<Model> upm) {
    std::cout << upm.get()->details("unique") << std::endl;
}

void testPassSmartPointers(){
    // shared
    std::cout << std::endl;
    auto spm1 = std::make_shared<Model>("spm1");
    auto spm2 = std::shared_ptr<Model>(new Model("spm2"));
    std::shared_ptr<Model> spm3(new Model("spm3"));

    std::cout << std::endl;
    std::cout << "spm1.useCount = " << spm1.use_count() << std::endl;
    fooSharedPtrTest(spm1);
    std::cout << "spm1.useCount = " << spm1.use_count() << std::endl;

    // weak
    std::cout << std::endl;
    auto spm4 = std::make_shared<Model>("spm4");
    std::weak_ptr<Model> wpm4(spm4);

    std::cout << "spm4.useCount = " << spm1.use_count() << std::endl;
    std::cout << "wpm4.useCount = " << wpm4.use_count() << std::endl;
    fooWeakPtrTest(wpm4);
    std::cout << "spm4.useCount = " << spm1.use_count() << std::endl;
    std::cout << "wpm4.useCount = " << wpm4.use_count() << std::endl;

    // unique
    std::cout << std::endl;
    auto upm1 = std::make_unique<Model>("upm1");
    auto upm2 = std::unique_ptr<Model>(new Model("upm2"));
    std::unique_ptr<Model> upm3(new Model("upm3"));

    std::cout << upm1.get()->details("unique before fooUniquePtrTest") << std::endl;
    fooUniquePtrTest(std::move(upm1));
    // will cause crash, unique ptr should not be accesed after move
    // qDebug() << upm1.get()->details("unique after fooUniquePtrTest");
};

#endif // TESTPASSSMARTPOINTERS_H