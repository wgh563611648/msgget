#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include "msg_com.h"

int main(int argc, char **argv)
{
	int msg_id = 0;
	MSG_TYPE data;
	SINT32 msgtype = 0;

	msg_id = msgget(MSG_ID_TEST, 0666 | IPC_CREAT);

	if(msg_id == -1)
	{
		printf("msgget error\n");
		exit(-1);
	}

	while(1)
	{
		if(-1 == msgrcv(msg_id, (void *)&data, sizeof(MSG_TYPE) - sizeof(SINT32), msgtype, 0))
		{
			printf("msgrcv fail\n");
			exit(-1);
		}
		
		switch(data.id)
		{
			case MSG_SEND_ID1:
				printf("send1 you wrote: %s\n", data.text);
				break;

			case MSG_SEND_ID2:
				printf("send2 you wrote: %s\n", data.text);
				break;
				
			default:
				break;
		}
 
        if (strncmp(data.text, "end", 3) == 0)
        {
            break;
        }
	}

	
	if (msgctl(msg_id, IPC_RMID, 0) == -1)
	{
		printf("msgctl(IPC_RMID) failed\n");
	}
	
	return 0;
}
