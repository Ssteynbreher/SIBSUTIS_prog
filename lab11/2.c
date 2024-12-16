#include <stdio.h> 
typedef struct { 
    char str[5]; 
    int num;     
} NumberRepr;

void format(NumberRepr* number) { 
    sprintf(number->str, "%3d", number->num); 
    snprintf(number->str, sizeof(number->str), "%d", number->num); // Преобразует число в строку и записывает её в массив str. sizeof(number->str) ограничивает размер записи, предотвращая переполнение буфера.
}

int main() { 
    NumberRepr number = { .num = 1025 }; 
    format(&number); // преобразование числа в строку
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num); 
    return 0; 
}

