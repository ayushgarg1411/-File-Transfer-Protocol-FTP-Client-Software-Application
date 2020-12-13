/**
 *  @file: ftp_client_ui.hpp
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
 #include "ftp_client_ui.hpp"
 #include "ftp_client_command.hpp"

 using namespace std;

 using namespace std;

 string response;
 int responseCount = 0;

 void getUserCommand()
 {
 	string command;
 	cout<<FTP_CLIENT_PROMT<<endl;
 	cin>>command;
 	interpretAndHandleUserCommand(command);
 }



 void interpretAndHandleUserCommand(string command)
 {
 	string str[2];
 	int i;

  char char_array[100];
  strcpy(char_array, command.c_str());
  char *token = strtok(char_array, " ");
  i=0;
	while (token != NULL)
	{
		str[i]=token;
		i++;
		token = strtok(NULL, " ");
	}



 	if(str[0] == FTP_CLIENT_USER_COMMAND_HELP)
 	{
 		handleCommandHelp();
 		showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_USER)
 	{
     	handleCommandUser(str[1], &response, responseCount);
     	showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_PASSWORD)
 	{
 	    handleCommandPassword(str[1], &response, responseCount);
 	    showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_DIRECTORY)
 	{
 	    handleCommandDirectory(&response, responseCount);
 	    showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_PRINT_DIRECTORY)
 	{
 	    handleCommandPrintDirectory(&response, responseCount);
 	    showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_CHANGE_DIRECTORY)
 	{
 	    handleCommandChangeDirectory(str[1], &response, responseCount);
 	    showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_CHANGE_DIRECTORY_UP)
 	{
 		handleCommandChangeDirectoryUp(&response, responseCount);
 		showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_GET)
 	{
 	    handleCommandGetFile(str[1], &response, responseCount);
 	    showFtpResponse(response);
 	}
 	else if(str[0] == FTP_CLIENT_USER_COMMAND_QUIT)
 	{
 	    handleCommandQuit(&response, responseCount);
 	    showFtpResponse(response);
 	}
 }


 
 void showFtpResponse(string response)
 {
 	cout<<response<<endl;
 }
