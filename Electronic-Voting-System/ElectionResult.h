#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct Result{
    string ElectionDate;
    string CountingDate;
    string constituency;
    string NoOfCandidate;
    string partyN;
    string candidateN;
    string NoOfVotes;
    
};

class ElectionResult{
    public:
    list<Result> file_to_list(){
        list<Result> l;
        Result r;
        fstream read("result.txt");
        read >> r.ElectionDate;
        read >> r.CountingDate;
        read >> r.constituency;
        read >> r.NoOfCandidate;
        read >> r.candidateN;
        read >> r.partyN;
        read >> r.NoOfVotes;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(r);
    	    read >> r.ElectionDate;
            read >> r.CountingDate;
            read >> r.constituency;
            read >> r.NoOfCandidate;
            read >> r.candidateN;
            read >> r.partyN;
            read >> r.NoOfVotes;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<Result>l){
        fstream write;
        write.open("result.txt", ios :: out);
        list<Result>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    write << it->ElectionDate <<"\n";
            write << it->CountingDate <<"\n";
            write << it->constituency <<"\n";
            write << it->NoOfCandidate <<"\n";
            write << it->candidateN <<"\n";
            write << it->partyN <<"\n";
            write << it->NoOfVotes <<"\n";
		    write << "\n";
	    }
    }
};
