#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Function to initialize hardware
void initialize_hardware() {
    // Initialize essential hardware components here
    // Example: CPU initialization, memory initialization, etc.
}

// Function to simulate the bootloader progress
void print_progress(const char *message) {
    printf("%s", message);
    fflush(stdout); // Ensure the message is displayed immediately
    sleep(1);
}

void print_centered(const char *text, int term_width) {
    int text_length = strlen(text);
    int start_pos = (term_width - text_length) / 2;

    for (int i = 0; i < start_pos; i++) {
        putchar(' ');
    }
    printf("%s\n", text);
}
int main() {
    // Initialize hardware
    initialize_hardware();

    // Print initial message
    print_progress("Starting bootloader...\n");

    // Simulate loading process
    for (int i = 1; i <= 10; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        for (int j = 0; j < 10 - i; j++) {
            printf(" ");
        }
        printf("] %d%%", i * 10);
        fflush(stdout);
        sleep(1);
    }

    // Print message indicating starting OS
    print_progress("\nStarting OS...\n");

    // Simulate loading and executing the OS
    // Replace the system("HassanOS") with the actual command to load your OS
    // For simplicity, we'll just print a message indicating OS execution
    system("cls"); // Clear screen (for Windows)
    system("clear"); // Clear screen (for Unix-like systems)
    system("HassanOS"); // Assuming HassanOS is an executable in the same directory

    return 0;
}
