//
// Created by cenicol on 5/29/19.
//

#ifndef PUBIP_IPREQUESTHANDLERFACTORY_HPP
#define PUBIP_IPREQUESTHANDLERFACTORY_HPP

#include <Poco/Net/HTTPRequestHandlerFactory.h>

class IpRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
public:
    IpRequestHandlerFactory(const std::string& format);

    Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

private:
    std::string _format;
};


#endif //PUBIP_IPREQUESTHANDLERFACTORY_HPP
