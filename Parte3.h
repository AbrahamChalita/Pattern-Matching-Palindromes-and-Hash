#ifndef PARTE_3
#define PARTE_3

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Customized datastructure for storing relevant data
struct result {
    int length;
    pair<int,int> boundaries;
};

class Parte3
{
private:
    // Class variables
    string text1, text2;

    // Methods
    result solution (string largest_text, string shortest_text, int order);

public:
    // Constructors
    Parte3(vector<string> file1, vector<string> file2);

    // Methods
    void longest_common_substring ();
};

Parte3::Parte3(vector<string> file1, vector<string> file2)
{
    // Reading first file and storing it in variable
    for ( string line : file1 ) {

        text1 += line;
        text1 += "\n";

    }

    // Reading second file and storing it in variable
    for ( string line : file2 ) {

        text2 += line;
        text2 += "\n";  

    }
}

result Parte3::solution (string largest_text, string shortest_text, int order) {
    int currentMatch;
    result res;

    res.length = 0;
    res.boundaries = pair<int,int>(0,0);

    for (int start = 0; start < largest_text.length(); start++) {
        
        currentMatch = 0;

        for (int i = start; i < largest_text.length(); i++) {
            
            if (i - start == shortest_text.length()) break;
            
            if (largest_text[i] == shortest_text[i - start]) {
                currentMatch++;
                if (currentMatch > res.length) {

                    if (order == 1) {
                        res.length = currentMatch;
                        res.boundaries = pair<int,int>(i + 1 - currentMatch, i);
                    }
                    else if (order == 2) {
                        res.length = currentMatch;
                        res.boundaries = pair<int,int>(i + 1 - currentMatch - start, i - start);
                    }

                    // cout << largest_text.substr(i + 1 - currentMatch, currentMatch);
                    // cout << "\n";
                }
            }
            else {
                currentMatch = 0;
            }
        }
    }
    return res;
}

void Parte3::longest_common_substring () {
    
    result res;
    
    // Finding the largest common substring between the texts
    if (text1.length() > text2.length()) {
        res = solution(text1, text2, 1);
    }
    else {
        res = solution(text2, text1, 2);
    }

    cout << res.boundaries.first << " - " << res.boundaries.second << "\t";
    for (int i = res.boundaries.first; i <= res.boundaries.second; i++) {
        cout << text1[i];
    }
    cout << endl;
}

#endif