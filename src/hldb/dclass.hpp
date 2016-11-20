#ifndef HLDB_DCLASS_HPP
#define HLDB_DCLASS_HPP

#include <map>

#include "hldb/dobject.hpp"

namespace hldb
{
    class dclass : public dobject
    {
    private:
        friend void bootstrap_classes();
        friend class dobject; // grant access to _instance_destructor
        typedef std::map<size_t, dobject *> instance_map_type;
        
        mutable size_t _next_instance_id;
        const dclass * _super;
        const char * _name;
        mutable instance_map_type _instance_objects;

        void register_class();
        inline void register_instance(dobject * obj) const { _instance_objects[obj->get_id()] = obj; }
        inline void unregister_instance(dobject * obj) const { _instance_objects.erase(obj->get_id()); }
        
        ~dclass();
      
    protected:
        void (*_instance_destructor)(dobject * obj);

    public:        
        dclass(const char * class_name, const dclass * super_class);

        /* only used for bootstrap */
        dclass(size_t id, size_t class_id, size_t next_instance_id, const dclass * super, const char * name);
        
        inline size_t next_instance_id() const { return ++_next_instance_id; }
        inline const dclass * get_super() const { return _super; }
        inline const char * get_name() const { return _name; }

        inline dobject * find_instance(size_t id) const
        {
            instance_map_type::const_iterator iter = _instance_objects.find(id);
            return iter != _instance_objects.end() ? iter->second : NULL;
        }
        
        inline static const dclass * find_class(size_t class_id)
        {
            return static_cast<const dclass *>(dclass_dclass->find_instance(class_id));
        }
        
        static const dclass * find_class(const char * class_name);
    };
}
    
#endif // HLDB_DCLASS_HPP
