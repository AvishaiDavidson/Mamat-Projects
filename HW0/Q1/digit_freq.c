// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // Allocate memory for the string and get its value from the user
    char *string = malloc(1001 * sizeof(char));
    if (string != NULL) {
        scanf("%1000s", string);
    } else {
        return 0; // Return an error code if memory allocation fails
    }
    // calculat the frequency of each digit in the string
    int digit_freq[10] = {0}; // Initialize an array offrequencies
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            digit_freq[string[i] - '0']++; // Count digit
        }
    }

    // Print the frequency of each digit
    for (int i = 0; i < 9; i++) {
        printf("%d ", digit_freq[i]);  //Print the frequency of digits 0 - 8
    }
    printf("%d\n", digit_freq[9]); //Print the frequency of digit 9 and new line

    free(string); // Free the allocated memory    
    return 0;
}
