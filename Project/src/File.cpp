#include "File.hpp"

File::File(string fileName)
{
    this->fileName = fileName;
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
        for (size_t i = 0; i < row.length(); i += 8)
        {
            string byteStr = row.substr(i, 8); // 8 bitlik parçaları al
            if (byteStr.length() < 8) {
                cerr << "Gecersiz 8 bitlik string: " << byteStr << endl;
                continue;
            }
            uint8_t byte = static_cast<uint8_t>(bitset<8>(byteStr).to_ulong()); // Binary stringi uint8_t'e çevir
            this->file.push_back(byte); // Vektöre ekle
        }
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