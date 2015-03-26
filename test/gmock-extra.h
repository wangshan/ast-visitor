#ifndef GTEST_GMOCK_EXTRA_H_INCLUDED
#define GTEST_GMOCK_EXTRA_H_INCLUDED

#include <gmock/gmock.h>


// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD0_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      ) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 0), \
        this_method_does_not_take_0_arguments); \
    GMOCK_MOCKER_(0, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(0, constness, Method).Invoke(); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method() constness ex { \
    GMOCK_MOCKER_(0, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(0, constness, Method).With(); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(0, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD1_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 1), \
        this_method_does_not_take_1_argument); \
    GMOCK_MOCKER_(1, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(1, constness, Method).Invoke(gmock_a1); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1) constness ex { \
    GMOCK_MOCKER_(1, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(1, constness, Method).With(gmock_a1); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(1, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD2_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 2), \
        this_method_does_not_take_2_arguments); \
    GMOCK_MOCKER_(2, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(2, constness, Method).Invoke(gmock_a1, gmock_a2); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2) constness ex { \
    GMOCK_MOCKER_(2, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(2, constness, Method).With(gmock_a1, gmock_a2); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(2, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD3_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 3), \
        this_method_does_not_take_3_arguments); \
    GMOCK_MOCKER_(3, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(3, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3) constness ex { \
    GMOCK_MOCKER_(3, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(3, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(3, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD4_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 4), \
        this_method_does_not_take_4_arguments); \
    GMOCK_MOCKER_(4, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(4, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4) constness ex { \
    GMOCK_MOCKER_(4, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(4, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(4, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD5_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 5), \
        this_method_does_not_take_5_arguments); \
    GMOCK_MOCKER_(5, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(5, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5) constness ex { \
    GMOCK_MOCKER_(5, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(5, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(5, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD6_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 6), \
        this_method_does_not_take_6_arguments); \
    GMOCK_MOCKER_(6, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(6, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6) constness ex { \
    GMOCK_MOCKER_(6, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(6, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(6, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD7_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 7), \
        this_method_does_not_take_7_arguments); \
    GMOCK_MOCKER_(7, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(7, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7) constness ex { \
    GMOCK_MOCKER_(7, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(7, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(7, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD8_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 8), \
        this_method_does_not_take_8_arguments); \
    GMOCK_MOCKER_(8, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(8, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8) constness ex { \
    GMOCK_MOCKER_(8, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(8, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(8, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD9_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 9), \
        this_method_does_not_take_9_arguments); \
    GMOCK_MOCKER_(9, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(9, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, \
        gmock_a9); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9) constness ex { \
    GMOCK_MOCKER_(9, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(9, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, \
        gmock_a9); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(9, constness, \
      Method)

// INTERNAL IMPLEMENTATION - DON'T USE IN USER CODE!!!
#define GMOCK_METHOD10_WITH_EX(tn, constness, ex, ct, Method, ...) \
  GMOCK_RESULT_(tn, __VA_ARGS__) ct Method( \
      GMOCK_ARG_(tn, 1, __VA_ARGS__) gmock_a1, \
      GMOCK_ARG_(tn, 2, __VA_ARGS__) gmock_a2, \
      GMOCK_ARG_(tn, 3, __VA_ARGS__) gmock_a3, \
      GMOCK_ARG_(tn, 4, __VA_ARGS__) gmock_a4, \
      GMOCK_ARG_(tn, 5, __VA_ARGS__) gmock_a5, \
      GMOCK_ARG_(tn, 6, __VA_ARGS__) gmock_a6, \
      GMOCK_ARG_(tn, 7, __VA_ARGS__) gmock_a7, \
      GMOCK_ARG_(tn, 8, __VA_ARGS__) gmock_a8, \
      GMOCK_ARG_(tn, 9, __VA_ARGS__) gmock_a9, \
      GMOCK_ARG_(tn, 10, __VA_ARGS__) gmock_a10) constness ex { \
    GTEST_COMPILE_ASSERT_((::std::tr1::tuple_size<                          \
        tn ::testing::internal::Function<__VA_ARGS__>::ArgumentTuple>::value \
            == 10), \
        this_method_does_not_take_10_arguments); \
    GMOCK_MOCKER_(10, constness, Method).SetOwnerAndName(this, #Method); \
    return GMOCK_MOCKER_(10, constness, Method).Invoke(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10); \
  } \
  ::testing::MockSpec<__VA_ARGS__>& \
      gmock_##Method(GMOCK_MATCHER_(tn, 1, __VA_ARGS__) gmock_a1, \
                     GMOCK_MATCHER_(tn, 2, __VA_ARGS__) gmock_a2, \
                     GMOCK_MATCHER_(tn, 3, __VA_ARGS__) gmock_a3, \
                     GMOCK_MATCHER_(tn, 4, __VA_ARGS__) gmock_a4, \
                     GMOCK_MATCHER_(tn, 5, __VA_ARGS__) gmock_a5, \
                     GMOCK_MATCHER_(tn, 6, __VA_ARGS__) gmock_a6, \
                     GMOCK_MATCHER_(tn, 7, __VA_ARGS__) gmock_a7, \
                     GMOCK_MATCHER_(tn, 8, __VA_ARGS__) gmock_a8, \
                     GMOCK_MATCHER_(tn, 9, __VA_ARGS__) gmock_a9, \
                     GMOCK_MATCHER_(tn, 10, \
                         __VA_ARGS__) gmock_a10) constness ex { \
    GMOCK_MOCKER_(10, constness, Method).RegisterOwner(this); \
    return GMOCK_MOCKER_(10, constness, Method).With(gmock_a1, gmock_a2, \
        gmock_a3, gmock_a4, gmock_a5, gmock_a6, gmock_a7, gmock_a8, gmock_a9, \
        gmock_a10); \
  } \
  mutable ::testing::FunctionMocker<__VA_ARGS__> GMOCK_MOCKER_(10, constness, \
      Method)

#define MOCK_METHOD0_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD0_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD1_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD1_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD2_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD2_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD3_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD3_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD4_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD4_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD5_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD5_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD6_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD6_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD7_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD7_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD8_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD8_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD9_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD9_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)
#define MOCK_METHOD10_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD10_WITH_EX(, , EXCEPT_SPEC, , m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD0_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD1_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD2_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD3_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD4_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD5_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD6_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD7_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD8_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD9_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD10_WITH_EX(, const, EXCEPT_SPEC, m, __VA_ARGS__)

#define MOCK_METHOD0_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD0_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD1_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD1_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD2_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD2_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD3_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD3_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD4_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD4_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD5_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD5_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD6_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD6_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD7_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD7_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD8_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD8_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD9_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD9_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_METHOD10_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) GMOCK_METHOD10_WITH_EX(typename, , EXCEPT_SPEC, m, __VA_ARGS__)

#define MOCK_CONST_METHOD0_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD0_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD1_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD1_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD2_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD2_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD3_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD3_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD4_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD4_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD5_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD5_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD6_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD6_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD7_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD7_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD8_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD8_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD9_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD9_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)
#define MOCK_CONST_METHOD10_T_WITH_EXCEPT_SPEC(m, EXCEPT_SPEC, ...) \
    GMOCK_METHOD10_WITH_EX(typename, const, EXCEPT_SPEC, m, __VA_ARGS__)

#endif

