#include "testPtrsAndRefs.h"
#include "testConsts.h"
#include "testLifecycle.h"
#include "testPassSmartPointers.h"
#include "testReturnSmartPointers.h"

int main()
{
    testPtrsAndRefs();
    testConsts();
    testLifecycle();
    testPassSmartPointers();
    testReturnSmartPtrs();
}