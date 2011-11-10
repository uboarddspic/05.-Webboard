/*
 * Prototype definitions for socket
 */
#ifndef	__SOCKET_h
#define	__SOCKET_h

void close(unsigned char sock);
void disconnect(unsigned char sock);
unsigned char socket(unsigned char sock,unsigned char eth_protocol,unsigned int tcp_port);
unsigned char listen(unsigned char sock);
unsigned int send(unsigned char sock,const unsigned char *buf,unsigned int buflen);
unsigned int recv(unsigned char sock,unsigned char *buf,unsigned int buflen);
unsigned int recv_size(void);
int strindex(char *s,char *t);

#endif
