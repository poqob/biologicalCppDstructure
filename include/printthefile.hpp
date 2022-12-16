#if !defined(PRINTFILE)
#define PRINTFILE
#include "iostream"
#include <string>
#include "fstream"
#include <cstdint>
#include <cstring>
#include "./dataStructures/arraylist/ArrayList.hpp"
using namespace std;
class printthefile
{
private:
public:
    printthefile();
    ArrayList<int> *a = new ArrayList<int>();
    int rowIntParser(string);
    int rowIntParser(string row, int firstSpaceLocc, int firstNumLocc);
    void print(int);
    void print(string);
    inline std::uint64_t parse_8_chars(const char *string) noexcept;
    int intcounter = 0;
    ~printthefile();
};

printthefile::printthefile()
{
    string temp0;
    fstream read;
    read.open("../data/data.txt", ios::in);

    int count = 0;
    while (getline(read, temp0))
    {
        print(temp0);
        rowIntParser(temp0);
        count++;
        if (count == -1)
            break;
    }
    cout << "\n"
         << count << " row readed. the size of array= " << a->size() << " \nthe intcounter value: " << intcounter << endl;

    char b;
    cin >> b;

    cout << *a;

    read.close();
}

printthefile::~printthefile()
{
}

inline std::uint64_t printthefile::parse_8_chars(const char *string) noexcept
{
    std::uint64_t chunk = 0;
    std::memcpy(&chunk, string, sizeof(chunk));

    // 1-byte mask trick (works on 4 pairs of single digits)
    std::uint64_t lower_digits = (chunk & 0x0f000f000f000f00) >> 8;
    std::uint64_t upper_digits = (chunk & 0x000f000f000f000f) * 10;
    chunk = lower_digits + upper_digits;

    // 2-byte mask trick (works on 2 pairs of two digits)
    lower_digits = (chunk & 0x00ff000000ff0000) >> 16;
    upper_digits = (chunk & 0x000000ff000000ff) * 100;
    chunk = lower_digits + upper_digits;

    // 4-byte mask trick (works on pair of four digits)
    lower_digits = (chunk & 0x0000ffff00000000) >> 32;
    upper_digits = (chunk & 0x000000000000ffff) * 10000;
    chunk = lower_digits + upper_digits;

    return chunk;
}

// int parsing
int printthefile::rowIntParser(string row)
{
    int firstSpaceLoc = 0;
    int till = 0;
    int firstNumLoc = 0;
    try
    {
        do
        {
            if (row.find(' ', firstNumLoc) != string::npos)
            {
                firstSpaceLoc = row.find(' ', firstNumLoc);
                till = firstSpaceLoc - firstNumLoc + 1;
                rowIntParser(row, firstSpaceLoc, firstSpaceLoc + 1);
                print(stoi(row.substr(firstNumLoc, till)));
                a->add(stoi(row.substr(firstNumLoc, till)));
                return stoi(row.substr(firstNumLoc, till));
                // print(parse_8_chars(row.substr(firstNumLoc, till).c_str()));
                // return parse_8_chars(row.substr(firstNumLoc, till).c_str());
            }
            else
            {
                print(stoi(row.substr(firstNumLoc, row.length() - firstNumLoc)));
                a->add(stoi(row.substr(firstNumLoc, row.length() - firstNumLoc)));
                return stoi(row.substr(firstNumLoc, row.length() - firstNumLoc));
                // print(parse_8_chars(row.substr(firstNumLoc, row.length() - firstNumLoc).c_str()));
                // return parse_8_chars(row.substr(firstNumLoc, row.length() - firstNumLoc).c_str());
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
    }
    return 0;
}

// int parsing
int printthefile::rowIntParser(string row, int firstSpaceLocc, int firstNumLocc)
{
    int firstSpaceLoc = firstSpaceLocc;
    int till = 0;
    int firstNumLoc = firstNumLocc;
    try
    {
        do
        {
            if (row.find(' ', firstNumLoc) != string::npos)
            {
                firstSpaceLoc = row.find(' ', firstNumLoc);
                till = firstSpaceLoc - firstNumLoc + 1;
                rowIntParser(row, firstSpaceLoc, firstSpaceLoc + 1);
                print(stoi(row.substr(firstNumLoc, till)));
                a->add(stoi(row.substr(firstNumLoc, till)));

                return stoi(row.substr(firstNumLoc, till));
                // print(parse_8_chars(row.substr(firstNumLoc, till).c_str()));
                // return parse_8_chars(row.substr(firstNumLoc, till).c_str());
            }
            else
            {
                print(stoi(row.substr(firstNumLoc, row.length() - firstNumLoc)));
                a->add(stoi(row.substr(firstNumLoc, row.length() - firstNumLoc)));
                return stoi(row.substr(firstNumLoc, row.length() - firstNumLoc));
                // print(parse_8_chars(row.substr(firstNumLoc, row.length() - firstNumLoc).c_str()));
                // return parse_8_chars(row.substr(firstNumLoc, row.length() - firstNumLoc).c_str());
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
    }
    return 0;
}

void printthefile::print(int p)
{
    // cout << p << " ";
    intcounter++;
}
void printthefile::print(string p)
{
    // cout << "\n"
    //<< p << "*" << endl;
}

#endif // PRINTFILE
