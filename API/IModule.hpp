//
// Created by Jean-Adrien DOMAGE on 04/12/2017.
// jean-adrien.domage@laposte.net
//
// Copyright (c) 2017 Billys Studio. All rights reserved.
//

#ifndef ZIAAPI_IMODULE_HPP
#define ZIAAPI_IMODULE_HPP

#include "../ziaapi/ZiaApi.hpp"

namespace module {

    enum e_type {
        REQUIRED = 0,
        REQUISITE = 1,
        OPTIONAL = 2
    };

    using Type = e_type;

    class IModule {
    public:
        virtual ~IModule() {return;}

        virtual void  exec(protocol::IRequestHandler *) = 0;
        virtual const int  getType(void) const = 0;
        virtual void SetType(const module::Type) = 0;
    };

}

#endif //ZIAAPI_IMODULE_HPP
