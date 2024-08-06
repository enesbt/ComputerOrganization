#include "Registers.hpp"

Registers::Registers()
{
    this->AR = nullptr;
    this->PC = nullptr;
    this->SP = nullptr;
    this->TR = nullptr;
}
Registers::~Registers()
{
    delete this->AR;
    delete this->PC;
    delete this->SP;
    delete this->TR;
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
void Registers::setTR(uint8_t* TR)
{
    this->TR = TR;
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
uint8_t* Registers::getTR()
{
    return this->TR;
}