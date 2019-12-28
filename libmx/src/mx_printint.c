#include "./libmx.h"

static void print_num(char *arr, int sign) {
    for (int i = 9; i >= 0; i--) {
        if (sign == -1 && i == 9)
            mx_printchar('-');
        if (arr[i] >= '0' && arr[i] <= '9')
            mx_printchar(arr[i]);
    }
}

void mx_printint(int n) {
    char arr[10];
    int sign = 1;
    int i = 0;

    if (n == 0)
        mx_printchar('0');
    else if (n == -2147483648)
        mx_printstr("-2147483648");
    else {
        if (n < 0) {
            sign = -1;
            n *= -1;
        }
        while (n > 0) {
            arr[i++] = (n % 10) + '0';
            n /= 10;
        }
        arr[i] = '\0';
        print_num(arr, sign);
    }
}
