
#define BUFSIZE (1024)
typedef signed long int SINT32;

typedef enum
{
	MSG_ID_MAIN = 0x1000,
	MSG_ID_TEST,
	MSG_ID_MAX
}T_MSG_ID;

typedef enum
{
	MSG_SEND_ID1,
	MSG_SEND_ID2
}SEND_MSG_ID;

typedef struct msg_st
{
	SINT32 msg_type;
	SEND_MSG_ID id;
    char text[BUFSIZE];
}MSG_TYPE;
