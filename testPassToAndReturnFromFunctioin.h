#ifndef TESTPASSTOANDRETURNFROMFUNCTIOIN_H
#define TESTPASSTOANDRETURNFROMFUNCTIOIN_H

#include "model.h"

void testPassToFunctioinByVal();
void testPassToFunctioinByPtr();
void testPassToFunctioinByRef();

void testReturnFromFunctioinByVal(); 
void testReturnFromFunctioinByPtr(); 
void testReturnFromFunctioinByRef(); 

void testPassToAndReturnFromFunctioin() {
    testPassToFunctioinByVal();
}

void fooPassToFunctioinByVal(Model model) {
    cout << "addr of model: " << &model << endl;
}

void testPassToFunctioinByVal() {
    Model model("tag0");
    Model * pModel = &model;
    Model & rModel = model;

    cout << "fooPassToFunctioinByVal for val" << endl;
    fooPassToFunctioinByVal(model);
    cout << "fooPassToFunctioinByVal from ptr" << endl;
    fooPassToFunctioinByVal(*pModel);
    cout << "fooPassToFunctioinByVal from ref" << endl;
    fooPassToFunctioinByVal(rModel);
    cout << "fooPassToFunctioinByVal from tmp val" << endl;
    fooPassToFunctioinByVal(Model("tag1"));
}

void fooPassToFunctioinByPtr(Model * model) {

}

void testPassToFunctioinByPtr() {

}

void fooPassToFunctioinByRef(Model & model) {

}

void fooPassToFunctioinByConstRef(Model const & model) {

}

void testPassToFunctioinByRef() {


}

void testReturnFromFunctioinByVal() {

}

void testReturnFromFunctioinByRef() {

}

void testReturnFromFunctioinByPtr() {

}


#endif // TESTPASSTOANDRETURNFROMFUNCTIOIN_H