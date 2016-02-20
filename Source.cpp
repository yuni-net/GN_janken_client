#include <winsock2.h>
#include "wsock32error.h"
#include <stdio.h>
#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32")
WSADATA m_wd; // �v�r�`�r�s�`�q�s�t�o�p
u_short m_portno = 20045; // �|�[�g�ԍ�
SOCKET m_mysock; // �\�P�b�g�ԍ�
sockaddr_in m_myaddr; // �����̃A�h���X
sockaddr_in m_serveraddr; // �T�[�o�[�A�h���X
HWND m_hwnd = 0;
char sendbuffer[1024]; // ���M�o�b�t�@
char recvbuffer[1024]; // ���M�o�b�t�@
					   //////////////////////////////////////////
					   // �\�P�b�g�G���[���b�Z�[�W�\������ //
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
// �f�[�^���M //
// p1 : �\�P�b�g //
// p2 : ���M�o�b�t�@ //
////////////////////////////////////////
void tcpsnd(SOCKET s, char* sendbuf)
{
	char* buf; // ���M�o�b�t�@�擪�A�h��
	int sendlen; // ���M�����f�[�^��
	int len = strlen(sendbuf); // ���M�o�b�t�@��
	buf = sendbuf;
	do {
		sendlen = send(s, buf, len, 0);
		len -= sendlen;
		buf += sendlen;
	} while (len > 0);
}
//////////////////////////////////////////////////
// �f�[�^��M�i�b�q�k�e�܂�) //
// �s�b�o�X�g���[���f�[�^����M���� //
// ���� //
// p1 : �\�P�b�g //
// p2 : ��M�o�b�t�@ //
// �߂�l //
// �@��M�f�[�^�� //
// (�O�ȉ� �F �G���[����) //
/////////////////////////////////////////////////
int tcprcv(SOCKET s, char* buf)
{
	char* bufstart = buf; // ��M�o�b�t�@�̐擪�A�h���X��ۑ�
	int rcv = 0; // ��M�o�C�g��
	while (1) {
		rcv = recv(s, buf, 1, 0); // �P�o�C�g�Â�M
		if (rcv <= 0) goto end; // ��M�G���[����
		if (*buf == '\r') { // ��؂蕶�����f�i0x0d�j
			rcv = recv(s, buf, 1, 0);
			if (rcv <= 0) goto end; // ��M�G���[����
			if (*buf == '\n') { // ��؂蕶�����f (0x0a)
				break;
			}
			buf += rcv;
		}
		buf += rcv; // ��M�擪�o�C�g��i�߂�
	}
	*buf = 0; // ������̍Ō�ɂm�t�k�k���Z�b�g����
	printf("%s \n", bufstart);
end:
	return rcv;
}
void main()
{
	int sts;
	int zyankendata;
	// WINSOCK������
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
	// ���\�P�b�g����
	m_mysock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_mysock == INVALID_SOCKET) {
		errcom();
		return;
	}
	char inputip[128];
	// �T�[�o�[�ɐڑ�����
	printf("\r\n�T�[�o�[�̂h�o�A�h���X����͂��Ă�������\n");
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
		printf("\r\n�T�[�o�[�ƃW�����P�������܂� 0: �O�[�@1: �`���L�@2:�p�[�@-1:�I��\n");
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
		// �f�[�^���M
		tcpsnd(m_mysock, sendbuffer);
		recvcnt = tcprcv(m_mysock, recvbuffer);
		if (recvcnt <= 0) break;
		recvcnt = tcprcv(m_mysock, recvbuffer);
		if (recvcnt <= 0) break;
	}
	closesocket(m_mysock);
	WSACleanup();
}