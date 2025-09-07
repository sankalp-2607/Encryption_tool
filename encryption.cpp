#include "encryption.h"

#include <fstream>  //for file input output reading
#include <cctype>   // for checking the case if the letter was uppercase alphabet or something like that
// It helps you work with characters (like checking if they’re letters, digits, spaces, etc.) and converting their case.


//main code to perform the ceasar cipher 
bool performCeasarCipher(string& content ,  bool encrypt){
    int shift = encrypt ? 3 : -3;

    //now we"ll make some shift
    for (char& ch: content){
        if (isalpha(ch)){
            char base = isupper(ch)? 'A' : 'a';
            ch = static_cast<char> ((ch - base + shift + 26) % 26 + base );

        }
    }
    return true;


}






bool encryptFile(const string& filename , bool encrypt){



    //open the input file
    ifstream inFile(filename);
    if (!inFile){
        return false;
    }

    string content (istreambuf_iterator <char> (inFile),{});

    inFile.close();


    if (performCeasarCipher(content , encrypt)){
        //create an output file and writing the modified content.
        ofstream outFile( encrypt ? "encrypted_" +filename : "decrypted_" + filename);   //naming the file 

        if (!outFile){  
            return false;   // if the op file was not created then it will return false
        }


        outFile << content ;
        outFile.close();

        return true;


    }


}

