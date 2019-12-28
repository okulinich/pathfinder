#include "./pathfinder.h"

bool mx_isdigit(char c) {
    if (c < 48 || c > 57)
        return false;
    return true;
}

int mx_atoi(char *str) {
    int res = 0;
    int i = 0;
    int sign = 1;

    if (mx_strlen(str) > 0 && mx_strcmp(str, "0") != 0) {
        if (str[0] == '-') {
            i++;
            sign = -1;
        }
        while(mx_isdigit(str[i]))
            res = res * 10 + (str[i++] - '0');
        return res * sign;
    }
    else
        return 0;
}
