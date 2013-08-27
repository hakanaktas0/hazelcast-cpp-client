//
// Created by sancar koyunlu on 8/27/13.
// Copyright (c) 2013 hazelcast. All rights reserved.




#ifndef HAZELCAST_ClientSerializationTest
#define HAZELCAST_ClientSerializationTest

#include "iTest.h"

namespace hazelcast {
    namespace client {
        namespace test {

            class ClientSerializationTest : public iTest::iTestFixture<ClientSerializationTest> {
            public:
                ClientSerializationTest();

                void beforeClass();

                void afterClass();

                void beforeTest();

                void afterTest();

                void addTests();

                void testCustomSerialization();

                void testRawData();

                void testIdentifiedDataSerializable();

                void testRawDataWithoutRegistering();

                void testInvalidWrite();

                void testInvalidRead();

                void testDifferentVersions();

                void testCompression();

                int write();

                void read(int size);

                void testSerializationViaFile();

                void testBasicFunctionality();
            };
        }
    }
}


#endif //HAZELCAST_ClientSerializationTest