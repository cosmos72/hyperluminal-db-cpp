#ifndef HLDB_DCLASS_HPP
#define HLDB_DCLASS_HPP

#include <string>

#include "hldb/dobject.hpp"

namespace hldb
{
    class dclass : public dobject
    {
    private:
      friend class dobject;
      
      size_t _next_instance_id;
      dclass * _super_class;
      std::string _class_name;

      ~dclass();
      
    protected:
      void (*_instance_destructor)(dobject * obj);

    public:
      dclass(const char * class_name, dclass * super_class);

      inline size_t next_instance_id() { return ++_next_instance_id; }
      inline dclass * get_super_class() const { return _super_class; }
      inline const std::string & get_name() const { return _class_name; }

      
      static dclass * get_class_by_id(size_t class_id);
      
      static dclass * get_class_by_name(const std::string & class_name);
    };
}
    
#endif // HLDB_DCLASS_HPP
