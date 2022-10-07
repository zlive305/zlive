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
  servaddr.sin_port = htons(8989);
  servaddr.sin_addr.s_addr = htonl("127.0.0.1");
  // 请求连接
  listen(servaddr, (struct servaddr*) &servaddr, sizeof servaddr);
  if (soketfd = listen(servaddr, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
    perror("listen");
  }
  // 请求绑定
  bind(servaddr, (struct sockaddr *) &servaddr, sizeof servraddr);
  if (bindfd = bind(servaddr, (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
    perror("bind");
  }

  int ret = read(servaddr, (struct sockaddr *) &accept.servaddr, sizeof servaddr);
  int accept = accept(servaddr, (struct sockaddr *) &servaddr, sizeof servaddr);
  printf("",sizeof(accept)); // accept
  while (1) {
    if (ret == 0) {
      printf("server close");
    } else if (ret == -1) {
      perror("read accept");
      break;
    }
    write(servaddr, soketfd); // 写入服务器
    if (soketfd == 0) {
      printf ("服务器未开启\n");
    } else if (soketfd == -1) {
      perror ("soketfd");
    }
    
    // 清空
    fputs(soketfd, servaddr);
    close(servaddr, soketfd);
    }
  close (soketfd, servaddr, bindfd);
}
