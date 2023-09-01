#ifndef TESTCONSTSS_H
#define TESTCONSTSS_H

#include "model.h"

void testConstVars();
void testConstPtrs();
void testConstRefs();

void testConsts() {
    testConstVars();
    testConstPtrs();
    testConstRefs();
}

void testConstVars() {
    const Model model("some model");
    auto t1 = model.m_tag;
    auto d1 = model.details();

    // won't compile: you can't change properties of const variable
    // model.m_tag = "new tag";

    // won't compile: you can't call non-const functions of const variable
    // model.fakeUpdate();

    // won't compile: you can't re-assign value of const variable
    // model = Model("some another model");
}

void testConstPtrs() {
        const Model model("some model");
    const Model * modelPtr = &(model);
    auto t3 = modelPtr->m_tag;
    auto d3 = model.details();
    // modelPtr->m_tag = "new tag";
};

Model constSyntaxFoo() {
    return Model("some model");
};

void testConstRefs() {
    const Model model("some model");
    const Model & modelRef = model;
    auto t2 = modelRef.m_tag;
    auto d2 = model.details();
    // modelRef.m_tag = "new tag";

    // Model model1("some model");
    // Model && model1Rvref = constSyntaxFoo();
};

#endif // TESTCONSTSS_H