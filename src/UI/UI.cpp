#include "../../include/UI/UI.hpp"
Ui::Ui() {}

void Ui::draw(string header, stringstream stream)
{
    // i used try catch the reason for that, i'm testing my code on linux as well.
    // linux bash use 'clear' instead 'cls'
    try
    {
        system("cls");
    }
    catch (const std::exception &e)
    {
    }
    string space = string(abs(50 - (int)header.length()), ' ');
    output << "\n"
           << space << header << "\n\n"
           << stream.str();
    cout << output.str();
    output.str("");

    try
    {
        system("pause");
    }
    catch (const std::exception &e)
    {
    }
}