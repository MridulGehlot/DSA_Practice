#include <stdio.h>
#include <stdlib.h>
#include <mg_heap.h>
#include <mg_error.h>

// Comparator for MIN HEAP
int compare(void *a, void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    // return 1 if x < y (min heap condition)
    return x < y;
}

int main()
{
    Heap *heap;
    int succ;
    int *x;

    // Create Heap
    heap = createHeap(compare, &succ);

    if(succ == FAILURE)
    {
        printf("Heap creation failed\n");
        return 0;
    }

    printf("Heap created successfully\n\n");

    // Insert elements (like linked list example)
    for(int i = 101; i <= 110; i++)
    {
        x = (int *)malloc(sizeof(int));
        *x = i;

        insert(heap, (void *)x, &succ);

        if(succ == SUCCESS)
            printf("Inserted: %d\n", *x);
        else
            printf("Insert failed\n");
    }

    printf("\nRemoving elements (Min Heap Order):\n\n");

    // Remove elements until heap is empty
    while(!isHeapEmpty(heap))
    {
        printf("size = %d\n", getSizeOfHeap(heap));

        x = (int *)removeFromHeap(heap, &succ);

        if(succ == SUCCESS)
        {
            printf("%d\n", *x);
            free(x);
        }
        else
        {
            printf("Remove failed\n");
        }
    }

    // Destroy heap
    //destroyHeap(heap, &succ);   // ⚠️ You must implement this if not done

    return 0;
}	