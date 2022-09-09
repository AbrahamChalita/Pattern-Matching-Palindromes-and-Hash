#include <iostream> 
#include <vector>
#include <string>
using namespace std;

void zArray(string texto, vector<int> &zArray);
void patternMatchZ(string texto, string patron);

int main(){

    string text = "faabbcdeffghiaaabbcdfgaabf";
    string pattern = "aabb";

    patternMatchZ(text, pattern);

    return 0;
}

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

void patternMatchZ(string texto, string patron){
    string nuevo = patron + '$' + texto;

    vector<int> arrayZ(nuevo.length());
    zArray(nuevo, arrayZ);

    for(int i = 0; i < nuevo.length(); i++){
        if(arrayZ[i] == patron.length()){
            cout << "Patron en index " << i - patron.length() - 1 << endl;
        }
    }
}