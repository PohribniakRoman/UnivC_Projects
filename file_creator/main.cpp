#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file ("index.txt");
    vector<string> Data;
    char ch;
    int s = 0;
    while (file.get(ch)){
        if(ch == '\n'){
            s++;
        }else{
            if(Data.size() > s){
                Data[s].push_back(ch);
            } else{
                string newElement = "";
                newElement.push_back(ch);
                Data.push_back(newElement);
            }
        }
    }
    for (int q = 0; q < Data.size(); ++q) {
        cout << Data[q] << "\n";
    }
    return 0;
}