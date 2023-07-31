#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "Administrator.h"

using namespace std;

void Administrator();
void ElectoralOfficer();
void Voter();

class Administrator admin;

int ID;

int main(){

	int ch = 0;
	while(ch != 4){
		cout <<"\n \t\t\t\t\t *********************************************************************** \n ";
		cout <<"\n \t\t\t\t\t\t               Electronic Voting System                             \n ";
		cout <<"\n \t\t\t\t\t *********************************************************************** \n ";
		cout <<"\n Welcome to Home Page \n";
		cout <<"\n 1. Administrator\n";
		cout <<"\n 2. ElectoralOfficer\n";
		cout <<"\n 3. Voter\n";
		cout <<"\n 4. Exit \n";
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
		        Administrator();
		        break;
		    case 2:
		     system("clear");
		        ElectoralOfficer();
		        break;
		    case 3:
		     system("clear");
		        Voter();
		        break;
		    case 4:
		        break;
		    default:
		        cout <<" \n Please Enter a Valid Choice \n";
		        continue;
		}
	}
}

void Administrator(){
    cout <<"\n Enter Adminstrator Login Credentials :- \n";
    int userid = 101;
    string pass = "12345";
    
    int uid;
    string pass1;
    cout <<"\n Enter your User ID : ";
    cin >> uid;
    while(true){
	    cout <<"\n Enter your Password : ";
	    cin >> pass1;
	    if(pass1.length() > 8){
	    	cout <<"\n Password length should be less then 9 \n";
	    	continue;
		}
		break;
	}    
    if(userid == uid  && pass == pass1){
        cout << "\n Your Login as Administration is Successful \n";
        admin.AdminPage();
    }
    else{
        cout <<"\n Invalid Username or Password \n" ;
    }
}

void ElectoralOfficer(){
    cout << "\n Welcome to Electoral Officer Module\n";
}

void Voter(){
    cout << "\n Welcome to Voter Module\n";
}

    
