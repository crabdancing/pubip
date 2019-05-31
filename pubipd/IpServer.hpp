//
// Created by cenicol on 5/29/19.
//

#ifndef PUBIP_IPSERVER_HPP
#define PUBIP_IPSERVER_HPP

#include <Poco/Util/ServerApplication.h>
#include "Poco/Util/OptionSet.h"

class IpServer : public Poco::Util::ServerApplication {
public:

    IpServer(): _helpRequested(false)
    {
    }

    ~IpServer()
    {
    }

protected:
    void initialize(Application& self);

    void uninitialize();

    void defineOptions(Poco::Util::OptionSet& options);

    void handleHelp(const std::string& name,
                    const std::string& value);

    int main(const std::vector<std::string>& args);

private:
    bool _helpRequested;
};


#endif //PUBIP_IPSERVER_HPP
