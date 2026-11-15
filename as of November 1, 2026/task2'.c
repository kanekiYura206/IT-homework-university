#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    int c;
    int words = 0, numbers = 0;
    bool in_word = false, in_number = false;

    while((c = getchar()) != '\n') {

        if(isalpha(c)) {
            if(!in_word) {
                words++;
            }
            in_word = true;
            in_number = false;
        } else if(isdigit(c)) {
            if(!in_number) {
                numbers++;
            }

            in_number = true;
            in_word = false;
        } else if(c == ' ' || c == '\t') {
            in_word = false;
            in_number = false;
        }
    }

    printf("\nwords: %d\n", words);
    printf("\nnumbers: %d\n", numbers);

    return 0;
}
