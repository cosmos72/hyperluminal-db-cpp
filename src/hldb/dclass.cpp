#include <vector>
#include <map>

#include "hldb/dclass.hpp"

namespace hldb
{
  static std::vector<dclass *>  all_classes_by_id;
  static std::map<std::string, dclass *> all_classes_by_name;
        
  dclass * const dclass_dobject = new dclass("dobject", NULL);
  dclass * const dclass_dclass  = new dclass("dclass", dclass_dobject);

  dclass::dclass(const char * class_name, dclass * super_class)
    : dobject(no_id), _next_instance_id(), _super_class(super_class),
      _class_name(class_name), _instance_destructor(NULL)
  {
    dclass * cls = dclass_dclass;
    size_t id;
    if (cls != NULL)
    {
      id = _id = cls->next_instance_id();
      _class_id = cls->get_id();
    }
    else
    {
      static size_t bootstrap_id = 0;
      id = _id = ++bootstrap_id;
      _class_id = 2;
      if (id == 2)
      {
        /* we are initializing dclass_dclass */
        _next_instance_id = id;
      }
    }
      
    if (all_classes_by_id.size() <= id)
      all_classes_by_id.resize(id + 1);
    all_classes_by_id[id] = this;
    all_classes_by_name[_class_name] = this;
  }

  dclass * dclass::get_class_by_id(size_t class_id)
  {
    size_t max_id =  all_classes_by_id.size();
    return class_id < max_id ? all_classes_by_id[class_id] : NULL;
  }

  dclass * dclass::get_class_by_name(const std::string & class_name)
  {
    std::map<std::string, dclass *>::const_iterator iter = all_classes_by_name.find(class_name);
    return iter != all_classes_by_name.end() ? iter->second : NULL;
  }
}
    
