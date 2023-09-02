#ifndef TESTPASSSMARTPOINTERS_H
#define TESTPASSSMARTPOINTERS_H

#include "model.h"

void fooSharedPtrTest(shared_ptr<Model> spm) {
    cout << "spm.useCount = " << spm.use_count() << endl;
    cout << spm.get()->details("shared") << endl;
}

void fooWeakPtrTest(weak_ptr<Model> wpm) {
    cout << "wpm.useCount = " << wpm.use_count() << endl;
    cout << wpm.lock().get()->details("weak") << endl;

    weak_ptr<Model> wpm2 = wpm;
    cout << "wpm.useCount = " << wpm.use_count() << endl;
    cout << "wpm2.useCount = " << wpm2.use_count() << endl;

    cout << endl;
}

void fooUniquePtrTest(unique_ptr<Model> upm) {
    cout << upm.get()->details("unique") << endl;
}

void testPassSmartPointers() {
    // shared
    cout << endl;
    auto spm1 = make_shared<Model>("spm1");
    auto spm2 = shared_ptr<Model>(new Model("spm2"));
    shared_ptr<Model> spm3(new Model("spm3"));

    cout << endl;
    cout << "spm1.useCount = " << spm1.use_count() << endl;
    fooSharedPtrTest(spm1);
    cout << "spm1.useCount = " << spm1.use_count() << endl;

    // weak
    cout << endl;
    auto spm4 = make_shared<Model>("spm4");
    weak_ptr<Model> wpm4(spm4);

    cout << "spm4.useCount = " << spm4.use_count() << endl;
    cout << "wpm4.useCount = " << wpm4.use_count() << endl;
    fooWeakPtrTest(wpm4);
    cout << "spm4.useCount = " << spm4.use_count() << endl;
    cout << "wpm4.useCount = " << wpm4.use_count() << endl;

    // unique
    cout << endl;
    auto upm1 = make_unique<Model>("upm1");
    auto upm2 = unique_ptr<Model>(new Model("upm2"));
    unique_ptr<Model> upm3(new Model("upm3"));

    cout << upm1.get()->details("unique before fooUniquePtrTest") << endl;
    fooUniquePtrTest(move(upm1));
    // will cause crash, unique ptr should not be accesed after move
    // cout << upm1.get()->details("unique after fooUniquePtrTest");
    
};

    // Model m("tag0");
    // cout << "size of m: " << sizeof(m) << endl;
    // Model * pM = &m;
    // cout << "size of ptr: " << sizeof(pM) << endl;
    
    // auto sM = make_shared<Model>("tag1");
    // cout << "size of shared_ptr: " << sizeof(sM) << endl;

    // weak_ptr<Model> wM = sM;
    // cout << "size of weak_ptr: " << sizeof(wM) << endl;

    // auto uM = make_unique<Model>("tag2");
    // cout << "size of unique_ptr: " << sizeof(uM) << endl;

#endif // TESTPASSSMARTPOINTERS_H