#include <iostream>
#include <fstream>

struct result {
    int length;
    std::pair<int,int> boundaries;
};

result solution (std::string largest_text, std::string shortest_text) {
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

                    res.length = currentMatch;
                    res.boundaries = std::pair(i + 1 - currentMatch, i);

                    std::cout << largest_text.substr(i + 1 - currentMatch, currentMatch);
                    std::cout << "\n";
                }
            }
            else {
                currentMatch = 0;
            }
        }
    }
    return res;
}

result longest_common_substring (std::string text_1, std::string text_2) {
    
    result res;
    
    if (text_1.length() > text_2.length()) {
        res = solution(text_1, text_2);
        for (int i = res.boundaries.first; i <= res.boundaries.second; i++) {
            std::cout << text_1[i];
        }
        std::cout << std::endl;
    }
    else {
        res = solution(text_2, text_1);
        for (int i = res.boundaries.first; i <= res.boundaries.second; i++) {
            std::cout << text_2[i];
        }
        std::cout << std::endl;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::string text1 = "";
    std::string text2 = "";

    std::ifstream myfile;
    myfile.open("log.txt");

    if ( myfile.is_open() ) {
        while ( myfile >> line ) {
            text1 += line;
            text1 += "\n";            
        }
    }

    myfile.close();

    
    myfile.open("log2.txt");

    if ( myfile.is_open() ) {
        while ( myfile >> line ) {
            text2 += line;
            text2 += "\n";            
        }
    }

    myfile.close();

    // text1 = "saludos desde otro salon";
    // text2 = "saludos vengo de otro salon";

    result res = longest_common_substring(text1, text2);

    return 0;
}
