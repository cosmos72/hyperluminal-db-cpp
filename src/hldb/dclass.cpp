#include "hldb/config.h"

#if defined(HAVE_CSTRING)
# include <string.h>
#elif defined(HAVE_STRING_H)
# include <string.h>
#endif

#include <vector>
#include <map>

#include "hldb/dclass.hpp"

using namespace std;

struct chars_less
{
    inline bool operator()(const char * lhs, const char * rhs) const
    {
        return strcmp(lhs ? lhs : "", rhs ? rhs : "") < 0;
    }
};



namespace hldb
{
    typedef map<const char *, const dclass *, chars_less> classes_map_type;
    
    static classes_map_type classes;

    const dclass * const dclass_dobject = new dclass(1, 2, 0, NULL,           "dobject");
    const dclass * const dclass_dclass  = new dclass(2, 2, 2, dclass_dobject, "dclass");
    
    void bootstrap_classes()
    {
        const_cast<dclass *>(dclass_dobject)->register_class();
        const_cast<dclass *>(dclass_dclass)->register_class();
    }

    static bool bootstrapped = (bootstrap_classes(), true);

    dclass::dclass(size_t id, size_t class_id, size_t next_instance_id, const dclass * super, const char * name)
        : dobject(id, class_id), _next_instance_id(next_instance_id), _super(super), _name(name)
    {
        /* cannot call register_class() yet, dclass_dclass is still NULL */
    }

    dclass::dclass(const char * name, const dclass * super)
        : dobject(dclass_dclass), _next_instance_id(no_id), _super(super),
        _name(name), _instance_destructor(NULL)
    {
        register_class();
    }
    
    void dclass::register_class()
    {
        dclass_dclass->register_instance(this);
        classes[_name] = this;
    }
    
    const dclass * dclass::find_class(const char * class_name)
    {
        classes_map_type::const_iterator iter = classes.find(class_name);
        return iter != classes.end() ? iter->second : NULL;
    }
}

