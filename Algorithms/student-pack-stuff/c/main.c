#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 15
#define MAX_COLS 19

void readMap(char *filePath, char map[MAX_ROWS][MAX_COLS]) {
    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(1); // Exit the program if file opening fails
    }

    // Read the file and populate the array
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            char c = fgetc(file);
            while (c != '0' && c != '1' && c != EOF) {
                c = fgetc(file);
            }
            if (c == EOF) {
                fclose(file);
                return; // Exit the function if end of file is reached
            }
            map[i][j] = c;
        }
    }

    fclose(file); // Close text file
}

void printMap(char map[MAX_ROWS][MAX_COLS]) {
    // Print the map in a grid format
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

struct Location {
    int row;
    int col;
};

struct Location getRandomLocation(char map[MAX_ROWS][MAX_COLS]) {

    struct Location randomLocation;
    int isNotValid = 1; // true
    while (isNotValid) {
        int random_row = rand() % MAX_ROWS;
        int random_col = rand() % MAX_COLS; // get random row and column
        // check point on map to see if it's a path
        if (map[random_row][random_col] == '0') {
            randomLocation.row = random_row;
            randomLocation.col = random_col;
            isNotValid = 0; // found valid location
        }
    }
    return randomLocation;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    char map[MAX_ROWS][MAX_COLS];
    readMap("map_1.txt", map);
    printMap(map);
    // generate random start and target location
    struct Location startLocation = getRandomLocation(map);
    struct Location targetLocation = getRandomLocation(map);

    printf("\n");
    printf("Start location: %d , %d\n", startLocation.row, startLocation.col);

    // reprint map with starting location
    map[startLocation.row][startLocation.col] = '*';

    printMap(map);
    return 0;
}
