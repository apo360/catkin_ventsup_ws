#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <ros/ros.h>
#include <ros/exceptions.h>
#include <std_msgs/String.h>

using namespace std;

int server, sendResult;

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "master_client");

	ros::NodeHandle nh;

	std_msgs::StringConstPtr dados = ros::topic::waitForMessage<std_msgs::String>("/teste_comuni", nh);

	string ipAddress = dados->data.c_str();		// IP Address of the server
	int port = 5000;						// Listening port # on the server

	// Create socket
	server = socket(AF_INET, SOCK_STREAM, 0);
	// Verify if the socket was created
    if (server < 0)
    {
        ROS_ERROR("[-]Error in connection with %s.\n", ipAddress.c_str());
        exit(1);
    }

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

	// Connect to server
	int connResult = connect(server, (sockaddr*)&hint, sizeof(hint));
	if (connResult < 0)
	{
        ROS_ERROR("[-]Error: Can't connect to %s.\n", ipAddress.c_str());
		exit(1);
	}

	// Do-while loop to send and receive data
	char buf[4096];
	string userInput;

	do
	{
		// Prompt the user for some text
		cout << "> ";
		getline(cin, userInput);

		if (userInput.size() > 0)		// Make sure the user has typed in something
		{
			// Send the text
			sendResult = send(server, userInput.c_str(), userInput.size() + 1, 0);
			if (sendResult != 0)
			{
				// Wait for response
				bzero(buf, 4096);
				int bytesReceived = read(server, buf, 4096);
				if (bytesReceived > 0)
				{
					// Echo response to console
					cout << "Vent-Sup --> " << string(buf, 1, bytesReceived) << endl;
				}
			}
		}
	
	} while (userInput.size() > 0);

	// Gracefully close down everything
    close(server);
	return 0;
}