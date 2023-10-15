#include <stdio.h>

void remove_blanks(void){
    int c;
    int flag;

    flag = 0;

    while ((c = getchar()) != '\n') {
        if (c != ' ' || flag) {
            putchar(c);
            if (c == ' ') {
                flag = 0;
            }
            else {
                flag = 1;
            }
        }
    }
}

void swap(int *px, int *py) {
    int temp; 

    temp = *px;
    *px = *py;
    *py = temp;
}
