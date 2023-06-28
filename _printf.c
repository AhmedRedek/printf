#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *ptr = format;

    while (*ptr != '\0') {
        if (*ptr == '%') {
            ptr++;  // Move past '%'
            if (*ptr == '\0')
                break;

            if (*ptr == 'c') {
                int ch = va_arg(args, int);
                putchar(ch);
                count++;
            } else if (*ptr == 's') {
                const char *str = va_arg(args, const char *);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*ptr == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*ptr);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return count;
}
