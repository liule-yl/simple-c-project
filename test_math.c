#include <stdio.h>
#include <string.h>
#include "simple_math.h"

// 测试用例计数
int tests_passed = 0;
int tests_failed = 0;

// 简单断言宏
#define ASSERT_EQ(actual, expected, message) \
    do { \
        if ((actual) == (expected)) { \
            printf("? %s\n", message); \
            tests_passed++; \
        } else { \
            printf("? %s - 期望: %d, 实际: %d\n", message, (expected), (actual)); \
            tests_failed++; \
        } \
    } while(0)

#define ASSERT_NEQ(actual, expected, message) \
    do { \
        if ((actual) != (expected)) { \
            printf("? %s\n", message); \
            tests_passed++; \
        } else { \
            printf("? %s - 不期望: %d, 实际: %d\n", message, (expected), (actual)); \
            tests_failed++; \
        } \
    } while(0)

// 测试函数
void test_add() {
    printf("\n=== 测试加法 ===\n");
    ASSERT_EQ(add(2, 3), 5, "2 + 3 = 5");
    ASSERT_EQ(add(-1, 1), 0, "-1 + 1 = 0");
    ASSERT_EQ(add(0, 0), 0, "0 + 0 = 0");
}

void test_subtract() {
    printf("\n=== 测试减法 ===\n");
    ASSERT_EQ(subtract(5, 3), 2, "5 - 3 = 2");
    ASSERT_EQ(subtract(3, 5), -2, "3 - 5 = -2");
}

void test_multiply() {
    printf("\n=== 测试乘法 ===\n");
    ASSERT_EQ(multiply(2, 3), 6, "2 * 3 = 6");
    ASSERT_EQ(multiply(0, 5), 0, "0 * 5 = 0");
}

void test_divide() {
    printf("\n=== 测试除法 ===\n");
    ASSERT_EQ(divide(6, 3), 2, "6 / 3 = 2");
    ASSERT_EQ(divide(5, 2), 2, "5 / 2 = 2 (整数除法)");
    ASSERT_EQ(divide(5, 0), 0, "5 / 0 返回 0");
}

void test_is_even() {
    printf("\n=== 测试偶数判断 ===\n");
    ASSERT_EQ(is_even(2), 1, "2 是偶数");
    ASSERT_EQ(is_even(3), 0, "3 不是偶数");
    ASSERT_EQ(is_even(0), 1, "0 是偶数");
}