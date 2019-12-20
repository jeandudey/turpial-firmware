/**
 * @file WsFrame.h
 * @author Locha Mesh Developers (contact@locha.io)
 * @brief
 * @version 0.1
 * @date 2019-12-20
 *
 * @copyright Copyright (c) 2019 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 *
 */

#ifndef WS_FRAME_H
#define WS_FRAME_H

#include <cstdint>

namespace ws {

static const uint8_t OPCODE_CONTINUE = 0x00; /*!< Continuation frame. */
static const uint8_t OPCODE_TEXT = 0x01;     /*!< Text frame. */
static const uint8_t OPCODE_BINARY = 0x02;   /*!< Binary frame. */
static const uint8_t OPCODE_CLOSE = 0x08;    /*!< Connecton close. */
static const uint8_t OPCODE_PING = 0x09;     /*!< Ping. */
static const uint8_t OPCODE_PONG = 0x0a;     /*!< Pong. */

/**
 * @brief A WebSocket frame.
 */
struct Frame {
    // Byte 0
    std::uint8_t opcode : 4; // [7:4]
    std::uint8_t rsv3 : 1;   // [3]
    std::uint8_t rsv2 : 1;   // [2]
    std::uint8_t rsv1 : 1;   // [1]
    std::uint8_t fin : 1;    // [0]

    // Byte 1
    std::uint8_t len : 7;  // [7:1]
    std::uint8_t mask : 1; // [0]
};


/**
 * @brief Dump the content of the WebSocket frame for debugging.
 *
 * @param[in] frame: The frame to dump.
 */
void dumpFrame(Frame frame);

} // namespace ws

#endif // WS_FRAME_H
