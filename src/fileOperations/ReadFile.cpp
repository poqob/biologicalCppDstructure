#include "../../include/fileOperations/ReadFile.hpp"

ReadFile::ReadFile(int stopRow, Controll *controller)
{
    string temp0;
    fstream read;
    controll = controller;
    read.open("data/data.txt", ios::in);

    int count = 0;
    while (getline(read, temp0))
    {
        rowIntParser(temp0, 0, 0);

        // debug code
        if (count == stopRow)
            break;
        count++;
    }
    controll->createOrganism();
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
                controll->send(value);
                return;
            }
            else
            {
                value = stoi(row.substr(firstNumLoc, row.length() - firstNumLoc));
                controll->send(value);
                return;
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
    }
}

ReadFile::~ReadFile()
{
    delete controll;
}