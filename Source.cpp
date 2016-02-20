#include <winsock2.h>
#include "wsock32error.h"
#include <stdio.h>
#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32")
WSADATA m_wd; // ＷＳＡＳＴＡＲＴＵＰ用
u_short m_portno = 20045; // ポート番号
SOCKET m_mysock; // ソケット番号
sockaddr_in m_myaddr; // 自分のアドレス
sockaddr_in m_serveraddr; // サーバーアドレス
HWND m_hwnd = 0;
char sendbuffer[1024]; // 送信バッファ
char recvbuffer[1024]; // 送信バッファ
					   //////////////////////////////////////////
					   // ソケットエラーメッセージ表示処理 //
					   //////////////////////////////////////////
void errcom()
{
	int i;
	int errno;
	char *errmsg;
	char errmsgall[256];
	char errtemp[256];
	errno = WSAGetLastError();
	if (errno == WSAEWOULDBLOCK) {
		return;
	}
	errtemp[0] = '\0';
	errmsg = errtemp;
	for (i = 0; i < _countof(errdata); i++) {
		if (errno == errdata[i].eno) {
			errmsg = errdata[i].errmsg;
		}
	}
	sprintf(errmsgall, "error code = %d %s", errno, errmsg);
	MessageBox(m_hwnd, errmsgall, "WINSOCK ERROR!!", MB_OK);
	return;
}
////////////////////////////////////////
// データ送信 //
// p1 : ソケット //
// p2 : 送信バッファ //
////////////////////////////////////////
void tcpsnd(SOCKET s, char* sendbuf)
{
	char* buf; // 送信バッファ先頭アドレ
	int sendlen; // 送信完了データ長
	int len = strlen(sendbuf); // 送信バッファ長
	buf = sendbuf;
	do {
		sendlen = send(s, buf, len, 0);
		len -= sendlen;
		buf += sendlen;
	} while (len > 0);
}
//////////////////////////////////////////////////
// データ受信（ＣＲＬＦまで) //
// ＴＣＰストリームデータを受信する //
// 引数 //
// p1 : ソケット //
// p2 : 受信バッファ //
// 戻り値 //
// 　受信データ長 //
// (０以下 ： エラー発生) //
/////////////////////////////////////////////////
int tcprcv(SOCKET s, char* buf)
{
	char* bufstart = buf; // 受信バッファの先頭アドレスを保存
	int rcv = 0; // 受信バイト数
	while (1) {
		rcv = recv(s, buf, 1, 0); // １バイトづつ受信
		if (rcv <= 0) goto end; // 受信エラー発生
		if (*buf == '\r') { // 区切り文字判断（0x0d）
			rcv = recv(s, buf, 1, 0);
			if (rcv <= 0) goto end; // 受信エラー発生
			if (*buf == '\n') { // 区切り文字判断 (0x0a)
				break;
			}
			buf += rcv;
		}
		buf += rcv; // 受信先頭バイトを進める
	}
	*buf = 0; // 文字列の最後にＮＵＬＬをセットする
	printf("%s \n", bufstart);
end:
	return rcv;
}
void main()
{
	int sts;
	int zyankendata;
	// WINSOCK初期化
	sts = WSAStartup(MAKEWORD(2, 0), &m_wd);
	if (sts != 0) {
		errcom();
		return;
	}
	if (m_wd.wVersion != MAKEWORD(2, 0))
	{
		MessageBox(m_hwnd, "VERSION ERROR!", "", MB_OK);
		return;
	}
	// 自ソケット生成
	m_mysock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_mysock == INVALID_SOCKET) {
		errcom();
		return;
	}
	char inputip[128];
	// サーバーに接続する
	printf("\r\nサーバーのＩＰアドレスを入力してください\n");
	scanf("%s", inputip);
	m_serveraddr.sin_port = htons(m_portno);
	m_serveraddr.sin_family = AF_INET;
	m_serveraddr.sin_addr.s_addr = inet_addr(inputip);
	sts = connect(m_mysock, (sockaddr*)&m_serveraddr, sizeof(m_serveraddr));
	if (sts == SOCKET_ERROR) {
		errcom();
		return;
	}
	while (1) {
	input:
		printf("\r\nサーバーとジャンケンをします 0: グー　1: チョキ　2:パー　-1:終了\n");
		scanf("%d", &zyankendata);
		if (zyankendata == -1) break;
		switch (zyankendata) {
		case 0:
			strcpy(sendbuffer, "0\r\n");
			break;
		case 1:
			strcpy(sendbuffer, "1\r\n");
			break;
		case 2:
			strcpy(sendbuffer, "2\r\n");
			break;
		default:
			goto input;
		}
		int recvcnt;
		// データ送信
		tcpsnd(m_mysock, sendbuffer);
		recvcnt = tcprcv(m_mysock, recvbuffer);
		if (recvcnt <= 0) break;
		recvcnt = tcprcv(m_mysock, recvbuffer);
		if (recvcnt <= 0) break;
	}
	closesocket(m_mysock);
	WSACleanup();
}