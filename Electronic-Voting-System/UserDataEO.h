#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct userDataEO{
    string uid;
};


class UserDataEO{
    public:
    list<userDataEO> file_to_list(){
        list<userDataEO> l;
        userDataEO ud;
        fstream read("userdataEO.txt");
        read >> ud.uid;
        read.ignore();
        
    	while(!read.eof()){
    	    l.push_back(ud);
            read >> ud.uid;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<userDataEO>l){
        fstream write;
        write.open("userdataEO.txt", ios :: out);
        list<userDataEO>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
	        
		    write << it->uid <<"\n";
		    write << "\n";
	    }
    }
};
