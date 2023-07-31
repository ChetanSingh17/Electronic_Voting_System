#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct Requesteduser{
    string uid;
    string fname;
    string lname;
    string dob;
    string age;
    string gender;
    string address;
    string phone;
    string district;
    string constituency;
    string pass;
    
};

class RequestedUser{
    public:
    list<Requesteduser> file_to_list(){
        list<Requesteduser> l;
        Requesteduser u;
        fstream read("RequestedUser.txt");
        read >> u.uid;
        read >> u.fname;
        read >> u.lname;
        read >> u.dob;
        read >> u.age;
        read >> u.gender;
        read >> u.address;
        read >> u.phone;
        read >> u.district;
        read >> u.constituency;
        read >> u.pass;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(u);
    	    read >> u.uid;
            read >> u.fname;
            read >> u.lname;
            read >> u.dob;
            read >> u.age;
            read >> u.gender;
            read >> u.address;
            read >> u.phone;
            read >> u.district;
            read >> u.constituency;
            read >> u.pass;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<Requesteduser>l){
        fstream write;
        write.open("RequestedUser.txt", ios :: out);
        list<Requesteduser>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    write << it->uid <<"\n";
            write << it->fname <<"\n";
            write << it->lname <<"\n";
            write << it->dob <<"\n";
            write << it->age <<"\n";
            write << it->gender <<"\n";
            write << it->address <<"\n";
            write << it->phone <<"\n";
            write << it->district <<"\n";
            write << it->constituency <<"\n";
            write << it->pass <<"\n";
		    write << "\n";
	    }
    }
};
