#include <stdio.h>

int main(void) {
    FILE *f;
    float new_val = 99.9;
    float temp_val;

    // Reference Page 8: "r+b" means read/update binary (allows reading AND writing)
    f = fopen("numbers.dat", "r+b"); 
    
    if (f == NULL) {
        perror("numbers.dat");
        return 1;
    }

    // 1. Move cursor to the 3rd float (index 2)
    // Reference Page 25: fseek(file, offset, origin)
    // Offset = 2 * size of a float (to skip the first two)
    // Origin = SEEK_SET (beginning of file)
    fseek(f, 2 * sizeof(float), SEEK_SET);

    // 2. Overwrite just that specific float
    // Reference Page 19: fwrite updates the data at the current position
    fwrite(&new_val, sizeof(float), 1, f);

    // 3. Go back to the beginning to verify
    // Reference Page 26: rewind(f) is equivalent to fseek(f, 0, SEEK_SET)
    rewind(f);

    // 4. Read all floats to verify the change
    printf("Updated file content:\n");
    while(fread(&temp_val, sizeof(float), 1, f) == 1) {
        // Reference Page 24: fread return value used for loop condition
        printf("%.1f ", temp_val);
    }
    printf("\n");

    fclose(f);
    return 0;
}