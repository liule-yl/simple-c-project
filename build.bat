@echo off
chcp 65001 >nul
echo ========================================
echo   C语言项目简单构建脚本
echo ========================================

REM 检查gcc是否可用
where gcc >nul 2>&1
if errorlevel 1 (
    echo 错误: 未找到gcc编译器
    echo 请安装MinGW并添加到PATH
    pause
    exit /b 1
)

echo 1. 清理旧文件...
del *.exe *.o 2>nul

echo 2. 编译库文件...
gcc -c simple_math.c -o simple_math.o

echo 3. 编译测试文件...
gcc -c test_math.c -o test_math.o
gcc -c test_runner.c -o test_runner.o

echo 4. 链接测试程序...
gcc simple_math.o test_math.o test_runner.o -o test_runner.exe

if exist test_runner.exe (
    echo 构建成功！
    echo 可执行文件: test_runner.exe
) else (
    echo 构建失败！
    exit /b 1
)

echo 5. 运行测试...
echo ========================================
test_runner.exe

REM 检查测试结果
if %errorlevel% equ 0 (
    echo ========================================
    echo ? 所有测试通过！
    exit /b 0
) else (
    echo ========================================
    echo ? 测试失败！
    exit /b 1
)