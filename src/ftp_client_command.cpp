/**
 * @file: ftp_client_command.cpp
 * @author: Ayush Garg, 656665809, F20N02, CSCI 460, VIU
 * @version: 1.0.0
 * @modified: Dec 12, 2020
 *
 */

 #include <iostream>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <fstream>
 #include "ftp_client_control.hpp"
 #include "ftp_client_ui.hpp"
 #include "ftp_server_response.hpp"
 #include "ftp_client_command.hpp"


 void handleCommandHelp()
 {
 	cout<<"Usage: csci460Ftp>> [ help | user | pass | pwd | dir | cwd | cdup | get | quit ]"<<endl;
 	cout<<"\thelp\t\t\tGives the list of FTP commands available and how to use them."<<endl;
 	cout<<"\tuser\t<username>\tSumbits the <username> to FTP server for authentication."<<endl;
 	cout<<"\tpass\t<password>\tSumbits the <password> to FTP server for authentication."<<endl;
 	cout<<"\tpwd\t\t\tRequests FTP server to print current directory."<<endl;
 	cout<<"\tdir\t\t\tRequests FTP server to list the entries of the current directory."<<endl;
 	cout<<"\tcwd\t<dirname>\tRequests FTP server to change current working directory."<<endl;
 	cout<<"\tcdup\t\t\tRequests FTP server to change current directory to parent directory."<<endl;
 	cout<<"\tget\t<filename>\tRequests FTP server to send the file with <filename>."<<endl;
 	cout<<"\tquit\t\t\tRequests to end FTP session and quit."<<endl;
 }



 void handleCommandUser(string username, string serverResponses[], int& serverResponseCount)
 {
 	string cmd;
 	cmd = "USER "+username;
 	handleSimpleCommand(cmd, true, serverResponses, serverResponseCount);
 }



 void handleCommandPassword(string password, string serverResponses[], int& serverResponseCount)
 {
   	string cmd;
   	cmd = "PASS "+password;
   	handleSimpleCommand(cmd, true, serverResponses, serverResponseCount);
 }


 void handleCommandDirectory(string serverResponses[], int& serverResponseCount)
 {
 	  handlePassive(serverResponses, serverResponseCount);
 		handleNLIST(serverResponses, serverResponseCount);
 }




 void handleCommandPrintDirectory(string serverResponses[], int& serverResponseCount)
 {
    handleSimpleCommand("PWD", false, serverResponses, serverResponseCount);
 }



 void handleCommandChangeDirectory(string path, string serverResponses[], int& serverResponseCount)
 {
   	string cmd = "CWD "+path;
   	handleSimpleCommand(cmd, false, serverResponses, serverResponseCount);
 }



 void handleCommandChangeDirectoryUp(string serverResponses[], int& serverResponseCount)
 {
    handleSimpleCommand("CDUP", false, serverResponses, serverResponseCount);
 }


 void handleCommandGetFile(string filename, string serverResponses[], int& serverResponseCount)
 {
 	  handlePassive(serverResponses, serverResponseCount);
 		handleRETR(filename, serverResponses, serverResponseCount);
 }



 void handleCommandQuit(string serverResponses[], int& serverResponseCount)
 {
 	  handleSimpleCommand("QUIT", false, serverResponses, serverResponseCount);

 }



 void handlePassive( string serverResponses[], int& serverResponseCount)
 {
     char* buffer = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
     sendOnControl("PASV", strlen("PASV"));
     int n;
     n = receiveOnControl(buffer, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
     serverResponses[serverResponseCount++] = buffer;
     if(n > 0)
     {
       char* hostIP = new char[100];
       int hostPort;
       getHostIPAndPortFromPassiveSuccessResponse(buffer, hostIP, hostPort);
       connectToServerData(hostIP, hostPort);
     }
      else
     {
       handleCommandQuit(serverResponses,serverResponseCount);
     }
 }



 void handleNLIST(string serverResponses[], int& serverResponseCount)
 {
    char* buffer = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
  	char* response = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
  	int n;
  	sendOnControl("NLST", strlen("NLST"));
  	n = receiveOnControl(buffer, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
  	serverResponses[serverResponseCount++] = buffer;
  	if(n > 0)
  	{
      receiveOnControl(buffer, BUFFER_SIZE);
      serverResponses[serverResponseCount++] = buffer;
      receiveOnData(response, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
      serverResponses[serverResponseCount++] = response;
  	}
 }


 void handleRETR(string filename, string serverResponses[], int& serverResponseCount)
 {
   string cmd;
   FILE* fp;
   int n;
   char* f = new char[100];
   char* response = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
   strcpy(f, filename.c_str());
   fp = fopen(f, FILE_OPEN_MODE);
   char* command = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
   char* buffer = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
   cmd = "RETR " + filename;
   strcpy(command, cmd.c_str());
   sendOnControl(command, strlen(command));
   n = receiveOnControl(buffer, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
   serverResponses[serverResponseCount++] = buffer;
   if(n > 0)
   {
  		receiveOnData(response, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
      receiveOnControl(buffer, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
   		serverResponses[serverResponseCount++] = buffer;
  		fprintf(fp, response);
   }
   fclose(fp);
 }


 void handleSimpleCommand(string ftpCommand, bool checkAuthentication, string serverResponses[], int& serverResponseCount)
 {
    int n;
    char* buffer = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
  	char* str = new char[DATA_SOCKET_RECEIVE_BUFFER_SIZE];
  	strcpy(str, ftpCommand.c_str());
  	sendOnControl(str, strlen(str));
  	n = receiveOnControl(buffer, DATA_SOCKET_RECEIVE_BUFFER_SIZE);
  	serverResponses[serverResponseCount++] = buffer;
  	if(n < 0 && checkAuthentication)
  	{
  		handleCommandQuit(serverResponses, serverResponseCount);
  	}
 }

 void getHostIPAndPortFromPassiveSuccessResponse(char* response, char* hostIP, int& hostPort)
 {
    int j = 0,s = 0,l = 0;
  	int i = 27;
  	int arr[6];
    strcpy(hostIP,"");
  	if(response[26] == '(')
  	{
  	    do
  	    {
  	        j = response[i];
  	        j = j-48;
  	        if(response[i] !=',' && response[i] !=')')
  	        {
  	            l = l+j;
  	            l = l*10;
  	        }
  	        else
  	        {
  	            l = l/10;
  	            arr[s] = l;
  	            s++;
  	            l = 0;
  	        }
  	        i++;
  	    }while(response[i] != '.');
  	}
  	i = 0;
    char hh[1000];
  	while(i!=5)
  	{
  		if(i < 4)
  		{
  			sprintf(hh, "%d", arr[i]);
  			strcat(hostIP,hh);
  			if(i!=3)
  		    {
  		        strcat(hostIP, ".");
  		    }
  			i++;
  		}
  		else
  		{
  			hostPort = (arr[i]*256);
        i++;
        hostPort = hostPort + arr[i];
  		}
   }
}
