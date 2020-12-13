/**
 * @file: ftp_client_connection.cpp
 * @author: Ayush Garg, 656665809, F20N02, CSCI 460, VIU
 * @version: 1.0.0
 * @modified: Dec 10, 2020
 *
 */
 #include <iostream>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include "ftp_client_connection.hpp"


void connectToServer(int& socketDescriptor, bool& isConnected, const char* serverIP, int serverPort)
{
	socketDescriptor = -1;
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = (htons(serverPort));
	server.sin_addr.s_addr = inet_addr(serverIP);
	socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
	if(connect(socketDescriptor, (const struct sockaddr*) &server, (socklen_t) sizeof(server)) != -1)
	{
		isConnected = true;
	}
}



void disconnectFromServer(int& socketDescriptor, bool& isConnected)
{
	close(socketDescriptor);
	isConnected = false;
}



int sendToServer(int sockDescriptor, const char* message, int messageLength)
{
	return send(sockDescriptor, message, messageLength, 0);
}



int receiveFromServer(int sockDescriptor, char* message, int messageLength)
{
	return recv(sockDescriptor, message, messageLength, 0);
}
