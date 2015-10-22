/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 6, 2015, 3:13 PM
 * Purpose: Mastermind Game, Version 1
 */

//system libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

//user libraries
#include "user.h"
#include "save.h"

//global constants

//function prototypes
void inst(string &);
void hardshp(bool &,unsigned short &,unsigned short &,unsigned short &);
void game(unsigned short &,unsigned short &,unsigned short &,unsigned int,Save *);
void uValid(string &,User *, unsigned int &,Save *);
void oData(User *,Save *);
void iData(User *,Save *);

//execution begins here
int main(int argc, char** argv) {
    
    //random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //declare variables
    
    string temp;    //temporary string variable
    
    //player game variables
    string pCode;             //player code input
    char dffclty;             //player difficulty input
    bool again=true;          //play again boolean
    string name="";           //player name
    User *player=new User[10];//allocate memory for 10 users
    Save *uData=new Save[10]; //allocate memory for 10 user's data
    unsigned int uloc;        //user index
    
    //game information variables
    unsigned short mod;       //number range
    unsigned short holes;     //number of holes
    unsigned short tries;     //number of tries
    
    iData(player,uData);            //read saved data from file
    inst(temp);                     // rules/instructions
    uValid(name,player,uloc,uData); //user validation
    
    //loop for the game
    do{
        unsigned short pTries=0;  //number of tries player has attempted\
            
        hardshp(again,mod,holes,tries); //getting game difficulty
        
        if(again){    //check if the player is playing game
            
            //play the game
            game(mod,holes,tries,uloc,uData);
            oData(player,uData);
        }else cout<<"Thank you for playing, "<<name<<"!"<<endl;
    }while(again);  //play again if again is true or else the game is over
    
    delete []player;
    delete []uData;
    return 0;
}

/*******************************************************************************
 *                                 oData                                       *
 *******************************************************************************
 * purpose: to save data to file
 * input:
 *      p -> array of structure of user name
 *      d -> user data
 ******************************************************************************/
void iData(User *,Save *){
    ifstream r; //input stream of saved data
    r.open("data.txt", ios::in | ios::binary);
    char ch;
    
    while(r.read(&ch,sizeof(ch))){
        cout<<ch<<endl;
    }
    
    r.close();
}

/*******************************************************************************
 *                                 oData                                       *
 *******************************************************************************
 * purpose: to save data to file
 * input:
 *      p -> array of structure of user name
 *      d -> user data
 ******************************************************************************/
void oData(User *p,Save *d){
    ofstream s;  //output stream of saved usernames
    
    char sp=' ';
    char nl=10;
    
    s.open("data.txt", ios::out | ios::binary);
    
    for(int i=0;i<10;i++){
        for(int j=0;j<p[i].name.size();j++){
            s.write(&p[i].name[j],sizeof(p[i].name[j]));
            s.write(&sp,sizeof(sp));
        }
        s.write(reinterpret_cast<char *>(&d[i].games),sizeof(d[i].games));
        s.write(&sp,sizeof(sp));
        s.write(reinterpret_cast<char *>(&d[i].wins),sizeof(d[i].wins));
        s.write(&sp,sizeof(sp));
        s.write(reinterpret_cast<char *>(&d[i].loses),sizeof(d[i].loses));
        s.write(&sp,sizeof(sp));
        s.write(reinterpret_cast<char *>(&d[i].average),sizeof(d[i].average));
        s.write(&sp,sizeof(sp));
        s.write(reinterpret_cast<char *>(&d[i].lTries),sizeof(d[i].lTries));
        s.write(&sp,sizeof(sp));
        s.write(&nl,sizeof(nl));
                
        
        
        if(p[i].name!=""){
            cout<<p[i].name<<endl;
            cout<<d[i].games<<endl;
            cout<<d[i].wins<<endl;
            cout<<d[i].loses<<endl;
            cout<<d[i].average<<endl;
            cout<<d[i].lTries<<endl;
        }
    }
    
    s.close();
}

