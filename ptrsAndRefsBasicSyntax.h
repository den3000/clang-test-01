#ifndef PTRSANDREFSBASICSYNTAX_H
#define PTRSANDREFSBASICSYNTAX_H

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