#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<unistd.h>
#include<climits>

using namespace std;

int main(int argc, char** argv){
	string infile = string(argv[1]);
	ifstream myFile(infile);
	string temp;
	long prev = INT_MIN;
	bool result = true;
	int count = 0;
	while(getline(myFile, temp, ',')){
		count++;
		long curr = stol(temp);
		if(curr < prev){
			result = false;
		}
		
		prev = curr;
	}
	
	if(result) cout << "Sorted" << endl;
	else cout << "Not sorted" << endl;
	
	cout << "Number of numbers: " << count << endl;
	return 0;
}
