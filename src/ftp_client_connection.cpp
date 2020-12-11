/**
 * @file: ftp_client_connection.cpp
 * @author: Ayush Garg, 656665809, Section, CSCI 460, VIU
 * @version: 1.0.0
 * @modified: June 24, 2020
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


// Sends a connection request on severPort of a sever whose IP address is equal to serverIP.
// If a connection has been established as a result of the request sets the connection descriptor value
// to reference 'socketDescriptor' and sets reference 'isConnected' to 'true'.
void connectToServer(int& socketDescriptor, bool& isConnected, const char* serverIP, int serverPort)
{
	socketDescriptor = -1;
  //socketDescriptor = socket(AF_INET, )
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


// Closes network connection represented by reference 'socketDescriptor' and
// sets reference 'isConnected' to 'false'.
void disconnectFromServer(int& socketDescriptor, bool& isConnected)
{
	close(socketDescriptor);
	isConnected = false;
}


// Sends 'message' of length 'messageLength' bytes to the server
// on the network connection represented by 'sockDescriptor'.
int sendToServer(int sockDescriptor, const char* message, int messageLength)
{
	return send(sockDescriptor, message, messageLength, 0);
}


// Receives 'message' of length 'messageLength' bytes from the server
// on the network connection represented by 'sockDescriptor'.
int receiveFromServer(int sockDescriptor, char* message, int messageLength)
{
	return recv(sockDescriptor, message, messageLength, 0);
}
