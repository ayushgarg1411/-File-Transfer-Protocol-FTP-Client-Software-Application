/**
 * @file: ftp_client_control.cpp
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
 #include "ftp_client_control.hpp"
int controlSocket = -1;
int dataSocket = -1;
bool isControlConnected = false;
bool isDataConnected = false;


void connectToServerControl(const char* serverIP, int serverPort)
{
	connectToServer(controlSocket, isControlConnected, serverIP, serverPort);
}



void connectToServerData(const char* serverIP, int serverPort)
{
	connectToServer(dataSocket, isDataConnected, serverIP, serverPort);
}



int sendOnControl(const char* buffer, int length)
{
	return sendToServer(controlSocket, buffer, length);
}



int sendOnData(const char* buffer, int length)
{
	return sendToServer(dataSocket, buffer, length);
}



int receiveOnControl(char* buffer, int length)
{
	return receiveFromServer(controlSocket, buffer, length);
}



int receiveOnData(char* buffer, int length)
{
	return receiveFromServer(dataSocket, buffer, length);
}



void disconnectControlConnection()
{
	disconnectFromServer(controlSocket, isControlConnected);
}



void disconnectDataConnection()
{
	disconnectFromServer(dataSocket, isDataConnected);
}



bool isControlConnectionAvailable()
{
	return isControlConnected;
}


bool isDataConnectionAvailable()
{
	return isDataConnected;
}
