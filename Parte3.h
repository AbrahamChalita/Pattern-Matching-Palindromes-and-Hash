#ifndef PARTE_3
#define PARTE_3

#include <iostream>
#include <fstream>

// Customized datastructure for storing relevant data
struct result {
    int length;
    std::pair<int,int> boundaries;
};

class Parte3
{
private:
    // Class variables
    std::string file1, file2;
    std::string text1, text2;

    // Methods
    result solution (std::string largest_text, std::string shortest_text, int order);

public:
    // Constructors
    Parte3(std::string filename_1, std::string filename_2);
    ~Parte3();

    // Methods
    result longest_common_substring ();
};

Parte3::Parte3(std::string filename_1, std::string filename_2)
{
    // Helper variables
    std::string line;
    std::ifstream myfile;

    // Reading first file and storing it in variable
    myfile.open(filename_1);

    if ( myfile.is_open() ) {
        while ( myfile >> line ) {

            text1 += line;
            text1 += "\n";

        }
    }

    myfile.close();

    // Reading second file and storing it in variable
    myfile.open(filename_2);

    if ( myfile.is_open() ) {
        while ( myfile >> line ) {

            text2 += line;
            text2 += "\n";  

        }
    }

    myfile.close();
}

Parte3::~Parte3()
{
}

result Parte3::solution (std::string largest_text, std::string shortest_text, int order) {
    int currentMatch;
    result res;

    res.length = 0;
    res.boundaries = std::pair(0,0);

    for (int start = 0; start < largest_text.length(); start++) {
        
        currentMatch = 0;

        for (int i = start; i < largest_text.length(); i++) {
            
            if (i - start == shortest_text.length()) break;
            
            if (largest_text[i] == shortest_text[i - start]) {
                currentMatch++;
                if (currentMatch > res.length) {

                    if (order == 1) {
                        res.length = currentMatch;
                        res.boundaries = std::pair(i + 1 - currentMatch, i);
                    }
                    else if (order == 2) {
                        res.length = currentMatch;
                        res.boundaries = std::pair(i + 1 - currentMatch - start, i - start);
                    }

                    // std::cout << largest_text.substr(i + 1 - currentMatch, currentMatch);
                    // std::cout << "\n";
                }
            }
            else {
                currentMatch = 0;
            }
        }
    }
    return res;
}

result Parte3::longest_common_substring () {
    
    result res;
    
    // Finding the largest common substring between the texts
    if (text1.length() > text2.length()) {
        res = solution(text1, text2, 1);
    }
    else {
        res = solution(text2, text1, 2);
    }

    std::cout << res.boundaries.first << " - " << res.boundaries.second << "\t";
    for (int i = res.boundaries.first; i <= res.boundaries.second; i++) {
        std::cout << text1[i];
    }
    std::cout << std::endl;

    return res;
}

#endif