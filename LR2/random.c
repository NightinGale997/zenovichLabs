#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    FILE *file = fopen("elements.txt", "w");
    for (int i = 0; i < 1000000; i++) {
        fprintf(file, "%d ", rand() % 1000 + 1);
    }
    fclose(file);
}