#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "parte1.h"
//#include "Parte2.h"
//#include "Parte3.h"

using namespace std;

int main(int argc, char const *argv[]){
  
  cout << "E1. Actividad Integradora 1" << endl;
  cout << "\nAbraham Chalita Núñez: A01653879\nJesús Daniel Rivas Nuño: A01655181\nEduardo Ángeles Guerrero: A01653868" << endl;
  cout << endl;
  cout << "---------------Parte 1---------------" << endl;
  cout << endl;
  searchPatterns("transmission1.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt");
  cout << endl;
  searchPatterns("transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt");
  cout << "---------------Parte 2---------------" << endl;
// biggest_palindrome_in("log_p.txt");
// biggest_palindrome_in("log3.txt");

/*Parte2 testp2 = Parte2("log_p.txt");
testp2.biggest_palindrome_in();
cout << endl;
cout << "Parte 3" << endl;
Parte3 testP3 = Parte3("log.txt", "log2.txt");
testP3.longest_common_substring();*/

}