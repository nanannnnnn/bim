#include "./common.h" 

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

void processCommand(char *command, FILE **f, char *filename) {
    if (strcmp(command, "edit") == 0) {
        enterEditMode(*f);
    } else if (strcmp(command, "save") == 0) {
        // close and restore the file
        fclose(*f);
        *f = fopen(filename, "a+");
        printf("File saved.\n");
    } else if (strcmp(command, "exit") == 0) {
        fclose(*f);
        exit(0);
    } else {
        printf("Unknown command.\n");
    }
}

int main(int argc, char *argv[]) {
    char *filename = "myfile.txt"; 
    if (argc > 1) {
        filename = argv[1]; 
    }

    FILE *file = fopen(filename, "a+"); 
    if (file == NULL) {
        perror("Failed to open file"); 
        return 1; 
    }

    char command[BUFFER_SIZE];
    printf("Enter command ('edit', 'save', 'exit'):\n");
    while (fgets(command, BUFFER_SIZE, stdin)) {
        // delete \n in command
        command[strcspn(command, "\n")] = 0;
        processCommand(command, &file, filename);
        printf("Enter command ('edit', 'save', 'exit'):\n");
    }

    return 0;
}
