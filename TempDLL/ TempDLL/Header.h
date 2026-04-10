#pragma once
#define NAME_LEN 50
#define COLS 2

__declspec(dllimport) void add_room(char rooms[][NAME_LEN], double temp[], int* count);
__declspec(dllimport) void show_rooms(char rooms[][NAME_LEN], double temp[], int count);
__declspec(dllimport) void find_min(char rooms[][NAME_LEN], double temp[], int count);
__declspec(dllimport) void find_max(char rooms[][NAME_LEN], double temp[], int count);
__declspec(dllimport) void save_rooms(char rooms[][NAME_LEN], double temp[], int count);
__declspec(dllimport) void load_rooms(char rooms[][NAME_LEN], double temp[], int* count);
__declspec(dllimport) void build_matrix(double temp[], int count, double table[][COLS]);
__declspec(dllimport) void show_matrix(double table[][COLS], int count);
