class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseBin = 0;
        // reverse bits
        for (int i = 0; i < 32; i++) {
            reverseBin = (reverseBin << 1) | (n & 1);
            n = n >> 1;
        }
        return reverseBin;
    }
};
