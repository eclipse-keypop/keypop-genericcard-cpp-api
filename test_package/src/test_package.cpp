#include <iostream>

#include "keypop/genericcard/GenericCardApiProperties.hpp"
#include "keypop/genericcard/GenericCardSelectionExtension.hpp"

int
main()
{
    /* GenericCardSelectionExtension transitively pulls in keypop-reader-cpp-api's
     * CardSelectionExtension header; referencing the type here proves the
     * transitive dependency resolves through Conan/CMake alone. */
    using keypop::genericcard::GenericCardSelectionExtension;

    std::cout << "Keypop::GenericCard header-only package resolved and linked correctly (API version "
              << keypop::genericcard::GenericCardApiProperties_VERSION << ")" << std::endl;
    return 0;
}
