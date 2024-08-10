#include "Alu.hpp"


void Alu::Add(Registers& registers)
{
    bitset<8> result;
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        // XOR toplama islemi
        result[i] = bit_a ^ bit_b;
        
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        result[i] = bit_a ^ bit_b;
    }
    
    registers.setACH(result);
}
void Alu::AddC(Registers& registers)
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

        registers.updateCarry(carry);
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
void Alu::And(Registers& registers)
{
    bitset<8> result;
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        // And
        result[i] = bit_a & bit_b;
        
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        result[i] = bit_a & bit_b;
    }
    
    registers.setACH(result);
}
void Alu::Cmp(Registers& registers)
{
    bitset<8> result;
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        if(bit_a==bit_b)
            result[i] = 1;
        else
            result[i] = 0;
        
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        if(bit_a==bit_b)
            result[i] = 1;
        else
            result[i] = 0;
    }
    
    registers.setACH(result);

}
void Alu::Xor(Registers& registers)
{
    bitset<8> result;
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        // Xor
        result[i] = bit_a ^ bit_b;
        
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        result[i] = bit_a ^ bit_b;
    }
    
    registers.setACH(result);
}


void Alu::Or(Registers& registers)
{
    bitset<8> result;
    
    for (size_t i = 0; i < 8; ++i) {
        bool bit_a = registers.getACL()[i];
        bool bit_b = registers.getDRL()[i];
        
        // Xor
        result[i] = bit_a | bit_b;
        
    }
    registers.setACL(result);
    result = 0;
    for (size_t i = 0; i < 8; ++i) 
    {
        bool bit_a = registers.getACH()[i];
        bool bit_b = registers.getDRH()[i];
        
        result[i] = bit_a | bit_b;
    }
    
    registers.setACH(result);
}


void Alu::Clr(Registers& registers)
{
    registers.setACH(0);
    registers.setACL(0);
}

// Elde Biti Kontrolu Gerekli
void Alu::Decr(Registers& registers)
{
    unsigned long value = registers.getACL().to_ulong();
    
    // Değeri 1 azalt
    value = value - 1;

    registers.setACL(bitset<8>(value));
}



void Alu::Incr(Registers& registers)
{
    unsigned long value = registers.getACL().to_ulong();
    
    value = value + 1;
    registers.setACL(bitset<8>(value));
}











