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

#ifndef WS_HANDLER_H
#define WS_HANDLER_H

class WebSocketInputStreambuf;
class WebSocket;

namespace ws {

/**
 * @brief Stub handler, does nothing.
 */
class Handler
{
public:
    /**
     * @brief Destructor.
     */
    virtual ~Handler();

    /**
     * @brief The onClose handler.
     *
     * If no overriding handler is provided for the "close" event, this method
     * is called.
     */
    virtual void onClose(WebSocket* websocket);

    /**
     * @brief The onMessage handler.
     *
     * If no overriding handler is provided for the "message" event, this method
     * is called.
     *
     * A particularly useful pattern for using onMessage is:
     *
     * @code{cpp}
     * std::stringstream buffer;
     * buffer << input;
     * @endcode
     *
     * This will read the whole message into the string stream.
     */
    virtual void onMessage(WebSocketInputStreambuf* input, WebSocket* websocket);

    /**
     * @brief The onError handler.
     *
     * If no overriding handler is provided for the "error" event, this method
     * is called.
     */
    virtual void onError(std::string error);
};

/**
 * @brief Stub handler, does nothing.
 */
class DefaultHandler : public Handler
{
public:
    /**
     * @briref Construct a DefaultHandler object.
     */
    DefaultHandler() {}
};

} // namespace

#endif
