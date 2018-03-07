#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "die_with_error.c"
#include "handle_tcp_client.c"

#define MAXPENDING 5
#define RCVBUFSIZE 32
#define SERVER_PORT 9876

void DieWithError(char *message);
void HandleTCPClient(int clntSock);

int main(void) {
	int servSock;
	int clntSock;
	struct sockaddr_in echoServAddr;
	struct sockaddr_in echoClntAddr;
	unsigned short echoServPort;
	unsigned int clntLen;
	char echoBuffer[RCVBUFSIZE];

	echoServPort = SERVER_PORT;
	printf("Default server port : %hu\n", SERVER_PORT);

	if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		DieWithError("socket() failed");

	memset(&echoServAddr, 0, sizeof(echoServAddr));
	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	echoServAddr.sin_port = htons(echoServPort);

	if (bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
		DieWithError("bind() failed");

	if (listen(servSock, MAXPENDING) < 0)
		DieWithError("listen() failed");

	for ( ; ; ) {

		clntLen = sizeof(echoClntAddr);

		if ((clntSock = accept(servSock, (struct sockaddr *)&echoClntAddr, &clntLen)) < 0)
			DieWithError("accept() failed");

		printf("client ip : %s\n", inet_ntoa(echoClntAddr.sin_addr));
		printf("port: %u\n", ntohs(echoClntAddr.sin_port));
		// client로 부터 handshaking message를 수신함
		if (recv(clntSock, echoBuffer, RCVBUFSIZE, 0) < 0)
			DieWithError("recv() failed");
		printf("msg<- %s\n", echoBuffer);
		// 수신한 메시지가 hello 인지 확인하고 아니라면 루프 처음오로 돌아감
		if (strcmp(echoBuffer, "hello"))
			continue;
		// hello 메시지를 제대로 받았다면 client에 hi를 보냄
		if (send(clntSock, "hi", 2, 0) != 2)
			DieWithError("send() failed");
		printf("msg-> %s\n", "hi");

		// client와 server간의 채팅 시작
		HandleTCPClient(clntSock);
	}
}
