#ifndef TESTLIFECYCLE_H
#define TESTLIFECYCLE_H

#include "model.h"

void testLifecycle() {
    cout << "testLifecycle start" << endl;

    Model("tag0");
    cout << endl;

    Model model1("tag1");
    Model model2 = Model("tag2");
    cout << endl;

    Model model3("tag3");
    Model & rModel3 = model3;
    // Model & rMode4 = Model("tag4");
    Model const & rModel5 = Model("tag5");
    cout << endl;

    Model model6("tag6");
    Model * pModel6 = &model6;
    // Model * pModel7 = &(Model("tag7"));
    cout << endl;

    Model && rvModel8 = Model("tag8");
    Model model9("tag9");
    // Model && rvModel9 = model9;
    Model && rvModel9 = move(model9);

    Model model10("tag10");
    Model const && rvModel10 = move(model10); 
    Model const && rvModel11 = Model("tag11"); 

    cout << endl << "testLifecycle end" << endl;
}


#endif // TESTLIFECYCLE_H