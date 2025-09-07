#include<iostream>
#include <string>
#include "encryption.h"  
using namespace std;

int main(){
    
    char mode;
    string filename;
    cout<< "Enter the file name: ";
    getline(cin >>ws ,filename);


    //select the mode
    cout << "Encrypt(e) or Decrypt (d) the file? ";
    cin >> mode ;

    if (mode == 'e' || mode == 'E'){
        if (encryptFile(filename , true)){
            cout << "Encryption completed successfully. "<<endl;
        }
        else{
            cerr << "Error: Unable to perform encryption."<<endl;

        }
    }
    else if (mode == 'd' || mode == 'D'){
        if (encryptFile(filename ,false)){
            cout << "Decryption completed successfully. "<<endl;
        }
        else{
            cerr << "Error: Unable to perform decryption."<<endl;

        }
    }


    else{
        cerr << "Error: Invalid mode selected . Use (e) to encrypt and (d) to decrypt the file "<< endl;

    }


    return 0;
}