/*******************************************************************************
 *                                 uValid                                      *
 *******************************************************************************
 * purpose: to validate users of the game
 * input-output:
 *      p -> user name goes in blank, goes out full
 *      l -> user location
 *      d -> user data
 ******************************************************************************/
void uValid(string &n,User *p,unsigned int &l,Save *d){
    char chce;                //user choice [y]/[n]
    bool find=false;          //username found
    bool newUser=true;        //new user boolean
    bool again=true;          //again boolean
    
    //select/create user
    do{
        cout<<"Are you a returning player? [Y]/[N]: ";
        cin>>chce;
        cin.ignore();
        cout<<endl;
        if(chce!='Y' && chce!='y' && chce!='N' && chce!='n'){
            cout<<"You did not enter a [Y] or [N]"<<endl<<endl;
        }
    }while(chce!='Y' && chce!='y' && chce!='N' && chce!='n');
    
    if(chce=='Y' || chce=='y'){
        newUser=false;
        do{
            cout<<"What is your username? (case-sensitive): ";
            cin>>n;
            cin.ignore();
            cout<<endl;

            for(int i=0;i<10;i++){
                if(p[i].name==n){
                    find=true;
                    l=i;
                    again=false;
                }
            }

            if(!find){
                cout<<"We do not have that username on file."<<endl;
                do{
                    cout<<"Would you like to try again? [Y]/[N]"<<endl;
                    cout<<"Entering [N] will prompt you to create a new"
                            " username"<<endl;
                    cin>>chce;
                    cin.ignore();
                    cout<<endl;
                    if(chce!='Y' && chce!='y' &&
                       chce!='N' && chce!='n'){
                        cout<<"You did not enter a [Y] or [N]"<<endl<<endl;
                    }
                }while(chce!='Y' && chce!='y' &&
                       chce!='N' && chce!='n');
                
                if(chce=='N' || chce=='n'){
                    newUser=true;
                    again=false;
                }else again=true;
            }
        }while(again);
        
        if(find){
            cout<<"Welcome back, "<<p[l].name<<"!"<<endl;
        }
    }
    if(newUser){
        do{
            cout<<"Please enter a username. (case-sensitive): ";
            cin>>n;
            cin.ignore();
            cout<<endl;

            do{
                cout<<"You have entered "<<n<<". Is this correct? [Y]/[N]: ";
                cin>>chce;
                cin.ignore();
                cout<<endl;
                if(chce!='Y' && chce!='y' && chce!='N' && chce!='n'){
                    cout<<"You did not enter a [Y] or [N]"<<endl<<endl;
                }
            }while(chce!='Y' && chce!='y' && chce!='N' && chce!='n');

            if(chce=='Y' || chce=='y'){
                while(p[l].name=="" && l<9)l++;
                p[l].name=n;
                again=false;
//                for(int i=0;i<10;i++){
//                    if(p[i].name==""){
//                        p[i].name=n;
//                        l=i;
//                        again=false;
//                        break;
//                    }
//                }
                cout<<"Welcome, "<<p[l].name<<"!"<<endl;
            }else{
                again=true;
            }
        }while(again);
        
        d[l].games=0;
        d[l].wins=0;
        d[l].loses=0;
        d[l].lTries=20;
        d[l].average=0;
    }
    
    
    cout<<endl;
}

/*******************************************************************************
 *                                 game                                        *
 *******************************************************************************
 * purpose: to play the game
 * input:
 *      m -> range of numbers
 *      h -> number of holes
 *      t -> number of tries
 * input-output:
 *      s->data -> array of structure
 ******************************************************************************/
