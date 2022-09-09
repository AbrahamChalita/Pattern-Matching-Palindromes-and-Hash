#include <iostream>
#include <fstream> //Leer archivo
#include <sstream> //Tokenizar string
#include <iostream>

#include <unistd.h>
#include <ctime>

using namespace std;

string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

int main() {

  //File is opened and written.
  srand((unsigned)time(NULL) * getpid()); 
  cout << "El archivo se abre y se escribe en el" << endl;
  string txt;
  string fileName = "test.txt";
  ofstream file;
  file.open(fileName);

  int n = 0;
  
  while (n <= 100)
  {  
    txt = gen_random(78);

    file << txt << endl;

    ++n;
  }

  file.close();

  //File is read
  cout << "El archivo se abre y se lee en el" << endl;
  vector<string> list;
  ifstream lector(fileName);

  if(lector.fail()){
    cout << "Error en lectura de archivo txt: " << fileName << endl;
    return -1;
  }

  string line, chain;

  while(getline(lector, line)){
    istringstream iss(line);
    iss >> chain;
  }

  lector.close();
  cout << "Cerrao" << endl;
  cout << chain <<endl;
}
