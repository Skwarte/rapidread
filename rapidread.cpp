#include    <algorithm>
#include    <fstream>
#include    <string>
#include    <iostream>
#include    <unistd.h>
#include    "rapidread.h"

#define MIN  60000000 
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
    if(str.compare(".txt"))
        supported = true;
//   else if(str == ".pdf")
//     supported = true;
//  else
//      supported = false;
	cout << supported << endl;
    return supported;
}

void txtProcess(string str)
{
    string word;
    file.open(str.c_str()); 
    while(file) 
    {
        file >> word;
        cout << word << endl;
		usleep(MIN/450); //insert wpm number
    }
}

int main(int argc, char* argv[]) 
{
    string fileName = argv[1];
    string fileType = findFileEx(fileName);
    bool supp = supported(fileType);
	cout << supp << endl;
    if(supp == true)
    {
        txtProcess(fileName);
    }
} 
