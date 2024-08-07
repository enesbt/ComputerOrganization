#include "Alu.hpp"


bitset<8> Alu::Add(bitset<8> register1,bitset<8> register2)
{
    bitset<8> result;
    bool carry = 0;

    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = register1[i];
        bool bit_b = register2[i];
        
        // XOR toplama islemi
        result[i] = bit_a ^ bit_b ^ carry;
        //elde biti hesaplanmasi
        carry = (bit_a & bit_b) | (carry & (bit_a ^ bit_b));
    }

    return result;

}