# 🌡️ Temperature in Rooms — C + DLL

> Lab work #1 | MSTU "STANKIN" | Group ИДБ-25-05 | Variant 11

> 🎓 This project was developed as part of Lab Work #1 for the
> "High-Level Language Programming" course at MSTU "STANKIN", Moscow, 2026.
> It demonstrates the use of C with a Windows DLL architecture to build
> a modular room temperature tracking system — covering arrays, file I/O,
> functions, and 2D data structures.

---

## 📋 Features

| # | Feature | Description |
|---|---------|-------------|
| 1 | Add room | Enter room name and temperature |
| 2 | Show all rooms | Display all rooms with temperatures |
| 3 | Min temperature | Find the coldest room |
| 4 | Max temperature | Find the hottest room |
| 5 | Save to file | Write data to `temperature.txt` |
| 6 | Load from file | Read data from `temperature.txt` |
| 7 | 2D table | Display data as a 2D array |

---

## 🗂️ Project Structure

```
📦 temperature-rooms-c
 ┣ 📂 TempDLL/
 ┃ ┣ 📄 dllmain.c      ← DLL library (all functions)
 ┃ ┗ 📄 Header.h       ← Function declarations
 ┣ 📂 TempMain/
 ┃ ┗ 📄 main.c         ← Main program
 ┣ 📄 temperature.txt  ← Sample data file
 ┣ 📄 .gitignore
 ┗ 📄 README.md
```

---

## 🚀 How to Run

1. Open `TempDLL.sln` in **Visual Studio**
2. Right-click `TempDLL` → **Build**
3. Right-click `TempMain` → **Build**
4. Right-click `TempMain` → **Set as Startup Project**
5. Press `Ctrl + F5`

---

## 💻 Demo

```
--- Temperature in Rooms ---
1. Add room
2. Show all rooms
3. Min temperature
4. Max temperature
5. Save to file
6. Load from file
7. Show table (2D array)
0. Exit

--- Room List ---
1) Bedroom     - 22.5 C
2) Kitchen     - 25.0 C
3) Bathroom    - 18.3 C

Min temperature: Bathroom - 18.3 C
Max temperature: Kitchen  - 25.0 C

--- Room Table (2D array) ---
 No | Temperature
----------------
 1  |  22.5 C
 2  |  25.0 C
 3  |  18.3 C
```

---

## 🛠️ Technologies

![C](https://img.shields.io/badge/Language-C-blue)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-purple)
![Windows](https://img.shields.io/badge/Platform-Windows-lightgrey)
![DLL](https://img.shields.io/badge/Architecture-DLL-orange)

---

## 👤 Author

**Bezeid Brahim** | MSTU "STANKIN" | 2026
