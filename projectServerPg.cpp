#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	/*Variables*/ 
	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;
	
	/*Create socket*/
	sock = socket (AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("Failed to create socket");
		exit(1);
	}
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port =htons(1026);
	
	/*call bind*/
	if(bind(sock, (struct sockaddr *)&server, sizeof(server)))
	{
		perror("bind failed");
		exit(1);
	}
	
	/*listen*/
	 listen(sock, 5);
	 
	/*Accept*/
	char hantar[9999];
	char dapat[9999];
	do
	{
		mysock = accept(sock, (struct sockaddr *) 0, 0);
		if(mysock == -1)
		{
			perror("accept failed");
		}
		else
		{
			memset(dapat, 0, sizeof(dapat));
			if ((rval = read(mysock,dapat, sizeof(dapat)))< 0)
				perror("reading stream message error");
			else if (rval == 0)
				printf("Ending connection\n");
			else	
				{		
					printf("Client site : %s\n",dapat);
					//printf("Server site : ");
					//scanf("%s",hantar);
					strcpy(hantar," OK..");
					write(mysock,hantar,sizeof(hantar));
				}

		}
	} while (1);
	return 0;
}
