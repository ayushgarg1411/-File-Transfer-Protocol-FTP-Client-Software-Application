/**
 * @file: ftp_client_command.cpp
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
 #include "ftp_client_control.hpp"
 #include "ftp_client_ui.hpp"
 #include "ftp_server_response.hpp"
 #include "ftp_client_command.hpp"


 void handleCommandHelp(){}
 // Displays following help text on the user terminal
 // Usage: csci460Ftp>> [ help | user | pass | pwd | dir | cwd | cdup | get | quit ]
 //          help                    Gives the list of FTP commands available and how to use them.
 //          user    <username>      Sumbits the <username> to FTP server for authentication.
 //          pass    <password>      Sumbits the <password> to FTP server for authentication.
 //          pwd                     Requests FTP server to print current directory.
 //          dir                     Requests FTP server to list the entries of the current directory.
 //          cwd     <dirname>       Requests FTP server to change current working directory.
 //          cdup                    Requests FTP server to change current directory to parent directory.
 //          get     <filename>      Requests FTP server to send the file with <filename>.
 //          quit                    Requests to end FTP session and quit.

 void handleCommandUser(string username, string serverResponses[], int& serverResponseCount){}
 // Sends a 'USER <username>' request meesage to the FTP Server.
 // Receives response from FTP Server.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter value "true"
 // to perform the activities mentioned above.

 void handleCommandPassword(string password, string serverResponses[], int& serverResponseCount){}
 // Sends a 'PASS <password>' request message to the FTP Server.
 // Receives response from FTP Server.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter "true"
 // to perform the activities mentioned above.

 void handleCommandDirectory(string serverResponses[], int& serverResponseCount){}
 // Calls handlePassive() function to do the followings:
 // 	-send a 'PASV' request message to the FTP server.
 // 	-receive the response against PASV request message from the server.
 // 	-update 'serverResponses' and 'serverResponseCount' parameters based on PASV responses.
 // 	-retrieve data-connection listener port number from the successful response.
 // 	-requests a data connection to the server at the listener port at the server.
 // If the data connection is successful, calls handleNLIST() function to do the followings:
 // 	-send a 'NLST' request message to the server on the control connection.
 // 	-receive the response against NLST request from the server on the control connection.
 // 	-retrieve the list of entries of the current directory at the server on the data connection from the successful response..
 // 	-update 'serverResponses' and 'serverResponseCount' parameters based on NLST responses.


 void handleCommandPrintDirectory(string serverResponses[], int& serverResponseCount){}
 // Sends a 'PWD' request message to FTP Server.
 // Receives the response from the server.
 // Successful server response contains the current FTP directory at the server.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter "false"
 // to perform the activities mentioned above.

 void handleCommandChangeDirectory(string path, string serverResponses[], int& serverResponseCount){}
 // Sends a 'CWD <path>' request message to the FTP Server.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter "false"
 // to perform the activities mentioned above.

 void handleCommandChangeDirectoryUp(string serverResponses[], int& serverResponseCount){}
 // Sends a 'CDUP' request message to FTP Server.
 // Receives the response from the server.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter "false"
 // to perform the activities mentioned above.

 void handleCommandGetFile(string filename, string serverResponses[], int& serverResponseCount){}
 // Calls handlePassive() function to do the followings:
 // 	-send a 'PASV' request message to the FTP server.
 // 	-receive the response against PASV request message from the server.
 // 	-update 'serverResponses' and 'serverResponseCount' parameters based on PASV responses.
 // 	-retrieve data-connection listener port number from the successful response.
 // 	-requests a data connection to the server at the listener port at the server.
 // If the data connection is successful, calls handleRETR() function to do the followings:
 // 	-send a 'RETR <filename>' request message to the server on the control connection.
 // 	-receive the response against RETR request from the server on the control connection.
 // 	-retrieve the content of the file on the data connection from the successful response.
 // 	-save the content of the file with <filename> at local folder.
 // 	-update 'serverResponses' and 'serverResponseCount' parameters based on RETR responses.

 void handleCommandQuit(string serverResponses[], int& serverResponseCount){}

 // Sends a 'QUIT' request message to FTP Server.
 // Calls function handleSimpleCommandResponse() with "checkAuthentication" parameter "false"
 // to send 'QUIT' request message.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // Quits from the application.

 void handlePassive( string serverResponses[], int& serverResponseCount){}
 // Sends a 'PASV' request message to the FTP server.
 // Receives the response against PASV request message from the server.
 // Updates 'serverResponses' and 'serverResponseCount' parameters based on PASV responses.
 // If the response is a successful one, retrives data-connection listener port number form the response.
 // Retrives data-connection listener port number form the response
 // using function getHostIPAndPortFromPassiveSuccessResponse().
 // Requests a data connection to the server on the listener port at the server.

 void handleNLIST(string serverResponses[], int& serverResponseCount){}
 // Sends a 'NLST' request message to the server on the control connection.
 // Receives the response against NLST request from the server on the control connection.
 // Updates 'serverResponses' and 'serverResponseCount' parameters based on NLST responses.
 // If the response is successful, retrieves the list of entries in server's current directory
 // on the data connection.
 // Adds the list of directory entries to 'serverResponses' and updates 'serverResponseCount'.

 void handleRETR(string filename, string serverResponses[], int& serverResponseCount){}
 // Sends a 'RETR <filename>' request message to the server on the control connection.
 // Receives the response against RETR request from the server on the control connection.
 // Updates 'serverResponses' and 'serverResponseCount' parameters based on RETR responses.
 // If the response is successful, retrieves the content of the file on the data connection.
 // Saves the file in the local directory at the client computer.

 void handleSimpleCommand(string ftpCommand, bool checkAuthentication, string serverResponses[], int& serverResponseCount){}
 // Sends 'ftpCommand' request message to FTP server on the control connection.
 // Receives the response from the server against the request.
 // Returns server responses and response count through 'serverResponses' and 'serverResponseCount' parameters respectively.
 // If the response is unsuccessful and checkAuthentication parameter value is true, quits the application.

 void getHostIPAndPortFromPassiveSuccessResponse(char* response, char* hostIP, int& hostPort){}
 // Retrieves IP address of FTP Server from the response string into reference 'hostIP'.
 // Retrives data-connection listening port number of FTP server from the response string into reference 'hostPort'.
 // The example of a successful response message is "227 Entering Passive Mode (192,168,1,65,202,143)."
 // From the above response message 'hostIP' will be 192.168.1.65 and 'hostPort' will be
 // (202x256 + 143) or 51855.
