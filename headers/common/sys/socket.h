#ifndef	SYS_SOCKET_H
#define	SYS_SOCKET_H


struct sockaddr {
	sa_family_t sa_family;
	char sa_data[14];
};



#endif
