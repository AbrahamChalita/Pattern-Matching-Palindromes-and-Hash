#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "parte1.h"
using namespace std;

int main(){
    cout << "Parte 1" << endl;
    cout << endl;
    searchPatterns("transmission1.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt");
    cout << endl;
    cout << "Parte 2" << endl;
    searchPatterns("transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt");

}

