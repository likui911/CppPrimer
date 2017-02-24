#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readToVect(const string& file_name,vector<string> &vec){
    string word;
    ifstream inf(file_name);
    if(inf)
    {
        while(inf>>word){
            vec.push_back(word);
        }
    }
}

int main(){
    string file_name = "..\\chapter08\\00.txt";
    vector<string> context;
    readToVect(file_name,context);
    for(string s:context){
        cout<<s<<endl;
    }
    return 0;
}