#ifndef TESTRETURNSMARTPOINTERS_H
#define TESTRETURNSMARTPOINTERS_H

#include "model.h"

auto m_spm = std::make_shared<Model>("m_spm");

std::shared_ptr<Model> fooReturnSharedPtr() {
    return std::make_shared<Model>("spm1");
}

std::weak_ptr<Model> fooReturnWeakPtr1() {
    std::weak_ptr<Model> wpm(m_spm);
    return wpm;
}

std::weak_ptr<Model> fooReturnWeakPtr2() {
    auto spm = std::make_shared<Model>("spm2");
    std::weak_ptr<Model> wpm(spm);
    return wpm;
}

std::unique_ptr<Model> fooReturnUniquePtr() {
    return std::make_unique<Model>("upm");
}

void testReturnSmartPtrs() {
    std::cout << std::endl;

    auto spm = fooReturnSharedPtr();

    auto wpm1 = fooReturnWeakPtr1();
    std::cout << "wpm1.expired = " << wpm1.expired() << std::endl;

    auto wpm2 = fooReturnWeakPtr2();
    std::cout << "wpm2.expired = " << wpm2.expired() << std::endl;
    
    auto upm = fooReturnUniquePtr();
}

#endif // TESTRETURNSMARTPOINTERS_H