void game(unsigned short &m,unsigned short &h,unsigned short &t,unsigned int l,Save *d){
    //declare variables
    int a;         //answer generated by the cpu
    string guess;  //player guess
    bool win=false;//win or lose boolean
    int nTry=t;    //number of tries remaining
    int pCount=0;  //number of numbers correct and in position
    int nCount=0;  //number of numbers correct but not in position
    bool valid;    //boolean if the guess is valid
    bool range;    //boolean if a digit is in range

    //2D Array board
    char board[t][h];
    for(int i=0;i<t;i++){
        for(int j=0;j<h;j++){
            board[i][j]=145;
        }
    }
    
    //2D array validation
    int correct[t][2];
    for(int i=0;i<t;i++){
        for(int j=0;j<2;j++){
            correct[i][j]=0;
        }
    }
    //2D parallel array for validation - output on board
    string valBrd[t][2];
    for(int i=0;i<t;i++){
        for(int j=0;j<2;j++){
            valBrd[i][j]="T";
        }
    }
    
    int *code=new int[h];
    //get the answer
    for(int i=0;i<h;i++){
        a=rand()%m+1;
        code[i]=a;
//        cout<<code[i];
    }
    cout<<"The computer has selected a code you must break"<<endl;
    do{
        //re-initialize variables to zero
        pCount=0;
        nCount=0;
        
        //output tries data and board
        cout<<nTry<<" tries remaining"<<endl;
        
        for(int i=0;i<t;i++){
            cout<<"        ";
            for(int j=0;j<h;j++){
                cout<<board[i][j]<<" ";
            }
            for(int j=0;j<2;j++){
                if(valBrd[i][j]!="T"){
                    cout<<valBrd[i][j];
                }
            }
            cout<<endl;
        }
        
        do{
            valid=true;
            range=true;
            cout<<"What is your guess?: ";
            getline(cin,guess);
            if(guess.size()!=h){
                cout<<"Incomplete Code. Re-enter your code: ";
                valid=false;
            }
            else{
                for(int i=0;i<h;i++){
                    if(!isdigit(guess[i])){
                        valid=false;
                    }
                }
                if(!valid) cout<<"You didn't enter a digit"<<endl;
            }
            for(int i=0;i<h;i++){
                if(guess[i]<'1' || guess[i]>m+48){
                    valid=false;
                    range=false;
                }
            }
            if(!valid && !range){
                cout<<"One of your digits was less than or greater than the"
                        " number range"<<endl;
            }
            
        }while(!valid);
        nTry--; //decrement after every guess
        
        //set the guess to the board
        for(int i=0;i<h;i++){
            board[nTry][i]=guess[i];
        }
        
        //create a boolean parallel array to check off a number that has been
        //confirmed to not check duplicates
        bool check[h];
        for(int i=0;i<h;i++){
            check[i]=true;
        }
        
        for(int i=0;i<h;i++){
            if(guess[i]-48==code[i]){
                //increment if a number is correct and in the correct spot
                pCount++;
                check[i]=false;
            }
        }
        for(int i=0;i<h;i++){
            if(guess[i]-48!=code[i]){
                for(int j=0;j<h;j++){
                   if(guess[i]-48==code[j] && check[j]){
                       //increment if a number is correct w/ incorrect spot
                       nCount++;
                       check[j]=false;
                       //break once a number is tested correct.
                       break;
                    } 
                }
            }
        }
//        cout<<pCount<<" numbers in the correct spot"<<endl;
//        cout<<nCount<<" numbers correct but not in the right spot"<<endl;
        //set the correct to the board
        for(int i=0;i<pCount;i++){
            correct[nTry][0]+=1;
        }
        for(int i=0;i<nCount;i++){
            correct[nTry][1]+=1;
        }
        for(int i=0;i<correct[nTry][0];i++){
            if(i==0) valBrd[nTry][0]="O";
            else valBrd[nTry][0]+="O";
        }
        for(int i=0;i<correct[nTry][1];i++){
            if(i==0) valBrd[nTry][1]="X";
            else valBrd[nTry][1]+="X";
        }
        cout<<endl;
        //if player cracked the code, output win message.
        if(pCount==h){
            cout<<"You have cracked the code in "<<t-nTry<<" tries! Nice Job!"
                    <<endl;
            win=true;
            d[l].wins+=1;
            if((t-nTry)<d[l].lTries) d[l].lTries=(t-nTry);
        }
    
    }while(!win && nTry>0);
    
    d[l].games+=1;
    d[l].average=(d[l].wins/d[l].games);
    
    //output the answer
    cout <<"Answer: ";
    for(int i=0;i <h;i++){
        cout <<code [i];
    }
    cout<<endl;
    cout<<"Your Final guess: "<<guess<<endl<<endl;
    
    //if the player did not win, output lose message.
    if(!win){
        cout<<"Sorry, you lost! You have run out of tries. Please Try"
                " Again."<<endl;
        d[l].loses+=1;
    }
    
    
    delete []code;
}

