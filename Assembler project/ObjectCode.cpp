#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

struct compLine{
	pair<int, int> address;
	string label, instruction, operand, object_code;
};

struct literalElement{
	string name, value;
	int length;
	pair<int, int> address, poolAdd;
};

struct symbolElement{
	string name, value, type;
	pair<int, int> address;
};

struct Block{
	string name;
	int number, address ,length;
};

void initialize_instructions(unordered_map<string, pair<int, string> > &dictionary, unordered_map<string, int> &data_types){
	dictionary["FIX"]= make_pair(1,"C4");
	dictionary["FLOAT"]= make_pair(1,"C0");
	dictionary["HIO"]= make_pair(1,"F4");
	dictionary["NORM"]= make_pair(1,"C8");
	dictionary["SIO"]= make_pair(1,"F0");
	dictionary["TIO"]= make_pair(1,"F8");

	dictionary["ADDR"]= make_pair(2,"90");
	dictionary["CLEAR"]= make_pair(2,"B4");
	dictionary["COMPR"]= make_pair(2,"A0");
	dictionary["DIVR"]= make_pair(2,"9C");
	dictionary["MULR"]= make_pair(2,"98");
	dictionary["SHIFTL"]= make_pair(2,"A4");
	dictionary["SHIFTR"]= make_pair(2,"A8");
	dictionary["RMO"]= make_pair(2,"AC");
	dictionary["SUBR"]= make_pair(2,"94");
	dictionary["SVC"]= make_pair(2,"B0");
	dictionary["TIXR"]= make_pair(2,"B8");

	dictionary["ADD"]= make_pair(3,"18");
	dictionary["ADDF"]= make_pair(3,"58");
	dictionary["AND"]= make_pair(3,"40");
	dictionary["COMP"]= make_pair(3,"28");
	dictionary["COMPF"]= make_pair(3,"88");
	dictionary["DIV"]= make_pair(3,"24");
	dictionary["DIVF"]= make_pair(3,"64");
	dictionary["J"]= make_pair(3,"3C");
	dictionary["JEQ"]= make_pair(3,"30");
	dictionary["JGT"]= make_pair(3,"34");
	dictionary["JLT"]= make_pair(3,"38");
	dictionary["JSUB"]= make_pair(3,"48");
	dictionary["LDA"]= make_pair(3,"00");
	dictionary["LDB"]= make_pair(3,"68");
	dictionary["LDT"]= make_pair(3,"74");
	dictionary["LDCH"]= make_pair(3,"50");
	dictionary["LDL"]= make_pair(3,"08");
	dictionary["LDX"]= make_pair(3,"04");
	dictionary["MUL"]= make_pair(3,"20");
	dictionary["OR"]= make_pair(3,"44");
	dictionary["RD"]= make_pair(3,"D8");
	dictionary["WD"]= make_pair(3,"DC");
	dictionary["RSUB"]= make_pair(3,"4C");
	dictionary["STA"]= make_pair(3,"0C");
	dictionary["STCH"]= make_pair(3,"54");
	dictionary["STL"]= make_pair(3,"14");
	dictionary["STSW"]= make_pair(3,"E8");
	dictionary["STX"]= make_pair(3,"10");
	dictionary["SUB"]= make_pair(3,"1C");
	dictionary["SSK"]= make_pair(3,"EC");
	dictionary["STI"]= make_pair(3,"D4");
	dictionary["STB"]= make_pair(3,"78");
	dictionary["STF"]= make_pair(3,"80");
	dictionary["STS"]= make_pair(3,"7C");
	dictionary["STT"]= make_pair(3,"84");
	dictionary["SUBF"]= make_pair(3,"5C");
	dictionary["TD"]= make_pair(3,"E0");
	dictionary["TIX"]= make_pair(3,"2C");
	dictionary["MULF"]= make_pair(3,"60");

	dictionary["+ADD"]= make_pair(4,"18");
	dictionary["+ADDF"]= make_pair(4,"58");
	dictionary["+AND"]= make_pair(4,"40");
	dictionary["+COMP"]= make_pair(4,"28");
	dictionary["+COMPF"]= make_pair(4,"88");
	dictionary["+DIV"]= make_pair(4,"24");
	dictionary["+DIVF"]= make_pair(4,"64");
	dictionary["+J"]= make_pair(4,"3C");
	dictionary["+JEQ"]= make_pair(4,"30");
	dictionary["+JGT"]= make_pair(4,"34");
	dictionary["+JLT"]= make_pair(4,"38");
	dictionary["+JSUB"]= make_pair(4,"48");
	dictionary["+LDA"]= make_pair(4,"00");
	dictionary["+LDCH"]= make_pair(4,"50");
	dictionary["+LDL"]= make_pair(4,"08");
	dictionary["+LDX"]= make_pair(4,"04");
	dictionary["+LDB"]= make_pair(4,"68");
	dictionary["+LDT"] = make_pair(4,"74");
	dictionary["+MUL"]= make_pair(4,"20");
	dictionary["+OR"]= make_pair(4,"44");
	dictionary["+RD"]= make_pair(4,"D8");
	dictionary["+WD"]= make_pair(4,"DC");
	dictionary["+RSUB"]= make_pair(4,"4C");
	dictionary["+STA"]= make_pair(4,"0C");
	dictionary["+STCH"]= make_pair(4,"54");
	dictionary["+STL"]= make_pair(4,"14");
	dictionary["+STSW"]= make_pair(4,"E8");
	dictionary["+STX"]= make_pair(4,"10");
	dictionary["+SUB"]= make_pair(4,"1C");
	dictionary["+SSK"]= make_pair(4,"EC");
	dictionary["+STI"]= make_pair(4,"D4");
	dictionary["+STB"]= make_pair(4,"78");
	dictionary["+STF"]= make_pair(4,"80");
	dictionary["+STS"]= make_pair(4,"7C");
	dictionary["+STT"]= make_pair(4,"84");
	dictionary["+SUBF"]= make_pair(4,"5C");
	dictionary["+TD"]= make_pair(4,"E0");
	dictionary["+TIX"]= make_pair(4,"2C");
	dictionary["+MULF"]= make_pair(4,"60");


	data_types["RESW"] = 3;
	data_types["RESB"] = 1;
	data_types["WORD"] = 3;
	data_types["BYTE"] = 1;
	data_types["EQU"] = 0;
}

