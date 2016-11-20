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
        
        /* only used for bootstrap */
        inline dobject(size_t id, size_t class_id) : _id(id), _class_id(class_id)
        { }
        
    protected:
        ~dobject();
        
    public:
        explicit dobject(const dclass * cls = dclass_dobject);
        
        inline size_t get_id() const { return _id; }
        const dclass * get_class() const;
        
        void destroy();
    };
}

#endif // HLDB_DOBJECT_HPP
