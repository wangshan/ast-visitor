#ifndef AST_OPERATIONS_H
#define AST_OPERATIONS_H

#include "utils.h"
#include <ast_visitor.h>

namespace ast { namespace detail {


struct IsBlank : public boost::static_visitor<bool>
{
    bool operator()(const Blank& a) const
    {
        return true;
    }

    template<typename T>
    bool operator()(const T& a) const
    {
        return false;
    }
};


struct Plus : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(Datum(a+b))
    {
        return Datum(a+b);
    }

    // TODO: should I disable a specialisation for std::string?

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid Plus operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "+";
};

struct Minus : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(Datum(a-b))
    {
        return Datum(a-b);
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid Minus operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }
    static constexpr const char* text = "-";
};

struct Multiplies : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(Datum(a*b))
    {
        return Datum(a*b);
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid Multiplies operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "*";
};

struct Divides : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(Datum(a/b))
    {
        return Datum(a/b);
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid Divides operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "/";
};

struct Greater : public boost::static_visitor<bool>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(a > b)
    {
        return a > b;
    }

    template <typename... Ts>
    bool operator()(const Ts&... params) const
    {
        std::string err("invalid \">\" comparison operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = ">";
};

struct Less : public boost::static_visitor<bool>
{
    template <typename T, typename U>
    auto operator()(const T& a, const U& b) const
    -> decltype(a < b)
    {
        return a < b;
    }

    template <typename... Ts>
    bool operator()(const Ts&... params) const
    {
        std::string err("invalid \"<\" comparison operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "<";
};


struct Equal : public boost::static_visitor<bool>
{
    // if different type, check comparibility
    template <typename T, typename U>
    auto operator()(const T&a, const U&b) const
    -> decltype(a == b)
    {
        return a == b;
    }

    // if one type is double of float, use a special equal operator --{
    template<typename T>
    auto operator()(double a, const T& b) const
    -> decltype(a == b)
    {
        return almostEqual(a, b);
    }

    template<typename T>
    auto operator()(const T& a, double b) const
    -> decltype(a == b)
    {
        return almostEqual(a, b);
    }

    template<typename T>
    auto operator()(float a, const T& b) const
    -> decltype(a == b)
    {
        return almostEqual(a, b);
    }

    template<typename T>
    auto operator()(const T& a, float b) const
    -> decltype(a == b)
    {
        return almostEqual(a, b);
    }
    // --}

    // must give better match for the 4 combinations of double and float,
    // otherwise will complain ambiguous --{
    bool operator()(double a, double b) const
    {
        return almostEqual(a, b);
    }

    bool operator()(double a, float b) const
    {
        return almostEqual(a, b);
    }

    bool operator()(float a, float b) const
    {
        return almostEqual(a, b);
    }

    bool operator()(float a, double b) const
    {
        return almostEqual(a, b);
    }
    // --}

    template <typename... Ts>
    bool operator()(const Ts&... params) const
    {
        std::string err("invalid \"==\" comparison operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "==";
};

struct MultipliesTo : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(T& a, const U& b) const
    -> decltype(Datum(static_cast<T>(a*=b)))
    {
        return Datum(static_cast<T>(a*=b));
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid MultipliesTo operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "*=";
};

struct DividesFrom : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(T& a, const U& b) const
    -> decltype(Datum(static_cast<T>(a/=b)))
    {
        return Datum(static_cast<T>(a/=b));
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid DividesFrom operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "/=";
};

struct PlusTo : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(T& a, const U& b) const
    -> decltype(Datum(static_cast<T>(a+=b)))
    {
        return Datum(static_cast<T>(a+=b));
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid PlusTo operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "+=";
};

struct MinusFrom : public boost::static_visitor<Datum>
{
    template <typename T, typename U>
    auto operator()(T& a, const U& b) const
    -> decltype(Datum(static_cast<T>(a-=b)))
    {
        return Datum(static_cast<T>(a-=b));
    }

    template <typename... Ts>
    Datum operator()(const Ts&... params) const
    {
        std::string err("invalid MinusFrom operands: ");
        throw std::invalid_argument(err + parameterPackToString(params...));
    }

    static constexpr const char* text = "-=";
};

// helper operators
// --{

// NOTE: the below functions takes non-const params because otherwise implicit
// conversion will come to play and we end up with endless recurssion:
// each static visitor will check for applicability of each operator and always
// find true, because the operands are converted to Datum these functions are
// invoked.
// --{

inline Datum operator + (Datum& lhs, Datum& rhs)
{
    return boost::apply_visitor(Plus(), lhs, rhs);
}

inline Datum operator - (Datum& lhs, Datum& rhs)
{
    return boost::apply_visitor(Minus(), lhs, rhs);
}

inline Datum operator * (Datum& lhs, Datum& rhs)
{
    return boost::apply_visitor(Multiplies(), lhs, rhs);
}

inline Datum operator / (Datum& lhs, Datum& rhs)
{
    return boost::apply_visitor(Divides(), lhs, rhs);
}

//--}

inline Datum operator += (Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(PlusTo(), lhs, rhs);
}

inline Datum operator -= (Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(MinusFrom(), lhs, rhs);
}

inline Datum operator *= (Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(MultipliesTo(), lhs, rhs);
}

inline Datum operator /= (Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(DividesFrom(), lhs, rhs);
}

inline bool operator > (Datum& lhs, Datum& rhs)
{
    return boost::apply_visitor(Greater(), lhs, rhs);
}

inline bool operator >= (const Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(Greater(), lhs, rhs)
        || boost::apply_visitor(Equal(), lhs, rhs);
}

// NOTE: can't define a non-member operator < for Datum, because operator < is 
// already defined as member of variant, but the default behaviour is not good:
//
//// If which() == rhs.which() then: content_this < content_rhs,
//// where content_this is the content of *this and content_rhs is the content of rhs.
//// Otherwise: which() < rhs.which().
//
// see below for the work around
//
// the same applies to operator ==

inline bool operator <= (const Datum& lhs, const Datum& rhs)
{
    return boost::apply_visitor(Less(), lhs, rhs)
        || boost::apply_visitor(Equal(), lhs, rhs);
}

inline bool operator != (const Datum& lhs, const Datum& rhs)
{
    try {
        return !boost::apply_visitor(Equal(), lhs, rhs);
    }
    catch (...) {
        return true;
    }
}

// --}


}
}


// NOTE: get the desired behaviour of operator < for boost::variant by adding a
// specialisation for Datum
namespace boost {
template<>
inline bool ast::detail::Datum::operator < (const ast::detail::Datum& rhs) const
{
    return boost::apply_visitor(ast::detail::Less(), *this, rhs);
}

template<>
inline bool ast::detail::Datum::operator == (const ast::detail::Datum& rhs) const
{
    return boost::apply_visitor(ast::detail::Equal(), *this, rhs);
}

}

#endif
