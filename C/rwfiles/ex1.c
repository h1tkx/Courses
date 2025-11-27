#include <stdio.h>


int main(void) {
    // 1. Declare the file identifier
    FILE *f;

    // 2. Open file in "write text" mode
    // Reference Page 8: mode "w" for writing, "t" for text (implicit or explicit "wt")
    f = fopen("info.txt", "wt");

    // 3. Check if opening was successful
    // Reference Page 8: fopen returns NULL if there is a problem
    if (f == NULL) {
        // Reference Page 18: Using stderr for errors
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // 4. Write data
    // Reference Page 16: fputc for characters
    fputc('A', f); 
    fputc('\n', f);
    
    // Reference Page 16: fputs for strings
    fputs("Year of Course:\n", f);
    
    // Reference Page 16: fprintf for formatted output
    fprintf(f, "%d", 2025);

    // 5. Close the file
    // Reference Page 22: fclose is mandatory
    fclose(f);

    return 0;
}