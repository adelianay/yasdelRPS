//
// Created by DKU on 2019-06-19.
//
#include <string.h>
#include<stdio.h>
#include<jni.h>
#include<stdlib.h>
#include "com_example_yasdelrps_MainActivity.h"
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<sys/mman.h>
#include<asm/unistd.h>
#include<errno.h>
#include<linux/input.h>

ssize_t mywrite(int fd, const void *buf, ssize_t count)
{
    return syscall(__NR_write, fd, buf, count);
}

JNIEXPORT jint JNICALL Java_com_example_yasdelrps_MainActivity_JNISound
  (JNIEnv *env, jobject jobj, jint value)
  {
    int fd;
    ssize_t ret;
    int data = value;

    fd = open("/dev/fpga_piezo",O_WRONLY);
    if(fd<0) return -errno;

    ret = mywrite(fd, &data, 1);
    close(fd);

    if(ret ==1)return 0;
    return -1;
  }

