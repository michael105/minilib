//+depends recvfrom
//+def
int recv(int sockfd, void *buf, size_t len, int flags){
	return( recvfrom(sockfd, buf, len, flags, 0, 0) );
}
