#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char *argv[])
{	
	int x = 0;
	do{
	int sock;
	struct sockaddr_in server;
	struct hostent *hp;
	char buff[1024];
	
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket failed");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if(hp == 0)
	{
		perror("gethostbyname failed");
		close(sock);
		exit(1);
	}

	char hantar[9999];
	char dapat[9999];

	
		
	//printf("Client site : ");
	//scanf("%s",hantar);
	
	memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
	server.sin_port = htons(1026);
	
	if(connect(sock, (struct sockaddr *) &server, sizeof (server))< 0)
	{
		perror("connect failed");
		close(sock);
		exit(1);
	}
	

	if(x==0)
	{
		strcpy(hantar,"Client connetion OK..");
		write(sock,hantar,sizeof(hantar));
		x=1;
	}
	else 
		if(write(sock, hantar, sizeof(hantar)) < 0)
		{
			perror("sent failed");
			close(sock);
			exit(1);
		}



	if(read(sock,dapat,sizeof(dapat))>0)
	{
		printf("Server site : %s\n",dapat);
		printf("Client site : ");
		scanf("%s",hantar);
	}	
	
	//printf("Server site:  %s\n", dapat);
	close(sock);
	}while(1);
	//close(sock);
	return 0;
}
