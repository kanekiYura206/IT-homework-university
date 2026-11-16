#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool validate_coordinates(char x1, char y1, char x2, char y2) {
    if(x1 < 'a' || x1 > 'h' ||
        x2 < 'a' || x2 > 'h' ||
        y1 < '1' || y1 > '8' ||
        y2 < '1' || y2 > '8') {
        return false;
    }

    if(x1 == x2 && y1 == y2) {
        return false;
    }

    return true;
}


bool validate_figure(char figure) {
    return (figure == 'K' || figure == 'Q' ||
            figure == 'R' || figure == 'B' ||
            figure == 'N');
}


bool can_move(char figure, char x1, char y1, char x2, char y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if(dx == 0 && dy == 0) {
        return false;
    }

    switch(figure) {
        case 'K':
            return (dx <= 1 && dy <= 1);

        case 'Q':
            return (dx == dy || dx == 0 || dy == 0);

        case 'R':
            return (dx == 0 || dy == 0);

        case 'B':
            return (dx == dy);

        case 'N':
            return ((dx == 1 && dy == 2) ||
                    (dx == 2 && dy == 1));

        default:
            return false;
    }
}


int main() {
    char x1, y1, x2, y2;
    char choice;

    printf("eter first cell (e.g. a1): ");

    if(scanf(" %c%c", &x1, &y1) != 2) {
        printf("inalid input\n");
        return 1;
    }

    printf("enter second cell (e.g. h8): ");

    if(scanf(" %c%c", &x2, &y2) != 2) {
        printf("invalid input\n");
        return 1;
    }

    if(!validate_coordinates(x1, y1, x2, y2)) {
        printf("invalid coordinates\n");
        return 1;
    }

    printf("\nchoose a figure:\n");
    printf("K - king\n");
    printf("Q - queen\n");
    printf("R - rook\n");
    printf("B - bishop\n");
    printf("N - knight\n");
    printf("your choice: ");

    if(scanf(" %c", &choice) != 1) {
        printf("invalid input\n");
        return 1;
    }

    if(!validate_figure(choice)) {
        printf("invalid figure\n");
        return 1;
    }

    if(can_move(choice, x1, y1, x2, y2)) {
        printf("the %c can move from %c%c to %c%c\n",
               choice, x1, y1, x2, y2);
    } else {
        printf("the %c cannot move from %c%c to %c%c\n",
               choice, x1, y1, x2, y2);

        char figures[] = {'K', 'Q', 'R', 'B', 'N'};
        bool found = false;

        printf("other figures that can move:\n");

        for(int i = 0; i < 5; i++) {
            if(figures[i] != choice &&
                can_move(figures[i], x1, y1, x2, y2)) {

                printf("%c\n", figures[i]);
                found = true;
            }
        }

        if(!found) {
            printf("none\n");
        }
    }

    return 0;
}
