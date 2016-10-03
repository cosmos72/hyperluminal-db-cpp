#ifndef HLDB_TRAITS_HPP
#define HLDB_TRAITS_HPP

#include <type_traits>  // for std::enable_if_t<>, std::is_integral<>, std::is_base_of<>

#include "hldb/fwd.hpp" // for hldb { size_t, empty, dobject }

namespace hldb
{
    template<class T>
        struct enable_if_integral_or_float : std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, empty>
    { };

    template<class T>
        using enable_if_integral_or_float_t = typename enable_if_integral_or_float<T>::type;
    
    
    template<class T>
        struct enable_if_extends_dobject : std::enable_if<std::is_base_of<dobject, T>::value, empty>
    { };
    
    template<class T>
        using enable_if_extends_dobject_t = typename enable_if_extends_dobject<T>::type;

}

#endif // HLDB_TRAITS_HPP
