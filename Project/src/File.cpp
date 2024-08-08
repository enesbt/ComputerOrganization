#include "File.hpp"

File::File(string fileName)
{
    this->fileName = fileName;
    this->file =  vector<uint8_t>(100,0);
    this->fileArray = new uint8_t[100];
    for(int i=0;i<100;i++)
    {
        fileArray[i] = 0;
    }
    loc = 0;
}

void File::WriteFile(string value)
{
    cout<<"VALUE: "<<value<<endl;
    string fileName = this->getFileName();
    fstream filef;
    filef.open(fileName, ios::app);
    if (!filef.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    
    filef << value;
    filef.close();
    if (filef.fail()) {
            cerr << "Error closing file: " << fileName << endl;
        }

}   
void File::ReadFile()
{
    string fileName = this->getFileName();
    cout<<"filename: "<<fileName<<endl;
    fstream filef;
    string row;

    filef.open(fileName, ios::in);
    
    if (!filef.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    while (getline(filef, row))     //satir satir dosyayi okur
    {
        int j= 0;
        for (size_t i = 0; i < row.length(); i += 8)
        {
            string byteStr = row.substr(i, 8); // 8 bitlik parçaları al
            if (byteStr.length() < 8) {
                cerr << "Gecersiz 8 bitlik string: " << byteStr << endl;
                continue;
            }
            uint8_t byte = static_cast<uint8_t>(bitset<8>(byteStr).to_ulong()); // Binary stringi uint8_t'e çevir

            //this->file.push_back(byte); // Vektöre ekle
            this->file[j] = byte;
            this->fileArray[j] = byte;
            j++;
            
        }
        this->loc = j;
    } 
    filef.close();

}

string File::getFileName()
{
    return this->fileName;
}
vector<uint8_t> File::getFile()
{
    return this->file;
}



File::~File(){
    file.clear();
}