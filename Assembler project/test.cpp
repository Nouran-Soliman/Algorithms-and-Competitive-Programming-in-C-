#include <bits/stdc++.h>

using namespace std;

#define HEXA(x, dec) right << setfill('0') << setw(x) << hex << uppercase << dec

struct Line{
	int location;
	string label, command, var, object_code;
	Line(int location=0, string label="", string command="", string var="", string object_code="")
		: location(location), label(label), command(command), var(var), object_code(object_code){}
};

unordered_map<string, int> op_code, loc_label, org_loc_label;
vector<Line> inlines, outlines;

void initialize(){
	op_code["add"]  = 0x18;	op_code["and"]  = 0x40;	op_code["comp"] = 0x28; op_code["div"]  = 0x24;	op_code["j"]    = 0x3c;
	op_code["jeq"]  = 0x30; op_code["jgt"]  = 0x34;	op_code["jlt"]  = 0x38;	op_code["jsub"] = 0x48; op_code["lda"]  = 0x00;
	op_code["ldch"] = 0x50;	op_code["ldl"]  = 0x08; op_code["ldx"]  = 0x04;	op_code["mul"]  = 0x20;	op_code["or"]   = 0x44;
	op_code["rd"]   = 0xd8;	op_code["rsub"] = 0x4c;	op_code["sta"]  = 0x0c; op_code["stch"] = 0x54;	op_code["stl"]  = 0x14;
	op_code["stsw"] = 0xe8; op_code["stx"]  = 0x10;	op_code["sub"]  = 0x1c;	op_code["td"]   = 0xe0; op_code["tix"]  = 0x2c;
	op_code["wd"]   = 0xdc; op_code["end"]  = 0;
}

inline void get_var(string &str){
	getline(cin, str);
	str.erase(remove_if( str.begin(), str.end(), [](char c){ return (c =='\r' || c =='\t' || c == '\n');}), str.end());
}

inline string string_tolower(const string &str){
	string ret="";
	for (int i = 0 ; i < (int)str.size() ; i ++){
		if (isalpha(str[i])) ret += tolower(str[i]);
		else ret += str[i];
	}
	return ret;
}

inline string string_toupper(const string &str){
	string ret="";
	for (int i = 0 ; i < (int)str.size() ; i ++){
		if (isalpha(str[i])) ret += toupper(str[i]);
		else ret += str[i];
	}
	return ret;
}

inline int string_tohexa(const string &str){
	int ret;
	istringstream buffer(str);
	buffer >> hex >> ret;
	return ret;
}

inline int string_todec(const string &str){
	int ret;
	istringstream buffer(str);
	buffer >> ret;
	return ret;
}

inline string int_tostring(int a, int b){
	stringstream str;
	str << setfill('0') << setw(2) << hex << uppercase << a << setw(4) << b;
	return str.str();
}

inline string ascii_tohexa(const string &str){
	string hexa;
	for (int i = 0 ; i < (int)str.size() ; i ++){
		ostringstream tmp;
		tmp << hex << uppercase << (int)str[i];
		hexa += tmp.str();
	}
	return hexa;
}

inline int get_nextlocation(const string &str1, const string &str2){
	if (str1 == "start" || str1 == "end") return 0;
	if (str1 == "resb") return string_todec(str2);
	if (str1 == "resw") return 3*string_todec(str2);
	if (str1 == "byte" && str2.substr(0, 2) == "x'") return (str2.size()-2)/2;
	if (str1 == "byte" && str2.substr(0, 2) == "c'") return str2.substr(2, str2.size()-3).size();
	if (str1 == "byte") return 1;
	if (str1 == "word"){
		int count = 1;
		for (int i = 1 ; i < (int)str2.size() ; i ++)
			if (str2[i-1] != ',' && str2[i] == ',') count ++;
		count -= (str2[str2.size()-1] == ',');
		return count*3;
	}
	return 3;
}

