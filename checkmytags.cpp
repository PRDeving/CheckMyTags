///////////////////////////////
//     v1.0    2015-07-17    //
// Pablo R Deving 2015-07-17 //
//  pablo.deving@gmail.com   //
///////////////////////////////

// Loads the lookfor.conf file, gets the tags stored there and
// looks for tags unclosed in the passed file
//
// Coded, compiled and runned in ArchLinux x64
//
// I tried to make it portable but not sure at all if it works
// in other OSes or not
//
// You are allowed to modify and distribute, just keep here my 
// verion comment.
//
// Good Luck :)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Tag{
    string name;
    string cname;
    int count;
};

string lookforfile = "lookfor.conf";

vector<Tag> tags;
int table = 0;
int tr = 0;
int td = 0;

void getLookFor(char* file[] = NULL){
    if(file != NULL)
        lookforfile = *file;

    string line;
    ifstream is(lookforfile.c_str());

    while(getline(is, line)){
        Tag item;
        item.name = line;
        item.cname = line.insert( 1, "/");
        item.count = 0;
        tags.push_back(item);
    }
}

int countSubstring(const string* str, const string sub){
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str->find(sub); offset != std::string::npos;
    offset = str->find(sub, offset + sub.length())){
        ++count;
    }
    return count;
}

void checkIf(string* line){
    for(int x = 0; x < tags.size(); x++){
        if(line->find(tags[x].name) != string::npos){
            tags[x].count += countSubstring(line, tags[x].name);
        }
        if(line->find(tags[x].cname) != string::npos){
            tags[x].count -= countSubstring(line, tags[x].cname);
        }
    }
}

int main(int argc, char* argv[]){

    getLookFor();
    int count = 0;    

    string line;
    if(argc < 2){
        cout << "No file." << endl;
        return 0;
    }
    ifstream is(argv[1]);

    while(getline(is, line)){
        checkIf(&line);
        count++;
    }

    cout << endl << endl << count << " lines analyzed." << endl
         << "____________________________" << endl <<endl;

    for(int x = 0; x < tags.size(); x++){
        if(tags[x].count < 0){
            cout << abs(tags[x].count) << " " << tags[x].name << "> closes uneeded" << endl;
        }else if(tags[x].count > 0){
            cout << tags[x].count << " " << tags[x].name << "> tags unclosed" << endl;
        }else{
            cout << "Every " << tags[x].name << "> tags correctly closed" << endl;
        }
    }
}
