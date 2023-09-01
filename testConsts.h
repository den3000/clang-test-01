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
    const Model model("tag");
    auto t = model.m_tag;
    auto d = model.details();

    // won't compile: you can't change properties of const variable
    // model.m_tag = "new tag";

    // won't compile: you can't call non-const functions of const variable
    // model.fakeUpdate();

    // won't compile: you can't re-assign value of const variable
    // model = Model("tag2");
}

void testConstPtrs() {
    Model modelNonConst("tagNonConst");
    const Model modelConst("tagConst");

    Model modelNonConst1("tagNonConst1");
    const Model modelConst1("tagConst1");

    // ============== 1. non const pointer to const ============== 
    // from non const
    const Model * pToConst1 = &(modelNonConst);
    // from const
    const Model * pToConst2 = &(modelConst);

    // both might be re-assigned
    pToConst1 = &(modelConst1);
    pToConst2 = &(modelNonConst1);

    // both allows read-only access to underlying object 
    auto t1 = pToConst1->m_tag;
    auto d1 = pToConst1->details();    
    auto t2 = pToConst2->m_tag;
    auto d2 = pToConst2->details();    

    // both fails to access underlying objects for write
    // won't compile 
    // pToConst1->m_tag = "new tag";
    // pToConst1->fakeUpdate();
    // pToConst2->m_tag = "new tag";
    // pToConst2->fakeUpdate();

    // ============== 2. const pointer to non const ============== 
    Model *const cpToNonConst1 = &(modelNonConst);

    // won't compile: can't create const pointer to non const from const variable
    // Model *const cpToNonConst2 = &(modelConst);

    // can't be re-assigned
    // won't compile: you can't re-assign const pointer
    // cpToNonConst1 = &(modelNonConst1);

    // allows full access to underlying object
    auto t3 = cpToNonConst1->m_tag;
    auto d3 = cpToNonConst1->details();
    cpToNonConst1->m_tag = "new tag";
    cpToNonConst1->fakeUpdate();

    // ============== 3. const pointer to const ============== 
    // from non const
    const Model *const cpToConst1 = &(modelNonConst);
    // from const
    const Model *const cpToConst2 = &(modelConst);

    // none of them  might be re-assigned
    // won't compile: you can't re-assign const pointer
    // cpToConst1 = &(modelConst1);
    // cpToConst2 = &(modelNonConst1);

    // both allows read-only access to underlying object 
    auto t4 = cpToConst1->m_tag;
    auto d4 = cpToConst1->details();    
    auto t5 = cpToConst2->m_tag;
    auto d5 = cpToConst2->details();   
    
    // both fails to access underlying objects for write
    // won't compile 
    // cpToConst1->m_tag = "new tag";
    // cpToConst1->fakeUpdate();
    // cpToConst2->m_tag = "new tag";
    // cpToConst2->fakeUpdate();
};

void testConstRefs() {
    Model modelNonConst("tagNonConst");
    const Model modelConst("tagConst");

    Model modelNonConst1("tagNonConst1");
    const Model modelConst1("tagConst1");

    const Model & refToConst1 = modelNonConst;
    const Model & refToConst2 = modelConst;

    // both can't be reassigned
    // won't compile: refrences created only once and can't be reassigned in any case
    // refToConst1 = modelNonConst1;
    // refToConst2 = modelConst1;

    // both allows read-only access to underlying object 
    auto t1 = refToConst1.m_tag;
    auto d1 = refToConst1.details();    
    auto t2 = refToConst2.m_tag;
    auto d2 = refToConst2.details();    

    // both fails to access underlying objects for write
    // won't compile 
    // refToConst1.m_tag = "new tag";
    // refToConst1.fakeUpdate();
    // refToConst2.m_tag = "new tag";
    // refToConst2.fakeUpdate();
};

#endif // TESTCONSTSS_H