//
// Created by cenicol on 5/29/19.
//

#ifndef PUBIP_IPREQUESTHANDLER_HPP
#define PUBIP_IPREQUESTHANDLER_HPP

#include <Poco/Net/HTTPRequestHandler.h>

#include <string>


class IpRequestHandler : public Poco::Net::HTTPRequestHandler {
public:
    IpRequestHandler(const std::string& format);

    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

private:
    std::string _format;

};


#endif //PUBIP_IPREQUESTHANDLER_HPP
