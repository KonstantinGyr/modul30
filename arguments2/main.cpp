#include <iostream>
#include <map>
#include <cpr/cpr.h>
#include <vector>

int main() {
    std::string name, args;
    std::map<std::string, std::string> myMap;
    std::map<std::string, std::string>::iterator it;
    do {
        std::cout << "Enter name and argument" << std::endl;
        std::cin >> name ;
        if(name == "get" || name == "post") break;
        std::cin >> args;
        std::string key;
        std::string value;
        myMap.insert(std::pair<std::string, std::string>(name, args));
    } while (name != "get" || name != "post");
    if (name == "get") {
        std::string request="?";
        for (it = myMap.begin(); it != myMap.end(); it++){
           request+=it->first;
           request.push_back('=');
           request+=it->second;
           request.push_back('&');
        }
        cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"+request));
        std::cout << r.text;
    }
    else if(name=="post") {
        std::string key;
        std::string value;
        cpr::Pair pair((std::string) key, (std::string) value);
        std::vector<cpr::Pair> payload;
        for (it = myMap.begin(); it != myMap.end(); it++) {
            pair.key = it->first;
            pair.value = it->second;
            payload.push_back(pair);
        }
        cpr::Payload pl = cpr::Payload(payload.begin(), payload.end());
        cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),pl);
        std::cout<<r.text;
    }
    return 0;
}