void initialize_reg(unordered_map<string, int> &reg){
	string hexA = "0000";
	string hexX = "0000";
	string hexL = "0000";
	string hexB = "0000";
	string hexS = "0000";
	string hexT = "0000";

	reg["A"] = strtol(hexA.c_str(), nullptr, 16);
	reg["X"] = strtol(hexX.c_str(), nullptr, 16);
	reg["L"] = strtol(hexL.c_str(), nullptr, 16);
	reg["B"] = strtol(hexB.c_str(), nullptr, 16);
	reg["S"] = strtol(hexS.c_str(), nullptr, 16);
	reg["T"] = strtol(hexT.c_str(), nullptr, 16);
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
	if(sz[0] == '='){
		if(sz[1] == 'X') return (sz.length() - 4) / 2;
		else if(sz[1] == 'C') return (sz.length() - 4);
	}
	else if(sz[0] == 'X') return (sz.length() - 3) / 2;
	else if(sz[0] == 'C') return (sz.length() - 3);
	else if(sz.find(',') != std::string::npos) return (sz.length()/2) + 1;
	return atoi(sz.c_str());
}

//

void set_current(compLine &current, string *parts, char type){
	if(type == 'i'){
		current.instruction = parts[0]; //save inst
		current.operand = parts[1]; //save operand
		current.label = ""; //reset label
	}
	else if(type == 'd'){
		current.label = parts[0]; //set label
		current.instruction = ""; //reset inst
		current.operand = parts[1]; //save operand
	}
	else{
		current.label = parts[0]; //set label
		current.instruction = parts[1]; //save inst
		current.operand = parts[2]; //save operand
		//cout << "%%%%%%%%%%%%%%%%%%%%%%%" << "label: " << current.label << "inst: " << current.instruction << "oper: " << current.operand << endl;
	}
}

bool literal(string &operand){
	return (operand.find('=') != std::string::npos);
}

string get_lit_val(const string &literal){
	string val = "";
	int litLen = literal.length();
	if(literal[1] == 'X'){
		for(int i = 3; i < litLen-1; i++){
			val += literal[i];
		}
	}
	else if (literal[1] == 'C'){
		stringstream ss;
		for(int i = 3; i < litLen-1; i++){
			ss << hex << (int)literal[i];
		}
		val = ss.str();
	}
	return val;
}

literalElement initialize_lit(const string &literal){
	literalElement lit;
	lit.name = literal;
    lit.length = get_size(literal);
	lit.value = get_lit_val(literal);
	return lit;
}

bool lit_not_exist(string &lit, const vector<literalElement> &litTable){
	string val = get_lit_val(lit);
	int len = litTable.size();
	for(int i = 0; i < len; i++){
		if(litTable[i].value == val)
			return false;
	}
	return true;
}

compLine create_litTemp(literalElement &literal){
	compLine ret;
	ret.address = literal.address;
	ret.instruction = "*";
	ret.operand = literal.name;
	ret.label = "";
	return ret;
}

void push_literals(vector<literalElement> &litTable, vector<compLine> &pass1, int &last_lit_index, pair<int, int> pooladd, pair<int, int> &address){
	int lit_table_sz = litTable.size();
	int prev_len = 0;

	for(int j = last_lit_index; j < lit_table_sz; j++){
		address.first += prev_len;
		litTable[j].poolAdd = pooladd;
		litTable[j].address =  address;
		prev_len = litTable[j].length;
		compLine litTemp = create_litTemp(litTable[j]);
		pass1.push_back(litTemp);
	}
	address.first += prev_len;
	last_lit_index = lit_table_sz;
}

string get_lit_val_by_name(string name, vector<literalElement> &litTable){
	int litTable_sz = litTable.size();
	for(int i = 0; i < litTable_sz; i++){
		if(litTable[i].name == name){
			return (litTable[i].value);
		}
	}
	return "";
}

