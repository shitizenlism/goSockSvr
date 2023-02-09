#include "tcpsock.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <io.h>
#include <fcntl.h>


using namespace std;

void tst_sendLine()
{
	 try {

		 SocketClient s("127.0.0.1", 17010);
		 // =@@1{"action":"redirect","devid":"A68000011809SN000320","vid":"0001","pid":"A680","devtype":"5"}##
		 // =@@1{"action":"redirect","devid":"A68000011809SN000320","vid":"0001","pid":"A680","devtype":"5"}##

	   	 s.SendLine("@@1{\"action\":\"redirect\",\"devid\":\"A68000011809SN000320\",\"vid\":\"0001\",\"pid\":\"A680\",\"devtype\":\"5\"}##");
		 //s.SendLine("Host: www.example.com");
	//	 s.SendLine("");

	   while (1) {
		 string l = s.ReceiveLine();
		 if (l.empty()){ 
		   cout<<"exit!";
		   break;
		 }
		 cout <<"recv[]= "<< l;
		 cout.flush();
	   }

	 } 
	 catch (const char* s) {
	   cerr << s << endl;
	 } 
	 catch (std::string s) {
	   cerr << s << endl;
	 } 
	 catch (...) {
	   cerr << "unhandled exception\n";
	 }

}

/*
两次发送中间没有延迟就当成一次发送！
D:\proj\gitwork\freeman\vipoker\release\vipoker_v1.0.0>vipoker_x64_vs2019.exe
open vipoker.conf
Enter main-loop. press ctrl+c or ! to exit!
recv[]: 48,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,45,42,38,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,32,32,
tcp data-loopback thread exit!

中间加200ms延迟，就当成两次发送！
recv[]: 48,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,45,42,
recv[]: 38,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,32,32,
tcp data-loopback thread exit!

D:\proj\gitwork\freeman\vipoker\release\vipoker_v1.0.0>

*/
void tst_sendBytes()
{
	 try {
	   SocketClient s("107.150.28.246", 17029);

	   //s.SendBytes("48,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,45,42,");
	   //Sleep(200);
	   s.SendBytes("@@1{\"action\":\"redirect\",\"devid\":\"A68000011809SN000320\",\"vid\":\"0001\",\"pid\":\"A680\",\"devtype\":\"5\"}##");

	   while (1) {
		 string l = s.ReceiveBytes();
		 if (l.empty()){ 
		   cout<<"exit!";
		   break;
		 }
		 cout <<"recv[]= "<< l;
		 cout.flush();
	   }

	 } 
	 catch (const char* s) {
	   cerr << s << endl;
	 } 
	 catch (std::string s) {
	   cerr << s << endl;
	 } 
	 catch (...) {
	   cerr << "unhandled exception\n";
	 }

}

void tst_recvLine()
{
	 try {
		 SocketClient s("47.115.190.127", 17029);

	   while (1) {
		   string l = s.ReceiveLine();
		   if (l.empty()){ 
			 cout<<"exit!";
			 break;
		   }
		   cout <<"recv[]= "<< l;
		   cout.flush();
		 }
	 } 
	 catch (const char* s) {
	   cerr << s << endl;
	 } 
	 catch (std::string s) {
	   cerr << s << endl;
	 } 
	 catch (...) {
	   cerr << "unhandled exception\n";
	 }

}

int json_packMsg(char **pName,char **pValue,int TokenNum, char *MsgBuf)
{
	int i=0;
	int len=0;

	if ( (!(pName&&pValue&&MsgBuf))||(TokenNum==0))
		return -1;

	len=sprintf(MsgBuf,"{");
	for (i=0; i<TokenNum; i++)
	{
		len+=sprintf(MsgBuf+len,"\"%s\":\"%s\"",*(pName+i),*(pValue+i));
		if (i==(TokenNum-1))
			break;
		else
			len+=sprintf(MsgBuf+len,",");
	}
	len+=sprintf(MsgBuf+len,"}\n\r");

	printf("Json sending string=%s,len=%d\n",MsgBuf,len);

	return len;
}

void tst_sendBuf()
{
	char revBuf[2000]={0};
	int revLen=0;
	string json_str("{\"msg_type\":\"node_login\",\"usrid\":\"B68000011809SN000111\",\"pid\":\"B680\",\"devtype\":\"8\"}");
	
	try {
		SocketClient s("127.0.0.1", 17010);
	   
	   	s.SendBytes(json_str);
	   	revLen = s.RecvBuf(revBuf, 500);
	   	cout <<"recv1[]= "<< revBuf<<endl;

	   	s.SendBytes(json_str);
		revLen = s.RecvBuf(revBuf, 500);
		cout <<"recv2[]= "<< revBuf<<endl;
	   
	} 
	catch (const char* s) {
	  cerr << s << endl;
	} 
	catch (std::string s) {
	  cerr << s << endl;
	} 
	catch (...) {
	  cerr << "unhandled exception\n";
	}

}

