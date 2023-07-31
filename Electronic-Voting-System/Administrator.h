#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include "PartyDetails.h"
#include "CandidateDetails.h"
#include "ElectionDetails.h"
#include "ElectionResult.h"
#include "RequestedUser.h"
#include "UserDataEO.h"
#include "Validate.h"
using namespace std;


void manageElectionDetails();
void managePartyDetails();
void manageCandidateDetails();
void viewRequest();
void viewElectionResult();

//Election section

class PartyDetails pd;
class CandidateDetails cd;
class ElectionDetails ed;
class ElectionResult er;
class RequestedUser ru;
class UserDataEO ueo;

void AddElectionD(list<ElectionD> l){
    ElectionD e;
    while(true){
        cout <<"\nEnter Election Name : ";
        cin >> e.name;
        if(!is_valid_name(e.name)){
            cout <<"\nElection Name Should be string\n";
        }
        else{
            break;
        }
    }
    cout <<"\nEnter Election Date : ";
    cin >> e.date;
    
    cout <<"\nEnter Voting Time : ";
    cin.get();
    getline(cin, e.votingTime);
    
    while(true){
        cout <<"\nEnter District : ";
        cin >> e.district;
        if(!is_valid_name(e.district)){
            cout <<"\nDistrict Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter Constituency : ";
        cin >> e.constituency;
        if(!is_valid_name(e.constituency)){
            cout <<"\nConstituency Should be string\n";
        }
        else{
            break;
        }
    }
    l.push_back(e);
    ed.list_to_file(l);
    cout <<"\nElection added Successfully!!!!";
}


void ViewElectionD(list<ElectionD> l){
    list<ElectionD> :: iterator it;
    cout <<"\n" <<  setw(22) << "Election Name " << setw(15) <<"Date " << setw(23) <<"Voting Time " 
    << setw(24) <<"District " << setw(24) <<"Constituency "<<"\n";
    for(it = l.begin(); it!=l.end(); it++){
        cout << setw(20) << it->name << setw(20) << it->date << setw(23) << it->votingTime
        << setw(20) << it->district << setw(20) << it->constituency <<"\n";
    }
}

//Party section

bool searchPartyN(list<PartyD> l, string name){
    list<PartyD> :: iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        if(it->name == name){
            return true;
        }
    }
    return false;
}

bool searchPartyS(list<PartyD> l, string symbol){
    list<PartyD> :: iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        if(it->symbol == symbol){
            return true;
        }
    }
    return false;
}


