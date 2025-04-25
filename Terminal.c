#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void Write_Machine(const char* message) {
    printf("%s\n", message);
}

int main() {
    FILE *fptr;
    char filename[1000]; // Increased size for filename
    int num = 1;
    char string[1000]; // Increased size for string
    while (1) {
        char command[100]; // Increased size for command
        printf("$");
        scanf("%99s", command); // Limited input to avoid buffer overflow

        if (strcmp(command, "readf()") == 0) {
            printf("Enter the filename: ");
            scanf("%999s", filename); // Limited input to avoid buffer overflow
            fptr = fopen(filename, "r");
            if (fptr == NULL) {
                printf("Failed to open the file '%s'.\n", filename);
                continue;
            }
            char line[500];
            while (fgets(line, sizeof(line), fptr) != NULL) {
                printf("|%d| %s", num, line);
                num++;
            }
            fclose(fptr);
        }
        else if (strcmp(command, "addf()") == 0) {
            printf("Enter the filename: ");
            scanf("%999s", filename); // Limited input to avoid buffer overflow
            fptr = fopen(filename, "a");
            if (fptr == NULL) {
                printf("Failed to open the file '%s'.\n", filename);
                continue;
            }
            char data[500];
            printf("Enter data to append: ");
            scanf(" %[^\n]", data);  // Added space before %[^\n] to consume leading whitespace
            fprintf(fptr, "%s\n", data);
            fclose(fptr);
        }
        else if (strcmp(command, "startf()") == 0) {
            printf("Enter the filename: ");
            scanf("%999s", filename); // Limited input to avoid buffer overflow
            fptr = fopen(filename, "w");
            fclose(fptr);
        }
        else if (strncmp(command, "Write-Machine(", 14) == 0) {
            char message[500];
            char* opening_quote = strchr(command, '"'); // Find the opening quote
            if (opening_quote != NULL) {
                char* closing_quote = strchr(opening_quote + 1, '"'); // Find the closing quote
                if (closing_quote != NULL) {
                    strncpy(message, opening_quote + 1, closing_quote - opening_quote - 1); // Copy the message between the quotes
                    message[closing_quote - opening_quote - 1] = '\0'; // Null-terminate the message
                    Write_Machine(message);
                } else {
                    printf("Error: Missing closing quote.\n");
                }
            } else {
                printf("Error: Missing opening quote.\n");
            }
        }
        else if (strcmp(command, "bin()") == 0) {
            printf("Insert the path of the file:");
            char sig[500];
            scanf("%s", sig);
            const char *old_path = sig;
            printf("Insert the file name:");
            char string2[500];
            scanf("%s", string2);
            char new_path[1000];
            sprintf(new_path, "C:\\Users\\Admin\\HassanOS\\Bin\\%s", string2);
            if (rename(old_path, new_path) == 0) {
                printf("Successfully Binned\n");
            } else {
                printf("Error 0x125\n");
            }
        }
        else if (strcmp(command, "renamef()") == 0) {
            printf("What file do you want to rename:");
            char vi[500];
            scanf("%s", vi);
            printf("What do you want to rename the file:");
            char emacs[500];
            scanf("%s", emacs);
            if (rename(vi, emacs) == 0) {
                printf("Successful Rename\n");
            } else {
                printf("Error 0x8823\n");
            }
        }
        else if (strcmp(command, "restoref()") == 0) {
            printf("Insert the path of the file:");
            char signa[500];
            scanf("%s", signa);
            printf("Insert the file name:");
            char wow[500];
            scanf("%s", wow);
            char nev_path[500 + strlen(wow) + strlen("C:\\Users\\Admin\\HassanOS") + 1];
            sprintf(nev_path, "C:\\Users\\Admin\\HassanOS\\%s", wow);
            if (rename(signa, nev_path) == 0) {
                printf("File successfully restored\n");
            } else {
                printf("Error 0x6541\n");
            }
        }
        else if (strcmp(command, "Neksus") == 0) {
            system("Neksus");
        }
        else if (strcmp(command, "deletef()") == 0) {
            printf("Give me the file path:");
            char file_path[500];
            scanf("%499s", file_path);
            if (remove(file_path) == 0) {
                printf("File deleted successfully.\n");
            } else {
                printf("Error deleting the file.\n");
            }
        }
	else if (strcmp(command, "whoami") == 0) {
            char computerName[MAX_COMPUTERNAME_LENGTH + 1];
            DWORD size = sizeof(computerName);
	    printf("%s", computerName);
	}
        else if (strcmp(command, "terminatef()") == 0) {
            break; // Exit the loop and terminate the program
        }
        // Implement other commands similarly...
    }
    return 0;
}