#include "md5.h"
typedef unsigned int t_uint32;

struct PACKET_HEADER
{
	t_uint32  cmd;
	t_uint32  size;
	t_uint32  seq;
};

#define DECL_PACKET(pack_name, id) const t_uint32 CMD_##pack_name = id; struct PK_##pack_name 
#define INIT_HEAD(type, pack) (pack).head.seq=0; (pack).head.cmd = htonl(CMD_##type); (pack).head.size = htonl(sizeof(PK_##type));

DECL_PACKET(OBS_SWITCH, 0x0BA001)
{
	PACKET_HEADER head;
	char vid[4];		//video id, "BG01", "BG02"
	char id[4];			//device id. fixed: "A001"
	char token[32];		//token =  md5(vid + 'obs' + id  + "15ad55a77b5c215bdcb7d5411d0d5bd8")
	t_uint32 scene;  //1: green-room-1, 2:green-room-2
};

DECL_PACKET(OBS_SWITCH_R, 0x0BA002)
{
	PACKET_HEADER head;
	t_uint32 code;  //0: success, other:error code
};

void ItoHexstring(unsigned char* strin, char* strout, unsigned int length)
{
	char* pchar = strout;
	for (int i = 0; i < length; i++)
	{
		//char tmp[3];
		_itoa(strin[i], pchar, 16);

		if (strlen(pchar) == 1)
		{
			pchar[1] = pchar[0];
			pchar[0] = '0';
			pchar[2] = '\0';
		}
		pchar = pchar + 2;
	}
	*pchar = 0;
}

/**
 * 32位MD5加密,strout的长度必须大于32
 *
 * @author Robot.O (2013/9/4)
 *
 * @param strin
 * @param ilen
 * @param strout
 */
void EncryMD5(unsigned char* strin, unsigned int ilen, char* strout)
{
	MD5_CTX m_md5;

	MD5Init(&m_md5);
	MD5Update(&m_md5, strin, ilen);
	MD5Final(&m_md5);

	ItoHexstring(m_md5.digest, strout, ilen);
}

void tst_sendBuf2()
{
	char revBuf[2000] = { 0 };
	int revLen = 0;

	char token[33] = { 0 };
	PK_OBS_SWITCH msg = { 0 };
	INIT_HEAD(OBS_SWITCH, msg);
	strncpy_s(msg.vid, "BG01", 4);
	strncpy_s(msg.id, "A001", 4);
	
	//token =  md5(vid + 'obs' + id  + "15ad55a77b5c215bdcb7d5411d0d5bd8")
	string token_s = string(msg.vid) + string("obs") + string(msg.id) + string("15ad55a77b5c215bdcb7d5411d0d5bd8");
	EncryMD5((unsigned char*)token_s.c_str(), token_s.length(), token);
	strncpy_s(msg.token, token, 32);
	msg.scene = htonl(1);
	char* json_str = (char*)& msg;
	cout << "prepare to send[]" << json_str<<endl;

	try {
		SocketClient s("127.0.0.1", 17010);

		s.SendBytes(json_str);
		revLen = s.RecvBuf(revBuf, 500);
		cout << "recv1[]= " << revBuf << endl;

		s.SendBytes(json_str);
		revLen = s.RecvBuf(revBuf, 500);
		cout << "recv2[]= " << revBuf << endl;

	}
	catch (const char* s) {
		cerr << s << endl;
	}
	catch (std::string s) {
		cerr << s << endl;
	}
	catch (...) {
		cerr << "unhandled exception\n";
	}

}


int cppsock_main() {

	//tst_sendLine();

	tst_sendBuf2();

	//while(1){
	//	tst_recvLine();

	//	Sleep(2);
	//}
	
	return 0;
}


#define TCP_SERVER "127.0.0.1"

#define TCP_SERVER_PORT 17029
#define TCP_MSG_LEN 100
#define MSG_HEAD_MAGIC 0x28
#define MSG_TAIL_MAGIC 0x29

#define MSG_TYPE_HELLO  "hello"
#define MSG_TYPE_START_REC  "start_record"
#define MSG_TYPE_STOP_REC  "stop_record"

