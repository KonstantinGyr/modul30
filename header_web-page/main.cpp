#include <iostream>
#include <cpr/cpr.h>
#include <vector>

int main() {
    std::vector<char> header;
    std::string text;
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept","text/html"}}));
    text=r.text;
    for(int i=text.find("<h1>")+4;i<text.find("</h1>");i++){
            header.push_back(text[i]);
    }
    for(int i=0;i<header.size();i++) {
        std::cout << header[i] ;
    }
    return 0;
}
