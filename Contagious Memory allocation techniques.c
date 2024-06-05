//worst fit

#include <stdio.h>

#define MAX 25

void main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, highest = 0;
    int bf[MAX], ff[MAX];

    // Initialize arrays
    for(i = 0; i < MAX; i++) {
        b[i] = 0;
        f[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    // Input number of blocks and files
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the sizes of the blocks
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the sizes of the files
    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Worst-Fit allocation
    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) { // If block is not already allocated
                temp = b[j] - f[i];
                if(temp >= 0 && temp > highest) {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1; // Mark block as allocated
        highest = 0; // Reset highest for next file
    }

    // Output result
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
}


//======================================================

//first fit



#include <stdio.h>

#define MAX 25

void main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf;
    int bf[MAX], ff[MAX];

    // Initialize arrays
    for(i = 0; i < MAX; i++) {
        b[i] = 0;
        f[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    // Input number of blocks and files
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the sizes of the blocks
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the sizes of the files
    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // First-Fit allocation
    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(bf[j] == 0 && b[j] >= f[i]) { // If block is not already allocated and can accommodate file
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    // Output result
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if (ff[i] != 0)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i, f[i]);
    }
}



//==========================================

//best fit


#include <stdio.h>

#define MAX 25

void main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, best_index;
    int bf[MAX], ff[MAX];

    // Initialize arrays
    for(i = 0; i < MAX; i++) {
        b[i] = 0;
        f[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    // Input number of blocks and files
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the sizes of the blocks
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the sizes of the files
    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Best-Fit allocation
    for(i = 1; i <= nf; i++) {
        best_index = -1;
        for(j = 1; j <= nb; j++) {
            if(bf[j] == 0) { // If block is not already allocated
                temp = b[j] - f[i];
                if(temp >= 0) {
                    if(best_index == -1 || temp < b[best_index] - f[i]) {
                        best_index = j;
                    }
                }
            }
        }

        if(best_index != -1) {
            ff[i] = best_index;
            frag[i] = b[best_index] - f[i];
            bf[best_index] = 1; // Mark block as allocated
        }
    }

    // Output result
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if (ff[i] != 0)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i, f[i]);
    }
}

