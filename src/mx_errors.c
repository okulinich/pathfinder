#include "./pathfinder.h"

bool mx_isalpha(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122) {
            return false;
        }
    }
    return true;
}

void mx_error_in_line(int i) {
    char *str = NULL;

    mx_printerr("error: line ");
    str = mx_itoa(i);
    mx_printerr(str);
    free(str);
    mx_printerr(" is not valid\n");
}

void mx_error_in_file(char *arg) {
    mx_printerr("error: file ");
    mx_printerr(arg);
    mx_printerr(" does not exist\n");
}

void mx_error_in_file2(char *arg) {
    mx_printerr("error: file ");
    mx_printerr(arg);
    mx_printerr(" is empty\n");
}

bool mx_check_distance(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!mx_isdigit(name[i])) {
            return false;
        }
    }
    return true;
}
