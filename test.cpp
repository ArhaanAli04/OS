#include <stdio.h>
#include <stdlib.h>

#define PAGE_FRAMES 3

int fifo_page_replacement(int pages[], int n,int f) {
    int page_frames[f];
    for(int i=0;i<f;i++){
        page_frames[i]=-1;
    }
    int page_faults = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in memory
        for (int j = 0; j < f; j++) {
            if (page_frames[j] == page) {
                found = 1;
                break;
            }
        }

        // Page not found, replace the page at index and update index
        if (!found) {
            page_frames[index] = page;
            index = (index + 1) % f;
            page_faults++;
        }
    }

    return page_faults;
}

int lru_page_replacement(int pages[], int n,int f) {
    int page_frames[f];
    for(int i=0;i<f;i++){
        page_frames[i]=-1;
    }
    int page_faults = 0;
    int recent_access[f];
    for(int i=0;i<f;i++){
        recent_access[i]=0;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in memory
        for (int j = 0; j < f; j++) {
            if (page_frames[j] == page) {
                found = 1;
                recent_access[j] = i;
                break;
            }
        }

        // Page not found, find the least recently used page
        if (!found) {
            int min_index = 0;
            for (int j = 1; j < f; j++) {
                if (recent_access[j] < recent_access[min_index]) {
                    min_index = j;
                }
            }
            page_frames[min_index] = page;
            recent_access[min_index] = i;
            page_faults++;
        }
    }

    return page_faults;
}
void printArray(int n,int pages[]){
    for(int i=0;i<n;i++){
        printf("%d ",pages[i]);
    }
}
int main() {
    int n;
   
    printf("Enter the number of pages: ");
    scanf("%d",&n);
     int pages[n];
    printf("Enter the reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("\nThe  reference string is given by: ");
    printArray(n,pages);
    int f;
    printf("\nEnter the number of frames: ");
    scanf("%d",&f);

    printf("Number of page faults using FIFO: %d\n", fifo_page_replacement(pages, n,f));
    printf("Number of page faults using LRU: %d\n", lru_page_replacement(pages, n,f));

    return 0;
}
