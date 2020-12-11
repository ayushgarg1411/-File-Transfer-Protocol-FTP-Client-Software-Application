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

 void getUserCommand(){}
 // Displays a command line prompt as follows:
 //      CSCI460FTP>>
 // Lets user to type command and reads the user command from the prompt.
 // Interprets and handles user command by calling function interpreteAndHandleUserCommand().

 void interpretAndHandleUserCommand(std::string command){}
 // Interprets and handles user command
 // Calls appropriate handleCommandXXXX() function from 'ftp_client_command.hpp'.
 // Displays all FTP server responses calling showFtpResponse() function.

 void showFtpResponse(std::string response){}
