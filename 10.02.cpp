#define CATCH_CONFIG_RUNNER
#include "10.02.dir/catch.h"
#include <iostream>

#include "10.02.dir/suchen.h"

int main()
{
    if (Catch::Session().run())
    {
        return 1;
    }
    // Ihr Code ab hier ...


    return 0;
}

