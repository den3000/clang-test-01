#ifndef TESTRETURNSMARTPOINTERS_H
#define TESTRETURNSMARTPOINTERS_H

#include "model.h"

auto m_spm = std::make_shared<Model>("m_spm");

std::shared_ptr<Model> fooReturnSharedPtr() {
    auto res = std::make_shared<Model>("spm1");
    std::cout << "res.useCount = " << res.use_count() << std::endl;
    return res;
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
    std::cout << "spm.useCount = " << spm.use_count() << std::endl;

    auto wpm1 = fooReturnWeakPtr1();
    std::cout << "wpm1.expired = " << wpm1.expired() << std::endl;
    std::cout << "wpm1 " << wpm1.lock().get()->details("pam 1") << std::endl;

    auto wpm2 = fooReturnWeakPtr2();
    std::cout << "wpm2.expired = " << wpm2.expired() << std::endl;
    if (!wpm2.expired()) {
        std::cout << "wpm2 " << wpm2.lock().get()->details("pam 2") << std::endl;
    } else {
        std::cout << "wpm2 expired" << std::endl;
    }

    auto upm = fooReturnUniquePtr();
}

#endif // TESTRETURNSMARTPOINTERS_H