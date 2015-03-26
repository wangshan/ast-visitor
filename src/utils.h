#ifndef AST_UTIL_H
#define AST_UTIL_H

#include <typeinfo>
#include <sstream>
#include <string>
#include <cfloat>
#include <cstdlib> // we want the abs function from this header

namespace ast { namespace detail {

inline std::string parameterPackToString()
{
    return "\n";
}

template <typename T>
inline std::string parameterPackToString(const T& t)
{
    std::ostringstream oss;
    oss<<t<<" : of type "<<typeid(decltype(t)).name()<<"\n";
    return oss.str();
}

template <typename T1, typename... Ts>
inline std::string parameterPackToString(const T1& t1, const Ts&... ts)
{
    std::ostringstream oss;
    oss<<t1<<" : of type "<<typeid(decltype(t1)).name()<<", ";
    oss<<parameterPackToString(ts...);
    return oss.str();
}


}
}

#endif
