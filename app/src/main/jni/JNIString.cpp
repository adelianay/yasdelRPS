//
// Created by DKU on 2019-05-29.
//
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<asm/unistd.h>
#include<stdlib.h>
#include "com_example_yasdelrps_MainActivity.h"
#include <errno.h>

JNIEXPORT jint JNICALL Java_com_example_yasdelrps_MainActivity_JNIString
        (JNIEnv *env, jobject jobj, jint LED) {
    int fd = open("/dev/fpga_led",O_RDWR);
    write(fd,&LED,sizeof(LED));
    close(fd);
    return 0;
};