#include <stdio.h>
#include <stdlib.h>

struct block {
    int id;
    int size;
    int start;
    struct block *next;
};

struct block *head = NULL;

void display() {
    struct block *temp = head;

    if (temp == NULL) {
        printf("No blocks available\n");
        return;
    }

    printf("\nID\tStart\tSize\n");
    while (temp) {
        printf("%d\t%d\t%d\n", temp->id, temp->start, temp->size);
        temp = temp->next;
    }
    printf("\n");
}

void addBlockSortedByStartAddress() {
    struct block *newNode =
        (struct block *)malloc(sizeof(struct block));

    printf("Enter Block ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Start Address: ");
    scanf("%d", &newNode->start);

    printf("Enter Size: ");
    scanf("%d", &newNode->size);

    newNode->next = NULL;

    if (head == NULL || newNode->start < head->start) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct block *curr = head;

    while (curr->next &&
           curr->next->start < newNode->start) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void AllocateMemory() {
    int reqSize;

    printf("Enter memory size required: ");
    scanf("%d", &reqSize);

    struct block *temp = head;

    while (temp) {
        if (temp->size >= reqSize) {
            printf("Allocated from Block ID %d\n", temp->id);

            temp->start += reqSize;
            temp->size -= reqSize;

            if (temp->size == 0) {
                deleteBlock(temp->id);
            }
            return;
        }
        temp = temp->next;
    }

    printf("Memory allocation failed\n");
}

void merge() {
    struct block *curr = head;

    while (curr && curr->next) {
        if (curr->start + curr->size ==
            curr->next->start) {

            struct block *temp = curr->next;

            curr->size += temp->size;
            curr->next = temp->next;

            free(temp);
        }
        else {
            curr = curr->next;
        }
    }

    printf("Adjacent blocks merged\n");
}

void deleteBlock(int id) {
    struct block *temp = head;
    struct block *prev = NULL;

    while (temp) {
        if (temp->id == id) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Block deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Block not found\n");
}

void deleteBlockMenu() {
    int id;

    printf("Enter Block ID to delete: ");
    scanf("%d", &id);

    deleteBlock(id);
}

int main() {
    while (1) {
        int choice;

        printf("\n1.Add Block (Sorted by Start Address)\n");
        printf("2.Allocate Memory\n");
        printf("3.Merge Adjacent Blocks\n");
        printf("4.Delete Block\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBlockSortedByStartAddress();
                break;

            case 2:
                AllocateMemory();
                break;

            case 3:
                merge();
                break;

            case 4:
                deleteBlockMenu();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
