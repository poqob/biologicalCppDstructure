#include "../../include/fileOperations/ReadFile.hpp"

ReadFile::ReadFile(int stopRow, Controll *controller)
{
    controll = controller;
    controll->totalSystemCountSetter(fileRowCounter());
    string temp0;
    fstream read;

    read.open("data/data.txt", ios::in);
    this->stopRow = stopRow;
    while (getline(read, temp0))
    {
        rowIntParser(temp0, 0, 0);
        controll->nextRow();
        if (count == stopRow - 1 && controller->debug_status())
            break;
        count++;
    }
    read.close();
    // controll->createOrganism();
    controll->debugPrinterPhoto();
}

ReadFile::ReadFile(Controll *controller)
{
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
    // controll->createOrganism();
    controll->debugPrinterPhoto();
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

int ReadFile::fileRowCounter()
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

ReadFile::~ReadFile()
{
    delete controll;
}