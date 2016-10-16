#ifndef HLDB_FWD_HPP
#define HLDB_FWD_HPP

#include <cstddef>     // for std::size_t

namespace hldb
{
  enum { no_id = 0 };

  using size_t = std::size_t;

  struct empty { };

  class dobject;
  class dclass;
  
  extern dclass * const dclass_dobject;
  extern dclass * const dclass_dclass;
}

#endif // HLDB_FWD_HPP
