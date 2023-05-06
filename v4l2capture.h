#ifndef _V4L2CAPTURE_H_
#define _V4L2CAPTURE_H_
#include <iostream>
#include <string>
#include <linux/videodev2.h>

#include "sysio.h"
#include "nvbuf_utils.h"

using namespace std;


class V4L2Capture{
public:
    V4L2Capture();
    bool initialize();
    bool prepare_buffers();
private:
    const static int V4L2_BUFFERS_NUM = 4;
    string devname;
    int fd;
    unsigned int pixfmt;
    unsigned int width;
    unsigned int height;
    // this deinterlace fd used for possible deinterlacing
    // if video is progressive this contain last fd of g_buff 
    int deinterlace_buf_fd;

    /* User accessible pointer */
    unsigned char * start[V4L2_BUFFERS_NUM];
    /* Buffer length */
    unsigned int size[V4L2_BUFFERS_NUM];
    /* File descriptor of NvBuffer */
    int dmabuff_fd[V4L2_BUFFERS_NUM];
};

#endif