// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Needed for Packet Capture Engine
#include <pcap.h>
#include <WinSock2.h>
#include <list>

// Needed for threading
// TODO! - Fix multiple reported errors when including these two.
// #include <thread>
// #include <mutex>

// Needed for 
#ifndef WIN32
#include <sys/socket.h>
#include <netinet/in.h>
#else
#include <winsock.h>
#endif

#endif //PCH_H