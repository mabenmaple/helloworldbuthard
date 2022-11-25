Max Value of a given Indice is 7
Complicate it more by making it binary
a single index takes up to 3 bits
size_t is 64x64 arch
11 words 3 bits, 11 * 3, 33 bits < 64, so can fit into 64 bit integer
x & 0b111, then shift by >>> (3 bits) -> push indices backwards because can only push from right

0 -> 0
1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 110
7 -> 111
