//
// Created by Jean-Adrien DOMAGE on 04/12/2017.
// jean-adrien.domage@laposte.net
//
// Copyright (c) 2017 Billys Studio. All rights reserved.
//

#ifndef ZIAAPI_IMEDIATOR_HPP
#define ZIAAPI_IMEDIATOR_HPP

#include <vector>
#include "../ziaapi/ZiaApi.hpp"

namespace   core {

    class IMediator {
    public:
        virtual ~IMediator() {return;}

        virtual int                             scheduler() = 0;
        virtual void                            setData(void *) = 0;
        virtual void                            *getData(void) = 0;
        virtual std::vector<module::IModule*>   &getHooks(void) = 0;
    };
}

#endif //ZIAAPI_IMEDIATOR_HPP