inline string get_object_code(const string &str1, const string &str2){
	if (str1 == "byte" && str2.substr(0, 2) == "x'")
		return string_toupper(str2.substr(2, str2.size()-3));
	if (str1 == "byte" && str2.substr(0, 2) == "c'")
		return ascii_tohexa(string_toupper(str2.substr(2, str2.size()-3)));
	if (str1 == "word")
		return int_tostring(0, string_todec(str2));
	if (str1 != "end" && op_code.count(str1) && str2.size() > 2 && str2[str2.size()-2] == ',' && str2[str2.size()-1] == 'x')
		return int_tostring(op_code[str1], loc_label[str2.substr(0, str2.size()-2)] + 0x8000);
	if (str1 != "end" && op_code.count(str1))
		return int_tostring(op_code[str1], loc_label[str2]);
	return "";
}

int main(){
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	initialize();

	string org, org2, org3, str, str2, str3;
	int mem_location;

	loc_label[""] = 0;

	while (cin >> org){
		//if (org == ".") continue;
		if (op_code.count(string_tolower(org))){
			org2 = org, org = str = "";
			get_var(org3);
		}
		else{
			cin >> org2;
			if (string_tolower(org) != "end") get_var(org3);
			else org3 = "";
		}
		str = string_tolower(org), str2 = string_tolower(org2), str3 = string_tolower(org3);
		if (str2 == "start")
			mem_location = string_tohexa(str3);
		else if (str != "")
			org_loc_label[org] = loc_label[str] = mem_location;
		inlines.push_back(Line(mem_location, str, str2, str3, ""));
		outlines.push_back(Line(mem_location, org, org2, org3, ""));
		mem_location += get_nextlocation(str2, str3);
	}
	// PATH 1
	cout << "PATH 1:\n------\n";
	for (int i = 0 ; i < (int)outlines.size() ; i ++)
		cout << HEXA(4, outlines[i].location) << "\t" << left << setfill(' ') << setw(10) << outlines[i].label << setw(10) << outlines[i].command << setw(10) << outlines[i].var << endl;

	// Symbol Table
	cout << "\nSymbol Table:\n-------------\n" << setw(10) << "Symbol" << "Location\n------------------\n";
	for (unordered_map<string, int> :: iterator it = org_loc_label.begin() ; it != org_loc_label.end() ; it ++)
		cout << left << setfill(' ') << setw(10) << it->first << " " << HEXA(4, it->second) << endl;

	// Path 2
	cout << "_____________________________________________________________\n\nPATH 2:\n------\n";
	for (int i = 0 ; i < (int)outlines.size() ; i ++){
		outlines[i].object_code = get_object_code(inlines[i].command, inlines[i].var);
		cout << HEXA(4, outlines[i].location) << "\t" << left << setfill(' ') << setw(10) << outlines[i].label << setw(10) << outlines[i].command << setw(10) << outlines[i].var << " " << outlines[i].object_code << endl;
	}

	// HTE Format
	cout << "\nHTE Format:\n-----------\n";
	cout << "H." << outlines[0].label << "." << HEXA(6, outlines[0].location) << "." << HEXA(6, outlines[outlines.size()-1].location) << endl;
	for (int i = 1 ; i < (int)outlines.size() ; i ++){
		if (outlines[i].object_code == "") continue;
		int e = i+1;
		for (int c = 0 ; c < 10 && e < (int)outlines.size() && outlines[e].object_code != "" ; c ++, e ++);
		if (outlines[e].object_code == "") e--;
		cout << "T." << HEXA(6, outlines[i].location) << "." << HEXA(2, outlines[e+1].location-outlines[i].location);
		for (int j = i ; j <= e ; j ++)
			cout << "." << outlines[j].object_code;
		cout << endl;
		i = e;
	}
	cout << "E." << HEXA(6, outlines[0].location) << endl;

	return 0;
}
