#ifndef TESTPTRSANDREFS_H
#define TESTPTRSANDREFS_H

#include "model.h"

void ptrsAndRefsBasicSyntax() {
    // creating a model on a stack
    cout << "Creating a model on a stack"<< endl;
    Model model("some model");
    cout << "model by value: " << model.details() << endl << endl;

    // creating a reference to tha str
    cout << "Creating a ref to a model on a stack"<< endl;
    Model & modelRef = model;
    cout << "str by ref: " << modelRef.details() << endl << endl;

    // taking the addr of model to create a pointer
    cout << "Taking an addr of a model on a stack to create a pointer"<< endl;
    Model * modelPtr = &(model);
    cout << "addr of this model on a stack: " << modelPtr << endl;
    cout << "accessing to model function by ptr syntax: " << modelPtr->details() << endl;
    cout << "accessing to model function by dereferencing: " << (*(modelPtr)).details() << endl << endl;

    // creating a string on a heap with pointer syntax
    cout << "Creating a model on a heap with pointer syntax" << endl;
    Model * modelPtr2 = new Model("one more string");
    cout << "addr of a model on a heap: " << modelPtr2 << endl;
    cout << "accessing to model function by ptr syntax: " << modelPtr2->details() << endl;
    cout << "accessing to model function by dereferencing: " << (*(modelPtr2)).details() << endl << endl;

    // cleaning up memory
    delete modelPtr2;
}

Model foo() {
    return Model("some model");
}

void constSyntax() {
    const Model model("some model");
    auto t1 = model.m_tag;
    auto d1 = model.details();
    // model.m_tag = "new tag";
    
    const Model & modelRef = model;
    auto t2 = modelRef.m_tag;
    auto d2 = model.details();
    // modelRef.m_tag = "new tag";

    const Model * modelPtr = &(model);
    auto t3 = modelPtr->m_tag;
    auto d3 = model.details();
    // modelPtr->m_tag = "new tag";

    Model model1("some model");
    Model && model1Rvref = foo();

}

void fooPtrsSizesAndAdrs2(Model model) {
    cout << "fooPtrsSizesAndAdrs2" << endl;

    cout << "value of model: " << model << endl;
    cout << "size of model: " << sizeof(model) << endl;
    cout << "addr of model: " << &model << endl;
}

void fooPtrsSizesAndAdrs3(Model * pModel) {
    cout << "fooPtrsSizesAndAdrs3" << endl;

    cout << "value of pModel: " << pModel << endl;
    cout << "dereferenced value of pModel: " << *pModel << endl;
    cout << "size of pModel: " << sizeof(pModel) << endl;
    cout << "addr of pModel: " << &pModel << endl;
}

void fooPtrsSizesAndAdrs() {
    cout << endl;
    cout << "fooPtrsSizesAndAdrs" << endl;

    // ==== int ====
    cout << endl;
    cout << "==== int ====" << endl;
    int x = 10;
    cout << "value of x: " << x << endl;
    cout << "size of x: " << sizeof(x) << endl;
    cout << "addr of x: " << &x << endl;

    int * px = &x;
    cout << "value of px: " << px << endl;
    cout << "de-refed value of px: " << *px << endl;
    cout << "size of px: " << sizeof(px) << endl;
    cout << "addr of px: " << &px << endl;

    // ==== string ====
    cout << endl;
    cout << "==== string ====" << endl;
    string str = "Some really really long text";
    cout << "value of str: " << str << endl;
    cout << "size of str: " << sizeof(str) << endl;
    cout << "addr of str: " << &str << endl;

    string * pStr = &str;
    cout << "value of pStr: " << pStr << endl;
    cout << "de-refed value of pStr: " << *pStr << endl;
    cout << "size of pStr: " << sizeof(pStr) << endl;
    cout << "addr of pStr: " << &pStr << endl;

    // ==== model ====
    cout << endl;
    cout << "==== model ====" << endl;
    Model model("some model");
    cout << "value of model: " << model << endl;
    cout << "size of model: " << sizeof(model) << endl;
    cout << "addr of model: " << &model << endl;

    Model * pModel = &model;
    cout << "value of pModel: " << pModel << endl;
    cout << "de-refed value of pModel: " << *pModel << endl;
    cout << "size of pModel: " << sizeof(pModel) << endl;
    cout << "addr of pModel: " << &pModel << endl;

    cout << endl;
    fooPtrsSizesAndAdrs2(model);
    cout << endl;
    fooPtrsSizesAndAdrs2(*pModel);

    cout << endl;
    fooPtrsSizesAndAdrs3(&model);
    cout << endl;
    fooPtrsSizesAndAdrs3(pModel);
    
    cout << endl;
}

void fooRefsSizesAndAdrs2(Model model) {
    cout << "fooRefsSizesAndAdrs2" << endl;

    cout << "value of model: " << model << endl;
    cout << "size of model: " << sizeof(model) << endl;
    cout << "addr of model: " << &model << endl;
}

void fooRefsSizesAndAdrs3(Model & rModel) {
    cout << "fooRefsSizesAndAdrs3" << endl;

    cout << "value of rModel: " << rModel << endl;
    cout << "size of rModel: " << sizeof(rModel) << endl;
    cout << "addr of rModel: " << &rModel << endl;
}

void fooRefsSizesAndAdrs() {
    cout << endl;
    cout << "fooRefsSizesAndAdrs" << endl;

    // ==== int ====
    cout << endl;
    cout << "==== int ====" << endl;
    int x = 10;
    cout << "value of x: " << x << endl;
    cout << "size of x: " << sizeof(x) << endl;
    cout << "addr of x: " << &x << endl;

    int & rx = x;
    cout << "value of rx: " << rx << endl;
    cout << "size of rx: " << sizeof(rx) << endl;
    cout << "addr of rx: " << &rx << endl;

    // ==== string ====
    cout << endl;
    cout << "==== string ====" << endl;
    string str = "Some really really long text";
    cout << "value of str: " << str << endl;
    cout << "size of str: " << sizeof(str) << endl;
    cout << "addr of str: " << &str << endl;

    string & rStr = str;
    cout << "value of rStr: " << rStr << endl;
    cout << "size of rStr: " << sizeof(rStr) << endl;
    cout << "addr of rStr: " << &rStr << endl;

    // ==== model ====
    cout << endl;
    cout << "==== model ====" << endl;
    Model model("some model");
    cout << "value of model: " << model << endl;
    cout << "size of model: " << sizeof(model) << endl;
    cout << "addr of model: " << &model << endl;

    Model & rModel = model;
    cout << "value of rModel: " << rModel << endl;
    cout << "size of rModel: " << sizeof(rModel) << endl;
    cout << "addr of rModel: " << &rModel << endl;

    cout << endl;
    fooRefsSizesAndAdrs2(model);
    cout << endl;
    fooRefsSizesAndAdrs2(rModel);

    cout << endl;
    fooRefsSizesAndAdrs3(model);
    cout << endl;
    fooRefsSizesAndAdrs3(rModel);
    
    cout << endl;
}

void testPtrsAndRefs() {
    ptrsAndRefsBasicSyntax();
    constSyntax(); 
    fooPtrsSizesAndAdrs();
    fooRefsSizesAndAdrs();
}

#endif // TESTPTRSANDREFS_H