#ifndef PARTE1_H
#define PARTE1_H

#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Parte1{
    private:
        string transmission1, transmission2;
        string mcode1, mcode2, mcode3;
    public:
        Parte1();
        Parte1(string transmission1, string transmission2, string mcode1, string mcode2, string mcode3);

        ~Parte1();


        void zArray(string texto, vector<int> &zArray);
        bool checkIfMatch(vector<int> zArray, int patLen);
        bool patternExists(string texto, string patron);
        void patternIndex(string texto, string patron);
        void printMatch(string texto, string patron);

        vector<string> getCodes(string fileName);
        void searchPatterns(string transmission, string mcode1, string mcode2, string mcode3);
};


void zArray(string texto, vector<int> &zArray){
    int c;
    int der = 0;  
    int izq = 0;

    for(int i = 0; i < texto.size(); i++){
        if(i > der){
            izq = i;
            der = i;

            while(der < texto.size() && texto[der-izq] == texto[der]){
                der++;
            }

            zArray[i] = der - izq;
            der--;

        }else{
            // Se entra a la caja l ... r
            c = i - izq;

            if(zArray[c] < der-i+1){
                zArray[i] = zArray[c];
            }else{
                izq = i;
                while(der < texto.size()&& texto[der-izq] == texto[der]){
                    der++;
                }

                zArray[i] = der-izq;
                der--;
            
            }
        }
    }
}

bool checkIfMatch(vector<int> zArray, int patLen){
    bool flag = false;

    for(int i = 0; i < zArray.size(); i++){
        if(zArray[i] == patLen){
            flag = true;
        }
    }

    return flag;
}

bool patternExists(string texto, string patron){
    string nuevo = patron + '$' + texto;

    vector<int> arrayZ(nuevo.length());
    zArray(nuevo, arrayZ);

    if(checkIfMatch(arrayZ, patron.length())){
        return true;
    }else{
        return false;
    }
}

void patternIndex(string texto, string patron){
    string nuevo = patron + '$' + texto;

    vector<int> arrayZ(nuevo.length());
    zArray(nuevo, arrayZ);
    
    for(int i = 0; i < nuevo.length(); i++){
            if(arrayZ[i] == patron.length()){
                cout << ", index: " << i - patron.length() - 1 << endl;
            }
    }
}

void printMatch(string texto, string patron, int count){
    cout << "(true) Found pattern: ";
    cout << "[" << patron << "]" << " on line: " << count - 1;
    patternIndex(texto, patron);
}

vector<string> getCodes(string fileName){
    vector<string> results;
    ifstream mcode(fileName);
    if(mcode.is_open()){
        string line;
        while(getline(mcode, line)){
            results.push_back(line);
        }
    }

    mcode.close();

    return results;
}

void searchPatterns(string transmission, string mcode1, string mcode2, string mcode3){
    vector<string> patternsCodeOne = getCodes(mcode1);
    vector<string> patternsCodeTwo = getCodes(mcode2);
    vector<string> patternsCodeThree = getCodes(mcode3);

    vector<string> linesTrans = getCodes(transmission);

    cout << "Transmission 1 -----------> mcode1";
    cout << endl;

    for(int i = 0; i < patternsCodeOne.size(); i++){
        bool flag = false;
        for(int j = 0; j < linesTrans.size(); j++){
            if(patternExists(linesTrans[j], patternsCodeOne[i])){
                printMatch(linesTrans[j], patternsCodeOne[i], j);
                flag = true;
            }
        }

        if(flag == false){
            cout << "(false) Pattern: " << patternsCodeOne[i] << " NOT FOUND" << endl;
        }
    }

    cout << endl;
    cout << "Transmission 1 -----------> mcode2";
    cout << endl;

    for(int i = 0; i < patternsCodeTwo.size(); i++){
        bool flag = false;
        for(int j = 0; j < linesTrans.size(); j++){
            if(patternExists(linesTrans[j], patternsCodeTwo[i])){
                printMatch(linesTrans[j], patternsCodeTwo[i], j);
                flag = true;
            }
        }

        if(flag == false){
            cout << "(false) Pattern: " << patternsCodeTwo[i] << " NOT FOUND" << endl;
        }
    }

    cout << endl;
    cout << "Transmission 1 -----------> mcode3";
    cout << endl;

    for(int i = 0; i < patternsCodeThree.size(); i++){
        bool flag = false;
        for(int j = 0; j < linesTrans.size(); j++){
            if(patternExists(linesTrans[j], patternsCodeThree[i])){
                printMatch(linesTrans[j], patternsCodeThree[i], j);
                flag = true;
            }
        }

        if(flag == false){
            cout << "(false) Pattern: " << patternsCodeThree[i] << " NOT FOUND" << endl;
        }
    }

    cout << endl;

}

#endif