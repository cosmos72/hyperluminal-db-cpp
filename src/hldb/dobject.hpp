#ifndef HLDB_OBJECT_HPP
#define HLDB_OBJECT_HPP

#include "hldb/fwd.hpp" // for hldb { dobject, dclass } forward declarations


namespace hldb
{
    class dobject
    {
    private:
      size_t _id;

    protected:
      explicit dobject(size_t id);

    public:
      inline size_t get_id() const { return _id; }
    };
}
    
#endif // HLDB_OBJECT_HPP
