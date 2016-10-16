#include "hldb/dobject.hpp"
#include "hldb/dclass.hpp"


using namespace hldb;

int main()
{
  dobject * obj = new dobject();
  int ret = obj->get_id();
  obj->destroy();
  return ret;
}