void AddPartyD(list<PartyD>l){
    PartyD p;
    while(true){
        while(true){
            cout <<"\nEnter Party Name : ";
            cin >> p.name;
            if(!is_valid_name(p.name)){
                cout <<"\nParty Name Should be string\n";
            }
            else{
                break;
            }
        }
        bool flag = false;
        flag = searchPartyN(l, p.name);
        if(flag == true){
            cout <<"\nParty Name is already Exist \n";
            cout <<"\nPlease Enter Unique Party Name \n";
            
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter Leader Name : ";
        cin >> p.leader;
        if(!is_valid_name(p.leader)){
            cout <<"\nLeader Name Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        while(true){
            cout <<"\nEnter Symbol : ";
            cin >> p.symbol;
            if(!is_valid_name(p.symbol)){
                cout <<"\nSymbol Should be string\n";
            }
            else{
                break;
            }
        }
        bool flag = false;
        flag = searchPartyS(l, p.symbol);
        if(flag == true){
            cout <<"\nParty Symbol already Exist \n";
            cout <<"\nPlease Enter Unique Party Symbol \n";
            
        }
        else{
            break;
        }
    }
    l.push_back(p);
    pd.list_to_file(l);
    cout <<"\nParty added Successfully!!!! \n";
}

void ViewPartyD(list<PartyD> l){
    list<PartyD> :: iterator it;
    cout <<"\n" <<  setw(22) << "Party Name " << setw(19) <<"Leader " << setw(21) <<"Symbol "<<"\n";
    for(it = l.begin(); it!=l.end(); it++){
        cout << setw(20) << it->name << setw(20) << it->leader << setw(20) << it->symbol <<"\n";
    }
}

//Candidate section

void AddCandicateD(list<CandidateD> l){
    CandidateD c;
    c.id;
    while(true){
        cout <<"\nEnter Candidate Name : ";
        cin >> c.name;
        if(!is_valid_name(c.name)){
            cout <<"\nCandidate Name Should be string\n";
        }
        else{
            break;
        }
    }
    //while(true){
        cout <<"\nEnter Date Of Birth : ";
        cin >> c.dob;
    //     if(!is_valid_num(c.dob)){
    //         cout <<"\nDOB Name Should be string\n";
    //     }
    //     else{
    //         break;
    //     }
    // }
    while(true){
        cout <<"\nEnter Election Name : ";
        cin >> c.electionN;
        if(!is_valid_name(c.electionN)){
            cout <<"\nElection Name Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter Party Name : ";
        cin >> c.partyN;
        if(!is_valid_name(c.partyN)){
            cout <<"\nParty Name Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter District : ";
        cin >> c.district;
        if(!is_valid_name(c.district)){
            cout <<"\nDistrict Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter Constituency : ";
        cin >> c.constituency;
        if(!is_valid_name(c.constituency)){
            cout <<"\nConstituency Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
        cout <<"\nEnter Address : ";
        cin >> c.address;
        if(!is_valid_name(c.address)){
            cout <<"\nAddress Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
	    cout <<"\nEnter your Phone Number : ";
	    cin >> c.phone;
	    if(c.phone.length() < 10 || c.phone.length() > 10 ){
	    	cout <<"\nPhone Number length should be 10 \n";
	    	continue;
		}
		break;
	}
	while(true){
        cout <<"\nEnter Email ID : ";
        cin >> c.email;
        if(!isValid(c.email)){
            cout <<"\nInvaild email id. Email id should contain @gmail.com\n";
        }
        else{
            break;
        }
    }
    l.push_back(c);
    cd.list_to_file(l);
    cout <<"\nCandidate added Successfully!!!!\n";
}
	              
void ViewCandidateD(list<CandidateD> l){
    list<CandidateD> :: iterator it;
    cout <<"\n" <<  setw(22) << "Candidate ID " << setw(19) <<"Name " << setw(18) <<"DOB " << setw(21) <<"Election Name " 
    << setw(21) <<"PartyName " << setw(20) <<"District " << setw(21) <<"Constituency " << setw(19) <<"Address " 
    << setw(21) <<"Phone no " << setw(21) <<"Email id "<<"\n";
    for(it = l.begin(); it!=l.end(); it++){
        cout << setw(20) << it->id << setw(20) << it->name << setw(20) << it->dob << setw(20) << it->electionN 
        << setw(20) << it->partyN << setw(20) << it->district << setw(20) << it->constituency << setw(20) << it->address
        << setw(22) << it->phone << setw(25) << it->email<<"\n";
    }
}



class Administrator{
	public :
	void AdminPage(){
	    int ch = 0;
	    cout <<" \n \t\t\t\t\t ************ Welcome to Administration Module *************** \n";
	    cout <<" \n \t\t\t\t\t *************************************************************\n";
	    while(ch != 6){
	        cout <<" \n 1. Manage Election Details \n";
	        cout <<" \n 2. Manage Party Details \n";
	        cout <<" \n 3. Manage Candidate Details \n";
	        cout <<" \n 4. View Requests \n";
	        cout <<" \n 5. View Election Result \n";
	        cout <<" \n 6. Logout \n";
	        while(true){
        		cout <<"\n Enter your choice : ";
        		cin >> ch;
        		if(cin.fail()){
        		    cin.clear();
        		    cin.ignore(512,'\n');
        		    cout <<"\nPlease Enter choice from given choices\n";
        		    cout <<"\nChoice should be Integer\n";
        		}
        		else{
        		    break;
        		}
    		}
	        switch(ch){
	            case 1:
	               system("clear");
	                manageElectionDetails();
	                break;
	            case 2:
	               system("clear");
	                managePartyDetails();
	                break;
	            case 3:
	               system("clear");
	                manageCandidateDetails();
	                break;
	            case 4:
	               system("clear");
	                viewRequest();
	                break;
	            case 5:
	               system("clear");
	            	viewElectionResult();
	                break;
	            case 6:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	}
};

void manageElectionDetails(){
	int ch = 0;
	    cout <<" \n \t\t\t\t ************ Manage Election Details *************** \n";
	    cout <<" \n \t\t\t\t **************************************************** \n";
	    while(ch != 3){
	        list<ElectionD> e = ed.file_to_list();
	        cout <<" \n 1. Add Election Details \n";
	        cout <<" \n 2. View Election Details \n";
	        cout <<" \n 3. Exit \n";
	        while(true){
        		cout <<"\n Enter your choice : ";
        		cin >> ch;
        		if(cin.fail()){
        		    cin.clear();
        		    cin.ignore(512,'\n');
        		    cout <<"\nPlease Enter choice from given choices\n";
        		    cout <<"\nChoice should be Integer\n";
        		}
        		else{
        		    break;
        		}
    		}
	        switch(ch){
	            case 1:
	               system("clear");
	                AddElectionD(e);
	                break;
	            case 2:
	               system("clear");
	                ViewElectionD(e);
	                break;
	            case 6:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
}

void managePartyDetails(){
    int ch = 0;
	    cout <<" \n \t\t\t\t  ************ Manage Party Details *************** \n";
	    cout <<" \n \t\t\t\t. *************************************************\n";
	    while(ch != 3){
	        list<PartyD> p = pd.file_to_list();
	        cout <<" \n 1. Add Party Details \n";
	        cout <<" \n 2. View Party Details \n";
	        cout <<" \n 3. Exit \n";
	        while(true){
        		cout <<"\n Enter your choice : ";
        		cin >> ch;
        		if(cin.fail()){
        		    cin.clear();
        		    cin.ignore(512,'\n');
        		    cout <<"\nPlease Enter choice from given choices\n";
        		    cout <<"\nChoice should be Integer\n";
        		}
        		else{
        		    break;
        		}
    		}
	        switch(ch){
	            case 1:
	             system("clear");
	                AddPartyD(p);
	                break;
	            case 2:
	             system("clear");
	                ViewPartyD(p);
	                break;
	            case 3:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	
}

void manageCandidateDetails(){
        int ch = 0;
	    cout <<" \n \t\t\t\t ************ Manage Candidate Details *************** \n";
	    cout <<" \n \t\t\t\t ***************************************************** \n";
	    while(ch != 3){
	        list<CandidateD> c = cd.file_to_list();
	        cout <<" \n 1. Add Candidate Details \n";
	        cout <<" \n 2. View Candidate Details \n";
	        cout <<" \n 3. Exit \n";
	        while(true){
        		cout <<"\n Enter your choice : ";
        		cin >> ch;
        		if(cin.fail()){
        		    cin.clear();
        		    cin.ignore(512,'\n');
        		    cout <<"\nPlease Enter choice from given choices\n";
        		    cout <<"\nChoice should be Integer\n";
        		}
        		else{
        		    break;
        		}
    		}
	        switch(ch){
	            case 1:
	             system("clear");
	                AddCandicateD(c);
	                break;
	            case 2:
	             system("clear");
	                ViewCandidateD(c);
	                break;
	            case 3:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
}



void deleteUserRequest(list<Requesteduser> l, string uid){
    list<Requesteduser> :: iterator it;
    for(it = l.begin(); it != l.end(); it++){
        if(it->uid == uid){
            l.erase(it);
            ru.list_to_file(l);
            break;
        }
    }
}

void viewRequest(){
    cout<<"\nWelcoome to the Reques Page\n";
    list<Requesteduser> l = ru.file_to_list();
    list<userDataEO> l1 = ueo.file_to_list();
    list<Requesteduser> :: iterator it;
    bool messege = false;
    for(it = l.begin(); it!=l.end(); it++){
        cout << "\nUser ID : " << it->uid << "\nFirst Name : " << it->fname << "\nLast Name : "  << it->lname << "\nDOB : " << it->dob << "\nAge : " << it->age
        << "\nGender : " << it->gender << "\nAddress : " << it->address << "\nPhone no : "  << it->phone << "\nDistrict : " << it->district << "\nConstituency : "
        << it->constituency << "\nPassword : " << it->pass<<"\n";
        
		    int ch = 0;
		    cout << "\nConfirm to send Approval\n";
		    cout <<"\n 1. Yes \n";
		    cout <<"\n 2. No \n";
		    cout <<"\n 3. Exit \n";
		    while(true){
        		cout <<"\nEnter your choice : ";
        		cin >> ch;
        		if(cin.fail()){
        		    cin.clear();
        		    cin.ignore(512,'\n');
        		    cout <<"\nPlease Enter choice from given choices\n";
        		    cout <<"\nChoice should be Integer\n";
        		}
        		else{
        		    break;
        		}
		    }
		        switch(ch){
		            case 1:{
		                userDataEO u;
		                u.uid = it->uid;
		                messege = true;
		                l1.push_back(u);
		                deleteUserRequest(l, it->uid);
		                break;
		            }
		            case 2:
		                cout <<"\nRequest Denied!!!! \n";
		                break;
		            case 3:
		                break;
		            default :
		                cout <<"\nPlease Enter valid choice \n";
		        }
		    }
	if(messege == true){
	        ueo.list_to_file(l1);
		    cout <<"\nRequest Successfully sent to the Electoral Officer\n";
    }
}
bool Dec(Result r1, Result r2){
    if(r1.NoOfVotes != r2.NoOfVotes)
        return r1.NoOfVotes>r2.NoOfVotes;
    else
        return false;
}

void viewElectionResult(){
	list<Result> l = er.file_to_list();
	l.sort(Dec);
    list<Result> :: iterator it;
    cout <<"\n" <<  setw(22) << "Election Date " << setw(20) <<"Counting Date " << setw(23) <<"Constituency " 
    << setw(23) <<"No Of Candidate " << setw(19) <<"Candidate Name " << setw(20) <<"Party Name " << setw(20) <<"No Of Votes " <<"\n";
    for(it = l.begin(); it!=l.end(); it++){
        cout << setw(20) << it->ElectionDate << setw(20) << it->CountingDate << setw(23) << it->constituency
        << setw(20) << it->NoOfCandidate << setw(20) << it->candidateN << setw(20) << it->partyN << setw(20) << it->NoOfVotes<<"\n";
    }
}
