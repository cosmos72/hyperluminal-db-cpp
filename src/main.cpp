#include "hldb/dvar.hpp"
#include "hldb/dobject.hpp"


using namespace hldb;

int main()
{
    dvar<const dobject *> abc((const dobject *)1);
    return (size_t)(abc += 2);
}

