#ifndef _ADT_Except_
#define _ADT_Except_

#include <exception>
#include <string>

using namespace std;

//Exception class
class ADTExceptions:public exception{
    string msg;

public:
    //Construtors
    ADTExceptions(const string& msg){
        this->msg = "\n**************************************** \n" + msg + "\n**************************************** \n";
    }

    ADTExceptions(const char& o,const string& type){
        if(o == '1')
            msg = "\n**************************************** \n  UNDERFLOW EXCEPTION:\n\n  " + type + " is Empty !!!\n******************************************* \n";
        else if(o == '2')
            msg = "\n**************************************** \n  OVERFLOW EXCEPTION:\n\n   " + type + " is Full !!!\n****************************************** \n"; 
    }
    //Functions
    
    void MsgDialog(){
         string s = "";
    #ifdef __linux__
        s = "zenity --error --text=\""+ msg +"\" --width=200 --height=100 --title=\"Warning\"";
    #elif _WIN32
        s = "msg * " + msg;
    #endif
        system(s.c_str());
    }
    const char* what() const throw() { return msg.c_str();}
    //Destructors
    ~ADTExceptions() throw(){}
};

template<typename T>
constexpr void chkEmpty(T* o){
    if(o->empty())
        throw ADTExceptions('1',o->adt_type);
}

template<typename T>
constexpr void chkFull(T* o){
    if(o->full())
        throw ADTExceptions('2',o->adt_type);
}

#endif