#pragma once


#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>

#include <liburing.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdexcept>
#include <thread> 

#include "log.hpp"

namespace m61 {
    
    class Socket {

    private:

        struct sockaddr_in addr;
        const uint16_t m_port; 
        const int m_socket;


        struct io_uring ring;
        struct io_uring_sqe* sqe;     
        struct io_uring_cqe* cqe;
        

    public:
        Socket(const char* ip, const uint16_t port);
        ~Socket();

        int send(const char* data, const size_t size) const;
        int send(const std::string_view data) const;

    };
}