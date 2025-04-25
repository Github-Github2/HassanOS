#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h> // for _getch()

void print_centered(const char *text, int term_width, int num_lines) {
    int text_length = strlen(text);
    int start_pos = (term_width - text_length) / 2;
    for (int i = 0; i < start_pos; i++) {
        putchar(' ');
    }
    printf("%s\n", text);
    for (int i = 0; i < num_lines; i++) {
        printf("\n");
    }
}

void print_bottom_boxes(int selected) {
    if (selected == 1) printf("+---+ +---+ +---+\n| c | | b | | n |\n+---+ +---+ +---+\n");
    else if (selected == 2) printf("+---+ +---+ +---+\n| c | | b | | n |\n+---+ +---+ +---+\n");
    else if (selected == 3) printf("+---+ +---+ +---+\n| c | | b | | n |\n+---+ +---+ +---+\n");
    else printf("+---+ +---+ +---+\n| c | | b | | n |\n+---+ +---+ +---+\n");
}

int main() {
    int term_width = 80; // Adjust according to your terminal size
    int term_height = 24; // Adjust according to your terminal size
    int selected = 0;

    while (1) {
        system("cls");
        const char *message = "~HassanOS~";
        print_centered(message, term_width, 10);

        int lines_to_bottom = term_height - 14;
        for (int i = 0; i < lines_to_bottom; i++) {
            printf("\n");
        }
        print_bottom_boxes(selected);
        
        int ch = _getch(); // Read keypress
        if (ch == '1') selected = 1;
        else if (ch == '2') selected = 2;
        else if (ch == '3') selected = 3;
        else if (ch == 27) break; // ESC to exit
    }

    return 0;
}
