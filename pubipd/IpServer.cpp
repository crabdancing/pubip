//
// Created by cenicol on 5/29/19.
//

#include <IpServer.hpp>

#include <IpRequestHandlerFactory.hpp>

#include <iostream>


#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPServerParams.h"


using std::cout;


using Poco::Util::ServerApplication;
using Poco::Util::OptionSet;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::DateTimeFormat;
using Poco::Net::ServerSocket;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerParams;


void IpServer::initialize(Application& self)
{
    loadConfiguration();
    ServerApplication::initialize(self);
}

void IpServer::uninitialize()
{
    ServerApplication::uninitialize();
}

void IpServer::defineOptions(OptionSet& options)
{
    ServerApplication::defineOptions(options);

    options.addOption(
            Option("help", "h", "display argument help information")
                    .required(false)
                    .repeatable(false)
                    .callback(OptionCallback<IpServer>(
                            this, &IpServer::handleHelp)));
}

void IpServer::handleHelp(const std::string& name,
                const std::string& value)
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader(
            "A web server that serves the current date and time.");
    helpFormatter.format(std::cout);
    stopOptionsProcessing();
    _helpRequested = true;
}

int IpServer::main(const std::vector<std::string>& args)
{
    if (!_helpRequested)
    {
        unsigned short port = (unsigned short) config().getInt("IpServer.port", 9980);
        std::string format(
                config().getString("IpServer.format", DateTimeFormat::SORTABLE_FORMAT));

        ServerSocket svs(port);
        HTTPServer srv(new IpRequestHandlerFactory(format), svs, new HTTPServerParams);
        srv.start();
        waitForTerminationRequest();
        srv.stop();
    }
    return Application::EXIT_OK;
}
