//
// Created by Quentin Robert de beauchamp on 1/13/22.
//

#ifndef WEBSERV_SOCKET_HPP
#define WEBSERV_SOCKET_HPP
#include "Response.hpp"

void create_socket(int &server_socket, sockaddr_in &address);
void receiving_information(int &server_socket, sockaddr_in &address, Response &response);

#endif //WEBSERV_SOCKET_HPP
