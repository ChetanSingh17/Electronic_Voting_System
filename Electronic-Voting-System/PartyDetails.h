#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct PartyD{
    string name;
    string leader;
    string symbol;
    
};


class PartyDetails{
    public:
    list<PartyD> file_to_list(){
        list<PartyD> l;
        PartyD p;
        fstream read("party.txt");
        read >> p.name;
        read >> p.leader;
        read >> p.symbol;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(p);
            read >> p.name;
            read >> p.leader;
            read >> p.symbol;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<PartyD>l){
        fstream write;
        write.open("party.txt", ios :: out);
        list<PartyD>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
	        
		    write << it->name <<"\n";
		    write << it->leader <<"\n";
		    write << it->symbol <<"\n";
		    write << "\n";
	    }
    }
};
