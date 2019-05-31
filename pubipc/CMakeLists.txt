#
# pubipd
#

add_executable(pubipc
        main.cpp)

target_link_libraries(pubipc PUBLIC Poco::Foundation Poco::Zip Poco::Net)

