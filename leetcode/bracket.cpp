string Decompress(string comp){
	string decomp, repeat, content;
	int rep  = 0, i = 0;
	
	while(comp.at(i) != '['){
		i++;
	}
	repeat = comp.substr(0, i);
	rep = stoi(repeat);
	
	i++;
	int start = i, len = 0;
	while(comp.at(i) != ']'){
		len++;
		i++;
	}
	
	content = comp.substr(start, len);
	
	if(CheckBracket(content)){ // '[' exists
		content = Parse(content);
	}
	content = content * rep;
	return content;
	
}

string Parse(string str){
	int idx1 = 0, idx2 = 0;
	
	while(!(str.at(idx1) >= '0' && str.at(idx) <= '9')){
		idx1++;
	}
	idx2 = idx1;
	while(str.at(idx2) != ']'){
		idx2++;
	}
	idx2++;
	
	string parsed = str.substr(0, idx1) + Decompress(idx1, idx2-idx1) + str.substr(idx2);
	return parsed;
}
