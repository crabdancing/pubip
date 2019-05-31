//
// Created by cenicol on 5/29/19.
//

#include <iostream>
#include <iterator>

#include <IpServer.hpp>

using namespace std;


int main(int argc, char *argv[])
{
    ostream_iterator<char*> out_it(std::cout,"\n");
    copy(argv, argv+argc,  out_it);

    IpServer app;
    return app.run(argc, argv);
}