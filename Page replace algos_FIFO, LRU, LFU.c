//FIFO


#include <stdio.h>

int main() {
    int pageFaultCount = 0, pages[50], memory[20], memoryIndex = 0;
    int numberOfPages, numberOfFrames, i, j, k;

    // Input number of pages
    puts("Enter number of pages:");
    scanf("%d", &numberOfPages);

    // Input the pages
    puts("Enter the pages:");
    for(i = 0; i < numberOfPages; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    puts("Enter number of frames:");
    scanf("%d", &numberOfFrames);

    // Initialize memory frames to -1 (indicating empty)
    for(i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;
    }

    puts("The Page Replacement Process is -->");

    // Page replacement process
    for(i = 0; i < numberOfPages; i++) {
        for(j = 0; j < numberOfFrames; j++) {
            if(memory[j] == pages[i]) {
                break;
            }
        }
        if(j == numberOfFrames) {
            memory[memoryIndex] = pages[i];
            memoryIndex++;
            pageFaultCount++;
        }
        for(k = 0; k < numberOfFrames; k++) {
            printf("\t%d", memory[k]);
        }
        if(j == numberOfFrames) {
            printf("\tPage Fault No: %d", pageFaultCount);
        }
        puts("");
        if(memoryIndex == numberOfFrames) {
            memoryIndex = 0;
        }
    }

    printf("The number of Page Faults using FIFO is: %d\n", pageFaultCount);
    return 0;
}



//==========================================


//LRU

#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pageFaultCount = 0, pages[50], memory[20], time[20], counter = 0;
    int numberOfPages, numberOfFrames, i, j, pos, flag1, flag2;

    puts("Enter number of pages:");
    scanf("%d", &numberOfPages);

    puts("Enter the pages:");
    for(i = 0; i < numberOfPages; i++) {
        scanf("%d", &pages[i]);
    }

    puts("Enter number of frames:");
    scanf("%d", &numberOfFrames);
    for(i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;  // Initialize memory frames to -1
    }

    puts("The Page Replacement Process is -->");
    for(i = 0; i < numberOfPages; i++) {
        flag1 = flag2 = 0;

        for(j = 0; j < numberOfFrames; j++) {
            if(memory[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {
            for(j = 0; j < numberOfFrames; j++) {
                if(memory[j] == -1) {
                    counter++;
                    pageFaultCount++;
                    memory[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {
            pos = findLRU(time, numberOfFrames);
            counter++;
            pageFaultCount++;
            memory[pos] = pages[i];
            time[pos] = counter;
        }

        for(j = 0; j < numberOfFrames; j++) {
            printf("\t%d", memory[j]);
        }
        if(flag2 == 0 || flag1 == 0) {
            printf("\tPage Fault No: %d", pageFaultCount);
        }
        puts("");
    }
    printf("The number of Page Faults using LRU is: %d\n", pageFaultCount);
    return 0;
}



//=====================================================

//LFU [there is fault in this code]


#include <stdio.h>

int findLFU(int frequency[], int n) {
    int i, minimum = frequency[0], pos = 0;
    for(i = 1; i < n; ++i) {
        if(frequency[i] < minimum) {
            minimum = frequency[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pageFaultCount = 0, pages[50], memory[20], frequency[20] = {0};
    int numberOfPages, numberOfFrames, i, j, pos, flag1, flag2;

    puts("Enter number of pages:");
    scanf("%d", &numberOfPages);

    puts("Enter the pages:");
    for(i = 0; i < numberOfPages; i++) {
        scanf("%d", &pages[i]);
    }

    puts("Enter number of frames:");
    scanf("%d", &numberOfFrames);
    for(i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;  // Initialize memory frames to -1
    }

    puts("The Page Replacement Process is -->");
    for(i = 0; i < numberOfPages; i++) {
        flag1 = flag2 = 0;

        for(j = 0; j < numberOfFrames; j++) {
            if(memory[j] == pages[i]) {
                frequency[j]++;
                flag1 = flag2 = 1;
                break;
            }
        }

        if(flag1 == 0) {
            for(j = 0; j < numberOfFrames; j++) {
                if(memory[j] == -1) {
                    pageFaultCount++;
                    memory[j] = pages[i];
                    frequency[j] = 1;
                    flag2 = 1;
                    break;
                }
            }
        }

        if(flag2 == 0) {
            pos = findLFU(frequency, numberOfFrames);
            pageFaultCount++;
            memory[pos] = pages[i];
            frequency[pos] = 1;
        }

        for(j = 0; j < numberOfFrames; j++) {
            printf("\t%d", memory[j]);
        }
        if(flag2 == 0 || flag1 == 0) {
            printf("\tPage Fault No: %d", pageFaultCount);
        }
        puts("");
    }
    printf("The number of Page Faults using LFU is: %d\n", pageFaultCount);
    return 0;
}
s
