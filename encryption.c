#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

Pixel image[MAX_ROWS][MAX_COLS];

// Arrays provided in the document
int arr_13[] = { 12, 121, 88, 158, 22, 87, 81, 240, 204, 20, 47, 139, 197 };
int arr_42[] = {166, 99, 142, 92, 180, 89, 147, 217, 213, 98, 105, 189, 61, 58, 243, 43, 4, 230, 45, 7, 29, 223, 188, 40, 135, 114, 205, 234, 199, 103, 16, 232, 149, 225, 52, 8, 214, 133, 86, 183, 202, 222};
int arr_45[] = {239, 223, 133, 225, 217, 253, 221, 10, 14, 138, 254, 136, 40, 186, 32, 74, 169, 41, 63, 235, 12, 111, 98, 229, 52, 244, 35, 5, 11, 6, 97, 29, 108, 43, 105, 250, 65, 173, 18, 149, 232, 134, 88, 141, 220};
int arr_40[] = {101, 221, 46, 187, 134, 254, 125, 2, 93, 189, 182, 44, 151, 30, 166, 105, 253, 213, 251, 58, 88, 160, 76, 109, 140, 218, 90, 78, 7, 80, 150, 28, 94, 73, 227, 186, 53, 243, 156, 167};

// Pixel coordinates {row, col}
int pix_13[][2] = {{1, 3}, {29, 30}, {9, 40}, {36, 9}, {23, 15}, {21, 8}, {3, 5}, {2, 4}, {37, 59}, {5, 6}, {42, 58}, {28, 51}, {25, 54} };
int pix_42[][2] = {{33, 15}, {39, 34}, {38, 43}, {3, 4}, {34, 22}, {42, 46}, {7, 14}, {4, 5}, {19, 25}, {7, 23}, {23, 8}, {3, 1}, {33, 25}, {1, 6}, {34, 59}, {35, 48}, {32, 48}, {45, 4}, {30, 1}, {39, 11}, {19, 28}, {25, 22}, {34, 1}, {40, 54}, {42, 10}, {26, 0}, {39, 8}, {28, 44}, {42, 43}, {3, 56}, {11, 19}, {13, 58}, {1, 53}, {6, 52}, {14, 31}, {44, 37}, {1, 17}, {29, 54}, {31, 38}, {40, 49}, {42, 39}, {18, 31}};
int pix_45[][2] = {{6, 56}, {25, 16}, {2, 3}, {25, 59}, {44, 33}, {22, 11}, {20, 18}, {37, 17}, {26, 39}, {19, 39}, {15, 51}, {18, 50}, {37, 6}, {31, 15}, {9, 10}, {24, 48}, {7, 5}, {39, 47}, {25, 2}, {28, 24}, {6, 38}, {0, 4}, {30, 36}, {11, 59}, {5, 36}, {22, 26}, {3, 26}, {40, 37}, {42, 46}, {34, 27}, {22, 52}, {42, 8}, {34, 5}, {25, 61}, {14, 31}, {14, 59}, {42, 13}, {13, 52}, {28, 19}, {17, 25}, {37, 44}, {34, 0}, {6, 4}, {45, 51}, {13, 49} };
int pix_40[][2] = {{20, 58}, {3, 2}, {27, 23}, {30, 20}, {31, 51}, {1, 5}, {24, 57}, {25, 13}, {9, 4}, {42, 14}, {45, 35}, {4, 45}, {4, 1}, {25, 45}, {5, 29}, {42, 57}, {13, 5}, {8, 24}, {14, 30}, {7, 5}, {32, 14}, {24, 46}, {8, 34}, {32, 40}, {4, 4}, {12, 16}, {31, 48}, {30, 58}, {11, 5}, {42, 31}, {13, 30}, {26, 56}, {1, 34}, {22, 4}, {25, 52}, {30, 50}, {23, 4}, {25, 15}, {10, 9}, {30, 21}};

