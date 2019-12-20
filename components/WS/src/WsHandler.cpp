/**
 * @file WsHandler.h
 * @author Locha Mesh Developers (contact@locha.io)
 * @brief
 * @version 0.1
 * @date 2019-12-20
 *
 * @copyright Copyright (c) 2019 Locha Mesh project developers
 * @license Apache 2.0, see LICENSE file for details
 *
 */

#ifndef WS_DEFAULTHANDLER_H
#define WS_DEFAULTHANDLER_H

#include "WebSocket.h"
#include "WsHandler.h"

#include <esp_log.h>

namespace ws {

static const char* TAG = "WsHandler";

Handler::~Handler()
{
}

void Handler::onClose(WebSocket* websocket)
{
    ESP_LOGI(TAG, "Default onClose handler.");
}

void Handler::onMessage(WebSocketInputStreambuf* input, WebSocket* websocket)
{
    ESP_LOGI(TAG, "Default onMessage handler");
}

void Handler::onError(std::string error)
{
    ESP_LOGI(TAG, " onError: %s", error.c_str());
}

} // namespace ws

#endif
