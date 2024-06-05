#include <stdio.h>
#include <conio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0;
    int i, p = 0;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);

    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    nob = ms / bs;
    ef = ms - nob * bs;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nNo. of Blocks available in memory: %d", nob);
    printf("\n\nPROCESS\t\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n");

    for (i = 0; i < n && p < nob; i++) {
        printf("%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs) {
            printf("\t\tNO\t\t---\n");
        } else {
            printf("\t\tYES\t\t%d\n", bs - mp[i]);
            tif += bs - mp[i];
            p++;
        }
    }

    if (i < n) {
        printf("\n\nMemory is Full, Remaining Processes cannot be accommodated\n");
    }

    printf("\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d", ef);

    getch();
    return 0;
}



//==========================================================

//Lab Exercise

//Implement a code to solve the Memory Management technique problem


#include <stdio.h>

int main() {
    int num_blocks, num_processes, i, j;

    // Input for blocks
    printf("Enter the number of Blocks: ");
    scanf("%d", &num_blocks);

    int block_sizes[num_blocks];
    int block_allocated[num_blocks];

    for (i = 0; i < num_blocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &block_sizes[i]);
        block_allocated[i] = -1; // Initially no block is allocated
    }

    // Input for processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    int process_sizes[num_processes];

    for (i = 0; i < num_processes; i++) {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &process_sizes[i]);
    }

    int int_frag[num_processes]; // Internal fragmentation array

    // Best-fit allocation
    for (i = 0; i < num_processes; i++) {
        int best_idx = -1;
        for (j = 0; j < num_blocks; j++) {
            if (block_allocated[j] == -1 && block_sizes[j] >= process_sizes[i]) {
                if (best_idx == -1 || block_sizes[best_idx] > block_sizes[j]) {
                    best_idx = j;
                }
            }
        }
        if (best_idx != -1) {
            block_allocated[best_idx] = i;
            int_frag[i] = block_sizes[best_idx] - process_sizes[i];
        } else {
            int_frag[i] = -1; // Indicates no allocation
        }
    }

    // Output result
    printf("\n%-15s%-18s%-12s%-15s%-18s%-10s\n", "Processes", "Process Size", "Blocks", "Block Size", "Allocated", "Int. Frag.");
    printf("-------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < num_processes; i++) {
        int allocated_block = -1;
        for (j = 0; j < num_blocks; j++) {
            if (block_allocated[j] == i) {
                allocated_block = j + 1;
                break;
            }
        }
        if (allocated_block != -1) {
            printf("Process %d\t%-18dBlock %d\t%-15dYes\t\t%-10d\n", i + 1, process_sizes[i], allocated_block, block_sizes[allocated_block - 1], int_frag[i]);
        } else {
            printf("Process %d\t%-18d-\t\t-\t\tNo\t\t-\n", i + 1, process_sizes[i]);
        }
    }

    return 0;
}

