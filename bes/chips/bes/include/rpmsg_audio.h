#ifndef __INCLUDE_RPMSG_AUDIO_H
#define __INCLUDE_RPMSG_AUDIO_H

#define CONFIG_RPMSG_MSG_DATA_LEN 32
enum
{
    RPMSG_AUD_CMD_CONFIGURE,
    RPMSG_AUD_CMD_GET_CAPS,
    RPMSG_AUD_CMD_GET_BUF_INFO,
    RPMSG_AUD_CMD_SET_BUF_INFO,
    RPMSG_AUD_CMD_START,
    RPMSG_AUD_CMD_STOP,
    RPMSG_AUD_CMD_SHUTDOWN,
    RPMSG_AUD_CMD_ENQUEUE,
    RPMSG_AUD_CMD_CAPTURE_DATA,
    RPMSG_AUD_CMD_CALLBACK_DEQUEUE,
    RPMSG_AUD_CMD_CALLBACK_COMPLETE,
    RPMSG_AUD_CMD_LOG,
    RPMSG_AUD_CMD_SET_PARAMTER,
    RPMSG_AUD_CMD_PAUSE,
    RPMSG_AUD_CMD_RESUME,
    RPMSG_AUD_CMD_NUM,
};

struct rpmsg_aud_msg_header
{
    uint8_t command;
    uint16_t len;
    int result;
    void *ptr[2];
};

struct rpmsg_aud_msg
{
    struct rpmsg_aud_msg_header header;
    uint8_t data[CONFIG_RPMSG_MSG_DATA_LEN];
};

#endif
