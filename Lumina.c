#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 512
#define MAX_VARS 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;

void say(const char *message) {
    printf("%s", message);
}

void inputc(const char *var_name) {
    char value[MAX_LINE_LENGTH];
    printf(" ");
    if (fgets(value, sizeof(value), stdin) != NULL) {
        value[strcspn(value, "\n")] = '\0';
        for (int i = 0; i < var_count; i++) {
            if (strcmp(variables[i].name, var_name) == 0) {
                strncpy(variables[i].value, value, MAX_LINE_LENGTH);
                variables[i].value[MAX_LINE_LENGTH - 1] = '\0';
                return;
            }
        }
        fprintf(stderr, "Variable %s not found.\n", var_name);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }
}

void sayinput(const char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, var_name) == 0) {
            printf("%s", variables[i].value);
            return;
        }
    }
    fprintf(stderr, "Variable %s not found.\n", var_name);
}

void set_variable(const char *var_name) {
    if (var_count < MAX_VARS) {
        strncpy(variables[var_count].name, var_name, MAX_LINE_LENGTH);
        variables[var_count].name[MAX_LINE_LENGTH - 1] = '\0';
        variables[var_count].value[0] = '\0';
        var_count++;
    } else {
        fprintf(stderr, "Maximum number of variables reached.\n");
    }
}

void num_variable(const char *var_name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, var_name) == 0) {
            snprintf(variables[i].value, MAX_LINE_LENGTH, "%d", value);
            return;
        }
    }
    if (var_count < MAX_VARS) {
        strncpy(variables[var_count].name, var_name, MAX_LINE_LENGTH);
        variables[var_count].name[MAX_LINE_LENGTH - 1] = '\0';
        snprintf(variables[var_count].value, MAX_LINE_LENGTH, "%d", value);
        var_count++;
    } else {
        fprintf(stderr, "Maximum number of variables reached.\n");
    }
}

void inputn(const char *var_name) {
    int value;
    printf(" ");
    if (scanf("%d", &value) == 1) {
        getchar();
        num_variable(var_name, value);
    } else {
        fprintf(stderr, "Error reading input.\n");
    }
}

void sayinputn(const char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, var_name) == 0) {
            int value = atoi(variables[i].value);
            printf("%d", value);
            return;
        }
    }
    fprintf(stderr, "Variable %s not found.\n", var_name);
}

void addinput(const char *result_var, const char *var1, const char *var2) {
    int value1 = 0, value2 = 0;
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, var1) == 0) {
            value1 = atoi(variables[i].value);
        }
        if (strcmp(variables[i].name, var2) == 0) {
            value2 = atoi(variables[i].value);
        }
    }
    int result = value1 + value2;
    num_variable(result_var, result);
}

void nextl() {
    printf("\n");
}

int evaluate_condition(const char *var_name, const char *operator, const char *value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, var_name) == 0) {
            if (strcmp(operator, "==") == 0) {
                return strcmp(variables[i].value, value) == 0;
            } else if (strcmp(operator, "!=") == 0) {
                return strcmp(variables[i].value, value) != 0;
            } // Add more operators if needed
        }
    }
    fprintf(stderr, "Variable %s not found.\n", var_name);
    return 0; // Default to false if variable not found
}

void check_and_execute_command(const char *line) {
    char message[MAX_LINE_LENGTH];
    char var_name[MAX_LINE_LENGTH];
    char var1[MAX_LINE_LENGTH], var2[MAX_LINE_LENGTH];
    char condition_var[MAX_LINE_LENGTH], condition_value[MAX_LINE_LENGTH];
    char operator[3]; // To hold "==" or "!="
    int var_amount;

    // Ignore comments
    if (strncmp(line, "//", 2) == 0) {
        return;
    }

    // Check for if statement: if(var == value) or if(var != value)
    if (sscanf(line, "if(%[a-zA-Z0-9_] %2[=!]= \"%[^\"]\");", condition_var, operator, condition_value) == 3) {
        if (evaluate_condition(condition_var, operator, condition_value)) {
            char command[MAX_LINE_LENGTH];
            // Execute the next command line
            if (fgets(command, sizeof(command), stdin) != NULL) {
                // Strip newline character from the end of the line
                command[strcspn(command, "\n")] = '\0';
                check_and_execute_command(command);
            }
        }
    } else if (sscanf(line, "say(\"%[^\"]\");", message) == 1) {
        say(message);
    } else if (sscanf(line, "inputc(%[a-zA-Z0-9_]);", var_name) == 1) {
        inputc(var_name);
    } else if (sscanf(line, "sayinput(%[a-zA-Z0-9_]);", var_name) == 1) {
        sayinput(var_name);
    } else if (sscanf(line, "set(%[a-zA-Z0-9_]);", var_name) == 1) {
        set_variable(var_name);
    } else if (sscanf(line, "num(%[a-zA-Z0-9_], %d);", var_name, &var_amount) == 2) {
        num_variable(var_name, var_amount);
    } else if (sscanf(line, "inputn(%[a-zA-Z0-9_]);", var_name) == 1) {
        inputn(var_name);
    } else if (sscanf(line, "sayinputn(%[a-zA-Z0-9_]);", var_name) == 1) {
        sayinputn(var_name);
    } else if (sscanf(line, "addinput(%[a-zA-Z0-9_], %[a-zA-Z0-9_]);", var1, var2) == 2) {
        addinput(var_name, var1, var2);
    } else if (strcmp(line, "nextl();") == 0) {
        nextl();
    } else {
        fprintf(stderr, "No valid command found in line: %s\n", line);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Strip newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';
        check_and_execute_command(line);
    }

    fclose(file);
    return 0;
}
