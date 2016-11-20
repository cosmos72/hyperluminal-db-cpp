#include "hldb/dobject.hpp"
#include "hldb/dclass.hpp"


using namespace hldb;

int main()
{
    dobject * obj = new dobject();
    size_t id = obj->get_id();
    dobject * obj2 = dclass_dobject->find_instance(id);
    int ret = obj == obj2 ? 0 : 1;
    obj->destroy();
    return ret;
}

