#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct CandidateD{
    string id;
    string name;
    string dob;
    string electionN;
    string partyN;
    string district;
    string constituency;
    string address;
    string phone;
    string email;
    
    CandidateD(){
        stringstream ss;
        ss <<  rand()%(200-100+1) +100;
        ss >> id;
    }
};

class CandidateDetails{
    public:
    list<CandidateD> file_to_list(){
        list<CandidateD> l;
        CandidateD c;
        fstream read("candidate.txt");
        read >> c.id;
        read >> c.name;
        read >> c.dob;
        read >> c.electionN;
        read >> c.partyN;
        read >> c.district;
        read >> c.constituency;
        read >> c.address;
        read >> c.phone;
        read >> c.email;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(c);
    	    read >> c.id;
            read >> c.name;
            read >> c.dob;
            read >> c.electionN;
            read >> c.partyN;
            read >> c.district;
            read >> c.constituency;
            read >> c.address;
            read >> c.phone;
            read >> c.email;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<CandidateD>l){
        fstream write;
        write.open("candidate.txt", ios :: out);
        list<CandidateD>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    write << it->id <<"\n";
            write << it->name <<"\n";
            write << it->dob <<"\n";
            write << it->electionN <<"\n";
            write << it->partyN <<"\n";
            write << it->district <<"\n";
            write << it->constituency <<"\n";
            write << it->address <<"\n";
            write << it->phone <<"\n";
            write << it->email <<"\n";
		    write << "\n";
	    }
    }
};
