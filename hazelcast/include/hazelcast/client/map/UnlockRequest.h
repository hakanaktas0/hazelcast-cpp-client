//
// Created by sancar koyunlu on 5/23/13.
// Copyright (c) 2013 hazelcast. All rights reserved.
#ifndef HAZELCAST_UNLOCK_REQUEST
#define HAZELCAST_UNLOCK_REQUEST

#include "hazelcast/client/impl/PortableRequest.h"
#include "hazelcast/client/serialization/pimpl/Data.h"
#include <string>

namespace hazelcast {
    namespace client {
        namespace map {
            class HAZELCAST_API UnlockRequest : public impl::PortableRequest {
            public:

                UnlockRequest(const std::string &name, serialization::pimpl::Data &key, long threadId, bool force);

                int getFactoryId() const;

                int getClassId() const;

                void write(serialization::PortableWriter &writer) const;


            private:
                std::string name;
                serialization::pimpl::Data key;
                long threadId;
                bool force;
            };
        }
    }
}

#endif //HAZELCAST_MAP_PUT_REQUEST