// Helper for sorting
int compare(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void load_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (fscanf(file, "%d %d %d", &image[i][j].r, &image[i][j].g, &image[i][j].b) != 3) {
                // Stop if file ends early or data is malformed
            }
        }
    }
    fclose(file);
}

int getMessage(char *message) {
    int len;
    while(1) {
        printf("Enter secret message: ");
        if (fgets(message, 300, stdin) == NULL) continue;
        
        // Remove newline
        message[strcspn(message, "\n")] = 0;
        len = strlen(message);
        
        if (len >= 1 && len <= 255) {
            printf("Length of the message: %d\n", len);
            return len;
        }
        printf("Length of the message: %d\n", len);
    }
}

int getTargetRed(int len) {
    int target_red;
    while(1) {
        printf("Enter target red value: ");
        if (scanf("%d", &target_red) != 1) {
            while(getchar() != '\n'); // clear buffer
            continue;
        }
        
        // Constraint: different than message length
        if (target_red == len) {
             printf("Invalid entry.\n");
             continue;
        }
        
        // Constraint: cannot be 13, 40, 42, 45
        if (target_red == 13 || target_red == 40 || target_red == 42 || target_red == 45) {
            printf("Invalid entry.\n");
            continue;
        }
        
        // Constraint: RGB boundary
        if (target_red < 0 || target_red > 255) {
             printf("Invalid entry.\n");
             continue;
        }
        
        return target_red;
    }
}

int setupArrays(int len, int **sorted_array, int (**pix_array)[2], char **filename) {
    *sorted_array = malloc(len * sizeof(int));
    if (!*sorted_array) return 0;
    
    if (len == 13) {
        memcpy(*sorted_array, arr_13, sizeof(arr_13));
        *pix_array = pix_13;
        *filename = "tiger.txt";
    } else if (len == 42) {
        memcpy(*sorted_array, arr_42, sizeof(arr_42));
        *pix_array = pix_42;
        *filename = "elephant.txt";
    } else if (len == 45) {
        memcpy(*sorted_array, arr_45, sizeof(arr_45));
        *pix_array = pix_45;
        *filename = "sunflower.txt";
    } else if (len == 40) {
        memcpy(*sorted_array, arr_40, sizeof(arr_40));
        *pix_array = pix_40;
        *filename = "pineapple.txt";
    } else {
        printf("Error: This message length is not supported for encryption in this demo.\n");
        free(*sorted_array);
        return 0;
    }
    
    qsort(*sorted_array, len, sizeof(int), compare);
    return 1;
}

void preprocessImage(int target_red) {
    for(int i=0; i<MAX_ROWS; i++) {
        for(int j=0; j<MAX_COLS; j++) {
            if (image[i][j].r == target_red) {
                image[i][j].r++;
                // Handle wrap around if it exceeds 255, though prompt implies boundaries are respected
                if (image[i][j].r > 255) image[i][j].r = 0; 
            }
        }
    }
}

void encryptMessage(int len, int target_red, char *message, int *sorted_array, int (*pix_array)[2]) {
    image[0][0].r = len;
    image[0][0].g = target_red;

    for(int i=0; i<len; i++) {
        int r = pix_array[i][0];
        int c = pix_array[i][1];
        
        if (r >= MAX_ROWS || c >= MAX_COLS) continue; 
        
        image[r][c].r = target_red;
        image[r][c].g = (int)message[i];
        image[r][c].b = sorted_array[i];
    }
    
    printf("Message has been successfully encrypted.\n");
}

void printEncryptedImage() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<8; j++) {
            printf("%d %d %d   ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    char message[300];
    int len = getMessage(message);
    int target_red = getTargetRed(len);
    
    int *sorted_array = NULL;
    int (*pix_array)[2] = NULL;
    char *filename = NULL;

    if (!setupArrays(len, &sorted_array, &pix_array, &filename)) {
        return 1;
    }

    load_image(filename);
    preprocessImage(target_red);
    encryptMessage(len, target_red, message, sorted_array, pix_array);
    printEncryptedImage();

    free(sorted_array);
    return 0;
}