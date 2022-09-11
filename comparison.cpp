#include "Parte3.h"


int main(int argc, char const *argv[])
{
    
    Parte3 test = Parte3("log.txt", "log2.txt");
    test.longest_common_substring();

    return 0;
}
