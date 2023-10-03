#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char * argv[]) 
{
	int std;
	char buff[100];
	int maxsizeofbuff=100;
	struct sockaddr_in server,client;
	int length=sizeof(server);
	int len=sizeof(client);
	std=socket(AF_INET,SOCK_DGRAM,0);
	if(std==-1)
	{
		printf("Error in socket creation\n");
		exit(0);
	}
	else
	{
		printf("Socket is created\n");
	}
	server.sin_family=AF_INET;
	server.sin_port= htons(65123);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	char msg[]="hello server";
	int lengthofmsg=strlen(msg);
	int sendMsg=sendto(std,(char*)msg,lengthofmsg,0,(struct sockaddr *)&server, sizeof server);
	if(sendMsg==-1)
	{
		printf("Error in sending message\n");
		exit(0);
	}
	else
	{
		printf("Message is sent\n");
	}
	int recieveMsg=recvfrom(std,(char*)buff,maxsizeofbuff,0,(struct sockaddr*)&server,&length);
	if(recieveMsg==-1)
	{
		printf("Error in recieveing message\n");
		exit(0);
	}
	else
	{
		printf("Message is recieveing\n");
	}

	return 0;
}
