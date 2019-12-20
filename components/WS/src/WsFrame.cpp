/**
 * @file WsFrame.cpp
 * @author Locha Mesh Developers (contact@locha.io)
 * @brief 
 * @version 0.1
 * @date 2019-11-26
 * 
 * @copyright Copyright (c) 2019 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 * 
 */

#include "WsFrame.h"

#include <esp_log.h>

namespace ws {

static const char* TAG = "WsFrame";

void dumpFrame(Frame frame)
{
    const char* opcode_str = nullptr;
    switch (frame.opcode) {
    case OPCODE_BINARY: {
        opcode_str = "BINARY";
        break;
    }
    case OPCODE_CONTINUE: {
        opcode_str = "CONTINUE";
        break;
    }
    case OPCODE_CLOSE: {
        opcode_str = "CLOSE";
        break;
    }
    case OPCODE_PING: {
        opcode_str = "PING";
        break;
    }
    case OPCODE_PONG: {
        opcode_str = "PONG";
        break;
    }
    case OPCODE_TEXT: {
        opcode_str = "TEXT";
        break;
    }
    default: {
        opcode_str = "Unknown";
        break;
    }
    }

    ESP_LOGD(TAG, "Frame: opcode = %s, rsv3 = %d, rsv1 = %d, rsv1 = %d,"
                  " fin = %d, len = %d, mask = %d",
        opcode_str,
        frame.rsv3,
        frame.rsv2,
        frame.rsv1,
        frame.fin,
        frame.len,
        frame.mask);
}

} // namespace ws
