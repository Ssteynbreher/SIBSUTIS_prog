#include <stdio.h>
#include <string.h>
//поменять местами
void sw(char *word) {
    int len = strlen(word);
    if (len > 1) {
        char t = word[0];
        word[0] = word[len - 1];
        word[len - 1] = t;
    }
}
//Разделить по знакам
void f(char *s) {
    char *word = strtok(s, " .,!?;:\n"); 
    while (word != NULL) {
        sw(word);
        printf("%s ", word); 
        word = strtok(NULL, " .,!?;:\n"); 
    }
    printf("\n");
}
int main() {
    char s[] = "Please put five and look at other practical ones on github, I will be very grateful to you, I don't know what else to write, the main thing is to make it work";
    printf("Оригинал:\n%s\n\n", s);
    printf("Измененный:\n");
    f(s);
}
