#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string timeConversion(string s) {
    //string stream to fetch each time data 
	stringstream ss(s);
	int num;
	vector<int> time(3);
	int count = 0;
	string am, store;
	while(ss >> num){
		time[count] = num;
		if(ss.peek() == ':'){
			ss.ignore();
		}
		else if (ss >> am){
			store = am;
		}
		count++;
	}

	//check store for AM and PM timing
	if (store == "PM"){
		if (time[0] != 12){
			time[0] = time[0] + 12;
		}
	}
	else{
		if (time[0] == 12){
			time[0] = 0;
		}
	}

	//to put 0 at the hour value if the digit is just 1 number or 0
	string resultTime;
	ostringstream temp;
	temp << time[0];
	
	string part = temp.str();

	int size = part.length();
	if( size == 1 && temp.str() == "0"){
		part = part + "0";

	}
	else if (size == 1 && temp.str() != "0"){
		part = "0" + part;
	}
	
	//delete hour value and AM/PM sign from the input
	resultTime = s.erase(0,2);
	resultTime = s.erase(s.find_last_of("M") -1 ,s.find_last_of("M"));

	//ADD new matric at the beginning
	resultTime =  part+resultTime;


	return resultTime;
}

int main() {
    string s;
	cout<< "12 hour clock time:" << endl;
    cin >> s;
    string result = timeConversion(s);
	cout<< "Military time conversion:" << endl;
    cout << result << endl;
    return 0;
}
