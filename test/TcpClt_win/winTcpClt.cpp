#include "tcpsock.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>

#include "EnumCmdID.pb.h"
#include "message.pb.h"

using namespace std;
using namespace pb;

typedef struct{
	int32_t id;
	int32_t len;
	char pbData[1];
}MSG_T;

#define TCP_MSG_LEN 4096

int gettimeofday(struct timeval* tv, struct timezone* tz)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME win_time;

	GetLocalTime(&win_time);

	tm.tm_year = win_time.wYear - 1900;
	tm.tm_mon = win_time.wMonth - 1;
	tm.tm_mday = win_time.wDay;
	tm.tm_hour = win_time.wHour;
	tm.tm_min = win_time.wMinute;
	tm.tm_sec = win_time.wSecond;
	tm.tm_isdst = -1;

	clock = mktime(&tm);

	tv->tv_sec = (long)clock;
	tv->tv_usec = win_time.wMilliseconds * 1000;

	return 0;
}

int64_t getTimestamp(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (int64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

int sendPingMsg(string host, int port)
{
	cout << "host=" << host << ",port=" << port << endl;
	int ret = 0;
	char buf[TCP_MSG_LEN]={0};
	MSG_T *pMsg= (MSG_T*)buf;

	Ping pingReq;
	pingReq.set_timestamp(getTimestamp());
	pingReq.set_hello("ping");
	string pingReq_s;
	pingReq.SerializeToString(&pingReq_s);
	pMsg->id = PING;
	strncpy(pMsg->pbData, pingReq_s.c_str(),pingReq_s.size());
	pMsg->len = pingReq_s.length();
	int len = 4 + 4 + pMsg->len;
	//cout << "msg.id=" << pMsg->id << ",len=" << pMsg->len << endl;
	try{
		SocketClient s(host,port);
		ret = s.SendBuf(buf, len);
		
		Ping pingRes;
		memset(buf, 0, sizeof(buf));
		s.RecvBuf(buf, sizeof(buf));
		string resp_s = pMsg->pbData;
		pingRes.ParseFromString(resp_s);
		int64_t ts = pingRes.timestamp();
		string msg = pingRes.hello();
		cout << "recv. msg.id="<<pMsg->id<<",len="<<pMsg->len<<endl;
		cout << "recv pbData. ts=" << ts << ",hello=" << msg.c_str() << endl;

		Scene sceneCmd;
		memset(buf, 0, sizeof(buf));
		s.RecvBuf(buf, sizeof(buf));
		resp_s = pMsg->pbData;
		sceneCmd.ParseFromString(resp_s);
		ts = sceneCmd.timestamp();
		msg = sceneCmd.scenename();
		cout << "recv. msg.id=" << pMsg->id << ",len=" << pMsg->len << endl;
		cout << "recv pbData. ts=" << ts << ",sceneName=" << msg.c_str() << endl;

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
	
	return ret;
}


int main(int argc, char **argv)
{
	if (argc >= 3) {
		sendPingMsg(argv[1], atoi(argv[2])); 
	}
	else {
		printf("usage: %s <host> <port>\n",argv[0]);
	}

}
