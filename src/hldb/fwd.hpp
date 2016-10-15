#ifndef HLDB_FWD_HPP
#define HLDB_FWD_HPP

#include <cstddef>     // for std::size_t

namespace hldb
{
    enum { no_id = 0 };

    using size_t = std::size_t;

    struct empty { };

    class dobject;
}

#endif // HLDB_FWD_HPP
