#ifndef AST_GTEST_PROD_H_
#define AST_GTEST_PROD_H_

#include <gtest/gtest_prod.h>

#ifndef DECLARE_FRIEND_TEST
#define DECLARE_FRIEND_TEST(test_case_name, test_name)\
class test_case_name##_##test_name##_Test
#endif

#endif // AST_GTEST_PROD_H
