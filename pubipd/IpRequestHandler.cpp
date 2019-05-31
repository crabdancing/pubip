//
// Created by cenicol on 5/29/19.
//

#include "IpRequestHandler.hpp"

#include <string>

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"


using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Util::Application;


using namespace std;


IpRequestHandler::IpRequestHandler(const std::string &format) : _format(format) {
}

void IpRequestHandler::handleRequest(HTTPServerRequest &request, HTTPServerResponse &response) {
    Application &app = Application::instance();
    app.logger().information("Request from " + request.clientAddress().toString() );

    string beg {"<tr><td>"};
    string mid {"</td><td>"};
    string end {"</td></tr>\n"};

    string uri = request.getURI();

    if( uri == "/" ) {
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream &ostr = response.send();
        ostr << "<html>";
        ostr << "<head><title>pubipd</title></head>";
        ostr << "<body>";
        ostr << "<table border='1'>";
        ostr << beg << "uri" << mid << request.getURI() << end;
        ostr << beg << "host" << mid << request.getHost() << end;
        ostr << beg << "client" << mid << request.clientAddress().toString() << end;
        ostr << "</body></html>";
    } else if( uri == "/plain" ) {
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream &ostr = response.send();
        ostr << request.clientAddress().toString();
    }
}