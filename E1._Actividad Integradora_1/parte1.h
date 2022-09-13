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
        
        // Definition of functions to be used
        void zArray(string texto, vector<int> &zArray);
        bool checkIfMatch(vector<int> zArray, int patLen);
        bool patternExists(string texto, string patron);
        void patternIndex(string texto, string patron);
        void printMatch(string texto, string patron);
        void searchPatterns(string transmission, string mcode1, string mcode2, string mcode3);
};

/* 
Function used to create a Z array, given a string. The Z array is filled according to the matches of the given prefix.
Time complexity: O(m + n)
*/
void zArray(string texto, vector<int> &zArray){
    int c;
    // Initial values of the window are defined 
    int der = 0;  
    int izq = 0;

    for(int i = 0; i < texto.size(); i++){
        // In this case, the index being bigger than r, the value is not yet known. The value might be not yet reached
        // The unknown value (outside window boundaries) is calculated using the naive way, comparing one by one.
        if(i > der){
            izq = i;
            der = i;

            while(der < texto.size() && texto[der-izq] == texto[der]){
                der++;
            }
            // Corresponding value in Z[i] is assigned
            zArray[i] = der - izq;
            der--;

        }else{
            // On the other hand, where i is less than r, it means that we are inside the window values, where we might know some of the values.
            // c equals to the index where there is a match inside the window.
            c = i - izq;
            
            // If the Z value on index c is less that the remaining interval, the value z[i] is updated
            if(zArray[c] < der-i+1){
                zArray[i] = zArray[c];
            }else{
                // If there is no validation, values are calculated naively
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

// Function to see if a given array (Z array) has an existing pattern, looks if a value matches the pattern length
// O(n)
bool checkIfMatch(vector<int> zArray, int patLen){
    bool flag = false;

    for(int i = 0; i < zArray.size(); i++){
        if(zArray[i] == patLen){
            flag = true;
        }
    }

    return flag;
}
// Function that creates a Z array, given a string and a pattern and validates wheather the pattern exists inside the string using the last function checkIfMatch()
// O(m + n)
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

// Function that creates a Z array given a string and a pattern and prints, the positions or indexes where there is a match (value == pattern length)
// O(m + n)
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

// Function that prints, in concatenation with the last function, when there is a match. The function prints the pattern and the line, given by a count as arrgument
// along with the indexes
// O(m + n)
void printMatch(string texto, string patron, int count){
    cout << "(true) Found pattern: ";
    cout << "[" << patron << "]" << " on line: " << count;
    patternIndex(texto, patron);
}

// Function that traverses a given vector of lines (transmission) within three other vectors of codes (patterns) to determine the positions where each element of codes
// is present in the given transmission vector (linesTrans)
// O(n^2)
void searchPatterns(vector<string> linesTrans, vector<string> patternsCodeOne, vector<string> patternsCodeTwo, vector<string> patternsCodeThree){
    cout << "<---############## mcode1 ##############--->";
    cout << endl;
    
    // For each value of patternsCode, linesTrans is Travered entirely to see if there is a match within every element inside.
    for(int i = 0; i < patternsCodeOne.size(); i++){
        bool flag = false;
        for(int j = 0; j < linesTrans.size(); j++){
            if(patternExists(linesTrans[j], patternsCodeOne[i])){
                printMatch(linesTrans[j], patternsCodeOne[i], j);
                flag = true;
            }
        }
        // If not match was found given a pattern patterns[i] a message is shown
        if(flag == false){
            cout << "(false) Pattern: " << patternsCodeOne[i] << " NOT FOUND" << endl;
        }
    }
    
    // The traversal process is repeated three times, one for each patterns vector
    cout << endl;
    cout << "<---############## mcode2 ##############--->";
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
    cout << "<---############## mcode3 ##############--->";
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
    cout << endl;

}

#endif