bool expression(string exp){
	return (exp.find('-') != std::string::npos) || (exp.find('+') != std::string::npos);
}

pair<bool, symbolElement> found_symbol_by_name(string name, vector<symbolElement> &symbol_table){
	pair<bool, symbolElement> elem;
	elem.first = false;
	int vec_size = symbol_table.size();
	for(int i = 0; i < vec_size; i++){
		if(symbol_table[i].name == name){
			elem.first = true;
			elem.second = symbol_table[i];
		}
	}
	return elem;
}

int count_occur(char s, string str){
	int c = 0;
	int str_len = str.length();
	for(int i = 0; i < str_len; i++){
		if(str[i] == s) c++;
	}
	return c;
}

pair<int, int> get_symbol_address_by_name(string name, vector<symbolElement> &symbol_table){
	int symb_sz = symbol_table.size();
	for(int i = 0; i < symb_sz; i++){
		if(symbol_table[i].name == name){
			return symbol_table[i].address;
		}
	}
	return make_pair(-1, -1);
}

int calc_num(char oper, int add){
	if(oper == '-')
		return add * -1;
	return add;
}

int stringToInt(string var){
	int res = 0;
	int sz = var.length();
	for(int i = 0; i < sz; i++){
		res *= 10;
		res += (var[i]-'0');
	}
	return res;
}

bool numeric(string var){
	int sz = var.length();
	for(int i = 0; i < sz; i++){
		if(!(var[i] >= '0' && var[i] <= '9'))
			return false;
	}
	return true;
}

pair< pair<int, int>, string> evaluate_expression(string operand, vector<symbolElement> &symbol_table){
	pair< pair<int, int>, string> AT;
	int plus = 1 + count_occur('+', operand);
	int minus = count_occur('-', operand);
	if(plus == minus) {
		AT.second = "A";
		AT.first.second = -1;
	}
	else AT.second = "R";

	int result = 0;
	int op_len = operand.length();
	char operation = '+';
	string var;
	for(int i = 0; i < op_len; i++){
		if(operand[i] == '+' || operand[i] == '-'){
			int add;
			if(numeric(var)) add = stringToInt(var);
			else add = get_symbol_address_by_name(var, symbol_table).first;

			result += calc_num(operation, add) ;
			operation = operand[i];
			var = "";
		}
		else var += operand[i];
	}
	int add;
	if(numeric(var)) add = stringToInt(var);
	else add = get_symbol_address_by_name(var, symbol_table).first;
	result += calc_num(operation, add) ;

	AT.first.first = result;
	return AT;
}

pair< pair<int, int>, string> get_EQU_val(string exp,
							  pair<int, int> address,
							  unordered_map<string, int> &reg,
							  vector<symbolElement> &symbol_table,
							  vector<literalElement> &litTable){
	pair<bool, symbolElement> elem = found_symbol_by_name(exp, symbol_table);
	pair< pair<int, int>, string> AT = make_pair(address, "R");
	if(elem.first){ //symbol
		AT.first = elem.second.address;
		AT.second = elem.second.type;
	}
	else if(exp == "*"){
		AT.second = "R"; //current place
	}
	else if(reg.find(exp) != reg.end()){
		AT.first.first = reg[exp];
		AT.first.second = address.second;
	    AT.second = "R";
	    //register val
	}
	else if(literal(exp)) { //literal
		string val = get_lit_val_by_name(exp, litTable);
		AT.first.first = strtol(val.c_str(), nullptr, 16);
		AT.first.second = address.second;
		AT.second = "R";
	}
	else if(expression(exp)){ //expression
		AT = evaluate_expression(exp, symbol_table);
	}
	else{ //number
		AT.first.first = atoi(exp.c_str());
		AT.first.second = address.second;
		AT.second = "A";
	}
	return AT;
}

symbolElement create_symbolElement(string name, pair<int, int> address, string type){
	symbolElement temp;
	temp.name = name;
	temp.address = address;
	temp.type = type;
	return temp;
}

void print_pass1(vector<compLine> &pass1){
	int pass1_size = pass1.size();
		for(int i = 0; i < pass1_size - 1; i++){
			if(pass1[i].address == pass1[i+1].address && pass1[i].label != "USE" ){
				cout << "		" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand << "	" << pass1[i].object_code << endl;
			}
			else {
				if (pass1[i].address.second == -1) cout << hex << pass1[i].address.first << "		" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand  << "	" << pass1[i].object_code << endl;
				else cout << hex << pass1[i].address.first << "	" << pass1[i].address.second << "	" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand << "	" << pass1[i].object_code << endl;
			}
		}
		cout << hex << pass1.back().address.first << "	" << pass1.back().address.second << "	" << pass1.back().label << "	"<< pass1.back().instruction << "	" << pass1.back().operand  << "	" << pass1.back().object_code << endl;
}

