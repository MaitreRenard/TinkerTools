#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> //Not mandatory (BSD)
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>


int main(int argc, char **argv) {
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		perror("socket()");
		exit(errno);
	}

	struct hostent *hostinfo = NULL;
	struct sockaddr_in sin = { 0 };
	//const char *hostname = "challenge03.root-me.org";
	const char *hostname = "laptom";

	hostinfo = gethostbyname(hostname);
	if (hostinfo == NULL)
	{
		fprintf (stderr, "Unknown host %s.\n", hostname);
		exit(EXIT_FAILURE);
	}

	sin.sin_addr = *(struct in_addr *) hostinfo->h_addr;
	//sin.sin_port = 56543;
	sin.sin_port = 4444;
	sin.sin_family = AF_INET;

	printf("CHECK\n");
	if(connect(sock,(struct sockaddr *) &sin, sizeof(struct sockaddr)) == -1)
	{
		perror("connect()");
		exit(errno);
	}

	char buffer[10];
	int n = 0;

	if((n = recv(sock, buffer, 5, 0)) < 0)
	{
		perror("recv()");
		exit(errno);
	}

	printf("CHECK\n");
	buffer[n] = '\0';
	printf("%s",buffer);

	return 0;
}
