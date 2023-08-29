#ifndef TESTRETURNSMARTPOINTERS_H
#define TESTRETURNSMARTPOINTERS_H

#include "model.h"

auto m_spm = make_shared<Model>("m_spm");

shared_ptr<Model> fooReturnSharedPtr() {
    auto res = make_shared<Model>("spm1");
    cout << "res.useCount = " << res.use_count() << endl;
    return res;
}

weak_ptr<Model> fooReturnWeakPtr1() {
    weak_ptr<Model> wpm(m_spm);
    return wpm;
}

weak_ptr<Model> fooReturnWeakPtr2() {
    auto spm = make_shared<Model>("spm2");
    weak_ptr<Model> wpm(spm);
    return wpm;
}

unique_ptr<Model> fooReturnUniquePtr() {
    return make_unique<Model>("upm");
}

void testReturnSmartPtrs() {
    cout << endl;

    auto spm = fooReturnSharedPtr();
    cout << "spm.useCount = " << spm.use_count() << endl;

    auto wpm1 = fooReturnWeakPtr1();
    cout << "wpm1.expired = " << wpm1.expired() << endl;
    cout << "wpm1 " << wpm1.lock().get()->details("pam 1") << endl;

    auto wpm2 = fooReturnWeakPtr2();
    cout << "wpm2.expired = " << wpm2.expired() << endl;
    if (!wpm2.expired()) {
        cout << "wpm2 " << wpm2.lock().get()->details("pam 2") << endl;
    } else {
        cout << "wpm2 expired" << endl;
    }

    auto upm1 = fooReturnUniquePtr();
}

#endif // TESTRETURNSMARTPOINTERS_H