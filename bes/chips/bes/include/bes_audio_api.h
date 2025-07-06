/***************************************************************************
 *
 * Copyright 2015-2024 BES.
 * All rights reserved. All unpublished rights reserved.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of BES.
 *
 * Use of this work is governed by a license granted by BES.
 * This work contains confidential and proprietary information of
 * BES. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/

#ifndef _BES_AUDIO_API_H_
#define _BES_AUDIO_API_H_

#include <nuttx/audio/audio.h>
#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#define CONFIG_RPMSG_MSG_DATA_LEN 32
enum RPMSG_AUD_CMD {
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

struct rpmsg_audio_msg_header{
    uint8_t command;
    char result;
    uint16_t msg_len;
};

struct rpmsg_audio_msg{
    struct rpmsg_audio_msg_header header;
    uint8_t data[CONFIG_RPMSG_MSG_DATA_LEN];
};

static inline int bes_audio_rpmsg_set_msg_cmdandlen(struct rpmsg_audio_msg_header *header, enum RPMSG_AUD_CMD cmd, uint16_t msg_len)
{
  if (header){
    header->command = cmd;
    header->msg_len = msg_len;
    header->result = EPERM;
  }
  return 0;
}

static inline int bes_audio_rpmsg_set_msg_result(struct rpmsg_audio_msg_header *header, char result)
{
  if (header){
    header->result = result;
  }
  return 0;
}

static inline int bes_audio_rpmsg_set_data(struct rpmsg_audio_msg *msg, uint8_t *data, uint16_t data_len)
{
  int ret = EPERM;
  if (data_len > CONFIG_RPMSG_MSG_DATA_LEN){
    auderr("[BES AUDIO]: datalen %d > max len %d", data_len, CONFIG_RPMSG_MSG_DATA_LEN);
    data_len = CONFIG_RPMSG_MSG_DATA_LEN;
  }
  if (msg){
    memcpy(msg->data, data, data_len);
    ret = OK;
  }
  return OK;
}

int bes_audio_local_initialize(FAR struct audio_lowerhalf_s *lowerhalf_audio);
int bes_audio_server_initialize(FAR struct audio_lowerhalf_s *lowerhalf_audio);
int bes_audio_client_initialize(void);

int bes_audio_rpmsg_set_msg_cmdandlen(struct rpmsg_audio_msg_header *header, enum RPMSG_AUD_CMD cmd, uint16_t msg_len);
int bes_audio_rpmsg_set_msg_result(struct rpmsg_audio_msg_header *header, char result);

#undef EXTERN
#ifdef __cplusplus
}
#endif
#endif
