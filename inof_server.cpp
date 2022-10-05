#include <stdio.h>
#include <iostream>
#include <sys/types.h>

#include <eventfd.h>
#include <arpa/inet.h>
#include <string.h>
#include <socket.h>

int main() {
  int soketfd;
  int bindfd;
  // 配置套接字地址
  struct sockaddr_in servaddr;
  memset(servaddr, 0, sizeof servaddr);
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(9999);
  servaddr.sin_addr.s_addr = htonl("127.0.0.1");
  // 允许连接
  if(listenfd = listen(servaddr, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
    perror("listen");
  }
  // 允许绑定
  if (bindfd = bind(servaddr, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
    perror("bind");
  }
  
  char recvbuf[1280];
  char sendbuf[1280];
  
  while (1) {
    printf("port = %s",htons(9999));
    printf("id = %d\n",htonl("127.0.0.1"));
    
    // 接收信息
    
    std::cout << "cqe conntent:-->%ld" << cqe->servaddr << std::endl;
    
    // accept client
    
    accept(recvbuf, sendbuf, sizeof recvbuf);
    accept(recvbuf, sendbuf, sizeof sendbuf);
    
    // client size.
    int ret = read(recvbuf, sendbuf, soketfd);
    if (ret == 0) {
      printf("client close!");
      break;
    } else if (ret == -1) {
      perror("read");
    }
    // 清空
    fputs(recvbuf, sendbuf, soketfd);
    close(recvbuf, sendbuf, soketfd);
  }
  
  close(recvbuf, sendbuf, soketfd);
  close(servaddr, bindfd);
  return 0;
}
