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

int main() {
    int pass = 2024; // Correct password
    int pw_input;    // User input password
    int attempt = 0; // Attempt count
    int choice;      // User choice
    const int max_attempts = 3;  // Maximum allowed attempts

    // Personalized interface and password input
    for(int i = 0; i < 20; i++) {
        printf("Hello!\n");
    }
    printf("Press any key to continue.\n");
    getch(); // Pause program execution, waiting for the user to press any key to continue
    system("cls");   // Clear console output
    printf("Please enter a four-digit password: ");
    scanf("%d", &pw_input);

    // Password verification loop
    while (attempt < max_attempts) {
        if (pw_input == pass) { // Correct password
            printf("Welcome! Password verification successful.\n");

            // Initialize seats
            initializeSeats();

            // Display main menu
            displayMainMenu();

            while (1) { // Main menu loop
                printf("Please enter your choice (a, b, c, or d): ");
                choice = getch(); // Hide user input

                switch (choice) {
                    case 'a':
                    case 'A':
                        system("cls");
                        displaySeats();
                        printf("Press any key to return to the main menu.");
                        getch();
                        displayMainMenu();
                        break;
                    case 'b':
                    case 'B':
                        system("cls");
                        arrangeSeats();
                        displayMainMenu();
                        break;
                    case 'c':
                    case 'C':
                        system("cls");
                        chooseSeats();
                        displayMainMenu();
                        break;
                    case 'd':
                    case 'D':
                        char exit_choice;
                        printf("\nContinue? (y/n): ");
                        exit_choice = getch();
                        if (exit_choice == 'n' || exit_choice == 'N') {
                            printf("\nProgram terminated. Returning to operating system.");
                            return 0;
                        } else if (exit_choice == 'y' || exit_choice == 'Y') {
                            system("cls");
                            displayMainMenu();
                        } else {
                            printf("\nInvalid input! Please enter y or n.\n");
                        }
                        break;
                    default:
                        printf("\nInvalid option!\n");
                        break;
                }
            }
        } else { // Incorrect password
            attempt++;
            printf("Incorrect password! Attempt %d out of %d. Please try again.\n", attempt, max_attempts);
            if (attempt == max_attempts) {
                printf("Maximum attempts reached. Program exiting.\n");
                return 1;
            }
            printf("Please enter the password: ");
            scanf("%d", &pw_input);
        }
    }
    
    return 0;
}

// Randomly initialize seats
void initializeSeats() {
    srand(time(NULL));
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            seats[i][j] = '-';
        }
    }

    // Randomly set 10 reserved seats
    for (int i = 0; i < 10; ++i) {
        int row, col;
        do {
            row = rand() % ROW;
            col = rand() % COL;
        } while (seats[row][col] == '*');
        seats[row][col] = '*';
    }
}

// Display main menu
void displayMainMenu() {
    system("cls");
    printf("----------[Booking System]----------\n");
    printf("|  a. Available Seats              |\n");
    printf("|  b. Arrange Seats                |\n");
    printf("|  c. Choose Seats                 |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

// Display seats
void displaySeats() {
    printf("  123456789\n");
    for (int i = 0; i < ROW; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < COL; ++j) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// Arrange seats
void arrangeSeats() {
    int numSeats;
    printf("Please enter the number of seats required (1-4): ");
    scanf("%d", &numSeats);
    if (numSeats < 1 || numSeats > 4) {
        printf("Invalid input!\n");
        return;
    }

    int row, col;
    int found = 0;
    int attempts = 0; // Track attempts
    while (!found && attempts < 100) { // Limit attempts to avoid infinite loop
        row = rand() % ROW;
        col = rand() % (COL - numSeats + 1); // Adjust to ensure correct range
        if (checkAvailability(row, col, numSeats)) {
            found = 1;
            break;
        }
        attempts++;
    }

    if (!found) {
        printf("Could not find %d consecutive seats.\n", numSeats);
        return;
    }

    for (int i = 0; i < numSeats; ++i)
        seats[row][col + i] = '@';
    displaySeats();

    char choice;
    printf("Are you satisfied with this arrangement? (y/n): ");
    scanf(" %c", &choice);
    if (choice != 'y') {
        for (int i = 0; i < numSeats; ++i)
            seats[row][col + i] = '-';
        return;
    }
}

// Choose seats
void chooseSeats() {
    int row, col;
    printf("Please enter the row number (1-9): ");
    scanf("%d", &row);
    printf("Please enter the column number (1-9): ");
    scanf("%d", &col);
    row--; // Adjust to array index
    col--; // Adjust to array index
    printf("Debug: row=%d, col=%d\n", row + 1, col + 1); // Debug statement
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        printf("Invalid seat selection!\n");
        return;
    }
    if (seats[row][col] == '*') {
        printf("This seat is already reserved!\n");
        return;
    }
    seats[row][col] = '@';
    printf("Seat reservation successful!\n");
    displaySeats();
}

// Check seat availability
int checkAvailability(int row, int col, int count) {
    if (row < 0 || row >= ROW || col < 0 || col + count > COL) // Adjust conditions
        return 0;
    for (int i = 0; i < count; ++i) {
        if (seats[row][col + i] == '*')
            return 0;
    }
    return 1;
}

//這次的排位系統我覺得很有趣，雖然程式碼寫起來很難,但在Chatgpt的輔助下,我終於把功能做出來了