void print_symbolTable(vector<symbolElement> &symbol_table){
	cout << endl << "Symbol Table" << endl << endl;
		int vec_size = symbol_table.size();
		for(int i = 0; i < vec_size; i++){
			cout << symbol_table[i].name << "	" << symbol_table[i].address.first << "	"<< symbol_table[i].address.second << "	" << symbol_table[i].type << endl;
		}
}

Block initialize_block(string name, pair<int, int> address){
	Block temp;
	temp.name = name;
	temp.number = address.second;
	temp.address = address.first;
	return temp;
}

bool found_block_by_name(string name, vector<Block> &blocks){
	int sz = blocks.size();
	for(int i = 0;i < sz; i++){
		if(blocks[i].name == name){
			return true;
		}
	}
	return false;
}

void print_blocks(vector<Block> &blocks){
	cout << endl << "BLOCKS" << endl;
	int sz = blocks.size();
	for(int i = 0; i < sz; i++){
		cout << blocks[i].name << "	" << blocks[i].number << "	" << blocks[i].address << "	" << blocks[i].length <<endl;
	}
}

void set_block_start(map<string, pair<int, int> > &last_block_data, vector<Block> &blocks){
	int sz = blocks.size();
	for(int i = 0; i < sz; i++){
		blocks[i].length = last_block_data[blocks[i].name].first;
	}
	for(int i = 1; i < sz; i++){
		blocks[i].address = blocks[i-1].address + blocks[i-1].length;
	}
}

void fill_extdef(string operands, vector<pair<string, int> > &EXTDEF){
	int sz = operands.length();
	string val;
	for(int i = 0; i < sz; i++){
		if(operands[i] == ','){
			EXTDEF.push_back( make_pair(val, 0) );
			val = "";
		}
		else val += operands[i];
	}
	EXTDEF.push_back(make_pair(val, 0) );
}

void fill_extref(string operands, vector<string> &EXTREF){
	int sz = operands.length();
	string val;
	for(int i = 0; i < sz; i++){
		if(operands[i] == ','){
			EXTREF.push_back( val );
			val = "";
		}
		else val += operands[i];
	}
	EXTREF.push_back(val);
}

void print_literals(vector<literalElement> &litTable){
	cout << endl << "LITERALS" << endl;
	int sz = litTable.size();
	for(int i = 0; i < sz; i++){
		cout << litTable[i].name << "	" << litTable[i].address.first << endl;
	}
}

void print_EXTDEF(vector<pair<string, int> > &EXTDEF){
	cout << endl << "EXTDEF" << endl;
	int sz = EXTDEF.size();
	for(int i = 0; i < sz; i++){
		cout << EXTDEF[i].first << "	" << EXTDEF[i].second << endl;
	}
}

void print_EXTREF(vector<string> &EXTREF){
	cout << endl << "EXTREF" << endl;
	int sz = EXTREF.size();
	for(int i = 0; i < sz; i++){
		cout << EXTREF[i] << endl;
	}
}

void set_EXDEF_add(vector<pair<string, int> > &EXTDEF, vector<symbolElement> &symbol_table){
	int sz = EXTDEF.size();
	for(int i = 0; i < sz; i++){
		EXTDEF[i].second = get_symbol_address_by_name(EXTDEF[i].first, symbol_table).first;
	}
}

