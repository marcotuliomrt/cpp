#include<iostream>
#include<string>
#include<cstring>


std::string iso_8859_1_to_utf8(std::string str) {
    std::string strOut;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it){
        uint8_t ch = *it;
        if (ch < 0x80) {
        strOut.push_back(ch);
        }
        else {
        strOut.push_back(0xc0 | ch >> 6);
        strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
}


std::string clean_word(std::string s)
{
    std::string out{};
    for (unsigned int c: s) {
        if (c>0xC0) {
            c = (c & 0xDF);
            switch(c) {
                case 0xC1:
                case 0xC2:
                case 0xC3:
                case 0xC4: c='A'; 
                break;
                case 0xC7: c='C'; 
                break;
                case 0xC8:
                case 0xC9:
                case 0xCA:
                case 0xCB: c='E'; 
                break;
                case 0xCC:
                case 0xCD:
                case 0xCE:
                case 0xCF: c='I'; 
                break;
                case 0xD2:
                case 0xD3:
                case 0xD4:
                case 0xD5:
                case 0xD6: c='O'; 
                break;
                case 0xD9:
                case 0xDA:
                case 0xDB:
                case 0xDC: c='U'; 
                break;
                
            }
        }
        out.push_back(std::toupper(c));
        //std::cout << iso_8859_1_to_utf8(static_cast<std::string>(c)) << ' ';
    }
    return out;
}

int main(){
    std::string a {"hEllOá"};
    std::string b {};
    b = clean_word(a);
    std::cout << b << std::endl;


    
    //std::cout << iso_8859_1_to_utf8(b) << ' ';

}