static int gSockFd=-1;

#define CMD_START_RECORD 0x5a01
#define CMD_START_RECORD_R 0x5b01
#define CMD_STOP_RECORD 0x5a02
#define CMD_STOP_RECORD_R 0x5b02
#pragma pack(2)
	typedef struct{
		int cmd;
		int size;
		short ver;
		char table[4];
		char gmcode[16];
	}DEALER_CMD_T;
	typedef struct{
		int cmd;
		int size;
		short ver;
		char gmcode[16];
		int ret;
	}DEALER_RES_T;

#pragma pack()


void Tcp_Close(int sockFd)
{
	if (sockFd>=0){
		shutdown(sockFd, SD_BOTH);
		closesocket(sockFd);
	}
	WSACleanup();
}

int Tcp_Connect(const char *TcpHost, unsigned short usPort)
{
	int ret=0;
	WSADATA wsaData;
	int iResult=0;

	do {
		if (gSockFd<0){
			iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
			if (iResult != NO_ERROR){
				printf("WSAStartup failed with err=%d\n", iResult);
				ret=-1;break;
			}

			gSockFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (gSockFd<0){
				printf("get socket error=%ld\n",WSAGetLastError());
				ret=-2;break;
			}

			int cltSockTimeout=3000;
			struct timeval tv;
			tv.tv_sec=cltSockTimeout/1000;
			tv.tv_usec=(cltSockTimeout%1000)*1000;
			setsockopt(gSockFd,SOL_SOCKET,SO_RCVTIMEO,(char*)&tv,sizeof(tv));
			setsockopt(gSockFd,SOL_SOCKET,SO_SNDTIMEO,(char*)&tv,sizeof(tv));

		}

		sockaddr_in addr;
		struct in_addr s;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(usPort);
		//inet_pton(AF_INET, TcpHost, (void *)&s);
		addr.sin_addr.s_addr = s.s_addr;
		memset(&(addr.sin_zero), 0, 8);
		printf("Tcp connnecting to 0x%x\n", s.s_addr);
		iResult = connect(gSockFd, (SOCKADDR*)&addr, sizeof(addr));
		if (iResult == SOCKET_ERROR){
			printf("socket connnec failed! error=%ld\n", WSAGetLastError());
			ret=-3;break;
		}
	}while(0);

	if (ret<0){
		Tcp_Close(gSockFd); gSockFd=-1;	
		printf("close socket!\n");
		return ret;
	}
	return gSockFd;
}


int Tcp_MsgProcess(int sockFd,const char *msgType,const char *TableName,
const char *RoundId)
{
	int ret=0;
	char buf[TCP_MSG_LEN]={0};
	char *p=NULL;
	int len=strlen(msgType) + strlen(TableName) + strlen(RoundId);

	if (len>(TCP_MSG_LEN-10)){
		cout<<"msg len exceed limit. cut it short"<<endl;
		return -1;
	}

	p=buf;
	buf[0]=MSG_HEAD_MAGIC;
	snprintf(p+1,90,"%s,%s,%s,",msgType,TableName,RoundId);
	buf[99]=MSG_TAIL_MAGIC;
	cout<<"send msg[]:"<<buf<<endl;

	do{
		ret=send(sockFd, buf, TCP_MSG_LEN, 0);
		if (ret==SOCKET_ERROR){
			cout<<"send error="<<ret<<endl;
		}
		else{
			cout<<"send done."<<endl;
		}

		memset(buf,0,sizeof(buf));
		ret=recv(sockFd,buf,sizeof(buf),0);
		if (ret<=0){
			cout<<"recv error="<<ret<<endl;
		}
		else{
			cout<<"recv buf[]"<<buf<<endl;
		}
	}while(0);

	return ret;
}

int c_main(int argc, char **argv)
{
	int ret=0;
	int sock=-1;

	if (argc != 5){
		printf("usage: %s start 10.10.10.10 B001 GT0123456001\n",argv[0]);
		return 0;
	}

	const char *msgType=MSG_TYPE_START_REC;
	const char *TableName=argv[3];
	const char *RoundId=argv[4];
	sock=Tcp_Connect(argv[2], TCP_SERVER_PORT);
	if (sock>=0){
		if (!strcmp(argv[1],"start"))
			ret=Tcp_MsgProcess(sock, MSG_TYPE_START_REC, TableName, RoundId);
		if (!strcmp(argv[1],"stop"))
			ret=Tcp_MsgProcess(sock, MSG_TYPE_STOP_REC, TableName, RoundId);
		Tcp_Close(sock);
	}

	return 0;
}