/*******************************************************************************
 *                              hardshp                                        *
 *******************************************************************************
 * purpose: to get the difficulty of the game
 * input:
 *      d -> difficulty chosen
 * input-output:
 *      m -> number range
 *      h -> number of holes
 *      t -> number of tries
 ******************************************************************************/
void hardshp(bool &x,unsigned short &m,unsigned short &h,unsigned short &t){
    char d;  //player difficulty input
    //validation
    do{
        cout<<"Choose your difficulty:\n[E]asy, [M]edium, [H]ard, or [C]ustom"
                <<endl<<"[X] to exit (uppercase 'X' only)"<<endl;
        cin>>d;   //difficulty input
        cin.ignore();
        cout<<endl;

        //if the input isn't valid output the statement
        if(d!='E' && d!='e' && d!='M' && d!='m' &&
           d!='H' && d!='h' && d!='C' && d!='c' && d!='X'){
            cout<<"You did not enter an appropriate difficulty"<<endl<<endl;
        }
    }while(d!='E' && d!='e' && d!='M' && d!='m' &&
           d!='H' && d!='h' && d!='C' && d!='c' && d!='X');
    t=12;      
    switch(d){
        case 'E': case 'e': {
            cout<<"Difficulty chosen: Easy"<<endl;
            m=6;
            h=4;
            break;
        }
        case 'M': case 'm': {
            cout<<"Difficulty chosen: Medium"<<endl;
            m=6;
            h=5;
            break;
        }
        case 'H': case 'h': {
            cout<<"Difficulty chosen: Hard"<<endl;
            m=9;
            h=6;
            break;
        }
        case 'C': case 'c': {
            cout<<"Difficulty chosen: Custom"<<endl;
            do{
                cout<<"What do you want your number range be? 1-";
                cin>>m;
                cin.ignore();
                if(m<6 || m>9){
                    cout<<"Please enter a number of from 6 to 9"<<endl;
                }
            }while(m<6 || m>9);
            do{
                cout<<"How many holes do you want?: ";
                cin>>h;
                cin.ignore();
                if(h<4 || h>6){
                    cout<<"Please enter a number of holes from 4 to 6"
                            <<endl;
                }
            }while(h<4 || h>6);
            do{
                cout<<"How many tries do you want to have?: ";
                cin>>t;
                cin.ignore();
                if(t<6 || t>12){
                    cout<<"Please enter a number of tries from 6 to 12"
                            <<endl;
                }
            }while(t<6 || t>12);
            cout<<endl<<"Difficulty chosen: Custom"<<endl;
            break;
        }
        case 'X': x=false; break;
        default: cout<<"no difficulty"<<endl;
    }
    if(d!='X'){
        cout<<"Number range:    1-"<<m<<endl;
        cout<<"Number of holes: "<<h<<endl;
        cout<<"Number of tries: "<<t<<endl;
        cout<<endl;
    }
    
}

/*******************************************************************************
 *                                 inst                                        *
 *******************************************************************************
 * purpose: to display the rules of the game
 * file:
 *      rules -> input file stream
 * output:
 *      temp -> each line from the file
 ******************************************************************************/
void inst(string &temp){
    ifstream rules; //input stream of rules
    
    //open the file
    rules.open("rules.txt");
    
    //output the rules to the screen
    while(getline(rules,temp)){
        cout<<temp;
    }
    rules.close(); //closing the file
    cout<<endl<<endl;
}