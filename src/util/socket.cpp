#include "socket.hpp"

m61::Socket::Socket(const char *ip, const uint16_t port) 
    : m_port(port), m_socket(socket(AF_INET, SOCK_STREAM, 0))
{
    try {

        if (m_socket == -1)
        {
            throw std::runtime_error("Failed to create socket");
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);

        if (connect(m_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        {
            throw std::runtime_error("Failed to connect to server");
        }
    }catch(std::exception &e){
        m61::Logger::log(e.what(), m61::LogLevel::ERROR);
    }
}

m61::Socket::~Socket()
{
    close(m_socket);
}