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

	msgid = msgget(MSG_ID_TEST, 0666 | IPC_CREAT);

	if(-1 == msgid)
	{
		fprintf(stderr, "msgget fail\n");
		exit(-1);
	}
	
	while(1)
	{
		printf("enter you text:");
		fgets(data.text, BUFSIZE, stdin);
		data.msg_type = 1;
		if(-1 == msgsnd(msgid, (void *)&data, BUFSIZE, 0))
		{
			printf("msgsnd fail\n");
			exit(-1);
		}

		if (strncmp(data.text, "end", 3) == 0)
        {
            break;
        }
 
        sleep(1);
	}
	return 0;
}
