
#define BUFSIZE (1024)

typedef enum
{
	MSG_ID_MAIN = 0x1000,
	MSG_ID_TEST,
	MSG_ID_MAX
}T_MSG_ID;

typedef struct msg_st
{
	long int msg_type;
    char text[BUFSIZE];
}MSG_TYPE;
