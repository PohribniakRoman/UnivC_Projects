#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file ("index.txt");
    file.seekg(0,ios_base::end);
    int n = file.tellg();
    file.seekg(n,ios_base::end);
    cout << n << "\n";
    char* buffer=new char[n+1]; buffer[n]=0;
    file.read(buffer,n);
    cout<< buffer;
    delete [] buffer;
    return 0;
}