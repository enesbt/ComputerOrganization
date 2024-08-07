#include "CommandCycle.hpp"

CommmandCycle::CommmandCycle()
{
    this->functionCommandMap["IVEDI.ADD"] = [this](Registers& reg, Alu& alu) { IvediAdd(reg, alu);};
}


void CommmandCycle::Fetch(Registers& registers)
{
    registers.setAR(registers.getPC());
    cout << "T0.FETCH: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;
    cout << "T0.FETCH: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;

    registers.setIR(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);

    cout << "T1.FETCH: IR Register Degeri: " << registers.getIR() << endl;
    cout << "T1.FETCH: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

}

void CommmandCycle::Decode(Registers& registers)
{
    registers.setAR(registers.getPC());
    cout << "T2.DECODE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;
    cout << "T2.DECODE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    registers.setPC(registers.getPC()+1);
    cout << "T2.DECODE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;
}



void CommmandCycle::IvediAdd(Registers& registers,Alu& alu)
{
    cout<<"Ivedi Add Komutu Calisti."<<endl;

}




