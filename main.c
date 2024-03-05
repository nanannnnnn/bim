#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void enterEditMode(FILE *f) {
    char buffer[BUFFER_SIZE];
    printf("Entering edit mode (Type 'EXIT' to finish editing):\n");
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        if (strncmp(buffer, "EXIT", 4) == 0) {
            break;
        }
        fputs(buffer, f);
    }
}

void processCommand(char *command, FILE **f) {
    if (strcmp(command, "edit") == 0) {
        enterEditMode(*f);
    } else if (strcmp(command, "save") == 0) {
        // ファイルを一時的に閉じて保存
        fclose(*f);
        *f = fopen("myfile.txt", "a+");
        printf("File saved.\n");
    } else if (strcmp(command, "exit") == 0) {
        fclose(*f);
        exit(0);
    } else {
        printf("Unknown command.\n");
    }
}

int main() {
    FILE *file = fopen("myfile.txt", "a+");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char command[BUFFER_SIZE];
    printf("Enter command ('edit', 'save', 'exit'):\n");
    while (fgets(command, BUFFER_SIZE, stdin)) {
        // コマンドの改行文字を削除
        command[strcspn(command, "\n")] = 0;
        processCommand(command, &file);
        printf("Enter command ('edit', 'save', 'exit'):\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void enterEditMode(FILE *f) {
    char buffer[BUFFER_SIZE];
    printf("Entering edit mode (Type 'EXIT' to finish editing):\n");
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        if (strncmp(buffer, "EXIT", 4) == 0) {
            break;
        }
        fputs(buffer, f);
    }
}

void processCommand(char *command, FILE **f) {
    if (strcmp(command, "edit") == 0) {
        enterEditMode(*f);
    } else if (strcmp(command, "save") == 0) {
        // ファイルを一時的に閉じて保存
        fclose(*f);
        *f = fopen("myfile.txt", "a+");
        printf("File saved.\n");
    } else if (strcmp(command, "exit") == 0) {
        fclose(*f);
        exit(0);
    } else {
        printf("Unknown command.\n");
    }
}

int main() {
    FILE *file = fopen("myfile.txt", "a+");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char command[BUFFER_SIZE];
    printf("Enter command ('edit', 'save', 'exit'):\n");
    while (fgets(command, BUFFER_SIZE, stdin)) {
        // コマンドの改行文字を削除
        command[strcspn(command, "\n")] = 0;
        processCommand(command, &file);
        printf("Enter command ('edit', 'save', 'exit'):\n");
    }

    return 0;
}
