#include "./common.h" 

#define BUFFER_SIZE 1024

void enterEditMode(FILE *f) {
    char buffer[BUFFER_SIZE];
    int ch; 
    int x = 0, y = 0; 
    clear(); // clear the screen
    printw("Entering edit mode (Type CTRL+G to finish editing):\n");
    move(1, 0); // move the cursor to the next line

    while ((ch = getch()) != 7) { // press CTRL+G to finish
        if (ch == KEY_BACKSPACE ||  ch == 127) { // process the backspace
            if (x > 0) {
                getyx(stdscr, y, x); 
                move(y, --x); 
                delch(); 
            }
        } else {
            getyx(stdscr, y, x); // get the position of the current cursor position
            printw("%c", ch); 
            buffer[x++] = ch; 
            if (ch == '\n' || x >= BUFFER_SIZE - 1) {
                buffer[x] = '\0'; // finish the string
                fputs(buffer, f); 
                x = 0; // reset the buffer
            }
        }
    }
    // write into the file when the last line finished without starting a new line
    if (x > 0) {
        buffer[x] = '\0'; 
        fputs(buffer, f); 
    }
    refresh(); 
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
        endwin(); // end the ncurses mode
        exit(0);
    } else {
        printf("Unknown command.\n");
    }
}

int main(int argc, char *argv[]) {
    char *filename = "sample.txt"; 
    if (argc > 1) {
        filename = argv[1]; 
    }

    FILE *file = fopen(filename, "a+"); 
    if (file == NULL) {
        perror("Failed to open file"); 
        return 1; 
    }

    initscr(); // start the ncurses mode
    raw(); // nullify the line buffer ring
    keypad(stdscr, TRUE); // make the specific key valid
    noecho(); // hide the input string from the screen

    char command[BUFFER_SIZE];
    printw("Enter command ('edit', 'save', 'exit'):\n");
    while (1) {
        getstr(command); 
        processCommand(command, &file, filename);
        printw("Enter command ('edit', 'save', 'exit'):\n");
    }
    endwin(); // finish the ncurses mode
    return 0;
}
