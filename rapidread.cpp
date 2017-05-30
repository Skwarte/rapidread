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
    return fileType;
}
int main(int argc, char* argv[]) 
{
    string fileName = argv[1];
    string ret = findFileEx(fileName);
} 
