#include <stdio.h>
#include "simple_math.h"

// 声明测试函数
void test_add();
void test_subtract();
void test_multiply();
void test_divide();
void test_is_even();

// 全局测试统计
extern int tests_passed;
extern int tests_failed;

int main() {
    printf("开始运行单元测试...\n");
    printf("========================\n");
    
    // 运行所有测试
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_is_even();
    
    // 输出测试结果
    printf("\n========================\n");
    printf("测试完成！\n");
    printf("通过: %d\n", tests_passed);
    printf("失败: %d\n", tests_failed);
    printf("总计: %d\n", tests_passed + tests_failed);
    
    if (tests_failed == 0) {
        printf("? 所有测试通过！\n");
        return 0; // 成功
    } else {
        printf("? 有测试失败！\n");
        return 1; // 失败
    }
}