void complete_pass1(string infilename, string outfilename,
					unordered_map<string, pair<int, string> > &dictionary,
					unordered_map<string, int> &data_types,
					unordered_map<string, int> &reg,
					vector<compLine> &pass1,
					vector<literalElement> &litTable,
					vector<symbolElement> &symbol_table,
					vector<Block> &blocks,
					vector<string> &EXTREF,
					vector<pair<string, int> > &EXTDEF){

		ifstream infile(infilename.c_str());
		//freopen("in.out","w",stdout);
		//freopen(infilename.c_str(), "r", stdin);

		string line, initial[3];
		pair<int, int> address;
		int last_lit_index = 0;
		bool LTORG = false;
		map<string, pair<int, int> > last_block_data;
		string current_block = "";

		//getline(cin, line);
		getline(infile, line);
		divide_line(line, initial);
		address.first = strtoul(initial[2].c_str(), NULL, 16);
		address.second = 0;
		blocks.push_back(initialize_block("", address));

		while(line != ""){	//PASS1
			string parts[3];
			divide_line(line, parts);

			compLine current;
			current.address = address; //save address
			last_block_data[current_block] = address;
			LTORG = false;
			//cout << hex << address << "	" << line << endl;
			//pass1.push_back(make_pair(address, line));

			if(dictionary.find(parts[0]) != dictionary.end()){ //instruction
				pair<int, string> instData = dictionary[parts[0]];
				address.first += instData.first;
				set_current(current, parts, 'i');
				if( literal(parts[1]) && lit_not_exist(parts[1], litTable) ){
					literalElement lit = initialize_lit(parts[1]);
					litTable.push_back(lit);
				}
			}
			else if(data_types.find(parts[1]) != data_types.end()){ //variable
				int sz = 0;
				pair< pair<int, int> , string> AT = make_pair(address, "R"); //address/type
				if(parts[1] == "EQU"){
					AT = get_EQU_val(parts[2], address, reg, symbol_table, litTable);
					current.address = AT.first;
				}
				else if(expression(parts[2])){
					AT = evaluate_expression(parts[2], symbol_table);
				}
				symbolElement temp = create_symbolElement(parts[0], current.address, AT.second);
				symbol_table.push_back(temp);
				sz = get_size(parts[2]);
				address.first += (sz * data_types[parts[1]]);
				set_current(current, parts, 'v');
			}
			else if(dictionary.find(parts[1]) != dictionary.end()){ //label
				symbolElement temp = create_symbolElement(parts[0], current.address, "R");
				symbol_table.push_back(temp);
				pair<int, string> instData = dictionary[parts[1]];
				address.first += instData.first;
				set_current(current, parts, 'l');
				if(literal(parts[2]) && lit_not_exist(parts[2], litTable) ){
					literalElement lit = initialize_lit(parts[2]);
					litTable.push_back(lit);
				}
			}
			else { //directive
				set_current(current, parts, 'd');
				if(current.label == "LTORG"){
					pass1.push_back(current);
					push_literals(litTable, pass1, last_lit_index, current.address, address);
					LTORG = true;
				}
				else if(current.label == "ORG"){
					pair<bool, symbolElement> found = found_symbol_by_name(current.operand, symbol_table);
					if(found.first){
						address = found.second.address;
					}
					else if(expression(current.operand)){
						address = evaluate_expression(current.operand, symbol_table).first;
					}
					else if(numeric(current.operand)){
						address.first = stringToInt(current.operand);
					}
				}
				else if(current.label == "USE"){
					if(!found_block_by_name(current.operand, blocks)){
						pair<int, int> tempAdd = make_pair( blocks.back().address, blocks.back().number+1);
						Block temp = initialize_block(current.operand, tempAdd);
						blocks.push_back(temp);
						last_block_data[current.operand] = tempAdd;
					}

					address = last_block_data[current.operand];
					current_block = current.operand;
					current.address = address;
				}
				else if(current.label == "EXTDEF"){
					fill_extdef(current.operand, EXTDEF);
				}
				else if(current.label == "EXTREF"){
					fill_extref(current.operand, EXTREF);
				}
			}
			if (!LTORG) pass1.push_back(current);
			//getline(cin, line);
			getline(infile, line);
		}

		push_literals(litTable, pass1, last_lit_index, address, address);
		set_block_start(last_block_data, blocks);
		set_EXDEF_add(EXTDEF, symbol_table);

		print_pass1(pass1);
		print_symbolTable(symbol_table);
		print_blocks(blocks);
		print_literals(litTable);
		print_EXTDEF(EXTDEF);
		print_EXTREF(EXTREF);
		cout << endl;
}

