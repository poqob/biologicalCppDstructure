#include "../../include/fileOperations/ReadFile.hpp"

ReadFile_::ReadFile_(int stopRow, Controll *controller)
{
    // attemting fields start values
    count = 0;
    totalRowNumber = 0;

    // controller
    controll = controller;
    controll->totalSystemCountSetter(fileRowCounter());
    string temp0;
    fstream read;

    read.open("data/data.txt", ios::in);
    this->stopRow = stopRow;
    while (getline(read, temp0))
    {
        if (count == stopRow)
            break;
        rowIntParser(temp0, 0, 0);
        controll->nextRow();

        count++;
    }
    read.close();
    controll->createOrganism();
}

ReadFile_::ReadFile_(Controll *controller)
{
    // attemting fields
    this->stopRow = -1;
    count = 0;
    totalRowNumber = 0;

    // controller
    controll = controller;
    controll->totalSystemCountSetter(fileRowCounter());
    string temp0;
    fstream read;

    read.open("data/data.txt", ios::in);
    while (getline(read, temp0))
    {
        rowIntParser(temp0, 0, 0);
        controll->nextRow();
        count++;
    }
    read.close();
    controll->createOrganism();
}

// int parsing
void ReadFile_::rowIntParser(string row, int firstSpaceLocc, int firstNumLocc)
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
                controll->send(value); // sending values to controll class.
                return;
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
    }
}

int ReadFile_::fileRowCounter()
{
    string temp0;
    fstream read;
    read.open("data/data.txt", ios::in);
    while (getline(read, temp0))
    {
        totalRowNumber++;
    }
    read.close();
    return totalRowNumber;
}

ReadFile_::~ReadFile_()
{
}