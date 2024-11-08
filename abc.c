#include <stdio.h>
#include <string.h>

void my_strcpy_without_percent(char *dst, const char *src) {
    while (*src) {
        if (*src != '%') { // Skip the '%' character
            *dst++ = *src; // Copy character to destination
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the destination string
}

int main() {
    char *format = "[Agil2]Image: 0x5574575460 setSource() page://manual.yunos.com/asset/image/presetimg/1703743032938%2540n6ickuj9.jpg";
    char buffer[1024]; // Buffer for the output
    my_strcpy_without_percent(buffer, format);
    printf("Formatted string: %s\n", buffer);
    return 0;
}
