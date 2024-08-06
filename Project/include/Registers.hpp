#ifndef REGISTERS_HPP
#define REGISTERS_HPP
#include<bitset>
#include<iostream>
using namespace std;

struct Registers
{
    private:
        uint8_t *AR; // address register
        uint8_t *PC; // program counter
        bitset<8> DRH; // data register high
        bitset<8> DRL; // data register low
        bitset<8> ACH; // akumulator high
        bitset<8> ACL; // akumulator low
        bitset<8> IR; //code register
        bitset<8> CCR; // durum code register
        uint8_t *SP; // stack pointer 
        uint8_t *TR; // temporal register


    //get set kurucu yikici
    public:
        Registers();
        void setAR(uint8_t*);
        void setPC(uint8_t*);
        void setDRH(bitset<8>);
        void setDRL(bitset<8>);
        void setACH(bitset<8>);
        void setACL(bitset<8>);
        void setIR(bitset<8>);
        void setCCR(bitset<8>);
        void setSP(uint8_t*);
        void setTR(uint8_t*);



        uint8_t* getAR();
        uint8_t* getPC();
        bitset<8> getDRH();
        bitset<8> getDRL();
        bitset<8> getACH();
        bitset<8> getACL();
        bitset<8> getIR();
        bitset<8> getCCR();
        uint8_t* getSP();
        uint8_t* getTR();

        ~Registers();
    
};




#endif