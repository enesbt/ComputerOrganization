#include "CommandCycle.hpp"

CommmandCycle::CommmandCycle()
{
    this->functionCommandMap["IVEDI.ADD"] = [this](Registers& reg, Alu& alu) { IvediAdd(reg, alu);};
    this->functionCommandMap["DIREKT.ADD"] = [this](Registers& reg, Alu& alu) { DirektAdd(reg, alu);};
    this->functionCommandMap["DOLAYLI.ADD"] = [this](Registers& reg, Alu& alu) { DolayliAdd(reg, alu);};
    this->functionCommandMap["IVEDI.ADDC"] = [this](Registers& reg, Alu& alu) { IvediAddC(reg, alu);};
    this->functionCommandMap["DIREKT.ADDC"] = [this](Registers& reg, Alu& alu) { DirektAddC(reg, alu);};
    this->functionCommandMap["DOLAYLI.ADDC"] = [this](Registers& reg, Alu& alu) { DolayliAddC(reg, alu);};
    this->functionCommandMap["IVEDI.AND"] = [this](Registers& reg, Alu& alu) { IvediAnd(reg, alu);};
    this->functionCommandMap["DIREKT.AND"] = [this](Registers& reg, Alu& alu) { DirektAnd(reg, alu);};
    this->functionCommandMap["DOLAYLI.AND"] = [this](Registers& reg, Alu& alu) { DolayliAnd(reg, alu);};
    this->functionCommandMap["IVEDI.CMP"] = [this](Registers& reg, Alu& alu) { IvediCmp(reg, alu);};
    this->functionCommandMap["DIREKT.CMP"] = [this](Registers& reg, Alu& alu) { DirektCmp(reg, alu);};
    this->functionCommandMap["DOLAYLI.CMP"] = [this](Registers& reg, Alu& alu) { DolayliCmp(reg, alu);};
    this->functionCommandMap["IVEDI.XOR"] = [this](Registers& reg, Alu& alu) { IvediXor(reg, alu);};
    this->functionCommandMap["DIREKT.XOR"] = [this](Registers& reg, Alu& alu) { DirektXor(reg, alu);};
    this->functionCommandMap["DOLAYLI.XOR"] = [this](Registers& reg, Alu& alu) { DolayliXor(reg, alu);};
    this->functionCommandMap["IVEDI.OR"] = [this](Registers& reg, Alu& alu) { IvediOr(reg, alu);};
    this->functionCommandMap["DIREKT.OR"] = [this](Registers& reg, Alu& alu) { DirektOr(reg, alu);};
    this->functionCommandMap["DOLAYLI.OR"] = [this](Registers& reg, Alu& alu) { DolayliOr(reg, alu);};
    this->functionCommandMap["DOGAL.CLR"] = [this](Registers& reg, Alu& alu) { DogalClr(reg, alu);};
    this->functionCommandMap["DOGAL.DECR"] = [this](Registers& reg, Alu& alu) { DogalDecr(reg, alu);};


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

void CommmandCycle::Dogal(Registers& registers,string value)
{
    cout<<"####################################################################################"<<endl;
    cout<<value<<" Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;    
    this->Fetch(registers);
    this->Decode(registers);
}

void CommmandCycle::DogalSon(Registers& registers,string value)
{
    cout << "T3."<<value<<".EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T3."<<value<<".EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout<<"####################################################################################"<<endl;
    cout<<value<<" Komutu Tamamlandi."<<endl;
    cout<<"####################################################################################"<<endl;
}


void CommmandCycle::Dolayli(Registers& registers,string value)
{
    cout<<"####################################################################################"<<endl;
    cout<<value<<" Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;    
    this->Fetch(registers);
    this->Decode(registers);


    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout <<"T3." <<value<<".EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout <<"T3." <<value<<".EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout <<"T3." <<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout <<"T3." <<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4."<<value<<".EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T4."<<value<<".EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T4."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T4."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;



    bitset<32> combined;
    for (int i = 0; i < 8; ++i) {
        combined[i] = registers.getTRL2()[i];
        combined[i + 8] = registers.getTRL1()[i];
        combined[i + 16] = registers.getTRH2()[i];
        combined[i + 24] = registers.getTRH1()[i];
    }
    cout<<"Combined: "<<bitset<32>(combined)<<endl;
    uintptr_t restoredAddress = combined.to_ullong();
    
    // Tam sayıyı void* işaretçisine dönüştür
    void* restoredPtr = reinterpret_cast<void*>(restoredAddress);
    
    //cout << "Restored address: 0x" << hex << uppercase << restoredAddress << endl;
    //cout << "Restored pointer: " << restoredPtr << endl;
    uint8_t* uint8Ptr = reinterpret_cast<uint8_t*>(restoredPtr);
    bitset<8> byteBits(*uint8Ptr);
    //cout << "Restored pointer value: " << byteBits << endl;

    // T5 
    registers.setAR(uint8Ptr);
    cout << "T5."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;


    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout << "T6."<<value<<".EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout << "T6."<<value<<".EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout << "T6."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T6."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    cout << "T7."<<value<<".EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T7."<<value<<".EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T7."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T7."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


    bitset<32> combined2;
    for (int i = 0; i < 8; ++i) {
        combined2[i] = registers.getTRL2()[i];
        combined2[i + 8] = registers.getTRL1()[i];
        combined2[i + 16] = registers.getTRH2()[i];
        combined2[i + 24] = registers.getTRH1()[i];
    }
    cout<<"Combined2: "<<bitset<32>(combined2)<<endl;
    uintptr_t restoredAddress2 = combined2.to_ullong();
    
    // Tam sayıyı void* işaretçisine dönüştür
    void* restoredPtr2 = reinterpret_cast<void*>(restoredAddress2);
    
    //cout << "Restored address: 0x" << hex << uppercase << restoredAddress << endl;
    //cout << "Restored pointer: " << restoredPtr << endl;
    uint8_t* uint8Ptr2 = reinterpret_cast<uint8_t*>(restoredPtr2);
    bitset<8> byteBits2(*uint8Ptr2);
    //cout << "Restored pointer value: " << byteBits << endl;

    // T8 AR <= TR
    registers.setAR(uint8Ptr2);
    cout << "T8."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;

    // T9
    registers.setDRH(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);

    cout << "T9."<<value<<".EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T9."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T9."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T10
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T10."<<value<<".EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T10."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;
    // T11
    cout << "T11."<<value<<".EXECUTE: CCR Register Degeri: " << registers.getCCR()<<endl;
    
}


void CommmandCycle::DolayliSon(Registers& registers,string value)
{
    cout << "T11."<<value<<".EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T11."<<value<<".EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout << "T11."<<value<<".EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;

    cout<<"####################################################################################"<<endl;
    cout<<value<<" Komutu Tamamlandi."<<endl;
    cout<<"####################################################################################"<<endl;

}


void CommmandCycle::Direkt(Registers& registers,string value)
{
    cout<<"####################################################################################"<<endl;
    cout<<value<<" Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;    
    this->Fetch(registers);
    this->Decode(registers);

    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout << "T3."<<value<<".EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout << "T3."<<value<<".EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout << "T3."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T3."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4."<<value<<".EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T4."<<value<<".EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T4."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T4."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


    bitset<32> combined;
    for (int i = 0; i < 8; ++i) {
        combined[i] = registers.getTRL2()[i];
        combined[i + 8] = registers.getTRL1()[i];
        combined[i + 16] = registers.getTRH2()[i];
        combined[i + 24] = registers.getTRH1()[i];
    }
    cout<<"Combined: "<<bitset<32>(combined)<<endl;
    uintptr_t restoredAddress = combined.to_ullong();
    
    // Tam sayıyı void* işaretçisine dönüştür
    void* restoredPtr = reinterpret_cast<void*>(restoredAddress);
    
    //cout << "Restored address: 0x" << hex << uppercase << restoredAddress << endl;
    //cout << "Restored pointer: " << restoredPtr << endl;
    uint8_t* uint8Ptr = reinterpret_cast<uint8_t*>(restoredPtr);
    bitset<8> byteBits(*uint8Ptr);
    //cout << "Restored pointer value: " << byteBits << endl;

    // T5 AR <= TR
    registers.setAR(uint8Ptr);
    cout << "T5."<<value<<".ADDC.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;

    // T6
    registers.setDRH(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);

    cout << "T6."<<value<<".EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T6."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T6."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T7
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T7."<<value<<".EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T7."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T8
    cout <<"T8."<<value<<".EXECUTE:CCR Register Degeri: " << registers.getCCR()<<endl;
    
}

void CommmandCycle::DirektSon(Registers& registers,string value)
{
    cout << "T8."<<value<<".EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T8."<<value<<".EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout << "T8."<<value<<".EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;
}

void CommmandCycle::Ivedi(Registers& registers,string value)
{
    cout<<"####################################################################################"<<endl;
    cout<< value <<" Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;
    this->Fetch(registers);
    this->Decode(registers);

    // T3
    // Data registerin yuksek bitli kismina datanin yuksek kisimli 8 biti yuklenir.
    registers.setDRH(bitset<8>(*(registers.getAR())));
    // AR registeri 1 artirilir.
    registers.setAR(registers.getAR()+1);

    cout << "T3."<<value<<".EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T3."<<value<<".EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T3."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


    // T4
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4."<<value<<".EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T4."<<value<<".EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T5
    // AC<=AC+DR, C<=Cout
    cout <<"T5."<<value<<".EXECUTE:CCR Register Degeri: " << registers.getCCR()<<endl;
    
    
}


void CommmandCycle::IvediSon(Registers& registers,string value)
{
    cout << "T5."<<value<<".EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T5."<<value<<".EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout << "T5."<<value<<".EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;
    
    cout<<"####################################################################################"<<endl;
    cout<<value <<" Komutu Tamamlandi."<<endl;
    cout<<"####################################################################################"<<endl;
}

// ADDC
void CommmandCycle::IvediAddC(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.ADDC");
    alu.AddC(registers);
    this->IvediSon(registers,"IVEDI.ADDC");
}
void CommmandCycle::DirektAddC(Registers& registers,Alu& alu)
{
    this->Direkt(registers,"DIREKT.ADDC");
    alu.AddC(registers);
    this->DirektSon(registers,"DIREKT.ADDC");

}
void CommmandCycle::DolayliAddC(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.ADDC");   
    alu.AddC(registers);
    this->DolayliSon(registers,"DOLAYLI.ADDC");
}
// ADD
void CommmandCycle::DolayliAdd(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.ADD");
    alu.Add(registers);
    this->DolayliSon(registers,"DOLAYLI.ADD");
}
void CommmandCycle::DirektAdd(Registers& registers,Alu& alu)
{
    this->Direkt(registers,"DIREKT.ADD");
    alu.Add(registers);
    this->DirektSon(registers,"DIREKT.ADD");
}
void CommmandCycle::IvediAdd(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.ADD");
    alu.Add(registers);
    this->IvediSon(registers,"IVEDI.ADD");
}

// AND
void CommmandCycle::IvediAnd(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.AND");
    alu.And(registers);
    this->IvediSon(registers,"IVEDI.AND");
}
void CommmandCycle::DirektAnd(Registers& registers,Alu& alu)
{
    this->Direkt(registers,"DIREKT.AND");
    alu.And(registers);
    this->DirektSon(registers,"DIREKT.AND");

}
void CommmandCycle::DolayliAnd(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.AND");
    alu.And(registers);
    this->DolayliSon(registers,"DOLAYLI.AND");

}

// CMP bit bit karsilastir ayni bitlere 1 farkli bitlere 0
void CommmandCycle::IvediCmp(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.CMP");
    alu.Cmp(registers);
    this->IvediSon(registers,"IVEDI.CMP");
}
void CommmandCycle::DirektCmp(Registers& registers,Alu& alu)
{
    this->Direkt(registers,"DIREKT.CMP");
    alu.Cmp(registers);
    this->DirektSon(registers,"DIREKT.CMP");
}
void CommmandCycle::DolayliCmp(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.CMP");
    alu.Cmp(registers);
    this->DolayliSon(registers,"DOLAYLI.CMP");
}

// XOR
void CommmandCycle::IvediXor(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.XOR");
    alu.Xor(registers);
    this->IvediSon(registers,"IVEDI.XOR");
}
void CommmandCycle::DirektXor(Registers& registers,Alu& alu)
{   
    this->Direkt(registers,"DIREKT.XOR");
    alu.Xor(registers);
    this->DirektSon(registers,"DIREKT.XOR");
}
void CommmandCycle::DolayliXor(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.XOR");
    alu.Xor(registers);
    this->DolayliSon(registers,"DOLAYLI.XOR");
}

// OR
void CommmandCycle::IvediOr(Registers& registers,Alu& alu)
{
    this->Ivedi(registers,"IVEDI.OR");
    alu.Or(registers);
    this->IvediSon(registers,"IVEDI.OR");
}
void CommmandCycle::DirektOr(Registers& registers,Alu& alu)
{
    this->Direkt(registers,"DIREKT.OR");
    alu.Or(registers);
    this->DirektSon(registers,"DIREKT.OR");
}
void CommmandCycle::DolayliOr(Registers& registers,Alu& alu)
{
    this->Dolayli(registers,"DOLAYLI.OR");
    alu.Or(registers);
    this->DolayliSon(registers,"DOLAYLI.OR");
}


// CLR
void CommmandCycle::DogalClr(Registers& registers,Alu& alu)
{
    this->Dogal(registers,"DOGAL.CLR");
    alu.Clr(registers);
    this->DogalSon(registers,"DOGAL.CLR");
}


// DECR
void CommmandCycle::DogalDecr(Registers& registers,Alu& alu)
{
    this->Dogal(registers,"DOGAL.DECR");
    alu.Decr(registers);
    this->DogalSon(registers,"DOGAL.DECR");
}


// INCR
void CommmandCycle::DogalIncr(Registers& registers,Alu& alu)
{
    this->Dogal(registers,"DOGAL.INCR");
    alu.Decr(registers);
    this->DogalSon(registers,"DOGAL.INCR");
}





