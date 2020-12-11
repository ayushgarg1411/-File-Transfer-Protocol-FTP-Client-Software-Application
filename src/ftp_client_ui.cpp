/**
 *  @file: ftp_client_ui.hpp
 *  @author: Name, Student Number, Section,  CSCI 460, VIU
 *  @version: 1.0.0
 *  @modified: June 22, 2020
 *
 */

 #include <iostream>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include "ftp_client_ui.hpp"
 #include "ftp_client_command.hpp"

 using namespace std;


 void getUserCommand()
 {/*
 	string command;
 	cout<<FTP_CLIENT_PROMT<<endl;
 	cin>>command;
 	interpretAndHandleUserCommand(command);
  */
 }
 // Displays a command line prompt as follows:
 //      CSCI460FTP>>
 // Lets user to type command and reads the user command from the prompt.
 // Interprets and handles user command by calling function interpreteAndHandleUserCommand().

 void interpretAndHandleUserCommand(string command)
 {/*
 	if(command == FTP_CLIENT_USER_COMMAND_HELP)
 	{
 		handleCommandHelp();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_USER)
 	{
 		handleCommandUser();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_PASSWORD)
 	{
 		handleCommandPassword();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_DIRECTORY)
 	{
 		handleCommandDirectory()
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_PRINT_DIRECTORY)
 	{
 		handleCommandPrintDirectory();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_CHANGE_DIRECTORY)
 	{
 		handleCommandChangeDirectory();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_CHANGE_DIRECTORY_UP)
 	{
 		handleCommandChangeDirectoryUp();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_GET)
 	{
 		handleCommandGetFile();
 	}
 	else if(command == FTP_CLIENT_USER_COMMAND_QUIT)
 	{
 		handleCommandQuit();
 	}*/
 }
 // Interprets and handles user command
 // Calls appropriate handleCommandXXXX() function from 'ftp_client_command.hpp'.
 // Displays all FTP server responses calling showFtpResponse() function.

 void showFtpResponse(string response)
 {
 	string message;
 	//receiveFromServer(------, message, FTP_COMMAND_MAX_LENGTH);
 	cout<<response;
 }
