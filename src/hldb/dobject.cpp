#include "hldb/dobject.hpp"
#include "hldb/dclass.hpp"

namespace hldb
{
    dobject::dobject(const dclass * cls) : _id(cls->next_instance_id()), _class_id(cls->get_id())
    {
        cls->register_instance(this);
    }
    
    dobject::~dobject()
    { }
    
    const dclass * dobject::get_class() const
    {
        return dclass::find_class(_class_id);
    }
    
    void dobject::destroy()
    {        
        const dclass * cls = get_class();
        if (cls != NULL)
        {
            cls->unregister_instance(this);
            void (*destructor)(dobject * obj) = cls->_instance_destructor;
            if (destructor != NULL)
            {
                destructor(this);
                return;
            }
        }
        delete this;
    }
}

