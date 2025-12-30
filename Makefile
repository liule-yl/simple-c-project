# 简单的Makefile for Windows
CC = gcc
CFLAGS = -Wall
TARGET = simple_math.exe
TEST_TARGET = test_runner.exe

# 默认目标
all: $(TARGET) $(TEST_TARGET)

# 主程序
$(TARGET): simple_math.c simple_math.h
	$(CC) $(CFLAGS) -o $@ simple_math.c main.c

# 测试程序
$(TEST_TARGET): simple_math.c simple_math.h test_math.c test_runner.c
	$(CC) $(CFLAGS) -o $@ simple_math.c test_math.c test_runner.c

# 运行测试
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# 清理
clean:
	del *.exe *.o 2>nul

.PHONY: all test clean