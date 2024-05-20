#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ROW 9
#define COL 9

char seats[ROW][COL];

// Function prototypes
void initializeSeats();
void displayMainMenu();
void displaySeats();
void arrangeSeats();
void chooseSeats();
int checkAvailability(int row, int col, int count);