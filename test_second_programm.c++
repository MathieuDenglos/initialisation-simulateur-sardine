#include <iostream>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::string test(argv[i]);
        std::cout << test << std::endl;
    }
    system("PAUSE");

    return 1;
}