#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h> // Include ncurses library

// Define constants for commands
#define CMD_CALCULATOR 1
#define CMD_BANK 2
#define CMD_NEKSUS 3
#define CMD_EXIT 192
#define CMD_MESSAGE_BOARD 4
#define CMD_NOVA 5
#define CMD_SEEKSMART 6
#define CMD_SETTINGS 7

// Sample documents
char* documents[] = {
    "apple: https://www.apple.com/ https://en.wikipedia.org/wiki/Apple_Inc.",
    "banana: https://en.wikipedia.org/wiki/Banana",
    "orange: https://en.wikipedia.org/wiki/Orange_(fruit)"
};

// Function to print the time
void print_time() {
    time_t current_time;
    struct tm *local_time;
    
    time(&current_time);
    local_time = localtime(&current_time);
    
    if (local_time == NULL) {
        printf("Failed to get local time\n");
        return;
    }

    char time_string[100];
    if (strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M", local_time) == 0) {
        printf("Failed to format time\n");
        return;
    }

    printw("Current local time: %s\n", time_string);
}

// Function to print the bottom boxes
void print_bottom_boxes() {
    printw("+---+ +---+ +---+ +---+ +---+ +---+ +---+\n");
    printw("| c | | b | | n | | m | | t | | s | | 7 |\n");
    printw("+---+ +---+ +---+ +---+ +---+ +---+ +---+\n");
}

// Function to handle system calls
void handle_system_call(int cmd) {
    switch (cmd) {
        case CMD_CALCULATOR:
            printw("Launching Calculator...\n");
            system("calc");
            break;
        case CMD_BANK:
            printw("Launching Bank application...\n");
            system("Bank");
            break;
        case CMD_NEKSUS:
            printw("Launching Neksus application...\n");
            system("Neksus");
            break;
        case CMD_EXIT:
            exit(0);
            break;
        case CMD_MESSAGE_BOARD:
            printw("Launching Message Board...\n");
            system("Messageboard");
            break;
        case CMD_NOVA:
            printw("Launching Nova application...\n");
            system("Nova");
            break;
        case CMD_SEEKSMART:
            {
                char query[100];
                printw("Enter your search query: ");
                scanw("%99s", query);
                printw("Search Results:\n");
                // search(query); // Implement search function
            }
            break;
        case CMD_SETTINGS:
            printw("Launching Settings...\n");
            // Implement settings menu
            break;
        default:
            printw("Invalid command\n");
            break;
    }
}

// Function to handle user input and system calls
void handle_user_input() {
    int ch = getch();
    int cmd = 0;
    switch (ch) {
        case 'c':
            cmd = CMD_CALCULATOR;
            break;
        case 'b':
            cmd = CMD_BANK;
            break;
        case 'n':
            cmd = CMD_NEKSUS;
            break;
        case 'm':
            cmd = CMD_MESSAGE_BOARD;
            break;
        case 't':
            cmd = CMD_NOVA;
            break;
        case 's':
            cmd = CMD_SEEKSMART;
            break;
        case '7':
            cmd = CMD_SETTINGS;
            break;
        default:
            printw("Invalid command\n");
            return;
    }
    handle_system_call(cmd);
}

// Function to print the user interface
void print_interface() {
    clear(); // Clear the screen

    const char *message = "~HassanOS~";
    int term_width = getmaxx(stdscr);
    printw("%*s\n", term_width / 2 + strlen(message) / 2, message);

    // Print the time in the top-right corner
    printw("\n");
    printw("%*s", term_width - 20, "");
    print_time();

    // Print the bottom boxes
    print_bottom_boxes();
    refresh(); // Refresh the screen
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't echo characters
    keypad(stdscr, TRUE); // Enable keypad for function keys
    timeout(60000); // Set timeout for getch() to 60 seconds

    while (1) {
        print_interface();
        handle_user_input();
    }

    // End ncurses
    endwin();

    return 0;
}
