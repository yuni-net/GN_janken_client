struct errdata_t {
	int		eno;
	char*	errmsg;
};
struct errdata_t errdata[] = {

WSANOTINITIALISED,
//	"A successful WSAStartup must occur before using this function."
	"この API を使う前に WSAStartup の呼び出しが正常終了していることが必要です。"
,WSAENETDOWN,	
//	"The Windows Sockets implementation has detected that the network "
//	"subsystem has failed."
	"Windows ソケットの実装が、ネットワーク サブシステムの異常を検出しました。"
,WSAENOTCONN,	
//	"The socket is not connected."
	"ソケットが接続されていません。"
,WSAEINTR,	
//	"The (blocking) call was canceled using WSACancelBlockingCall."
	"(ブロッキング)呼び出しは WSACancelBlockingCall によりキャンセルされました。"
,WSAEINPROGRESS,	
//	"A blocking Windows Sockets operation is in progress."
	"実行中の Windows ソケット呼び出しがブロッキングされています。"
,WSAENOTSOCK,	
//	"The descriptor is not a socket."
	"記述子がソケットではありません。"
,WSAEOPNOTSUPP,	
//	"MSG_OOB was specified, but the socket is not of type SOCK_STREAM."
	"参照しているソケットは、接続指向のサービスをサポートするタイプではありません。"
,WSAESHUTDOWN,	
//	"The socket has been shut down; it is not possible to recv on a socket"
//	" after shutdown has been invoked with how set to 0 or 2."
	"ソケットはシャット ダウンしています。"
,WSAEWOULDBLOCK,	
//	"The socket is marked as nonblocking and the receive operation would block."
	"ソケットは非ブロッキングになっていて、受け入れる接続がありません。"
,WSAEMSGSIZE,	
//	"The datagram was too large to fit into the specified buffer and was truncated."
	"データグラムが長すぎて、指定したバッファに入りきらないため、切り詰められました。"
,WSAEINVAL,	
//	"The socket has not been bound with bind."
	"指定したパラメータの 1 つが無効です。"
,WSAECONNABORTED,	
//	"The virtual circuit was aborted due to timeout or other failure."
	"タイムアウトまたはその他の障害により、仮想回路はアボートされました。"
,WSAECONNRESET,	
//	"The virtual circuit was reset by the remote side."
	"リモート側から仮想回路がリセットされました。"
,WSAEAFNOSUPPORT,	
//	"The specified address family is not supported."
	"指定したアドレス ファミリはサポートしていません。"
,WSAEMFILE,	
//	"No more file descriptors are available."
	"利用できるファイル記述子がありません。"
,WSAENOBUFS,	
//	"No buffer space is available. The socket cannot be created."
	"利用できるバッファ領域がありません。"
,WSAEPROTONOSUPPORT,	
//	"The specified protocol is not supported."
	"指定したプロトコルはサポートしていません。"
,WSAEPROTOTYPE,	
//	"The specified protocol is the wrong type for this socket."
	"指定したプロトコルの型が正しくありません。"
,WSAESOCKTNOSUPPORT,	
//	"The specified socket type is not supported in this address family."
	"指定したソケットの方は、このアドレス ファミリではサポートしていません。"
,WSAEADDRINUSE,	
//	"The specified address is already in use. (See the SO_REUSEADDR"
//	" socket option under setsockopt.)"
	"指定したアドレスは使用中です。"
,WSAEFAULT,	
//	"The namelen argument is too small (less than the size of a struct sockaddr)."
	"引数が不正です。"
,WSAEADDRINUSE,	
//	"The specified address is already in use."
	"指定したアドレスは使用中です。"
,WSAEADDRNOTAVAIL,	
//	"The specified address is not available from the local computer."
	"指定したアドレスはローカル コンピュータからは利用できません。"
,WSAECONNREFUSED,	
//	"The attempt to connect was forcefully rejected."
	"接続を試みましたが、強制的に拒否されました。"
,WSAEDESTADDRREQ,	
//	"A destination address is required."
	"宛先アドレスが必要です。"
,WSAEISCONN,	
//	"The socket is already connected."
	"ソケットは既に接続されています。"
,WSAENETUNREACH,	
//	"The network can't be reached from this host at this time."
	"現時点では、このホストからネットワークに到達できません。"
,WSAETIMEDOUT,	
//	"Attempt to connect timed out without establishing a connection"
	"接続を試みましたが、タイムアウトしました。接続は確立していません。"
,WSAEACCES,	
//	"The requested address is a broadcast address, but the appropriate flag was not set."
	"要求したアドレスはブロードキャスト アドレスですが、適切なフラグが設定されていませんでした。"
,WSAENETRESET,	
//	"The connection must be reset because the Windows Sockets implementation dropped it."
	"Windows ソケットの実装が接続をドロップしたので、接続をリセットする必要があります。"
};
