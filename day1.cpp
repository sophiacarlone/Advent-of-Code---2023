#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main(int argc, char *argv[]){
	string filename = argv[1];
	fstream in;
    in.open(filename);

    int sum = 0;
    char curr;
    vector<int> nums;
    int lines = 0;

    while(in >> noskipws >> curr){
        if((int)curr > 47 && (int)curr < 58){
            nums.push_back(((int)curr-48));
        }
        if(curr == '\n'){
            cout << (nums[0] * 10) + nums[nums.size() -1] << endl;
            sum += (nums[0] * 10) + nums[nums.size() -1];
            while (!nums.empty()){
                nums.pop_back();
            }
        }
    }

    cout << sum << endl;

    return 0;
}