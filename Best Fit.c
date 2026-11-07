#include <stdio.h>
int main( ){
int n;
printf("Enter number of memory blocks: ");
scanf("%d",&n);

int memory[n];
for(int i=0; i<n; i++){
printf("Enter size of block %d: ", i+1);
scanf("%d", &memory[i]);
}
while(1){
    int size, bestIndex= -1;
    printf("\nEnter size needed (0 to exit): ");
    scanf("%d", &size);

    if(size==0)break;
    //FIND BEST FITTING BLOCK
    for(int i=0; i<n; i++){
        if(memory[i]>=size){
            if (bestIndex==-1||memory[i]<memory[bestIndex]){
                bestIndex=i;
            }
        }
    }
    if(bestIndex != -1){
        memory[bestIndex]-=size;
        printf("Allocate in block %d\n:", bestIndex+1);
    }else{
    printf("No Suitable block found\n");
    }
}

return 0;
}
