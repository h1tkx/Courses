#include <stdio.h>

int main(void) {
    FILE *f;
    char c;
    char buffer[100];
    int year;

    // 1. Open file in "read text" mode
    // Reference Page 8: mode "rt" for read text
    f = fopen("info.txt", "rt");

    if (f == NULL) {
        perror("info.txt"); // Reference Page 18: using perror
        return 1;
    }

    // 2. Read the first character
    // Reference Page 11: fgetc usage
    c = fgetc(f);
    
    // Consume the newline after the character 'A' so fgets doesn't read an empty line
    fgetc(f); 

    // 3. Read the string line
    // Reference Page 11: fgets reads up to n-1 characters or newline
    fgets(buffer, 100, f);

    // 4. Read the integer
    // Reference Page 11: fscanf usage similar to scanf
    fscanf(f, "%d", &year);

    // Display results to standard output
    printf("Char read: %c\n", c);
    printf("String read: %s", buffer); // buffer likely contains '\n' from fgets
    printf("Int read: %d\n", year);

    // 5. Close
    // Reference Page 22
    fclose(f);

    return 0;
}