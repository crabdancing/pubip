#
# pubipd
#

add_executable(pubipd
        main.cpp
        IpServer.cpp
        IpServer.hpp IpRequestHandlerFactory.cpp IpRequestHandlerFactory.hpp IpRequestHandler.cpp IpRequestHandler.hpp)

target_link_libraries(pubipd
        PUBLIC Poco::Foundation
        Poco::Net
        Poco::Util
        )