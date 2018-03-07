#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

void HandleTCPClient(int clntSocket) {
	char echoBuffer[RCVBUFSIZE];
	int recvMsgSize;
	FILE *f;

	if ((f = fopen("echo_history.log", "a+")) < 0)
		DieWithError("fopen() failed");

	if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
		DieWithError("recv() failed");
	else {
		// 메시지를 화면에 출력
		echoBuffer[recvMsgSize] = '\0';
		printf("msg<- %s\n", echoBuffer);

		// 메시지를 파일에 출력
		fputs(echoBuffer, f);
		fprintf(f, "%s", echoBuffer);
	}

	while (recvMsgSize > 0) {

		if (!strcmp(echoBuffer, "/quit")) {
			printf("--Client Offline--\n\n");
			break;
		}

		if (send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
			DieWithError("send() failed");

		printf("msg-> %s\n", echoBuffer);

		if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
			DieWithError("recv() failed");
		else if (recvMsgSize == 0) {
			printf("--Client offline--\n\n");
			break;
		}

		echoBuffer[recvMsgSize] = '\0';
		printf("msg<- %s\n", echoBuffer);

		fprintf(f, "%s\n", echoBuffer);
	}

	close(clntSocket);
	fclose(f);
}
