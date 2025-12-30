pipeline {
    agent any
    
    stages {
        stage('检出代码') {
            steps {
                echo '正在克隆代码仓库...'
                git branch: 'main',
                    url: 'https://github.com/yourname/simple-c-project.git'
            }
        }
        
        stage('构建项目') {
            steps {
                bat '''
                    echo 检查编译器版本...
                    gcc --version
                    
                    echo 开始构建...
                    build.bat
                '''
            }
        }
        
        stage('运行测试') {
            steps {
                bat '''
                    echo 运行单元测试...
                    test_runner.exe
                '''
            }
            
            post {
                always {
                    // 生成简单的测试报告
                    bat '''
                        echo 生成测试报告...
                        echo "<html><head><title>测试报告</title></head>" > test_report.html
                        echo "<body><h1>测试结果</h1>" >> test_report.html
                        
                        REM 运行测试并捕获输出
                        test_runner.exe > test_output.txt 2>&1
                        
                        echo "<pre>" >> test_report.html
                        type test_output.txt >> test_report.html
                        echo "</pre>" >> test_report.html
                        echo "</body></html>" >> test_report.html
                    '''
                    
                    // 发布HTML报告
                    publishHTML([
                        allowMissing: true,
                        alwaysLinkToLastBuild: true,
                        keepAll: true,
                        reportDir: '.',
                        reportFiles: 'test_report.html',
                        reportName: '测试报告'
                    ])
                }
            }
        }
    }
    
    post {
        success {
            echo '? 构建和测试成功！'
        }
        failure {
            echo '? 构建或测试失败！'
        }
    }
}