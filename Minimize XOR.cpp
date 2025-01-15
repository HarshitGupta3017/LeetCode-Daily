class Solution {
public:

    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;
        int reqSetBits = __builtin_popcount(num2);
        int currSetBits = __builtin_popcount(x);
        int bit = 0;
        if (currSetBits < reqSetBits) {
            while (currSetBits < reqSetBits) {
                if (!isSet(x, bit)) {
                    x |= (1 << bit);
                    currSetBits++;
                }   
                bit++;
            }
        } else if (currSetBits > reqSetBits) {
            while (currSetBits > reqSetBits) {
                if (isSet(x, bit)) {
                    x ^= (1 << bit);
                    currSetBits--;
                }   
                bit++;
            }
        }
        return x;
    }
};
