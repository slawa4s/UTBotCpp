/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 */

#include <unistd.h>

int check_password(int fd) {
  char buf[5];
  if (read(fd, buf, 5) != -1) {
    if (buf[0] == 'h' && buf[1] == 'e' &&
	buf[2] == 'l' && buf[3] == 'l' &&
	buf[4] == 'o')
      return 1;
  }
  return 0;
}

int long_read() {
    char buf[1000];
    if (read(0, buf, 1000) == 1000) {
        return 0;
    } else {
        return 1;
    }
}