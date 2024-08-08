#include "Alu.hpp"


void Alu::Add(Registers& registers)
{

    bitset<8> result;
    bool carry = registers.getCCR()[0];
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        // XOR toplama islemi
        result[i] = bit_a ^ bit_b ^ carry;
        //elde biti hesaplanmasi
        carry = (bit_a & bit_b) | (carry & (bit_a ^ bit_b));
        registers.setCCR(carry);
        //cout<<"Cary: "<<carry<<endl;
        //cout << "Carry Register Degeri:  " << registers.getCCR() << endl;
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        result[i] = bit_a ^ bit_b ^ carry;
        carry = (bit_a & bit_b) | (carry & (bit_a ^ bit_b));
        registers.setCCR(carry);
    }
    
    registers.setACH(result);
}