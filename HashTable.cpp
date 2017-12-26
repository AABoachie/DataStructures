#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
void hashFunction1(vector<string> strings, string * hash);
void hashFunction2(vector<string> strings, string * hash);
int hashFunction2Retrieve(string * hash, string key);
string * createHash(int size);
void displayHash(string * hash, int size);

int main(){
	string * hash = createHash(17);	
	string elements [] = {"14", "28", "42", "30", "4", "5", "6", "12", "30"};
	vector<string>strings(elements, elements + sizeof(elements) / sizeof(char *));
	
	//hashFunction1(strings, hash);
	hashFunction2(strings, hash);
	cout << hashFunction2Retrieve(hash, "30") << endl;
	
	displayHash(hash, 15);
	return 0;
}

void hashFunction1(vector<string> strings, string * hash){
	for(int i = 0; i < strings.size(); i++){
		string str = strings[i];
		int intparse = atoi(str.c_str());
		hash[intparse] = str;
	}
}

void hashFunction2(vector<string> strings, string * hash){
	for(int i = 0; i < strings.size(); i++){
		string str = strings[i];
		int intparse = atoi(str.c_str()) % 17;
		while(hash[intparse] != "-1"){
			intparse++;
			cout << "collision" << endl;
		}
		hash[intparse] = str;
	}
}

int hashFunction2Retrieve(string * hash, string key){
	int intparse = atoi(key.c_str()) % 17;
	while(hash[intparse] != key){
		intparse++;
	}
	return intparse;
}

string * createHash(int size){
	string * hash = new string[size];
	for(int i = 0; i < size; i++){
		hash[i] = "-1";
	}
	return hash;
}

void displayHash(string * hash, int size){
	cout << "\nhashtable: \n";
	for(int i = 0; i < size; i++){
		cout << "|"  <<  i << "\t";
	}	
	for(int i = 0; i < size; i++){
		cout << "|"  << hash[i] << "\t";
	}
	cout << endl;
}
