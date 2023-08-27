#include <iostream>
#include <string>

#include "model.h"

void ptrsAndRefsBasicSyntax() {
    // creating a model on a stack
    std::cout << "Creating a model on a stack"<< std::endl;
    Model model("some model");
    std::cout << "model by value: " << model.details() << std::endl << std::endl;

    // creating a reference to tha str
    std::cout << "Creating a ref to a model on a stack"<< std::endl;
    Model & modelRef = model;
    std::cout << "str by ref: " << modelRef.details() << std::endl << std::endl;

    // taking the addr of model to create a pointer
    std::cout << "Taking an addr of a model on a stack to create a pointer"<< std::endl;
    Model * modelPtr = &(model);
    std::cout << "addr of this model on a stack: " << modelPtr << std::endl;
    std::cout << "accessing to model function by ptr syntax: " << modelPtr->details() << std::endl;
    std::cout << "accessing to model function by dereferencing: " << (*(modelPtr)).details() << std::endl << std::endl;

    // creating a string on a heap with pointer syntax
    std::cout << "Creating a model on a heap with pointer syntax" << std::endl;
    Model * modelPtr2 = new Model("one more string");
    std::cout << "addr of a model on a heap: " << modelPtr2 << std::endl;
    std::cout << "accessing to model function by ptr syntax: " << modelPtr2->details() << std::endl;
    std::cout << "accessing to model function by dereferencing: " << (*(modelPtr2)).details() << std::endl << std::endl;

    // cleaning up memory
    delete modelPtr2;
}