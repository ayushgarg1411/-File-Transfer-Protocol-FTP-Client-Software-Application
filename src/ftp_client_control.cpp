/**
 * @file: ftp_client_control.cpp
 * @author: Name, Student Number, Section, CSCI 460, VIU
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
 #include "ftp_client_control.hpp"
int controlSocket = -1; 		//-- Represents control connection to the server
int dataSocket = -1;			//-- Represents data connection to the server
bool isControlConnected = false; 	//-- Represents the status of the control connection
bool isDataConnected = false;	//-- Represents the status of the data connection


void connectToServerControl(const char* serverIP, int serverPort)
{
	connectToServer(controlSocket, isControlConnected, serverIP, serverPort);
}
// Sends a control connection request on severPort of a sever whose IP address is equal to serverIP.
// If the control connection is successful sets its value to controlSocket and
// sets isControlConnected to true.
// Calls connectToServer() function from 'ftp_client_connection.cpp' to do the above.

void connectToServerData(const char* serverIP, int serverPort)
{
	connectToServer(dataSocket, isDataConnected, serverIP, serverPort);
}
// Sends a data connection request on severPort of a sever whose IP address is equal to serverIP.
// If the data connection is successful sets its value to dataSocket and
// sets isDataConnected to true.
// Calls connectToServer function from 'ftp_client_connection.cpp' to do the above.

int sendOnControl(const char* buffer, int length)
{
	return sendToServer(controlSocket, buffer, length);
}
// Sends the info in the buffer of length equal to 'length' on control connection.
// Returns the actual number of bytes sent.
// Calls sendToServer() function from 'ftp_client_connection.cpp' to do the above.

int sendOnData(const char* buffer, int length)
{
	return sendToServer(dataSocket, buffer, length);
}
// Sends the info in the buffer of length equal to 'length' on data connection.
// Returns the actual number of bytes sent.
// Calls sendToServer() function from 'ftp_client_connection.cpp' to do the above.

int receiveOnControl(char* buffer, int length)
{
	return receiveFromServer(controlSocket, buffer, length);
}
// Receives the info in the buffer of length equal to 'length' on control connection.
// Returns the actual number of bytes received.
// Calls receiveFromServer() fucntion from 'ftp_client_connection.cpp' to do the above.

int receiveOnData(char* buffer, int length)
{
	return receiveFromServer(dataSocket, buffer, length);
}
// Receives the info in the buffer of length equal to 'length' on data connection.
// Returns the actual number of bytes received.
// Calls receiveFromServer() function from 'ftp_client_connection.cpp' to do the above.

void disconnectControlConnection()
{
	disconnectFromServer(controlSocket, isControlConnected);
}
// Closes the opened control connection and sets isControlConnected to false;
// Calls disconnectFromServer() function from 'ftp_client_connection.cpp' to do the above

void disconnectDataConnection()
{
	disconnectFromServer(dataSocket, isDataConnected);
}
// Closes the opened data connection and sets isDataConnected to false;
// Call disconnectFromServer() function from 'ftp_client_connection.cpp' to do the above.

bool isControlConnectionAvailable()
{
	return isControlConnected;
}
// Returns the value of isControlConnected.

bool isDataConnectionAvailable()
{
	return isDataConnected;
}
// Returns the value of isDataConnected.
