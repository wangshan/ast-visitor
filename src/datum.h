#ifndef AST_DETAIL_DATUM_H
#define AST_DETAIL_DATUM_H

#include <boost/utility.hpp>
#include <boost/variant.hpp>
#include <boost/optional.hpp>

#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <stdexcept>

namespace ast {
namespace detail {

struct Blank
{
    bool operator == (const Blank&) const { return true; }
    bool operator > (const Blank&) const { return false; }
    bool operator < (const Blank&) const { return false; }
    Blank& operator += (const Blank&) { return *this; }
    Blank& operator -= (const Blank&) { return *this; }
    Blank& operator *= (const Blank&) { return *this; }
    Blank& operator /= (const Blank&) { return *this; }
    Blank operator + (const Blank&) const { return Blank(); }
    Blank operator - (const Blank&) const { return Blank(); }
    Blank operator * (const Blank&) const { return Blank(); }
    Blank operator / (const Blank&) const { return Blank(); }
};

template <typename T>
inline bool operator > (const Blank& blank, const T& rhs) { return false; }

template <typename T>
inline bool operator > (const T& rhs, const Blank& blank) { return true; }

template <typename T>
inline bool operator < (const Blank& blank, const T& rhs) { return false; }

template <typename T>
inline bool operator < (const T& rhs, const Blank& blank) { return true; }

template <typename T>
inline T operator + (const T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator - (const T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator * (const T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator / (const T& lhs, const Blank& blank) { return lhs; }

/*
template <typename T>
inline T operator + (const Blank& blank, const T& rhs) { return rhs; }

template <typename T>
inline T operator - (const Blank& blank, const T& rhs) { return rhs; }

template <typename T>
inline T operator * (const Blank& blank, const T& rhs) { return rhs; }

template <typename T>
inline Blank operator / (const Blank& blank, const T& rhs) { return blank; }
*/

template <typename T>
inline T operator += (T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator -= (T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator *= (T& lhs, const Blank& blank) { return lhs; }

template <typename T>
inline T operator /= (T& lhs, const Blank& blank) { return lhs; }


inline std::ostream& operator<< (std::ostream& os, const Blank& blank)
{
    return os<<"(blank)";
}

typedef boost::variant<
        Blank, // default constructor of Datum will construct a Blank
        long,
        unsigned long,
        int,
        unsigned int,
        float,
        double,
        std::string
        > Datum;

using DatumID = unsigned short;
using DatumType = std::pair<DatumID, Datum>;
using Datums = std::map<DatumID, Datum>;

}
}

#endif
