#include "Registers.hpp"
#include<bitset>

Registers::Registers()
{
    this->AR = nullptr;
    this->PC = nullptr;
    this->SP = nullptr;
    this->CCR = bitset<8>("00000001");
    this->ACH = bitset<8>("00000000");
    this->ACL = bitset<8>("00000000");


}
Registers::~Registers()
{
    delete this->AR;
    delete this->PC;
    delete this->SP;
}

void Registers::setTRH1(bitset<8> TRH1)
{
    this->TRH1 = TRH1;
}
void Registers::setTRH2(bitset<8> TRH2)
{
    this->TRH2 = TRH2;
}
void Registers::setTRL1(bitset<8> TRL1)
{
    this->TRL1 = TRL1;
}
void Registers::setTRL2(bitset<8> TRL2)
{
    this->TRL2 = TRL2;
}

bitset<8> Registers::getTRH1()
{
    return this->TRH1;
}
bitset<8> Registers::getTRH2()
{
    return this->TRH2;
}
bitset<8> Registers::getTRL1()
{   
    return this->TRL1;
}
bitset<8> Registers::getTRL2()
{
    return this->TRL2;
}


void Registers::setAR(uint8_t *AR)
{
    this->AR = AR;
}
void Registers::setPC(uint8_t *PC)
{
    this->PC = PC;
}
void Registers::setDRH(bitset<8> DRH)
{
    this->DRH = DRH;
}
void Registers::setDRL(bitset<8> DRL)
{
    this->DRL = DRL;
}
void Registers::setACH(bitset<8> ACH)
{
    this->ACH = ACH;
}
void Registers::setACL(bitset<8> ACL)
{
    this->ACL = ACL;
}
void Registers::setIR(bitset<8> IR)
{
    this->IR = IR;
}
void Registers::setCCR(bitset<8> CCR)
{
    this->CCR = CCR;
}

void Registers::setSP(uint8_t* SP)
{
    this->SP = SP;
}


uint8_t* Registers::getAR()
{
    return this->AR;
}

uint8_t* Registers::getPC()
{
    return this->PC;
}

bitset<8> Registers::getDRH()
{
    return this->DRH;
}
bitset<8> Registers::getDRL()
{
    return this->DRL;
}
bitset<8> Registers::getACH()
{
    return this->ACH;
}
bitset<8> Registers::getACL()
{
    return this->ACL;
}
bitset<8> Registers::getIR()
{
    return this->IR;
}
bitset<8> Registers::getCCR()
{
    return this->CCR;
}
uint8_t* Registers::getSP()
{
    return this->SP;
}
