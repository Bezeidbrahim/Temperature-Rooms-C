#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"

#define MAX_ROOMS 100

int main(void) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    system("chcp 65001 > nul");

    char rooms[MAX_ROOMS][NAME_LEN];
    double temp[MAX_ROOMS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Temperature in Rooms ---\n");
        printf("1. Add room\n");
        printf("2. Show all rooms\n");
        printf("3. Min temperature\n");
        printf("4. Max temperature\n");
        printf("5. Save to file\n");
        printf("6. Load from file\n");
        printf("7. Show table (2D array)\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: add_room(rooms, temp, &count);        break;
            case 2: show_rooms(rooms, temp, count);       break;
            case 3: find_min(rooms, temp, count);         break;
            case 4: find_max(rooms, temp, count);         break;
            case 5: save_rooms(rooms, temp, count);       break;
            case 6: load_rooms(rooms, temp, &count);      break;
            case 7: {
                if (count == 0) { printf("List is empty.\n"); break; }
                double table[MAX_ROOMS][COLS];
                build_matrix(temp, count, table);
                show_matrix(table, count);
                break;
            }
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid input!\n");
        }
    } while (choice != 0);

    return 0;
}
