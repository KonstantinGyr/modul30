#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::string command;
    do{
        std::cout << "Enter command: " ;
        std::cin>>command;
        if(command=="get"){
            cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout<<r.text<<std::endl;
        }
        else if(command=="post"){
            cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout<<r.text<<std::endl;
        }
        else if(command=="put"){
            cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout<<r.text<<std::endl;
        }
        else if(command=="delete"){
            cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout<<r.text<<std::endl;
        }
        else if(command=="patch"){
            cpr::Response r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout<<r.text<<std::endl;
        }
    }while(command!="exit");

    return 0;
}
