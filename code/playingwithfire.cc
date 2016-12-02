/*

Huvudprogram för lek inte med elden II, återkomsten

*/
#include "Menu.h"
#include <iostream>
#include <exception>

int main()
{
    Menu menu{};
    try
    {
        menu.run();
    }
    catch (std::exception& e)
    {
        std::cout << "Ett okänt fel har inträffat: " << e.what() << std::endl;
    }

    return 0;
}
