#include "../include/isbn.h"

#include <bits/stdc++.h>
#include <string>

Isbn::Isbn(const std::string Isbn)
    :isbn_{Isbn}{
        if(!IsValid(isbn_)){throw ISBN_invalid();}
    }

bool Isbn::IsValid(std::string isbn){
    
    if(isbn.length()!=13)return false;
    int start = 0;
    std::string delimitator="-";
    std::string append;
    
    int end = isbn.find(delimitator);
    while (end != -1) {
         append+=isbn.substr(start, end - start);
         
        start = end + delimitator.size();
        end = isbn.find(delimitator, start);
    }
    for (int i = 0; i < append.length(); i++)
    {
        if(!isdigit(append[i])){
            return false;
        }
    }
    if(!isalnum(isbn[12])){
        return false;
    }
    return true;
 
} 