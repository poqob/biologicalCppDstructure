#include "../../include/fileOperations/ReadFile.hpp"

ReadFile::ReadFile(Tissue *t, int stopRow = -1)
{
    string temp0;
    fstream read;
    tissue = t;
    read.open("data/data.txt", ios::in);

    int count = 0;
    while (getline(read, temp0))
    {
        rowIntParser(temp0, 0, 0);
        count++;
        if (count == stopRow)
            break;
    }
    read.close();
}

// int parsing
void ReadFile::rowIntParser(string row, int firstSpaceLocc, int firstNumLocc)
{
    int firstSpaceLoc = firstSpaceLocc;
    int till = 0;
    int firstNumLoc = firstNumLocc;
    int value = 0;
    try
    {
        do
        {
            if (row.find(' ', firstNumLoc) != string::npos)
            {
                firstSpaceLoc = row.find(' ', firstNumLoc);
                till = firstSpaceLoc - firstNumLoc + 1;
                rowIntParser(row, firstSpaceLoc, firstSpaceLoc + 1);
                value = stoi(row.substr(firstNumLoc, till));
                tissue->add(Cell(value));
                return;
            }
            else
            {
                value = stoi(row.substr(firstNumLoc, row.length() - firstNumLoc));
                tissue->add(Cell(value));
                return;
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
    }
}
// TODO: we will create cells and send them to Controll class to have controll over them.
// TODO: tissues will be added to organs; organs will be added to systems; system gonna added to organism and end.

ReadFile::~ReadFile()
{
}