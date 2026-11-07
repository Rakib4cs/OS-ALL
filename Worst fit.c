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
        int size, worstIndex = -1;
        printf("\nEnter size needed (0 to exit): ");
        scanf("%d", &size);

        if (size == 0) break;

        // Find the worst fitting block (largest sufficient)
        for (int i = 0; i < n; i++) {
            if (memory[i] >= size) {
                if (worstIndex == -1 || memory[i] > memory[worstIndex]) {
                    worstIndex = i;
                }
            }
        }

        if (worstIndex != -1) {
            memory[worstIndex] -= size;
            printf("Allocated in block %d\n", worstIndex + 1);
        } else {
            printf("No suitable block found\n");
        }
    }

    return 0;
}
