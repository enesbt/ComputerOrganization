#include "CommandCycle.hpp"

CommmandCycle::CommmandCycle()
{
    this->functionCommandMap["IVEDI.ADD"] = [this](Registers& reg, Alu& alu) { IvediAdd(reg, alu);};
    this->functionCommandMap["DIREKT.ADD"] = [this](Registers& reg, Alu& alu) { DirektAdd(reg, alu);};
    this->functionCommandMap["DOLAYLI.ADD"] = [this](Registers& reg, Alu& alu) { DolayliAdd(reg, alu);};

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


void CommmandCycle::DolayliAdd(Registers& registers,Alu& alu)
{
    cout<<"####################################################################################"<<endl;
    cout<<"DOLAYLI.ADD Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;    
    this->Fetch(registers);
    this->Decode(registers);


    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout << "T3.DOLAYLI.ADD.EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout << "T3.DOLAYLI.ADD.EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout << "T3.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T3.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4.DOLAYLI.ADD.EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T4.DOLAYLI.ADD.EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T4.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T4.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;



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
    cout << "T5.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;


    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout << "T6.DOLAYLI.ADD.EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout << "T6.DOLAYLI.ADD.EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout << "T6.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T6.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    cout << "T7.DOLAYLI.ADD.EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T7.DOLAYLI.ADD.EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T7.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T7.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


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
    cout << "T8.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;

    // T9
    registers.setDRH(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);

    cout << "T9.DOLAYLI.ADD.EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T9.DOLAYLI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T9.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T10
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T10.DOLAYLI.ADD.EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T10.DOLAYLI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T11
    cout <<"T11.DOLAYLI.ADD.EXECURE:Toplama Oncesi CCR Register Degeri: " << registers.getCCR()<<endl;
    alu.Add(registers);
    cout << "T11.DOLAYLI.ADD.EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T11.DOLAYLI.ADD.EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout << "T11.DOLAYLI.ADD.EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;

    cout<<"####################################################################################"<<endl;
    cout<<"DOLAYLI.ADD Komutu Tamamlandi."<<endl;
    cout<<"####################################################################################"<<endl;




}


//direkt add

void CommmandCycle::DirektAdd(Registers& registers,Alu& alu)
{
    cout<<"####################################################################################"<<endl;
    cout<<"DIREKT.ADD Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;    
    this->Fetch(registers);
    this->Decode(registers);

    registers.setTRH1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRH2(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    cout << "T3.DIREKT.ADD.EXECUTE: TRH1 Register Degeri: " << registers.getTRH1() << endl;
    cout << "T3.DIREKT.ADD.EXECUTE: TRH2 Register Degeri: " << registers.getTRH2() << endl;
    cout << "T3.DIREKT.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T3.DIREKT.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    registers.setTRL1(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);
    registers.setTRL2(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4.DIREKT.ADD.EXECUTE: TRL1 Register Degeri: " << registers.getTRL1() << endl;
    cout << "T4.DIREKT.ADD.EXECUTE: TRL2 Register Degeri: " << registers.getTRL2() << endl;
    cout << "T4.DIREKT.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T4.DIREKT.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


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
    cout << "T5.DIREKT.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;

    // T6
    registers.setDRH(bitset<8>(*(registers.getAR())));
    registers.setAR(registers.getAR()+1);

    cout << "T6.DIREKT.ADD.EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T6.DIREKT.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T6.DIREKT.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T7
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T7.DIREKT.ADD.EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T7.DIREKT.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T8
    cout <<"T8.DIREKT.ADD.EXECURE:Toplama Oncesi CCR Register Degeri: " << registers.getCCR()<<endl;
    alu.Add(registers);
    cout << "T8.DIREKT.ADD.EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T8.DIREKT.ADD.EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout << "T8.DIREKT.ADD.EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;


  

    
}


void CommmandCycle::IvediAdd(Registers& registers,Alu& alu)
{
    cout<<"####################################################################################"<<endl;
    cout<<"IVEDI.ADD Komutu Calisti."<<endl;
    cout<<"####################################################################################"<<endl;
    this->Fetch(registers);
    this->Decode(registers);

    // T3
    // Data registerin yuksek bitli kismina datanin yuksek kisimli 8 biti yuklenir.
    registers.setDRH(bitset<8>(*(registers.getAR())));
    // AR registeri 1 artirilir.
    registers.setAR(registers.getAR()+1);

    cout << "T3.IVEDI.ADD.EXECUTE: DRH Register Degeri: " << registers.getDRH() << endl;
    cout << "T3.IVEDI.ADD.EXECUTE: AR Register Degeri: " << static_cast<void*>(registers.getAR()) << endl;
    cout << "T3.IVEDI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;


    // T4
    registers.setDRL(bitset<8>(*(registers.getAR())));
    registers.setPC(registers.getPC()+1);
    cout << "T4.IVEDI.ADD.EXECUTE: DRL Register Degeri: " << registers.getDRL() << endl;
    cout << "T4.IVEDI.ADD.EXECUTE: PC Register Degeri: " << static_cast<void*>(registers.getPC()) << endl;

    // T5
    // AC<=AC+DR, C<=Cout
    cout <<"T5.IVEDI.ADD.EXECURE:Toplama Oncesi CCR Register Degeri: " << registers.getCCR()<<endl;
    alu.Add(registers);
    cout << "T5.IVEDI.ADD.EXECUTE: ACH Register Degeri: " << registers.getACH() << endl;
    cout << "T5.IVEDI.ADD.EXECUTE: ACL Register Degeri: " << registers.getACL() << endl;
    cout <<"T5.IVEDI.ADD.EXECURE: CCR Register Degeri: " << registers.getCCR()<<endl;

    
    cout<<"####################################################################################"<<endl;
    cout<<"IVEDI.ADD Komutu Tamamlandi."<<endl;
    cout<<"####################################################################################"<<endl;

}




