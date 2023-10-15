#include <stdio.h>

#define BAR '|'
#define MAXLINE 1000
#define ALLOCSIZE 1000

static unsigned long numbuf[ALLOCSIZE];

void histogram_words_lenght() {
    int c, flag;

    flag = 1;
    
    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (flag == 1) {
                putchar('\n');
                flag = 0;
            }
        }
        else {
            flag = 1;
            putchar(BAR);
        }
    }
}

void reverse(char s[], char reverse_s[]) {
    int i, len;

    i = 0;
    for (len = 0; (s[len]) != '\0'; ++len);
    while (i < len) {
        reverse_s[i] = s[len - i - 2];
        ++i;
    }
}

void squeeze(char s1[], char s2[]) {
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0' ; ++j) {
            if (s1[i] != s2[j]) {
                s1[k++] = s1[i];
            }
        }
    }
    s1[k] = '\0';
}

void prints(char *s) {
    while (*s) {
        putchar(*s++);
    }
    putchar('\n');
}

int abs(int n) {
    return n > 0 ? n : -n;
}

int isdigit(int c) {
    return (c>= '0' && c <= '9') ? 1 : 0;
}

int isletter(int c) {
    return ((c>= 'a' && c <= 'z') || (c>= 'A' && c <= 'Z')) ? 1 : 0;
}

int issamecase(int c1, int c2) {
    if (isletter(c1) && isletter(c2)){
        return abs(c1 - c2) <= 25 ? 1 : 0;
    }
    return 0;
}

void append(char start, char stop, char s[]) {
    int i = 0;
    while (s[i] != '\0') i++; 
    if (s[i - 1] == start) i--;
    while (start <= stop) {
        s[i++] = start++;
    }
    s[i] = '\0';
}

void expand(char s1[], char s2[]) {
    int i = 0;
    int j = 0;

    if (s1[i] == '-') append('-', '-', s2), i++;
    
    while (s1[i++] != '\0') {
        if (s1[i] == '-') {
            if (s1[i + 1] == '\0') {
                append('-', '-', s2);
            }
            else if (isdigit(s1[i - 1]) && isdigit(s1[i + 1])) {
                append(s1[i - 1], s1[i + 1], s2);
            }
            else if (isletter(s1[i - 1]) && isletter(s1[i + 1]) && issamecase(s1[i - 1], s1[i + 1])) {
                append(s1[i - 1], s1[i + 1], s2);
            }
        }
    }
}

unsigned long fibonacci(unsigned long i) {
    if (i == 0) return 1;
    if (i == 1) return 1;
    if (i == 2) return 2;
    else return (fibonacci(i - 1) << 1) - fibonacci(i - 3);
}

unsigned long fibonacci_s(unsigned long i) {
    if (i == 0) return 1;
    if (i == 1) return 1;
    else return fibonacci(i - 1) + fibonacci(i - 2);
}

unsigned long *fibonacci_f(int i) {
    unsigned long *buf = numbuf + i;
    if (buf == &numbuf[0]){
        *buf = 1;
        return buf;
    }
    else if (buf == &numbuf[1]){
        *buf = 1;
        return buf;
    }
    else if (buf == &numbuf[2]){
        *buf = 2;
        return buf;
    }
    else if (!*buf) {
        *buf = (*fibonacci_f(i - 1) << 1) - *fibonacci_f(i - 3);
    }
    return buf;
}

unsigned long *fib(int i) {
    unsigned long *buf = numbuf + i;
    if (buf == &numbuf[0]){
        *buf = 1;
    }
    else if (buf == &numbuf[1]){
        *buf = 1;
    }
    else if (buf == &numbuf[2]){
        *buf = 2;
    }
    else if (!*buf) {
        *buf = (*fib(i - 1) << 1) - *fib(i - 3);
    }
    return buf;
}

struct point {
    int x; 
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};

struct rect canonical(struct rect *r) {
    struct point temp;

    if (r->pt1.x > r->pt2.x) {
        temp = r->pt1;
        r->pt1 = r->pt2;
        r->pt1 = temp;
    }
    if (r->pt1.y > r->pt2.x) {
        temp = r->pt1;
        r->pt1 = r->pt2;
        r->pt1 = temp;
    }

    return *r;
};

int power(int base, int power) {
    int pow = 1;
    if (!power) return pow;
    while (power > 0) {
        pow *= base;
        power--;
    }
    return pow;
}


int atop(char *s){
    int max_power = -1; 
    int n = 0;
    char *temp = s;

    while (*temp != '\0') {
        max_power++;
        temp++;
    }
    
    temp = s;
    while (max_power >= 0) {
        n += (int) (*temp - '0') * power(10, max_power);
        temp++;
        max_power--;
    }

    return n;
}