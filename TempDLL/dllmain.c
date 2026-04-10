#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define NAME_LEN 50
#define COLS 2

__declspec(dllexport)
void add_room(char rooms[][NAME_LEN], double temp[], int* count) {
    if (*count >= MAX_ROOMS) {
        printf("Cannot add more rooms!\n");
        return;
    }
    printf("Enter room name: ");
    fgets(rooms[*count], NAME_LEN, stdin);
    rooms[*count][strcspn(rooms[*count], "\n")] = '\0';
    printf("Enter temperature: ");
    scanf("%lf", &temp[*count]);
    getchar();
    (*count)++;
    printf("Room added!\n");
}

__declspec(dllexport)
void show_rooms(char rooms[][NAME_LEN], double temp[], int count) {
    if (count == 0) { printf("List is empty.\n"); return; }
    printf("\n--- Room List ---\n");
    for (int i = 0; i < count; i++)
        printf("%d) %s - %.1f C\n", i + 1, rooms[i], temp[i]);
}

__declspec(dllexport)
void find_min(char rooms[][NAME_LEN], double temp[], int count) {
    if (count == 0) { printf("List is empty.\n"); return; }
    int minIndex = 0;
    for (int i = 1; i < count; i++)
        if (temp[i] < temp[minIndex]) minIndex = i;
    printf("Min temperature: %s - %.1f C\n", rooms[minIndex], temp[minIndex]);
}

__declspec(dllexport)
void find_max(char rooms[][NAME_LEN], double temp[], int count) {
    if (count == 0) { printf("List is empty.\n"); return; }
    int maxIndex = 0;
    for (int i = 1; i < count; i++)
        if (temp[i] > temp[maxIndex]) maxIndex = i;
    printf("Max temperature: %s - %.1f C\n", rooms[maxIndex], temp[maxIndex]);
}

__declspec(dllexport)
void save_rooms(char rooms[][NAME_LEN], double temp[], int count) {
    FILE* f = fopen("temperature.txt", "w");
    if (!f) { printf("Error opening file!\n"); return; }
    for (int i = 0; i < count; i++)
        fprintf(f, "%s;%.1f\n", rooms[i], temp[i]);
    fclose(f);
    printf("Data saved to file.\n");
}

__declspec(dllexport)
void load_rooms(char rooms[][NAME_LEN], double temp[], int* count) {
    FILE* f = fopen("temperature.txt", "r");
    if (!f) { printf("File not found.\n"); return; }
    *count = 0;
    while (fscanf(f, " %49[^;];%lf", rooms[*count], &temp[*count]) == 2)
        (*count)++;
    fclose(f);
    printf("Data loaded.\n");
    show_rooms(rooms, temp, *count);
}

__declspec(dllexport)
void build_matrix(double temp[], int count, double table[][COLS]) {
    for (int i = 0; i < count; i++) {
        table[i][0] = i + 1;
        table[i][1] = temp[i];
    }
}

__declspec(dllexport)
void show_matrix(double table[][COLS], int count) {
    printf("\n--- Room Table (2D array) ---\n");
    printf(" No | Temperature\n");
    printf("----------------\n");
    for (int i = 0; i < count; i++)
        printf("%2.0f  |  %.1f C\n", table[i][0], table[i][1]);
}
