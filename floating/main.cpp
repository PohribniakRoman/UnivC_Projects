#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> decToBinary(int n){
    vector<int> number;
    for (int i = 0;n > 0;i++) {
        number.push_back(n % 2);
        n /= 2;
    }
    return number;
}
vector<int> fractToBinary(double n,int len){
    vector<int> res;
    for (int i = 0; n != 0; ++i) {
        if(i == len)return res;
        n *= 2;
        res.push_back(::floor(n));
        n -= ::floor(n);
    }
    while(res.size() != 12){
        res.push_back(0);
    }
    return res;
}

class Float {
private:
    const int explicitLength = 8;
    const int significantLength = 12;
    void visualize(vector<int> arr){
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
        }
    }
    vector<int> reverse(vector<int> arr,int len){
        vector<int> res;
        while (len != arr.size()){
            arr.push_back(0);
        }
        for (int i = 0; i < arr.size(); ++i) {
            res.push_back(arr[arr.size()-i-1]);
        }
        return res;
    }
public:
    void toFloat(double num){
        if(num != 0) {
            cout << ((num < 0) ? "1" : "0") << "|";
            num = abs(num);
            vector<int> binary = decToBinary(num);
            vector<int> floatExplicit = reverse(decToBinary(floor(log(num) / log(2.)) + 127), explicitLength);
            double res = num >= 1 ?
                         (num - pow(2, binary.size() - 1)) / pow(2, binary.size() - 1) :
                         abs(num - pow(2, floor(log(num) / log(2.))));
            vector<int> significant = fractToBinary(res, significantLength);

            this->visualize(floatExplicit);
            cout << "|";
            this->visualize(significant);
        }else{

        }
    }
};


int main(){
    Float FloatConstructor;
    double x;
    cin >>x;
    FloatConstructor.toFloat(x);
  return 0;
}