int cpp_main1(int argc, char **argv)
{
	if (argc != 6){
		printf("usage: %s start 10.10.10.10 B001 GT0123456001 100\n",argv[0]);
		return 0;
	}

	char sndBuf[TCP_MSG_LEN]={0};
	char *p=NULL;
	char revBuf[TCP_MSG_LEN]={0};
	const char *TableName=argv[3];
	const char *RoundIdBase=argv[4];
	int roundCnt=atoi(argv[5]);
	int i=0;
	char RoundId[100]={0};

	try{
		SocketClient s(argv[2],TCP_SERVER_PORT);

		for (i=0; i<roundCnt; i++){
			snprintf(RoundId,sizeof(RoundId),"%s%04d",RoundIdBase,i);
			p=sndBuf;
			sndBuf[0]=MSG_HEAD_MAGIC;
			sndBuf[99]=MSG_TAIL_MAGIC;
			snprintf(p+1,98,"%s,%s,%s",MSG_TYPE_START_REC,TableName,RoundId);
			s.SendBuf(sndBuf,sizeof(sndBuf));
			cout<<"send msg[]="<<sndBuf<<endl;
			memset(revBuf,0,sizeof(revBuf));
			s.RecvBuf(revBuf,sizeof(revBuf));
			cout<<"recv msg[]="<<revBuf<<endl;

			Sleep(50*1000);	//game duration

			snprintf(p+1,98,"%s,%s,%s",MSG_TYPE_STOP_REC,TableName,RoundId);
			s.SendBuf(sndBuf,sizeof(sndBuf));
			cout<<"send msg[]="<<sndBuf<<endl;
			memset(revBuf,0,sizeof(revBuf));
			s.RecvBuf(revBuf,sizeof(revBuf));
			cout<<"recv msg[]="<<revBuf<<endl;
		}
	}
	catch(const char *s){
		cerr<<s<<endl;
	}
	catch(std::string s){
		cerr<<s<<endl;
	}
	catch(...){
		cerr<<"unknown exception happen"<<endl;
	}
	
	return i;
}

int cpp_main2(int argc, char **argv)
{
	if (argc != 6){
		printf("usage: %s start 47.115.190.127 B001 GT0123456001 2\n",argv[0]);
		return 0;
	}

	char sndBuf[TCP_MSG_LEN]={0};
	char *p=NULL;
	char revBuf[TCP_MSG_LEN]={0};
	const char *TableName=argv[3];
	const char *RoundIdBase=argv[4];
	int roundCnt=atoi(argv[5]);
	int i=0;
	char RoundId[100]={0};
	DEALER_CMD_T cmdMsg;
	int cmdMsgLen=sizeof(DEALER_CMD_T);

	try{
		SocketClient s(argv[2],TCP_SERVER_PORT);
		for (i=0; i<roundCnt; i++){
			snprintf(RoundId,sizeof(RoundId),"%s%04d",RoundIdBase,i);
			cmdMsg.cmd = htonl(CMD_START_RECORD);
			cmdMsg.size = htonl(cmdMsgLen);
			cmdMsg.ver = htons(1);
			memcpy(cmdMsg.table,TableName,4);
			memcpy(cmdMsg.gmcode,RoundId,16);
			s.SendBuf((char *)&cmdMsg,cmdMsgLen);
			cout<<"send msg["<<cmdMsgLen<<"]="<<endl;
			memset(revBuf,0,sizeof(revBuf));
			s.RecvBuf(revBuf,sizeof(revBuf));
			cout<<"recv msg[]="<<revBuf<<endl;

			Sleep(50*1000);	//game duration

			cmdMsg.cmd = htonl(CMD_STOP_RECORD);
			s.SendBuf((char *)&cmdMsg,cmdMsgLen);
			cout<<"send msg["<<cmdMsgLen<<"]="<<endl;
			memset(revBuf,0,sizeof(revBuf));
			s.RecvBuf(revBuf,sizeof(revBuf));
			cout<<"recv msg[]="<<revBuf<<endl;
		}
		
	}
	catch(const char *s){
		cerr<<s<<endl;
	}
	catch(std::string s){
		cerr<<s<<endl;
	}
	catch(...){
		cerr<<"unknown exception happen"<<endl;
	}
	
	return i;
}

int main(int argc, char **argv)
{
	//return cpp_main2(argc, argv);
	return cppsock_main();
}



