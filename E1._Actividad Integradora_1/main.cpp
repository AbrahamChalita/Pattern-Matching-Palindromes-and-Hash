/*
		Abraham Chalita Núñez      A01653879
		Jesús Daniel Rivas Nuño    A01655181
		Eduardo Ángeles Guerrero   A01653868
	
		E1 - Actividad Integradora 1
		12/09/2022
*/

#include "Parte1.h"
#include "Parte2.h"
#include "Parte3.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool file_is_hexa(vector<string> file) {
  for (string line : file) {
    for (char c : line) {
      if ((c < '0' || c > '9') || (c < 'A' || c > 'F')) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {

  // Variables with file names
  string fileT1 = "transmission1.txt";
  string fileT2 = "transmission2.txt";
  string fileMC1 = "mcode1.txt";
  string fileMC2 = "mcode2.txt";
  string fileMC3 = "mcode3.txt";

  cout << "E1. Actividad Integradora 1" << endl;
  cout << endl;
  cout << "ASEGURESE DE QUE LOS ARCHIVOS TXT SE ENCUENTREN EN LA MISMA CARPETA "
          "QUE EL MAIN.CPP"
       << endl;
  cout << endl;

  // Variables to fill with content
  string line, chain;
  vector<string> transmission1;
  vector<string> transmission2;
  vector<string> mcode1;
  vector<string> mcode2;
  vector<string> mcode3;

  // Transmission1 file 1
  ifstream lector(fileT1);

  if (lector.fail()) {
    cout << "Error while reading txt file, please check the file: " << fileT1
         << endl;
    return -1;
  }

  while (getline(lector, line)) {
    istringstream iss(line);
    iss >> chain;
    transmission1.push_back(chain);
  }

  lector.close();

  // Transmission1 file 2
  lector.open(fileT2);

  if (lector.fail()) {
    cout << "Error while reading txt file, please check the file: " << fileT2
         << endl;
    return -1;
  }

  while (getline(lector, line)) {
    istringstream iss(line);
    iss >> chain;
    transmission2.push_back(chain);
  }

  lector.close();

  // Mcode file 1
  lector.open(fileMC1);

  if (lector.fail()) {
    cout << "Error while reading txt file, please check the file: " << fileMC1
         << endl;
    return -1;
  }

  while (getline(lector, line)) {
    istringstream iss(line);
    iss >> chain;
    mcode1.push_back(chain);
  }

  lector.close();

  // Mcode file 2
  lector.open(fileMC2);

  if (lector.fail()) {
    cout << "Error while reading txt file, please check the file: " << fileMC2
         << endl;
    return -1;
  }

  while (getline(lector, line)) {
    istringstream iss(line);
    iss >> chain;
    mcode2.push_back(chain);
  }

  lector.close();

  // Mcode file 3
  lector.open(fileMC3);

  if (lector.fail()) {
    cout << "Error while reading txt file, please check the file: " << fileMC3
         << endl;
    return -1;
  }

  while (getline(lector, line)) {
    istringstream iss(line);
    iss >> chain;
    mcode3.push_back(chain);
  }

  lector.close();

  // Verifying the Files
  if (!file_is_hexa(transmission1)) {
    cout << "Error verifying hexadecimal values in file (0-9 A-F), please "
            "check the file: "
         << fileT1 << endl;
    return -2;
  }
  if (!file_is_hexa(transmission2)) {
    cout << "Error verifying hexadecimal values in file (0-9 A-F), please "
            "check the file: "
         << fileT2 << endl;
    return -2;
  }
  if (!file_is_hexa(mcode1)) {
    cout << "Error verifying hexadecimal values in file (0-9 A-F), please "
            "check the file: "
         << fileMC1 << endl;
    return -2;
  }
  if (!file_is_hexa(mcode2)) {
    cout << "Error verifying hexadecimal values in file (0-9 A-F), please "
            "check the file: "
         << fileMC2 << endl;
    return -2;
  }
  if (!file_is_hexa(mcode3)) {
    cout << "Error verifying hexadecimal values in file (0-9 A-F), please "
            "check the file: "
         << fileMC3 << endl;
    return -2;
  }

  cout << endl;
  cout << "---------------Parte 1---------------" << endl;
  cout << endl;
  cout << "Pattern matches for: " << fileT1 << endl;
	cout << endl;
  searchPatterns(transmission1, mcode1, mcode2, mcode3);
  cout << endl;
	cout << "Pattern matches for: " << fileT2 << endl;
	cout << endl;
  searchPatterns(transmission2, mcode1, mcode2, mcode3);
  cout << "---------------Parte 2---------------" << endl;
  cout << endl;
  // biggest_palindrome_in("log_p.txt");
  // biggest_palindrome_in("log3.txt");

  Parte2 palin1 = Parte2(transmission1);
  Parte2 palin2 = Parte2(transmission2);
  palin1.biggest_palindrome_in();
  cout << endl;
  palin2.biggest_palindrome_in();
  cout << "---------------Parte 3---------------" << endl;
  Parte3 testP3 = Parte3(transmission1, transmission2);
  testP3.longest_common_substring();
}
