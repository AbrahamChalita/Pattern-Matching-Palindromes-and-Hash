#ifndef PARTE_2
#define PARTE_2

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct palindrome
{
    string palindromo;
    int length;
    int begin;
    int end;
};

class Parte2
{
private:
    vector<string> text;
    void find_palindrome (string text, palindrome &best_result);
public:
    Parte2(vector<string> text);
    ~Parte2();
    void biggest_palindrome_in ();
};

Parte2::Parte2(vector<string> text)
{
    this->text = text;
}

Parte2::~Parte2()
{
    // delete this;
}

// Function that finds and prints the largest palindrome in a given text
// n: length of text
// m: length of largest palindrome
// Space complexity: O(1)
void Parte2::find_palindrome (string text, palindrome &best_result) {
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
                // cout << best_result.palindromo << "\n";
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
                // cout << best_result.palindromo << "\n";
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

void Parte2::biggest_palindrome_in () {

    palindrome mejor_palindromo;
    mejor_palindromo.begin = 0;
    mejor_palindromo.end = 0;
    mejor_palindromo.length= 0;
    mejor_palindromo.palindromo = "";
    palindrome curr_palindromo = mejor_palindromo;

    int line_n = 1;
    int result_line = line_n;

    for ( string read_line : this->text ) {

        // Searching biggest palindrome in a given line
        find_palindrome(read_line, curr_palindromo);

        if (mejor_palindromo.length < curr_palindromo.length) {
            mejor_palindromo = curr_palindromo;
            result_line = line_n;
        }

        line_n++;
    }

    cout << "\nLargest palindrome @ line " << result_line << "\n";
    cout << "Length of palindrome " << mejor_palindromo.length << "\n\n";
    cout << mejor_palindromo.begin << " - " << mejor_palindromo.end << "\t";
    cout << mejor_palindromo.palindromo << "\n" << endl;
}

#endif