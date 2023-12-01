#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

int main(int argc, char *argv[]){
	string filename = argv[1];
	fstream in;
    in.open(filename);

    int sum = 0;
    char curr;
    vector<int> nums;
    int lines = 0;

    map<string, int> string2values;

    string2values["0"] = 0;
    string2values["1"] = 1;
    string2values["2"] = 2;
    string2values["3"] = 3;
    string2values["4"] = 4;
    string2values["5"] = 5;
    string2values["6"] = 6;
    string2values["7"] = 7;
    string2values["8"] = 8;
    string2values["9"] = 9;
    string2values["zero"] = 0;
    string2values["one"] = 1;
    string2values["two"] = 2;
    string2values["three"] = 3;
    string2values["four"] = 4;
    string2values["five"] = 5;
    string2values["six"] = 6;
    string2values["seven"] = 7;
    string2values["eight"] = 8;
    string2values["nine"] = 9;

    string values[20] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //JANK

    string line = "";

    int track = 0; //jank

    int last_digit = 0;

    while(in >> noskipws >> curr){
        line += curr;
        // cout << line << endl;
        for(int i = 0; i < 20; i++){
            if(line.find(values[i]) != string::npos){
                //cout << values[i] << endl;
                nums.push_back(string2values[values[i]]);
                // if((track % 2) == 0){
                //     sum += string2values[values[i]] * 10;
                // }
                // if((track % 2) == 1){
                //     sum += string2values[values[i]];
                // }
                // last_digit = string2values[values[i]];
                // track++;
                line = "";
            }
        }
        if(curr == '\n'){
            cout << (nums[0] * 10) + nums[nums.size() -1] << endl;
            sum += (nums[0] * 10) + nums[nums.size() -1];
            while (!nums.empty()){
                nums.pop_back();
            }
            //cout << sum << endl;
            line = "";
        }
    }
//part 1;
/*
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
*/
    cout << sum << endl;

    return 0;
}