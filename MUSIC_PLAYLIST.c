#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char songName[50];
    char artist[50];
    struct Music *next;
};

struct Music *head = NULL;
struct Music *curr = NULL;

void add_song() {
    struct Music *newSong =
        (struct Music *)malloc(sizeof(struct Music));

    printf("Enter song name: ");
    scanf("%s", newSong->songName);

    printf("Enter artist name: ");
    scanf("%s", newSong->artist);

    if (head == NULL) {
        head = newSong;
        newSong->next = head;
        curr = head;
    }
    else {
        struct Music *temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newSong;
        newSong->next = head;
    }

    printf("Song added successfully!\n");
}

void delete_song() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    char deleteSong[50];

    printf("Enter song name to delete: ");
    scanf("%s", deleteSong);

    /* Single node case */
    if (head->next == head) {
        if (strcmp(head->songName, deleteSong) == 0) {
            free(head);
            head = NULL;
            curr = NULL;
            printf("Song deleted successfully!\n");
        }
        else {
            printf("Song not found.\n");
        }
        return;
    }

    /* Delete first node */
    if (strcmp(head->songName, deleteSong) == 0) {
        struct Music *last = head;

        while (last->next != head)
            last = last->next;

        struct Music *temp = head;
        head = head->next;
        last->next = head;

        if (curr == temp)
            curr = head;

        free(temp);

        printf("Song deleted successfully!\n");
        return;
    }

    /* Delete other nodes */
    struct Music *prev = head;
    struct Music *temp = head->next;

    while (temp != head) {
        if (strcmp(temp->songName, deleteSong) == 0) {
            prev->next = temp->next;

            if (curr == temp)
                curr = temp->next;

            free(temp);

            printf("Song deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Song not found.\n");
}

void search_song() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    char searchSong[50];

    printf("Enter song name to search: ");
    scanf("%s", searchSong);

    struct Music *temp = head;

    do {
        if (strcmp(temp->songName, searchSong) == 0) {
            printf("Song Found!\n");
            printf("Song: %s\n", temp->songName);
            printf("Artist: %s\n", temp->artist);
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Song not found.\n");
}

void display_playlist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Music *temp = head;

    printf("\n------ MUSIC PLAYLIST ------\n");

    do {
        printf("Song: %s\tArtist: %s\n",
               temp->songName,
               temp->artist);

        temp = temp->next;

    } while (temp != head);
}

void play_next() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    if (curr == NULL)
        curr = head;
    else
        curr = curr->next;

    printf("\nNow Playing:\n");
    printf("Song: %s\n", curr->songName);
    printf("Artist: %s\n", curr->artist);
}

int main() {

    while (1) {
        int choice;

        printf("\n===== MUSIC PLAYLIST =====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display Playlist\n");
        printf("5. Play Next Song\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                add_song();
                break;

            case 2:
                delete_song();
                break;

            case 3:
                search_song();
                break;

            case 4:
                display_playlist();
                break;

            case 5:
                play_next();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
