/* Q7.c : Implement three stacks in one array with random stack selection */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30       // total array size
#define NSTACKS 3    // number of stacks
#define SIZE (MAX/NSTACKS)   // size for each stack

int arr[MAX];
int top[NSTACKS], base[NSTACKS];

// Initialize 3 stacks
void init() {
    for (int i = 0; i < NSTACKS; i++) {
        top[i] = -1;
        base[i] = i * SIZE;
    }
}

// Push into a stack
void push(int st, int x) {
    if (top[st] + 1 >= SIZE) {
        printf("Stack %d Overflow\n", st);
        return;
    }
    top[st]++;
    arr[base[st] + top[st]] = x;
    printf("Pushed %d into Stack %d\n", x, st);
}

// Pop from a stack
int pop(int st) {
    if (top[st] < 0) {
        printf("Stack %d Underflow\n", st);
        return -1;
    }
    int val = arr[base[st] + top[st]];
    top[st]--;
    printf("Popped %d from Stack %d\n", val, st);
    return val;
}

// Display all stacks
void display() {
    for (int s = 0; s < NSTACKS; s++) {
        printf("Stack %d: ", s);
        for (int i = 0; i <= top[s]; i++)
            printf("%d ", arr[base[s] + i]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("File not found!\n");
        return 0;
    }

    init();
    srand(time(NULL));

    int x;
    while (fscanf(f, "%d", &x) == 1) {
        int st = rand() % NSTACKS;   // pick random stack
        int op = rand() % 2;         // 0 = push, 1 = pop
        if (op == 0) push(st, x);
        else pop(st);
        display();
    }

    fclose(f);
    return 0;
}
