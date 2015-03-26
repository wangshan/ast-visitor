#ifndef AST_ASTVISITOR_H_INCLUDED
#define AST_ASTVISITOR_H_INCLUDED

#include <iostream>
#include <boost/optional.hpp>

namespace ast {

class AstNodeVisitor;

// The design of AstVisitable(s) and AstVisitableFailure(s) is based on an
// answer to my stackoverflow question here:
// http://stackoverflow.com/questions/28240936/whats-the-best-way-to-implement-ast-using-visitor-pattern-with-return-value

template <class T>
struct tag
{
    using type=T;
};

template <class...Ts>
struct types
{
    using type=types;
};

template <class T>
struct AstVisitable {
    virtual boost::optional<T> accept( tag<T>, AstNodeVisitor&v ) = 0;
    virtual ~AstVisitable() {};
};

template <>
struct AstVisitable<void> {
    virtual void accept( tag<void>, AstNodeVisitor&v ) = 0;
    virtual ~AstVisitable() {};
};

template <class Types>
struct AstVisitables;

template <>
struct AstVisitables< types<> > {
    virtual ~AstVisitables() {};
};

template <class T0, class...Ts>
struct AstVisitables<types<T0, Ts...> > : virtual AstVisitable<T0>
                                        , AstVisitables<types<Ts...> >
{
    using AstVisitable<T0>::accept;
};

using supported_ast_return_types = types<int, bool, std::string, void>;

class AstNode : public AstVisitables<supported_ast_return_types>
{
    public:
        void addLeft(AstNode* child) { m_left = child; }
        void addRight(AstNode* child) { m_right = child; }
        AstNode* left() { return m_left; }
        AstNode* right() { return m_right; }

    private:
        AstNode* m_left;
        AstNode* m_right;
};

template <class T>
struct AstVisitableFailure : virtual AstVisitable<T>
{
    boost::optional<T> accept( tag<T>, AstNodeVisitor& ) override
    {
        return {};
    }
};

template <>
struct AstVisitableFailure<void> : virtual AstVisitable<void>
{
    void accept( tag<void>, AstNodeVisitor& ) override
    {
        return;
    }
};

template <class Types>
struct AstVisitablesFailAll;

template <>
struct AstVisitablesFailAll< types<> >
{
    virtual ~AstVisitablesFailAll() {};
};

template <class T0, class...Ts>
struct AstVisitablesFailAll<types<T0, Ts...> >
                            : virtual AstVisitableFailure<T0>
                            , AstVisitablesFailAll<types<Ts...> >
{
    using AstVisitableFailure<T0>::accept;
};


class SumNode;
class CompareNode;
class ValueNode;

class AstNodeVisitor
{
    public:
        boost::optional<int> visitSumNode(SumNode& node);
        boost::optional<bool> visitCompareNode(CompareNode& node);
        boost::optional<int> visitValueNode(ValueNode& node);
};

class SumNode : public AstNode
              , public AstVisitablesFailAll<supported_ast_return_types>
{
    public:
        void accept(tag<void>, AstNodeVisitor& v) override
        {
            accept(tag<int>(), v );
        }

        boost::optional<int> accept(tag<int>, AstNodeVisitor& v) override
        {
            return v.visitSumNode(*this);
        }

        int eval(int lhs, int rhs) const
        {
            return lhs + rhs;
        }
};

class CompareNode : public AstNode
              , public AstVisitablesFailAll<supported_ast_return_types>
{
    public:
        void accept(tag<void>, AstNodeVisitor& v) override
        {
            accept(tag<bool>(), v );
        }

        boost::optional<bool> accept(tag<bool>, AstNodeVisitor& v) override
        {
            return v.visitCompareNode(*this);
        }

        bool eval(int lhs, int rhs) const
        {
            return lhs < rhs;
        }
};

class ValueNode : public AstNode
                , public AstVisitablesFailAll<supported_ast_return_types>
{
    private:
        int m_value;
    public:
        explicit ValueNode(int x)
            : m_value(x)
        {
        }

        void accept(tag<void>, AstNodeVisitor& v) override
        {
            accept(tag<int>(), v );
        }

        boost::optional<int> accept(tag<int>, AstNodeVisitor& v) override
        {
            return v.visitValueNode(*this);
        }

        int eval() const { return m_value; }
};


//
// implementation
// -- {

inline boost::optional<int> AstNodeVisitor::visitSumNode(SumNode& node)
{
    boost::optional<int> lhs = node.left()->accept(tag<int>(), *this);
    boost::optional<int> rhs = node.right()->accept(tag<int>(), *this);
    if (!lhs || !rhs) {
        return {};
    }

    return node.eval(*lhs, *rhs);
}

inline boost::optional<bool> AstNodeVisitor::visitCompareNode(CompareNode& node)
{
    boost::optional<int> lhs = node.left()->accept(tag<int>(), *this);
    boost::optional<int> rhs = node.right()->accept(tag<int>(), *this);
    if (!lhs || !rhs) {
        return {};
    }

    return node.eval(*lhs, *rhs);
}

inline boost::optional<int> AstNodeVisitor::visitValueNode(ValueNode& node)
{
    return node.eval();
}

// -- }

}

#endif

