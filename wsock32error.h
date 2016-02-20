struct errdata_t {
	int		eno;
	char*	errmsg;
};
struct errdata_t errdata[] = {

WSANOTINITIALISED,
//	"A successful WSAStartup must occur before using this function."
	"���� API ���g���O�� WSAStartup �̌Ăяo��������I�����Ă��邱�Ƃ��K�v�ł��B"
,WSAENETDOWN,	
//	"The Windows Sockets implementation has detected that the network "
//	"subsystem has failed."
	"Windows �\�P�b�g�̎������A�l�b�g���[�N �T�u�V�X�e���ُ̈�����o���܂����B"
,WSAENOTCONN,	
//	"The socket is not connected."
	"�\�P�b�g���ڑ�����Ă��܂���B"
,WSAEINTR,	
//	"The (blocking) call was canceled using WSACancelBlockingCall."
	"(�u���b�L���O)�Ăяo���� WSACancelBlockingCall �ɂ��L�����Z������܂����B"
,WSAEINPROGRESS,	
//	"A blocking Windows Sockets operation is in progress."
	"���s���� Windows �\�P�b�g�Ăяo�����u���b�L���O����Ă��܂��B"
,WSAENOTSOCK,	
//	"The descriptor is not a socket."
	"�L�q�q���\�P�b�g�ł͂���܂���B"
,WSAEOPNOTSUPP,	
//	"MSG_OOB was specified, but the socket is not of type SOCK_STREAM."
	"�Q�Ƃ��Ă���\�P�b�g�́A�ڑ��w���̃T�[�r�X���T�|�[�g����^�C�v�ł͂���܂���B"
,WSAESHUTDOWN,	
//	"The socket has been shut down; it is not possible to recv on a socket"
//	" after shutdown has been invoked with how set to 0 or 2."
	"�\�P�b�g�̓V���b�g �_�E�����Ă��܂��B"
,WSAEWOULDBLOCK,	
//	"The socket is marked as nonblocking and the receive operation would block."
	"�\�P�b�g�͔�u���b�L���O�ɂȂ��Ă��āA�󂯓����ڑ�������܂���B"
,WSAEMSGSIZE,	
//	"The datagram was too large to fit into the specified buffer and was truncated."
	"�f�[�^�O�������������āA�w�肵���o�b�t�@�ɓ��肫��Ȃ����߁A�؂�l�߂��܂����B"
,WSAEINVAL,	
//	"The socket has not been bound with bind."
	"�w�肵���p�����[�^�� 1 �������ł��B"
,WSAECONNABORTED,	
//	"The virtual circuit was aborted due to timeout or other failure."
	"�^�C���A�E�g�܂��͂��̑��̏�Q�ɂ��A���z��H�̓A�{�[�g����܂����B"
,WSAECONNRESET,	
//	"The virtual circuit was reset by the remote side."
	"�����[�g�����牼�z��H�����Z�b�g����܂����B"
,WSAEAFNOSUPPORT,	
//	"The specified address family is not supported."
	"�w�肵���A�h���X �t�@�~���̓T�|�[�g���Ă��܂���B"
,WSAEMFILE,	
//	"No more file descriptors are available."
	"���p�ł���t�@�C���L�q�q������܂���B"
,WSAENOBUFS,	
//	"No buffer space is available. The socket cannot be created."
	"���p�ł���o�b�t�@�̈悪����܂���B"
,WSAEPROTONOSUPPORT,	
//	"The specified protocol is not supported."
	"�w�肵���v���g�R���̓T�|�[�g���Ă��܂���B"
,WSAEPROTOTYPE,	
//	"The specified protocol is the wrong type for this socket."
	"�w�肵���v���g�R���̌^������������܂���B"
,WSAESOCKTNOSUPPORT,	
//	"The specified socket type is not supported in this address family."
	"�w�肵���\�P�b�g�̕��́A���̃A�h���X �t�@�~���ł̓T�|�[�g���Ă��܂���B"
,WSAEADDRINUSE,	
//	"The specified address is already in use. (See the SO_REUSEADDR"
//	" socket option under setsockopt.)"
	"�w�肵���A�h���X�͎g�p���ł��B"
,WSAEFAULT,	
//	"The namelen argument is too small (less than the size of a struct sockaddr)."
	"�������s���ł��B"
,WSAEADDRINUSE,	
//	"The specified address is already in use."
	"�w�肵���A�h���X�͎g�p���ł��B"
,WSAEADDRNOTAVAIL,	
//	"The specified address is not available from the local computer."
	"�w�肵���A�h���X�̓��[�J�� �R���s���[�^����͗��p�ł��܂���B"
,WSAECONNREFUSED,	
//	"The attempt to connect was forcefully rejected."
	"�ڑ������݂܂������A�����I�ɋ��ۂ���܂����B"
,WSAEDESTADDRREQ,	
//	"A destination address is required."
	"����A�h���X���K�v�ł��B"
,WSAEISCONN,	
//	"The socket is already connected."
	"�\�P�b�g�͊��ɐڑ�����Ă��܂��B"
,WSAENETUNREACH,	
//	"The network can't be reached from this host at this time."
	"�����_�ł́A���̃z�X�g����l�b�g���[�N�ɓ��B�ł��܂���B"
,WSAETIMEDOUT,	
//	"Attempt to connect timed out without establishing a connection"
	"�ڑ������݂܂������A�^�C���A�E�g���܂����B�ڑ��͊m�����Ă��܂���B"
,WSAEACCES,	
//	"The requested address is a broadcast address, but the appropriate flag was not set."
	"�v�������A�h���X�̓u���[�h�L���X�g �A�h���X�ł����A�K�؂ȃt���O���ݒ肳��Ă��܂���ł����B"
,WSAENETRESET,	
//	"The connection must be reset because the Windows Sockets implementation dropped it."
	"Windows �\�P�b�g�̎������ڑ����h���b�v�����̂ŁA�ڑ������Z�b�g����K�v������܂��B"
};