string intToString(int num){
    stringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

char binToHex(string flags){
    if (flags == "0000") return '0';
    else if (flags == "0001") return '1';
    else if (flags == "0010") return '2';
    else if (flags == "0011") return '3';
    else if (flags == "0100") return '4';
    else if (flags == "0101") return '5';
    else if (flags == "0110") return '6';
    else if (flags == "0111") return '7';
    else if (flags == "1000") return '8';
    else if (flags == "1001") return '9';
    else if (flags == "1010") return 'A';
    else if (flags == "1011") return 'B';
    else if (flags == "1100") return 'C';
    else if (flags == "1101") return 'D';
    else if (flags == "1110") return 'E';
    else if (flags == "1111") return 'F';
}

bool checkLabel(string operand){
    for(int i=0;i<operand.size();i++)
    {
        if(operand[i]=='-' || operand[i]=='+' || operand[i]=='*' || operand[i]=='/')
            return false;
        else continue;
    }
    return true;
}

char getRegisterNum(char registr){
    switch(registr){
        case 'A': return '0'; break;
        case 'X': return '1'; break;
        case 'L': return '2'; break;
        case 'B': return '3'; break;
        case 'S': return '4'; break;
        case 'T': return '5'; break;
    }
}

template< typename T >
string intToHex(T i,int format){
  string s="";
  stringstream stream;
  stream << hex << uppercase << i;
  string hexa= stream.str();
  if(format == 3){
    if(hexa.size()<3){
        for(int i=hexa.size();i<3;i++)
            s = s+ '0';}
    else if(hexa.size() >= 3) {
        for (int i = hexa.size()-3; i < hexa.size(); i ++)
            s += hexa[i];
        hexa = "";
    }
    hexa = s + hexa;
  }
  else if (format == 4){
        if(hexa.size()<5){
        for(int i=hexa.size();i<5;i++)
            s = s+ '0';}
    hexa = s + hexa;
  }
  return hexa;
}

int BLKStartAdd(vector<Block> &blocks, int BLKNum){
    for(int i=0 ; i< blocks.size();i++){
        if(blocks[i].number == BLKNum)
            return blocks[i].address;
    }
    return 0;
}

int findOperandIndexSYM(vector<symbolElement> &symbol_table,string operaND){
    for(int i=0;i<symbol_table.size();i++){
        if(symbol_table[i].name == operaND)
            return i;
    }
    return symbol_table.size();
}

string bPFlagBitsBLKSYM(vector<symbolElement> &symbol_table,string operand, int PC ,int &disp , vector<Block> &blocks){
    int TA=0;
    int addIndex = findOperandIndexSYM(symbol_table,operand);
    if(addIndex!=symbol_table.size()) {
            TA=symbol_table[addIndex].address.first + BLKStartAdd(blocks,symbol_table[addIndex].address.second);
        cout << "$$$ HELOOOOOOOOOOOOOOOO" << endl;
    }
    else if(numeric(operand)) return "00";
    disp=TA-PC;
    cout << "#####  " << TA << " " << PC << endl;
    if(disp>=-2048 && disp <= 2047) return "01";
}

int findOperandIndexLIT(vector<literalElement> &litTable,string operaND){
    for(int i=0;i<litTable.size();i++){
        if(litTable[i].name == operaND)
            return i;
    }
    return litTable.size();
}

string bPFlagBitsBLKLIT(vector<literalElement> &litTable,string operand, int PC ,int &disp , vector<Block> &blocks){
    int TA=0;
    int addIndex = findOperandIndexLIT(litTable,operand) ;
    if(operand[0]=='=')
        if(addIndex!=litTable.size())
                TA=litTable[addIndex].address.first + BLKStartAdd(blocks,litTable[addIndex].address.second);
    else return "00";
    disp=TA-PC;
    if(disp>=-2048 && disp <= 2047) return "01";
}

string getOperandIfIndexed(string operand){
    int c=0;
    for(int i=0;i<operand.size();i++)
    {
        if(operand[i]==',')
             c=i;
    }
    return operand.substr(0,c);
}

string getValuesByte (string operand){
    string result="";
    if(operand[0]=='X'){
       result = operand.substr (2,2);
    }
    else if(operand[0]=='C'){
            int x=0;
            for(int i=2;i<operand.size()-1;i++){
                x=operand[i];
                result = result + intToHex(x,0);
            }
    }
    return result;
}

string checkSix(string var,char LabelOrNum){
    if(var.size()<6)
        if(LabelOrNum =='L')
            for(int i=var.size();i<6;i++)
                var = var + " ";
        else if(LabelOrNum =='N')
            for(int i=0;i < (8 - var.size());i++)
                var = "0" + var;
    return var;
}

string getValuesWord(string operand){
    /*if(!checkLabel(operand))
        return intToHex(evaluateExpression(operand),0); //tt3adel*/
    return checkSix(intToHex(atoi(operand.c_str()),0),'N');
}



bool foundinExref(vector<string> &EXTREF,string operand){
    for(int i=0;i<EXTREF.size();i++)
        if(operand.find(EXTREF[i]))
            return true;
    return false;
}

void ObjectCode(vector<compLine> &pass1,
					vector<literalElement> &littable,
					vector<symbolElement> &symbol_table,
					vector<Block> &blocks,
					unordered_map<string, pair<int, string> > &dictionary,
					unordered_map<string, int> &data_types,
					vector<string> &EXTREF,
					vector<pair<string, int> > &EXTDEF){

    for(int i=0;i<pass1.size();i++){
        int address=pass1[i].address.first + BLKStartAdd(blocks,pass1[i].address.second);
        string instruction = pass1[i].instruction; //instruction or data_type or directive
        string objectCode;
        string operand=pass1[i].operand;
        int PC = 0 ;
        if (i+1 < pass1.size()){
            if(pass1[i+1].label == "USE")
                 PC = pass1[i].address.first + BLKStartAdd(blocks,pass1[i].address.second) + dictionary [instruction].first ;
            else PC = pass1[i+1].address.first + BLKStartAdd(blocks,pass1[i].address.second);
        }
        //int Base= value reg;
        cerr << "**********************      " << instruction << " " << operand << endl;
        if(dictionary.find(instruction) != dictionary.end()){ // el instruction mawgodaa
            int format=dictionary[instruction].first;
            string opCode=dictionary[instruction].second;
            if(format==1)
                objectCode=opCode;
            else if(format==2){
                objectCode=opCode;
                if(operand.find(',') != std::string::npos)
                    objectCode= objectCode + getRegisterNum(operand[0]) + getRegisterNum(operand[2]);
                else
                    objectCode= objectCode + getRegisterNum(operand[0]) + '0';
            }
            else if(format == 3){
                int disp=0;
                string flags="",bpBits="";
                objectCode=opCode[0];
                char tmpo[] = {opCode[1], 0};
                int opSecDig =strtol(tmpo, nullptr, 16); // 3shan el n i  from string to int
                if(operand[0]=='@'){
                    opSecDig=opSecDig|2;
                    objectCode= objectCode + intToHex(opSecDig,0);
                    operand = operand.substr(1); //mn 3'ir @
                    bpBits = bPFlagBitsBLKSYM(symbol_table,operand,PC,disp,blocks);
                    flags = flags + '0' + bpBits + '0';
                    objectCode = objectCode+ binToHex(flags) + intToHex(disp,format);
                }
                else if(operand[0]=='#'){
                    opSecDig=opSecDig|1;
                    objectCode=objectCode+ intToHex(opSecDig,0);
                    operand = operand.substr(1); //mn 3'ir #
                    bpBits = bPFlagBitsBLKSYM(symbol_table,operand,PC,disp,blocks);
                    flags = flags + '0' + bpBits + '0';
                    if(bpBits=="00"){ int opValue =strtol(operand.c_str(), NULL, 16); //lw immediate brkm
                        objectCode=objectCode+ binToHex(flags) + intToHex(opValue,format);}
                    else objectCode=objectCode+ binToHex(flags) + intToHex(disp,format);//lw immediate w label
                }
                else if(checkLabel(operand) || operand[0]=='='){
                    opSecDig=opSecDig|3; // n i 11
                    objectCode=objectCode+ intToHex(opSecDig,0);
                    /*if (instruction == "JEQ"){
                        cout << "----------------  " << opSecDig << " " << tmpo << " " << objectCode << endl;
                    }*/
                    if(operand.find(',') != std::string::npos) { //x
                        flags = flags + '1';
                        operand= getOperandIfIndexed(operand);
                    }
                    else flags = flags+ '0'; //x bardo
                    if(operand[0]=='=') bpBits = bPFlagBitsBLKLIT(littable,operand,PC,disp,blocks);
                    else bpBits = bPFlagBitsBLKSYM(symbol_table,operand,PC,disp,blocks);
                    flags = flags + bpBits + '0'; // e
                    objectCode=objectCode+ binToHex(flags) + intToHex(disp,format);
                }
            }
            else if (format == 4){
                string flags="";
                int addIndexSYM = findOperandIndexSYM(symbol_table,operand) ;
                int addIndexLIT = findOperandIndexLIT(littable,operand) ;
                int opValue =0; //operandValue
                objectCode=opCode[0];
                char temp[] = {opCode[1], 0};
                int opSecDig =strtol(temp, NULL, 16);
                if(operand[0]=='#'){
                    opSecDig=opSecDig|1;
                    objectCode=objectCode+ intToHex(opSecDig,0);
                    operand = operand.substr(1);
                    addIndexSYM = findOperandIndexSYM(symbol_table,operand);
                    flags = flags + "0001";
                    if(addIndexSYM!=symbol_table.size()) // #label
                        opValue = symbol_table[addIndexSYM].address.first + BLKStartAdd(blocks,symbol_table[addIndexSYM].address.second);
                    else if(foundinExref(EXTREF,operand)) opValue= 0;
                    else opValue =strtol(operand.c_str(), NULL, 16); // string l int k2no #4096
                    objectCode=objectCode+ binToHex(flags) + intToHex(opValue,format);
                }
                else if(checkLabel(operand) || operand[0]=='='){
                    opSecDig=opSecDig|3;
                    objectCode=objectCode+ intToHex(opSecDig,0);
                    if(operand.find(',') != std::string::npos){
                            flags = flags+'1';
                            operand= getOperandIfIndexed(operand);
                    }
                    else flags = flags + '0';
                    flags = flags + "001"; //bpe
                    if(operand[0]=='='){
                        if(addIndexLIT!=littable.size()) //
                            opValue = littable[addIndexLIT].address.first + BLKStartAdd(blocks,littable[addIndexLIT].address.second);
                    }
                    else{
                        if(addIndexSYM!=symbol_table.size()) // #label
                        opValue = symbol_table[addIndexSYM].address.first + BLKStartAdd(blocks,symbol_table[addIndexSYM].address.second);
                        else if(foundinExref(EXTREF,operand)) opValue= 0;
                    }
                    objectCode=objectCode+ binToHex(flags) + intToHex(opValue,format);
                }
            }
        }


    else if(instruction=="*"){
                int addIndexLIT = findOperandIndexLIT(littable,operand) ;
                if(addIndexLIT!=littable.size())
                    objectCode=littable[addIndexLIT].value;
        }
        /*else if(data_types.find(instruction) != data_types.end()) */ // NOURAN
          {
              if(instruction == "BYTE") objectCode = getValuesByte(operand);
              else if(instruction == "WORD") objectCode = getValuesWord(operand);
             //cout << "$$$$$$$$$$$$$$$$$$$$$  " << instruction << " " << objectCode << endl << endl;
          }
    pass1[i].object_code=objectCode;
    //if(instruction == "BYTE") cout << "BYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYTE " << objectCode << endl;
    }
}


string generateTRecordBLK(vector<compLine> &pass1,int TstartAddIndex,unordered_map<string, pair<int, string> > &dictionary,vector<literalElement> &littable){ // mn 3'ir M Record
    string TRecord="T";
    string objectCodes="";
    int LastAddIndex=pass1.size()-1;
    int Tlength = 0;
    cerr << TstartAddIndex << " " << LastAddIndex+1 << endl;
    if(TstartAddIndex == LastAddIndex+1) return TRecord ;

    while(Tlength <= 30){
        if(pass1[TstartAddIndex].label == "USE") {
                return TRecord + generateTRecordBLK(pass1,TstartAddIndex+1,dictionary,littable);
        }
        else{
            if(dictionary.find(pass1[TstartAddIndex].instruction) != dictionary.end() ||
              (findOperandIndexLIT(littable,pass1[TstartAddIndex].operand)!= littable.size() )  ||   //instruction de tt3adel 3shan struct
               pass1[TstartAddIndex].instruction == "WORD" || pass1[TstartAddIndex].instruction == "BYTE"){ // lw instruction ao litral ao word ao byte ml a5r 7aga liha object code
                    objectCodes = objectCodes + pass1[TstartAddIndex].object_code;
                    Tlength += pass1[TstartAddIndex+1].address.first - pass1[TstartAddIndex].address.first;
                    TstartAddIndex++;
            }
            else if(pass1[TstartAddIndex].instruction == "RESW" ||
                    pass1[TstartAddIndex].instruction == "RESB" ||
                    pass1[TstartAddIndex].instruction == "EQU"){ // lw mlhash object code w lsa gowa el 30
                        TRecord = TRecord + intToHex(Tlength,0) + objectCodes + "\n";
                        TstartAddIndex++;
                        while(pass1[TstartAddIndex].instruction == "RESW" ||
                            pass1[TstartAddIndex].instruction == "RESB" ||
                            pass1[TstartAddIndex].instruction == "EQU")
                            TstartAddIndex++;
                        if(TstartAddIndex == LastAddIndex) return TRecord; //lw el reserved ao el directives 3amtn a5r 7aga fel program
                        else return TRecord + generateTRecordBLK(pass1,TstartAddIndex,dictionary,littable); //nbtdi T Record gdeed
            }
            else {
                cout << "Eh dah??   " << pass1[TstartAddIndex].instruction << endl;
            }
        }

    }
    if(Tlength > 30){
        Tlength = Tlength - (pass1[TstartAddIndex].address.first - pass1[TstartAddIndex-1].address.first);
        TstartAddIndex--;
        size_t lastObjAdded = objectCodes.find(pass1[TstartAddIndex].object_code); // ems7 a5r object code et7at
        if (lastObjAdded != std::string::npos)
            objectCodes.erase(lastObjAdded, pass1[TstartAddIndex].object_code.length());
    }
    TRecord = TRecord + intToHex(Tlength,0) + objectCodes + "\n";
    if(TstartAddIndex == LastAddIndex) return TRecord; //lw el reserved ao el directives 3amtn a5r 7aga fel program
    else return TRecord + generateTRecordBLK(pass1,TstartAddIndex,dictionary,littable); //nbtdi T Record gdeed
}

string HTEBLKs(vector<compLine> &pass1,unordered_map<string, pair<int, string> > &dictionary,vector<literalElement> &littable){
    string startingAddress = checkSix( intToHex(pass1[0].address.first,0),'N');
    int Length = (pass1[pass1.size()-1].address.first - pass1[0].address.first);
    string progLength = intToHex(Length,0) ;
    string progName =  checkSix(pass1[0].label,'L');
    string hRecord = "H" + progName + startingAddress + checkSix(progLength,'N') + "\n";
    string eRecord = "E" + startingAddress;
    string tRecord = generateTRecordBLK(pass1,1,dictionary,littable);
    //string mRecord = generateMRecord(pass1,dictionary); //ttzabt
    return hRecord + tRecord + eRecord ;

}

int main(){
	#ifndef ONLINE_JUDGE
		//freopen("in.in", "r", stdin);	//input file
		//freopen("in.out","w",stdout);	//output file

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, pair<int, string> > dictionary;
	unordered_map<string, int> data_types, reg;

	vector<compLine> pass1_1, pass1_2, pass1_3;
	vector<literalElement> litTable1, litTable2, litTable3;
	vector<symbolElement> symbol_table1, symbol_table2, symbol_table3;
	vector<Block> blocks1, blocks2, blocks3;
	vector<string> EXTREF1, EXTREF2, EXTREF3;
	vector<pair<string, int> > EXTDEF1, EXTDEF2, EXTDEF3;
	initialize_instructions(dictionary, data_types);
	initialize_reg(reg);

	complete_pass1( "in.in", "in.out", dictionary, data_types, reg, pass1_1, litTable1, symbol_table1, blocks1, EXTREF1, EXTDEF1);
	//complete_pass1( "in2.in", "in.out", dictionary, data_types, reg, pass1_2, litTable2, symbol_table2, blocks2, EXTREF2, EXTDEF2);
	//complete_pass1( "in3.in", "in.out", dictionary, data_types, reg, pass1_3, litTable3, symbol_table3, blocks3, EXTREF3, EXTDEF3);

    ObjectCode(pass1_1,litTable1,symbol_table1,blocks1,dictionary,data_types,EXTREF1,EXTDEF1);
    print_pass1( pass1_1 );
    //cout << "SAMAR TABLE FEEN?  " << HTEBLKs(pass1_1,dictionary,litTable1) << endl;
	return 0;
}
