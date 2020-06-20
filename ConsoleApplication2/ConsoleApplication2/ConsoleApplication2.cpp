#include <stdio.h>
int main() {
    int age;
    scanf_s("%d", &age);
    switch (age) {
    case '17':
        printf("고등학교 1학년");
        break;
    case '18':
        printf("고등학교 2학년");
        break;
    case '19':
        printf("고등학교 3학년");
        break;
    }
    return 0;
}