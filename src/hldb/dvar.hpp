#ifndef HLDB_DVAR_HPP
#define HLDB_DVAR_HPP

#include "hldb/traits.hpp" // for struct enable_if_...<T> 

namespace hldb
{


    template<class T> class dvar : enable_if_integral_or_float_t<T>
    {
    private:
#ifdef HLDB_STM
        size_t version;
#endif    
        
        T value;
        
#ifdef HLDB_STM
        char pad[sizeof(size_t) - sizeof(T)];
#endif    
        
    public:
        inline dvar() :
#ifdef HLDB_STM
            version(),
#endif
            value()
            { }
        
        explicit inline dvar(T val) :
#ifdef HLDB_STM
            version(),
#endif
            value(val)
            { }
        
        inline ~dvar()
        { }
        
        inline T get() const
        {
            return value;
        }
        
        inline T set(T val)
        {
            value = val;
            return val;
        }
        
        inline operator T() const
        {
            return get();
        }
        
        inline T operator=(T val)
        {
            return set(val);
        }
        
        inline T operator++()
        {
            return set(get() + 1);
        }
        
        inline T operator++(int)
        {
            T tmp = get();
            set(tmp + 1);
            return tmp;
        }
        
        inline T operator--()
        {
            return set(get() - 1);
        }
        
        inline T operator--(int)
        {
            T tmp = get();
            set(tmp - 1);
            return tmp;
        }
        
        inline T operator+=(T delta)
        {
            return set(get() + delta);
        }
        
        inline T operator-=(T delta)
        {
            return set(get() - delta);
        }
        
        inline T operator&=(T delta)
        {
            return set(get() & delta);
        }
        
        inline T operator|=(T delta)
        {
            return set(get() | delta);
        }
        
        inline T operator^=(T delta)
        {
            return set(get() ^ delta);
        }
    };
    
    
    
    template<class T> class dvar<T *> : enable_if_extends_dobject_t<T>
    {
    private:
#ifdef HLDB_STM
        size_t version;
#endif    
        
        size_t offset;
        
        static char sizeof_size_t_equal_sizeof_T_pointer[sizeof(size_t) == sizeof(T *) ? 0 : -1];
        
        
    public:
        inline dvar() :
#ifdef HLDB_STM
            version(),
#endif
            offset()
            { }
        
        explicit inline dvar(T * val) :
#ifdef HLDB_STM
            version(),
#endif
            offset()
            {
                set(val);
            }
        
        inline ~dvar()
        { }
        
        inline T * get() const
        {
            return reinterpret_cast<T *>
                (const_cast<char *>
                    (reinterpret_cast<const char *>(this)
                      + offset));
        }
        
        inline T * set(T * val)
        {
            offset = (size_t)
                (reinterpret_cast<const char *>(val)
                  - reinterpret_cast<const char *>(this));
            return val;
        }
        
        inline operator T *() const
        {
            return get();
        }
        
        inline T * operator=(T * val)
        {
            return set(val);
        }
        
        inline T * operator++()
        {
            return set(get() + 1);
        }
        
        inline T * operator++(int)
        {
            T * tmp = get();
            set(tmp + 1);
            return tmp;
        }
        
        inline T * operator--()
        {
            return set(get() - 1);
        }
        
        inline T * operator--(int)
        {
            T * tmp = get();
            set(tmp - 1);
            return tmp;
        }
        
        inline T * operator+=(size_t delta)
        {
            return set(get() + delta);
        }
        
        inline T * operator-=(size_t delta)
        {
            return set(get() - delta);
        }
    };
    
}

#endif // HLDB_DVAR_HPP
