#include "Cpu.hpp"


Cpu::Cpu(string fileName)
{
    this->file = new File(fileName);
    this->registers = new Registers();
    this->commands = new Commands();
    this->alu = new Alu();
    this->commandCycle = new CommmandCycle();
}
Cpu::~Cpu()
{
    delete file;
    delete registers;
    delete commands;
    delete alu;
    delete commandCycle;
}

vector<int> Cpu::RandomValues(int min,int max)
{
    srand(static_cast<unsigned int>(time(0)));
    
    int randomValue =  min + rand() % (max - min + 1);
    int random = randomValue+5;
    int randomValue2 = random + rand() % (max - random + 1);

    vector<int>result;
    result.push_back(randomValue);
    result.push_back(randomValue2);
    return result;
}

void Cpu::StartDecodeCode()
{
    this->file->ReadFile();
    uint8_t  *PC= this->registers->getPC();

    this->registers->setPC(this->file->fileArray);
    //OPCODE degeri IR registerine kaydedilir.
    this->registers->setIR(*this->registers->getPC());
    cout<<"IR: "<<this->registers->getIR()<<endl;

    string addressMode = this->commands->AddressModeDecoder(this->registers->getIR());
    string  command = this->commands->CommandDecoder(this->registers->getIR());
    string combined = addressMode+"."+command;

    // baslangic fonksiyonlari
    if(addressMode == "IVEDI")
        this->StartIvedi();
    else if(addressMode == "DOLAYLI")
        this->StartDolayli();
    else if(addressMode == "DIREKT")
        this->StartDirekt();

    
    // komut saykilini calistir.
    auto it = this->commandCycle->functionCommandMap.find(combined);
    if (it != this->commandCycle->functionCommandMap.end()) {
        it->second(*this->registers,*this->alu);  
    } else {
        std::cout << "Command not found." << endl;
    }
    

    
}

void Cpu::StartIvedi()
{
    this->file->ReadFile();
}
// belirlenen bir adres diğer adresi tutmak için 2.adress veri tutacak.
void Cpu::StartDolayli()
{
    //this->file->ReadFile();
    vector<int> result = this->RandomValues(20,80);
    int randomValue = result[0];
    int randomValue2 = result[1];


    void* yazilacakAddress =  static_cast<void*>(&this->file->fileArray[randomValue]);
    uintptr_t address = reinterpret_cast<uintptr_t>(&this->file->fileArray[randomValue]);
    bitset<sizeof(uintptr_t) * 8> addressBits(address);
    uint8_t* ptr = reinterpret_cast<uint8_t*>(address);
    cout << "Bit olarak adres: " << addressBits << endl;
    cout << "Yazilacak Address: " << yazilacakAddress << endl;
    cout << "Address: " << address << endl;

    void* yazilacakAddress2 = static_cast<void*>(&this->file->fileArray[randomValue2]);
    uintptr_t address2 = reinterpret_cast<uintptr_t>(&this->file->fileArray[randomValue2]);
    bitset<sizeof(uintptr_t) * 8> addressBits2(address2);
    uint8_t* ptr2 = reinterpret_cast<uint8_t*>(address2);
    cout << "Bit olarak adres: " << addressBits2 << endl;
    cout << "Yazilacak Address: " << yazilacakAddress2 << endl;
    cout << "Address: " << address2 << endl;

    const int BITS_IN_BYTE = 8;
    bitset<BITS_IN_BYTE> part1, part2, part3, part4;
    
    for (int i = 0; i < BITS_IN_BYTE; ++i) {
        part1[i] = addressBits2[i];
        part2[i] = addressBits2[i + BITS_IN_BYTE];
        part3[i] = addressBits2[i + 2 * BITS_IN_BYTE];
        part4[i] = addressBits2[i + 3 * BITS_IN_BYTE];
    }
    cout << "Address bits: " << addressBits2 <<endl;
    cout << "Part 1: " << part1 <<endl;
    cout << "Part 2: " << part2 <<endl;
    cout << "Part 3: " << part3 <<endl;
    cout << "Part 4: " << part4 <<endl;

    *ptr = static_cast<uint8_t>(bitset<8>(part4).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part3).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part2).to_ulong());
    ptr = ptr+1; 
    *ptr = static_cast<uint8_t>(bitset<8>(part1).to_ulong());


    *ptr2 = static_cast<uint8_t>(bitset<8>("11111111").to_ulong());
    ptr2 = ptr2+1; 
    *ptr2 = static_cast<uint8_t>(bitset<8>("11000011").to_ulong());

    this->file->WriteFile(addressBits.to_string());
    this->file->ReadFile();

    // RAM
    for(int i=0;i<100;++i)
    {
        cout << "RAM Address: " << static_cast<void*>(&this->file->fileArray[i])<< endl; 
        cout<<"Value: "<<bitset<8>(this->file->fileArray[i])<<endl;
    }


}
void Cpu::StartDirekt()
{
    //this->file->ReadFile();
    vector<int> result = this->RandomValues(20,80);
    int randomValue = result[0];
    
    // Random secilen adrese veri yazilir
    void* yazilacakAddress =  static_cast<void*>(&this->file->fileArray[randomValue]);
    uintptr_t address = reinterpret_cast<uintptr_t>(&this->file->fileArray[randomValue]);
    bitset<sizeof(uintptr_t) * 8> addressBits(address);
    uint8_t* ptr = reinterpret_cast<uint8_t*>(address);
    cout << "Bit olarak adres: " << addressBits << endl;
    cout << "Yazilacak Address: " << yazilacakAddress << endl;
    cout << "Address: " << address << endl;


    const int BITS_IN_BYTE = 8;
    bitset<BITS_IN_BYTE> part1, part2, part3, part4;
    
    for (int i = 0; i < BITS_IN_BYTE; ++i) {
        part1[i] = addressBits[i];
        part2[i] = addressBits[i + BITS_IN_BYTE];
        part3[i] = addressBits[i + 2 * BITS_IN_BYTE];
        part4[i] = addressBits[i + 3 * BITS_IN_BYTE];
    }
    cout << "Address bits: " << addressBits << endl;
    cout << "Part 1: " << part1 << endl;
    cout << "Part 2: " << part2 << endl;
    cout << "Part 3: " << part3 << endl;
    cout << "Part 4: " << part4 << endl;


    // Verinin yukset 8 biti
    *ptr = static_cast<uint8_t>(bitset<8>("11111111").to_ulong());
    ptr = ptr+1; 
    // Verinin dusuk 8 biti
    *ptr = static_cast<uint8_t>(bitset<8>("11000011").to_ulong());

    this->file->WriteFile(addressBits.to_string());
    this->file->ReadFile();

    // RAM
    for(int i=0;i<100;++i)
    {
        cout << "RAM Address: " << static_cast<void*>(&this->file->fileArray[i])<< endl; 
        cout<<"Value: "<<bitset<8>(this->file->fileArray[i])<<endl;
    }

}