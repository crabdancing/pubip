//
// Created by cenicol on 5/29/19.
//

#include "IpRequestHandlerFactory.hpp"

#include <IpRequestHandler.hpp>

#include "Poco/Net/HTTPServerRequest.h"


using Poco::Net::HTTPServerRequest;


IpRequestHandlerFactory::IpRequestHandlerFactory(const std::string& format):
        _format(format)
{
}

Poco::Net::HTTPRequestHandler* IpRequestHandlerFactory::createRequestHandler(
        const Poco::Net::HTTPServerRequest& request)
{
    if (request.getURI() == "/") {
        return new IpRequestHandler(_format);
    } else if( request.getURI() == "/plain" ) {
        return new IpRequestHandler(_format);
    } else {
        return 0;
    }
}
