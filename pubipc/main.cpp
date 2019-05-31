#include <iostream>

#include <Poco/URI.h>
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;


int main() {
    std::cout << "pubipc" << std::endl;

    URI uri("ipecho.net/plain");

    Net::HTTPRequest *test = new Net::HTTPRequest("HTTP_GET", "http://www.example.com", "HTTP/1.1");

    return 0;
}