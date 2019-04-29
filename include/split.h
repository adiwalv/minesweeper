#include <vector>
#include <string>
using namespace std; 
const string delimiters = " \n\t~!@#%^&*()_+={}|\\{};:,.<>,?\"";

vector<string> split(const string & s, const string& delim = delimiters){
	vector<string> v;
	string::size_type pos1, pos2=0;
	string word;
	pos1=s.find_first_not_of(delim,pos2); 
	while(pos1!=string::npos){ 
		if((pos2=s.find_first_of(delim,pos1))==string::npos){ 
			word=s.substr(pos1);
			pos1=pos2;
		}
		else{
			word=s.substr(pos1,pos2-pos1);
			pos1=s.find_first_not_of(delim,pos2); 
		}
		v.push_back(word);
	}
	return v;
}