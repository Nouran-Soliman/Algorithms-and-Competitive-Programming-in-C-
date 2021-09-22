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
				cout << "		" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand << endl;
			}
			else {
				if (pass1[i].address.second == -1) cout << hex << pass1[i].address.first << "		" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand << endl;
				else cout << hex << pass1[i].address.first << "	" << pass1[i].address.second << "	" << pass1[i].label << "	"<< pass1[i].instruction << "	" << pass1[i].operand << endl;
			}
		}
		cout << hex << pass1.back().address.first << "	" << pass1.back().address.second << "	" << pass1.back().label << "	"<< pass1.back().instruction << "	" << pass1.back().operand << endl;
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
	complete_pass1( "in2.in", "in.out", dictionary, data_types, reg, pass1_2, litTable2, symbol_table2, blocks2, EXTREF2, EXTDEF2);
	complete_pass1( "in3.in", "in.out", dictionary, data_types, reg, pass1_3, litTable3, symbol_table3, blocks3, EXTREF3, EXTDEF3);

	return 0;
}
