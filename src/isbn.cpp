#include "../include/isbn.h"
#include <sstream> 
#include <string>

Isbn::Isbn(const std::string Isbn)
        : isbn_{Isbn} {
    if (!IsValid(isbn_)) {
        throw ISBN_invalid();
    }
}

bool Isbn::IsValid(std::string isbn) {
    if(isbn.length()!=13)return false;
    if(isbn.at(3)!='-'||isbn.at(7)!='-'||isbn.at(11)!='-')return false;
    std::string append="";
    std::stringstream isbnstream(isbn);
    std::string el;
    while (getline(isbnstream,el,'-')){
        append+=el;
    }
    for (int i = 0; i < append.length(); i++)
    {
        if(i==(append.length()-1)){
            if(!isalnum(append[i]))return false;
        }else{
            if(!isdigit(append[i]))return false;   
        }
        
    }
    return true;
}

bool Isbn::IsValid10(std::string isbn){
    if(isbn.length()!=13)return false;  
    if(isbn.at(3)!='-'||isbn.at(7)!='-'||isbn.at(11)!='-')return false;
    if(tolower(isbn[isbn.length()-1])!='x'&&(isbn[isbn.length()-1]<0||isbn[isbn.length()-1]>9))return false;
    std::stringstream isbnstream(isbn);
    std::string el;
    std::string append="";
    while (getline(isbnstream,el,'-')){
        append+=el;
    }
    //cout<<append<<endl;
    int sum=0;
    for (int i = 0,j=10; i < append.length(); i++,j--){ 
        if (i==(append.length()-1) && tolower(append[append.length()-1])=='x'){
            sum+=10;
            }else{     
                sum+=(append[i]-48)*j;
            }       
            //cout<<"sum:"<<i<<"="<<sum<<endl;   
    }
    //cout<<sum<<endl;
    if((sum%11)!=0)return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Isbn &isbn) {
    os << isbn.isbn();
    return os;
}

bool operator==(const Isbn &a, const Isbn &b) {
    return a.isbn() == b.isbn();
}
