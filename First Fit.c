#include <stdio.h>

int main() {
    int n;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    int memory[n];
    for (int i = 0; i < n; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &memory[i]);
    }

    while (1) {
        int size, allocated = 0;
        printf("\nEnter size needed (0 to exit): ");
        scanf("%d", &size);

        if (size == 0) break;

        for (int i = 0; i < n; i++) {
            if (memory[i] >= size) {
                memory[i] -= size;
                printf("Allocated in block %d\n", i + 1);
                allocated = 1;
                break;
            }
        }

        if (!allocated)
            printf("No suitable block found\n");
    }

    return 0;
}
