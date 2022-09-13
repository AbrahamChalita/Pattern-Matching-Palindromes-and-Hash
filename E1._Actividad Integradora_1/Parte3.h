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

// Sultion
// Function that finds the largest common substring between two texts. / O(n^2)
result Parte3::solution (string largest_text, string shortest_text, int order) {
    int currentMatch;
    result res;

    res.length = 0;
    res.boundaries = pair<int,int>(0,0);

    // For loop that defines the shift to the left that the largest string has from the shortest string
    for (int start = 0; start < largest_text.length(); start++) {
        // Initializing current match to 0 for a given shift
        currentMatch = 0;
        // For loop iterating matching characters
        for (int i = start; i < largest_text.length(); i++) {
            
            // If index goes out of bounds, loop breaks
            if (i - start == shortest_text.length()) break;
            
            // Counting matching characters
            if (largest_text[i] == shortest_text[i - start]) {
                currentMatch++;
                // Updating biggest match if current count is max
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
                // Restarting counter
                currentMatch = 0;
            }
        }
    }
    return res;
}

void Parte3::longest_common_substring () { // O(n^2)
    
    result res;
    
    // Finding the largest common substring between the texts
    if (text1.length() > text2.length()) {
        res = solution(text1, text2, 1); // O(n^2)
    }
    else {
        res = solution(text2, text1, 2); // O(n^2)
    }

    // Printing the results
    cout << res.boundaries.first << " - " << res.boundaries.second << "\t";
    for (int i = res.boundaries.first; i <= res.boundaries.second; i++) {
        cout << text1[i];
    }
    cout << endl;
}

#endif
