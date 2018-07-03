#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#define MAX_PKT 1024
typedef UINT seqNum;
typedef enum { DATA, ACK, NAK } frameKind;
typedef enum { NO_ERR, CKSUM_ERR, LOST_ERR } errMode;
typedef struct { UCHAR data[MAX_PKT]; } packet;

typedef struct  
{
	frameKind kind;
	seqNum seq;
	seqNum ack;
	int size;		//���ݳ��ȣ�������֡ͷ
	errMode err;	//���ֶ�����ģ���ŵ�����
} frame_hdr;

typedef struct
{
	frame_hdr hdr;
	packet info;
} frame;

#endif //_PROTOCOL_H_
