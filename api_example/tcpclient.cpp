#include "tcpsock.h"

#include <iostream>

using namespace std;


void tst_sendLine()
{
	 try {
	   SocketClient s("127.0.0.1", 17101);

	   s.SendLine("48,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,42,32,");
	//	 s.SendLine("Host: www.example.com");
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
	   SocketClient s("127.0.0.1", 17101);

	   s.SendBytes("48,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,45,42,");
	   Sleep(200);
	   s.SendBytes("38,34,8,17,16,13,11,23,26,7,24,12,0,14,40,43,33,20,5,32,32,");

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
	   SocketClient s("127.0.0.1", 17101);

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


int main() {

	//tst_sendLine();

	//tst_sendBytes();

	while(1){
		tst_recvLine();

		Sleep(2);
	}
	
	return 0;
}
