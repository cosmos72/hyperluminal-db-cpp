#include "hldb/dobject.hpp"
#include "hldb/dclass.hpp"

namespace hldb
{
  dobject::dobject(dclass * cls) : _id(cls->next_instance_id()), _class_id(cls->get_id())
  { }

  dobject::~dobject()
  { }

  dclass * dobject::get_class() const
  {
    return dclass::get_class_by_id(_class_id);
  }
  
  void dobject::destroy()
  {
    dclass * cls = get_class();
    void (*destructor)(dobject * obj) = cls->_instance_destructor;
    if (destructor != NULL)
      destructor(this);
    else
      delete this;
  }
}
    
