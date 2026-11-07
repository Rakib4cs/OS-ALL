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

    int lastIndex = 0; // Keep track of where we last allocated

    while (1) {
        int size, allocated = 0;
        printf("\nEnter size needed (0 to exit): ");
        scanf("%d", &size);

        if (size == 0) break;

        // Start searching from lastIndex
        for (int count = 0; count < n; count++) {
            int i = (lastIndex + count) % n; // Wrap around
            if (memory[i] >= size) {
                memory[i] -= size;
                printf("Allocated in block %d\n", i + 1);
                lastIndex = i; // Update lastIndex to current block
                allocated = 1;
                break;
            }
        }

        if (!allocated)
            printf("No suitable block found\n");
    }

    return 0;
}
