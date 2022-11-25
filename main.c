include <stdio.h>
#include <string.h>
#include <inttypes.h>
#define TABLE_CAP 64
#define HIST_CAP 256
#define IDX_CAP 64

const char *message = "Hello World";
size_t hist[256] = {0}; //make a histogram of frequency
char table[TABLE_CAP] = {0};
size_t table_sz = 0;
size_t idx[IDX_CAP] = {0};
size_t idx_sz = 0;

int main() {
    size_t message_sz = strlen(message);
    for (size_t i = 0; i < message_sz; ++i) {
        hist[message[i]]++;
    }  

    for (size_t i = 0; i < HIST_CAP; ++i) {
        if (hist[i] > 0) {
            table[table_sz++] = (char) i;
        }
    } 
    table[table_sz++] = '\0';
    
    idx[idx_sz++] = '\0';
    for (size_t i = 0; i <  message_sz; ++i) {
        for (size_t j = 0; j < table_sz; ++j) {
            if (table[j] == message[i]) {
                idx[idx_sz++] = j;
            }
        }
    }

    uint64_t idx64 = 0;

    for (size_t i = 0; i < idx_sz; ++i) {
        idx64 = (idx64 << 3) | idx[idx_sz - i - 1];
    }

    //ok basically make a table of indices of the frequency in a histogram, then convert that into hexadecimal from binary and then because its only 33 bits further
    //convert that into a 64bit integer to create hello.c
    printf("Message: \"%s\"\n", message);
    printf("Table:   \"%s\"\n", table);
    printf("Indices: {");
    for (size_t i = 0; i < idx_sz; ++i) {
        if (i > 0) printf(", ");
        printf("%zu", idx[i]);
    }
    printf("}\n");
    printf("Table64: 0x%"PRIX64"\n", *(uint64_t*)table);
    printf("Idx64:   0x%"PRIX64"\n", idx64);

    return 0;
}
