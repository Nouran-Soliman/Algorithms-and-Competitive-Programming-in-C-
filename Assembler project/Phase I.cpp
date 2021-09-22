#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

void initialize_instructions(unordered_map<string, int> &dictionary, unordered_map<string, int> &data_types){
	dictionary["FIX"]=1;
	dictionary["FLOAT"]=1;
	dictionary["HIO"]=1;
	dictionary["NORM"]=1;
	dictionary["SIO"]=1;
	dictionary["TIO"]=1;
	dictionary["ADDR"]=2;
	dictionary["CLEAR"]=2;
	dictionary["COMPR"]=2;
	dictionary["DIVR"]=2;
	dictionary["MULR"]=2;
	dictionary["SHIFTL"]=2;
	dictionary["SHIFTR"]=2;
	dictionary["RMO"]=2;
	dictionary["SUBR"]=2;
	dictionary["SVC"]=2;
	dictionary["TIXR"]=2;
	dictionary["ADD"]=3;
	dictionary["ADDF"]=3;
	dictionary["AND"]=3;
	dictionary["COMP"]=3;
	dictionary["COMPF"]=3;
	dictionary["DIV"]=3;
	dictionary["DIVF"]=3;
	dictionary["J"]=3;
	dictionary["JEQ"]=3;
	dictionary["JGT"]=3;
	dictionary["JLT"]=3;
	dictionary["JSUB"]=3;
	dictionary["LDA"]=3;
	dictionary["LDB"]=3;
	dictionary["LDT"]=3;
	dictionary["LDCH"]=3;
	dictionary["LDL"]=3;
	dictionary["LDX"]=3;
	dictionary["MUL"]=3;
	dictionary["OR"]=3;
	dictionary["RD"]=3;
	dictionary["WD"]=3;
	dictionary["RSUB"]=3;
	dictionary["STA"]=3;
	dictionary["STCH"]=3;
	dictionary["STL"]=3;
	dictionary["STSW"]=3;
	dictionary["STX"]=3;
	dictionary["SUB"]=3;
	dictionary["SSK"]=3;
	dictionary["STI"]=3;
	dictionary["STB"]=3;
	dictionary["STF"]=3;
	dictionary["STS"]=3;
	dictionary["STT"]=3;
	dictionary["SUBF"]=3;
	dictionary["TD"]=3;
	dictionary["TIX"]=3;
	dictionary["MULF"]=3;

	dictionary["+ADD"]= 4;
	dictionary["+ADDF"]= 4;
	dictionary["+AND"]= 4;
	dictionary["+COMP"]= 4;
	dictionary["+COMPF"]= 4;
	dictionary["+DIV"]= 4;
	dictionary["+DIVF"]= 4;
	dictionary["+J"]= 4;
	dictionary["+JEQ"]= 4;
	dictionary["+JGT"]= 4;
	dictionary["+JLT"]= 4;
	dictionary["+JSUB"]= 4;
	dictionary["+LDA"]= 4;
	dictionary["+LDCH"]= 4;
	dictionary["+LDL"]= 4;
	dictionary["+LDX"]= 4;
	dictionary["+LDB"]= 4;
	dictionary["+LDT"] = 4;
	dictionary["+MUL"]= 4;
	dictionary["+OR"]= 4;
	dictionary["+RD"]= 4;
	dictionary["+WD"]= 4;
	dictionary["+RSUB"]= 4;
	dictionary["+STA"]= 4;
	dictionary["+STCH"]= 4;
	dictionary["+STL"]= 4;
	dictionary["+STSW"]= 4;
	dictionary["+STX"]= 4;
	dictionary["+SUB"]= 4;
	dictionary["+SSK"]= 4;
	dictionary["+STI"]= 4;
	dictionary["+STB"]= 4;
	dictionary["+STF"]= 4;
	dictionary["+STS"]= 4;
	dictionary["+STT"]= 4;
	dictionary["+SUBF"]= 4;
	dictionary["+TD"]= 4;
	dictionary["+TIX"]= 4;
	dictionary["+MULF"]= 4;

	data_types["RESW"] = 3;
	data_types["RESB"] = 1;
	data_types["WORD"] = 3;
	data_types["BYTE"] = 1;
}

void divide_line(const string &line, string *parts){
	int line_size = line.length(), ind = 0;

	for(int i = 0; i < line_size; i++){
		if(line[i] == ' '){
			if(ind < 2){
				ind++;
			}
			continue;
		}
		parts[ind] += line[i];
	}
}

int get_size(string sz){
	if(sz[0] == 'X') return (sz.length() - 3) / 2;
	else if(sz[0] == 'C') return (sz.length() - 3);
	else if(sz.find(',') != std::string::npos) return (sz.length()/2) + 1;
	return atoi(sz.c_str());
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);	//input file
		freopen("in.out","w",stdout);	//output file
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> dictionary, data_types;
	initialize_instructions(dictionary, data_types);

	string line, initial[3];
	int address;
	vector<pair<int, string> > pass1;
	vector<pair<string, int> > symbol_table;
	getline(cin, line);
	divide_line(line, initial);
	address = strtoul(initial[2].c_str(), NULL, 16);

	while(line != ""){
		string parts[3];
		divide_line(line, parts);

		//cout << hex << address << "	" << line << endl;
		pass1.push_back(make_pair(address, line));
		if(dictionary.find(parts[0]) != dictionary.end()){ //instruction
			address += dictionary[parts[0]];
		}
		else if(data_types.find(parts[1]) != data_types.end()){ //variable
			symbol_table.push_back(make_pair(parts[0], address));
			int sz = get_size(parts[2]);
			address += (sz * data_types[parts[1]]);
		}
		else if(dictionary.find(parts[1]) != dictionary.end()){ //label
			symbol_table.push_back(make_pair(parts[0], address));
			address += dictionary[parts[1]];
		}

		getline(cin, line);
	}

	int pass1_size = pass1.size();
	for(int i = 0; i < pass1_size - 1; i++){
		if(pass1[i].first == pass1[i+1].first){
			cout << "	" << pass1[i].second << endl;
		}
		else cout << hex << pass1[i].first << "	" << pass1[i].second << endl;
	}
	cout << hex << pass1.back().first << "	" << pass1.back().second << endl;

	cout << endl << "Symbol Table" << endl << endl;

	int vec_size = symbol_table.size();
	for(int i = 0; i < vec_size; i++){
		cout << symbol_table[i].first << "	" << symbol_table[i].second << endl;
	}

	return 0;
}
