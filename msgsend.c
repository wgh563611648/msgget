#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include "msg_com.h"

int main(int argc, char **argv)
{
	int msgid = 0;
	MSG_TYPE data;
	char buffer[BUFSIZE];

	msgid = msgget(MSG_ID_TEST, 0666 | IPC_CREAT);

	if(-1 == msgid)
	{
		printf("msgget fail\n");
		exit(-1);
	}

	while(1)
	{
		printf("enter you text:");
		fgets(buffer, BUFSIZE, stdin);
		data.msg_type = 1;
		printf("buffer=%s\n",buffer);
		if(-1 == msgsnd(msgid, (void *)&buffer, BUFSIZE, 0))
		{
			printf("msgsnd fail\n");
			exit(-1);
		}

		if (strncmp(buffer, "end", 3) == 0)
        {
            break;
        }
 
        sleep(1);
	}
	printf("snd adf\n");
	return 0;
}
