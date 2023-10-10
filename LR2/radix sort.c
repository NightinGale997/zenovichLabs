#include <stdio.h>
#include <malloc.h>

void ReadFile(FILE *file, int amount, int array[]){
    for(int i = 0; i < amount; i++){
        fscanf(file,"%d", &array[i]);
    }
}
void PrintArray(int amount, int array[]){
    for(int i = 0 ; i < amount; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");
}
int MaximumNumberOfDigit(int amount, int array[]){
    int maxElement = -1;
    for(int i = 0; i < amount; i++){
        if(array[i] > maxElement){
            maxElement = array[i];
        }
    }
    int digitsAmount = 0;
    while(maxElement > 0){
        digitsAmount++;
        maxElement = maxElement / 10;
    }
    return digitsAmount;
}
void Sort(int array[], int amount, int notation, int maxDigit){
    int *source = malloc(amount * sizeof(int));
    int *b = malloc(notation * sizeof(int));
    int z = 1;
    for(int j = 0; j < maxDigit; j++){
        for(int i = 0; i < amount; i++){
            source[i] = array[i];
        }
        for(int i = 0; i < notation; i++){
            b[i] = 0;
        }
        for(int i = 0; i < amount; i++){
            b[array[i] / z % 10]++;
        }
        int summNum = 0;
        for(int i = 0; i < notation; i++){
            int tmp = b[i];
            b[i] = summNum;
            summNum += tmp;
        }
        for(int  i = 0; i < amount; i++){
            int c = source[i];
            array[b[c/z % 10]] = c;
            b[c/z % 10]++;
        }
        z*=10;
    }
    free(source);
    free(b);
}
int main(){
    FILE *file = fopen("elements.txt","r");
    int amountOfElements = 100, maximumNumberOfDigit;
    int *array = malloc(amountOfElements * sizeof(int));
    ReadFile(file, amountOfElements, array);
    fclose(file);
    PrintArray(amountOfElements, array);
    maximumNumberOfDigit = MaximumNumberOfDigit(amountOfElements, array);
    Sort(array, amountOfElements, 10, maximumNumberOfDigit);
    PrintArray(amountOfElements, array);
    free(array);
return 0;
}

