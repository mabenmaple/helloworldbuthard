#include <stdio.h>
#include <stdint.h>

int main() {
    // shift hexa by two e.g. to access byte 57, 0x726F6C6564574820, 0x726F6C65645748, 0x726F6C656457
    // apply mask 0x00000000000000FF to erase everything but 57 which is the byte you want to print, iterate and then you get Hello World
    uint64_t table = 0x726F6C6564574820;
    uint64_t idx = 0x77E435B08; //exhausted all characters once idx is 0, so dont need to know how many indices are in there
    while (idx) { //0 auto FALSE
        // 8 is the same as 2^3, *2 == << 1, so only have to << 3
        putchar((table >> (((idx >>= 3)  & 7) << 3)) & 0xFF); //i want to put idx >>= 3 in the loop but it kills the H, so i have to add an extra 0 pushed at the beginning 
    }

}
