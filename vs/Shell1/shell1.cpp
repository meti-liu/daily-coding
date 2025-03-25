#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024   // 定义输入的最大长度
#define MAX_ARGS 64     // 定义最大参数个数

void parse_command(char* input, char** args) {
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
}

int main() {
    char input[MAX_LINE];    // 用户输入的命令
    char* args[MAX_ARGS];    // 存放解析后的命令和参数
    pid_t pid;               // 子进程ID
    int status;              // 子进程的退出状态

    while (1) {
        printf("myshell> "); // 输出命令提示符
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            break;  // 输入EOF时退出
        }

        // 解析用户输入的命令
        parse_command(input, args);

        // 检查是否输入了退出命令
        if (args[0] == NULL) {
            continue;  // 如果输入为空，继续等待输入
        }
        if (strcmp(args[0], "exit") == 0) {
            break;  // 输入 "exit" 时退出shell
        }

        // 创建子进程
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            continue;
        }

        if (pid == 0) {  // 子进程
            if (execvp(args[0], args) == -1) {  // 执行命令
                perror("Exec failed");
            }
            exit(EXIT_FAILURE);  // exec失败时退出子进程
        }
        else {  // 父进程
            if (waitpid(pid, &status, 0) == -1) {
                perror("Wait failed");
            }
            else {
                // 打印子进程的退出状态
                if (WIFEXITED(status)) {
                    printf("Child exited with status %d\n", WEXITSTATUS(status));
                }
                else {
                    printf("Child terminated abnormally\n");
                }
            }
        }
    }

    return 0;
}
