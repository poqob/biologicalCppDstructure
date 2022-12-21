#include "../../include/UI/UI.hpp"
Ui::Ui() {}

void Ui::set_visual(bool visual_status)
{
    check = visual_status;
}

void Ui::draw(string header, stringstream stream, bool mutated)
{

    // i used try catch the reason for that, i'm testing my code on linux as well.
    // linux bash use 'clear' instead 'cls'
    try
    {
        system("cls");
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    catch (const std::exception &e)
    {
    }
    string space = string(abs(50 - (int)header.length()), ' ');
    if (hConsole != NULL && mutated == 1)
        SetConsoleTextAttribute(hConsole, 12);
    output << "\n"
           << space << header << "\n\n"
           << stream.str();
    cout << output.str() << endl;
    output.str("");
    if (hConsole != NULL && mutated == 1)
        SetConsoleTextAttribute(hConsole, 15);
    try
    {
        system("pause");
    }
    catch (const std::exception &e)
    {
    }
}