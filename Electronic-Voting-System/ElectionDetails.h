#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct ElectionD{
    string name;
    string date;
    string votingTime;
    string district;
    string constituency;
    
};


class ElectionDetails{
    public:
    list<ElectionD> file_to_list(){
        list<ElectionD> l;
        ElectionD e;
        fstream read("election.txt");
        read >> e.name;
        read >> e.date;
        read.get();
        getline(read, e.votingTime);
        read >> e.district;
        read >> e.constituency;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(e);
            read >> e.name;
            read >> e.date;
            read.get();
            getline(read, e.votingTime);
            read >> e.district;
            read >> e.constituency;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<ElectionD>l){
        fstream write;
        write.open("election.txt", ios :: out);
        list<ElectionD>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
	        
		    write << it->name <<"\n";
		    write << it->date <<"\n";
		    write << it->votingTime <<"\n";
		    write << it->district <<"\n";
		    write << it->constituency <<"\n";
		    write << "\n";
	    }
    }
};
