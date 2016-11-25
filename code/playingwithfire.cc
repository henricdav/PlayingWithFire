/*

Huvudprogram för lek inte med elden II, återkomsten

*/
#include "Menu.h"
#include <iostream>

int main()
{
    Menu menu{};
    try
    {
        menu.run();
    }
    catch (...)
    {
        std::cout << "Ett okänt fel har inträffat.\n";
    }

    return 0;
}
