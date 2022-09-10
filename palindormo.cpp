#include <string>
#include <iostream>
#include <fstream>


// Function that finds and prints the largest palindrome in a given text
// n: length of text
// m: length of largest palindrome
// Space complexity: O(1)
bool palindromo (std::string text, std::pair<int, int> &curr_best) {
    int center = 0;
    int left_bound, right_bound;
    
    bool even;

    for (center; center < text.length(); center++) { // O(nm)

        left_bound = center; right_bound = center;

        // Initializing palindrome length as 0 at center
        int palindrome_length = 0;

        // Odd palindrome
        while (text[left_bound] == text[right_bound]) // O(m) / Average: O(1)
        {

            // Increase palindrome length by one
            palindrome_length++;

            // Updating max_length and center
            if (palindrome_length > curr_best.first) {
                curr_best.first = palindrome_length;
                curr_best.second = center;
                even = false;
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
            if (palindrome_length > curr_best.first) {
                curr_best.first = palindrome_length;
                curr_best.second = center;
                even = true;
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

    std::cout << "\nLargest palindrome @ " << line_n << "\n";
    std::cout << "Length of palindrome " << max_length << "\n\n";
    std::cout << max_center - max_length + 1;

    // Print even palindrome
    if (even_result) {
        std::cout << " - " << max_center + max_length << "\t";
        for (int i = max_center - max_length + 1; i < max_center + max_length + 1; i++) { // O(m)
            std::cout << line[i];
        }
    }

    // Print odd palindrome
    else {
        std::cout << " - " << max_center + max_length - 1 << "\t";
        for (int i = max_center - max_length + 1; i < max_center + max_length; i++) { // O(m)
            std::cout << line[i];
        }
    }

    return even;
}

void biggest_palindrome_in (std::string name) {

    std::string line;
    std::string pal1;

    std::ifstream myfile;
    myfile.open(name);

    std::pair<int, int> result = std::pair(0, 0);
    int curr_max_length = result.first;
    bool even, even_result;
    int line_n = 1;
    int result_line = line_n;

    if ( myfile.is_open() ) {
        while ( myfile >> line ) {

            even = palindromo(line, result);

            if (curr_max_length < result.first) {
                curr_max_length = result.first;
                result_line = line_n;
                pal1 = line;
                even_result = even;
            }

            line_n++;
        }
    }

    myfile.close();

    
    int max_center = result.second;
    int max_length = result.first;

    std::cout << "\nLargest palindrome @ " << line_n << "\n";
    std::cout << "Length of palindrome " << max_length << "\n\n";
    std::cout << max_center - max_length + 1;

    // Print even palindrome
    if (even_result) {
        std::cout << " - " << max_center + max_length << "\t";
        for (int i = max_center - max_length + 1; i < max_center + max_length + 1; i++) { // O(m)
            std::cout << line[i];
        }
    }

    // Print odd palindrome
    else {
        std::cout << " - " << max_center + max_length - 1 << "\t";
        for (int i = max_center - max_length + 1; i < max_center + max_length; i++) { // O(m)
            std::cout << line[i];
        }
    }

    std::cout << "\n" << std::endl;



}

int main(int argc, char const *argv[])
{
    biggest_palindrome_in("log.txt");

    /* code */
    return 0;
}
