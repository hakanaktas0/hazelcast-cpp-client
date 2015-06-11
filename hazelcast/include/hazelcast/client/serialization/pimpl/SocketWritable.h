/*
 * Copyright (c) 2008-2015, Hazelcast, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * SocketReadable.h
 *
 *  Created on: Mar 17, 2015
 *      Author: ihsan
 */

#ifndef HAZELCAST_CLIENT_SERIALIZATION_PIMPL_SOCKETWRITABLE_H_
#define HAZELCAST_CLIENT_SERIALIZATION_PIMPL_SOCKETWRITABLE_H_

namespace hazelcast {
    namespace util {
        class ByteBuffer;
    }
    namespace client {
        namespace serialization {
            namespace pimpl {
                class SocketWritable {
                    /**
                     * Asks the SocketWritable to write its content to the destination ByteBuffer.
                     *
                     * @param destination the ByteBuffer to write to.
                     * @return todo: unclear what return value means.
                     */
                    virtual bool writeTo(util::ByteBuffer &destination) = 0;
                };
            }
        }
    }
}



#endif /* HAZELCAST_CLIENT_SERIALIZATION_PIMPL_SOCKETWRITABLE_H_ */