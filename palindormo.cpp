#include <string>
#include <iostream>
#include <fstream>

struct result
{
    std::string palindromo;
    int length;
    int begin;
    int end;
};

// Function that finds and prints the largest palindrome in a given text
// n: length of text
// m: length of largest palindrome
// Space complexity: O(1)
void find_palindrome (std::string text, std::pair<int, int> &curr_best, result &best_result) {
    int center = 0;
    int left_bound, right_bound;
    
    bool even;

    for (center; center < text.length(); center++) { // O(nm)

        // Odd palindrome
        left_bound = center; right_bound = center;

        // Initializing palindrome length as 0 at center
        int palindrome_length = 0;

        while (text[left_bound] == text[right_bound]) // O(m) / Average: O(1)
        {

            // Increase palindrome length by one
            palindrome_length++;

            // Updating max_length and center
            if (palindrome_length * 2 - 1 > best_result.length) {
                best_result.length = palindrome_length * 2 - 1;
                best_result.begin = center - palindrome_length + 1;
                best_result.end = center + palindrome_length - 1;
                best_result.palindromo = text.substr(best_result.begin, palindrome_length * 2 - 1);
            }

            // Keep expanding palindrome
            if (left_bound - 1 >= 0 && right_bound < text.length()) {
                left_bound--;
                right_bound++;
            }

            // Palindrome breaks
            else {
                break;
            }
        }

        // Even palindrome
        left_bound = center; right_bound = center + 1;
            
        // Initializing palindrome length as 0 at center
        palindrome_length = 0;

        while (text[left_bound] == text[right_bound]) // O(m) / Average: O(1)
        {

            // Increase palindrome length by one
            palindrome_length++;

            // Updating max_length and center
            if (palindrome_length * 2 > best_result.length) {
                best_result.length = palindrome_length * 2;
                best_result.begin = center - palindrome_length + 1;
                best_result.end = center + palindrome_length;
                best_result.palindromo = text.substr(best_result.begin, palindrome_length * 2);
            }

            // Keep expanding palindrome
            if (left_bound - 1 >= 0 && right_bound < text.length()) {
                left_bound--;
                right_bound++;
            }

            // Palindrome breaks
            else {
                break;
            }
        }
    }
}

void biggest_palindrome_in (std::string name) {

    std::string read_line;

    result mejor_palindromo;
    result curr_palindromo;
    mejor_palindromo.begin = 0;
    mejor_palindromo.end = 0;
    mejor_palindromo.length= 0;
    mejor_palindromo.palindromo = "";

    std::ifstream myfile;
    myfile.open(name);

    std::pair<int, int> result = std::pair(0, 0);
    int curr_max_length = result.first;
    bool even, even_result;
    int line_n = 1;
    int result_line = line_n;

    if ( myfile.is_open() ) {
        while ( myfile >> read_line ) {

            // Searching biggest palindrome in a given line
            find_palindrome(read_line, result, curr_palindromo);

            if (mejor_palindromo.length < curr_palindromo.length) {
                mejor_palindromo = curr_palindromo;
                result_line = line_n;
            }

            line_n++;
        }
    }

    myfile.close();

    std::cout << "\nLargest palindrome @ " << result_line << "\n";
    std::cout << "Length of palindrome " << mejor_palindromo.length << "\n\n";
    std::cout << mejor_palindromo.begin << " - " << mejor_palindromo.end << "\t";
    std::cout << mejor_palindromo.palindromo << "\n" << std::endl;
}

int main(int argc, char const *argv[])
{
    biggest_palindrome_in("log_p.txt");
    // biggest_palindrome_in("log3.txt");

    /* code */
    return 0;
}
