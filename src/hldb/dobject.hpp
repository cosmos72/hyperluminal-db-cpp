#ifndef HLDB_DOBJECT_HPP
#define HLDB_DOBJECT_HPP

#include "hldb/fwd.hpp" // for hldb { dobject, dclass } forward declarations


namespace hldb
{
    class dobject
    {
    private:
      friend class dclass;
      
      size_t _id, _class_id;

      // do not initialize. used by dclass() constructor
      inline dobject(size_t dummy)
      { }

    protected:
      ~dobject();

    public:
      explicit dobject(dclass * cls = dclass_dobject);

      inline size_t get_id() const { return _id; }
      dclass * get_class() const;

      void destroy();
    };
}
    
#endif // HLDB_DOBJECT_HPP
