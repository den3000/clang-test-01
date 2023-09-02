#include "testPtrsAndRefs.h"
#include "testConsts.h"
#include "testLifecycle.h"
#include "testPassSmartPointers.h"
#include "testReturnSmartPointers.h"
#include "testPassToAndReturnFromFunctioin.h"

int main()
{
    testPtrsAndRefs();
    testConsts();
    testLifecycle();
    testPassToAndReturnFromFunctioin();
    testPassSmartPointers();
    testReturnSmartPtrs();
}