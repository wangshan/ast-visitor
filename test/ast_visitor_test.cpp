#include <gtest/gtest.h>

#include <ast_visitor.h>

#include <iostream>

using namespace ::testing;
using namespace ast;

TEST(AstVisitorTest, testVisitBinaryNode)
{
    AstNodeVisitor visitor;

    SumNode* sumNode = new SumNode;
    ValueNode* valueNode1 = new ValueNode(10);
    ValueNode* valueNode2 = new ValueNode(15);
    sumNode->addLeft(valueNode1);
    sumNode->addRight(valueNode2);
    boost::optional<int> res = sumNode->accept(tag<int>(), visitor);
    if (res) {
        std::cout<<res.value()<<std::endl;
    }

    CompareNode* compNode = new CompareNode;
    compNode->addLeft(valueNode1);
    compNode->addRight(valueNode2);
    boost::optional<bool> res2 = compNode->accept(tag<bool>(), visitor);
    if (res2) {
        std::cout<<std::boolalpha<<res2.value()<<std::endl;
    }

    delete sumNode;
    delete compNode;
    delete valueNode1;
    delete valueNode2;
}
