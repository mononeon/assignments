/* ADT List using Array */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n = 0;

// Create list from file
void createList(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX) {
        n++;
    }
    fclose(fp);
    printf("List created with %d elements.\n", n);
}

int length() {
    return n;
}

void printList(int dir) {
    if (dir == 1) { // left to right
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    } else { // right to left
        for (int i = n - 1; i >= 0; i--) printf("%d ", arr[i]);
    }
    printf("\n");
}

int retrieve(int i) {
    if (i < 0 || i >= n) return -1;
    return arr[i];
}

void store(int x, int i) {
    if (i < 0 || i >= n) {
        printf("Invalid index!\n");
        return;
    }
    arr[i] = x;
}

void insert(int x, int i) {
    if (n >= MAX) {
        printf("List full!\n");
        return;
    }
    if (i < 0 || i > n) {
        printf("Invalid index!\n");
        return;
    }
    for (int j = n; j > i; j--) arr[j] = arr[j - 1];
    arr[i] = x;
    n++;
}

void deleteElem(int i) {
    if (i < 0 || i >= n) {
        printf("Invalid index!\n");
        return;
    }
    for (int j = i; j < n - 1; j++) arr[j] = arr[j + 1];
    n--;
}

int search(int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    int choice, x, i;
    char filename[50];

    printf("Enter input filename: ");
    scanf("%s", filename);
    createList(filename);

    while (1) {
        printf("\n--- Menu (Array) ---\n");
        printf("1. Length\n2. PrintList\n3. Retrieve\n4. Store\n5. Insert\n6. Delete\n7. Search\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Length = %d\n", length());
            break;
        case 2:
            printf("1. Left-to-right, 2. Right-to-left: ");
            scanf("%d", &x);
            printList(x);
            break;
        case 3:
            printf("Enter index: ");
            scanf("%d", &i);
            printf("Element = %d\n", retrieve(i));
            break;
        case 4:
            printf("Enter index and new value: ");
            scanf("%d %d", &i, &x);
            store(x, i);
            break;
        case 5:
            printf("Enter index and value to insert: ");
            scanf("%d %d", &i, &x);
            insert(x, i);
            break;
        case 6:
            printf("Enter index to delete: ");
            scanf("%d", &i);
            deleteElem(i);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &x);
            i = search(x);
            if (i == -1) printf("Not found\n");
            else printf("Found at index %d\n", i);
            break;
        case 8:
            exit(0);
        }
    }
}
