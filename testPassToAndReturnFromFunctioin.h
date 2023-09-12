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
    cout << "addr of passed model: " << &model << endl;
}

void testPassToFunctioinByVal() {
    Model model("tag0");
    cout << "model after creation: " << model << endl;

    Model * pModel = &model;
    Model & rModel = model;
    Model && rvModel = move(model);
    cout << "model after rvalue-ref creation: " << model << endl;

    cout << endl << "fooPassToFunctioinByVal from val" << endl;
    fooPassToFunctioinByVal(model);

    cout << endl << "fooPassToFunctioinByVal from ptr" << endl;
    fooPassToFunctioinByVal(*pModel);

    cout << endl << "fooPassToFunctioinByVal from ref" << endl;
    fooPassToFunctioinByVal(rModel);

    cout << endl << "fooPassToFunctioinByVal from rval-ref" << endl;
    fooPassToFunctioinByVal(rvModel);
    cout << "model after pass by rval-ref: " << model << endl;

    cout << endl << "fooPassToFunctioinByVal with move" << endl;
    fooPassToFunctioinByVal(move(model));
    cout << "model after pass move: " << model << endl;

    cout << endl << "fooPassToFunctioinByVal from tmp val" << endl;
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

void fooPassToFunctioinByRvalRef(Model && model) {

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