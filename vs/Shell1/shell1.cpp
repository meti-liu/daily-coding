#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024   // �����������󳤶�
#define MAX_ARGS 64     // ��������������

void parse_command(char* input, char** args) {
    int i = 0;
    args[i] = strtok(input, " \n");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
}

int main() {
    char input[MAX_LINE];    // �û����������
    char* args[MAX_ARGS];    // ��Ž����������Ͳ���
    pid_t pid;               // �ӽ���ID
    int status;              // �ӽ��̵��˳�״̬

    while (1) {
        printf("myshell> "); // ���������ʾ��
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            break;  // ����EOFʱ�˳�
        }

        // �����û����������
        parse_command(input, args);

        // ����Ƿ��������˳�����
        if (args[0] == NULL) {
            continue;  // �������Ϊ�գ������ȴ�����
        }
        if (strcmp(args[0], "exit") == 0) {
            break;  // ���� "exit" ʱ�˳�shell
        }

        // �����ӽ���
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            continue;
        }

        if (pid == 0) {  // �ӽ���
            if (execvp(args[0], args) == -1) {  // ִ������
                perror("Exec failed");
            }
            exit(EXIT_FAILURE);  // execʧ��ʱ�˳��ӽ���
        }
        else {  // ������
            if (waitpid(pid, &status, 0) == -1) {
                perror("Wait failed");
            }
            else {
                // ��ӡ�ӽ��̵��˳�״̬
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
