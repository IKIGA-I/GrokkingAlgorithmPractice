#include <stdio.h>

void greet2(char *name){
    printf("how are you, %s?\n", name);
}

void bye() {
    printf("ok bye!\n");
}

void greet(char *name) {
    printf("hello, %s!\n", name); //hello golam
    greet2(name); //how are you golam
    printf("getting ready to say bye...\n"); 
    bye(); 
}

int main(void) {

    greet("golam");

    return 0;
}