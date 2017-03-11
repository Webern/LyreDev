//  Copyright (c) by Matthew James Briggs. All rights reserved.

#include <iostream>
#include "Registry.h"
#include "SampleObject.h"

int main()
{
    using namespace lyre;
    Registry registry;
    SampleObject a{registry};
    SampleObject b{registry};
    return 0;
}
