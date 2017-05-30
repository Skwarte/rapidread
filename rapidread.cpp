#include    <algorithm>
#include    <fstream>
#include    <string>
#include    <iostream>
#include    <unistd.h>
#include    "rapidread.h"

#define SECOND  1000000 
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

void processFile(string str)
{
    string word;
    file.open(str); 
    while(file) 
    {
        file >> word;
        cout << word << endl;
		usleep(SECOND/(3));
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
        processFile(fileName);
    }
} 
