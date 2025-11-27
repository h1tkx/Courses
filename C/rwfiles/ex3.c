#include <stdio.h>

int main(void) {
    FILE *f;
    float data_out[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float data_in[5];
    int i;

    // --- STEP 1: WRITING ---
    
    // Reference Page 8: "wb" for write binary
    f = fopen("numbers.dat", "wb");
    if (f != NULL) {
        // Reference Page 19: fwrite(ptr, size, count, stream)
        // Writing 5 elements of size float
        fwrite(data_out, sizeof(float), 5, f);
        
        // Reference Page 22: Close after writing
        fclose(f);
    }

    // --- STEP 2: READING ---

    // Reference Page 8: "rb" for read binary
    f = fopen("numbers.dat", "rb");
    if (f != NULL) {
        // Reference Page 13: fread(ptr, size, count, stream)
        // Reading 5 elements into data_in
        int count = fread(data_in, sizeof(float), 5, f);
        
        printf("Elements read: %d\n", count);
        for(i = 0; i < 5; i++) {
            printf("%.1f ", data_in[i]);
        }
        printf("\n");

        fclose(f);
    }

    return 0;
}