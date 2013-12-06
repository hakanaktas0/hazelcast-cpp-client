//
// Created by sancar koyunlu on 7/1/13.
// Copyright (c) 2013 hazelcast. All rights reserved.

#ifndef HAZELCAST_TestCustomSerializableWithBase
#define HAZELCAST_TestCustomSerializableWithBase


#include "hazelcast/client/serialization/Serializer.h"
#include "customSerialization/TestCustomXSerializable.h"

namespace hazelcast {
    namespace client {
        namespace test {

            class HAZELCAST_API TestCustomPersonSerializer : public serialization::Serializer<TestCustomPerson> {
            public:

                void write(hazelcast::client::serialization::ObjectDataOutput & out, const TestCustomPerson& object);

                void read(hazelcast::client::serialization::ObjectDataInput & in, TestCustomPerson& object);

                int getTypeId() const;
            };
        }
    }
}


#endif //HAZELCAST_TestCustomSerializableWithBase

