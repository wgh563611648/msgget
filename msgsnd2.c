#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include "msg_com.h"

int main(int argc, char *argv[])
{
	int msgid;
	MSG_TYPE data;

	msgid = msgget(MSG_ID_TEST, 0666 | IPC_CREAT);
	if(-1 == msgid)
	{
		fprintf(stderr, "%s msgget fail\n", __FILE__);
		exit(-1);
	}

	while(1)
	{
		data.msg_type = 1;
		fprintf(stdout, "please input text:");
		fgets(data.text, BUFSIZE, stdin);
		data.id = MSG_SEND_ID2;
		if(msgsnd(msgid, (void *)&data, sizeof(MSG_TYPE) - sizeof(SINT32), 0) == -1)
		{
			fprintf(stderr, "%s msgsnd fail\n", __FILE__);
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
