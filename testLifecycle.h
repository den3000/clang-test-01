#ifndef TESTLIFECYCLE_H
#define TESTLIFECYCLE_H

#include "model.h"

void testLifecycleByVal(Model model);
void testLifecycleByPtr(Model * model);
void testLifecycleByRef(Model & model);

void testLifecycle() {
    cout << "testLifecycle" << endl;

    Model model("tag");

    testLifecycleByVal(model);
    testLifecycleByPtr(&model);
    testLifecycleByRef(model);
}

void testLifecycleByVal(Model model) {

}

void testLifecycleByPtr(Model * model) {

}

void testLifecycleByRef(Model & model) {

}


#endif // TESTLIFECYCLE_H