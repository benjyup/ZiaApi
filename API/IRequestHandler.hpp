//
// Created by Jean-Adrien DOMAGE on 05/12/2017.
// jean-adrien.domage@laposte.net
//
// Copyright (c) 2017 Billys Studio. All rights reserved.
//

#ifndef ZIAAPI_IREQUESTHANDLER_HPP
#define ZIAAPI_IREQUESTHANDLER_HPP

#include <string>
#include <map>

//
//  IRequestHandler
//
//  The Request Handler is provide by the server and it is given as exec() paramater
//  to the modules.
//  This is the most critical Interface for this API, before reading make sure to get all http Request and
//  Response code/format in mind
//

namespace protocol {

    struct  s_requestHandler {

        struct s_request {
            //
            std::string                         command;
            std::string                         body;
            std::map<std::string, std::string>  header;
            //
            //  This Getter allow you to access to the Request data formatted as :
            //
            //  Request Command : as a string (GET /index.html HTTP/1.1)
            //  Request Header : as a map (<key : as string> | <value : as string>)
            //  Request Body : as a string
            //
        };

        struct s_answer {
            int                                 statusCode;
            std::string                         textCode;
            std::string                         command;
            std::string                         body;
            std::map<std::string, std::string>  header;

        };



        struct s_request    req;
        struct s_answer     answer;
    };

    using t_request = s_requestHandler;

    class IRequestHandler {
    public:

        virtual ~IRequestHandler() { return; }

        //
        //  Request Data Getter
        //

        //
        virtual std::string &getRequestCommand(void) = 0;
        virtual std::map<std::string, std::string> &getRequestHeader(void) = 0;
        virtual std::string &getRequestBody(void) = 0;
        //
        //  This Getter allow you to access to the Request data formatted as :
        //
        //  Request Command : as a string (GET /index.html HTTP/1.1)
        //  Request Header : as a map (<key : as string> | <value : as string>)
        //  Request Body : as a string
        //

        //
        //  Server Data Access
        //

        //
        virtual std::string &getServerInfo(void) = 0;
        //
        //  This getter allow you to get the generic server info, the format is free
        //  For example if you do not recognize you'r server here (has it could implement extra/overloading method for your modules)
        //  you can use this String as a default value for the server field in the response handler
        //


        //
        //  Response Data Setter/getter
        //

        //
        //  Value in Request Status response field should have some default value.
        //  For example the return code at the beginning should be 200 and could be modify by a module in case of error
        //
        virtual bool isOptional(void) = 0;
        virtual void setStatusCode(const unsigned int) = 0;
        virtual void setTextCode(const char *) = 0;

        //
        virtual std::map<std::string, std::string> &getResponsetHeader(void) = 0;
        virtual std::string &getResponseBody(void) = 0;
        //
        //  The same as the request
        //

    };

}

#endif //ZIAAPI_IREQUESTHANDLER_HPP
