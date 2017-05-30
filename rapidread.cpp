#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "rapidread.h"
string findFileEx(string s)
{
    int len = s.length(); 
    bool exFound = false;
    string fileType = "";

    for(int i = 1; i <= len; i++)
    {
        if(s[i] == '.')
            exFound = true;
        if(exFound == true) 
        {
            fileType+=s[i]; 
        }   
    }
    transform(fileType.begin(), fileType.end(), fileType.begin(), ::tolower);
    return fileType;
}

bool supported(string str) 
{
    bool supported = false;
    cout << "supported: " << supported << endl;
    if(str == ".txt")
        supported = true;
//   else if(str == ".pdf")
//     supported = true;
//  else
//      supported = false;
    return supported;
}

int main(int argc, char* argv[]) 
{
    string fileName = argv[1];
    string fileType = findFileEx(fileName);
    bool supp = supported(fileType);
} 
