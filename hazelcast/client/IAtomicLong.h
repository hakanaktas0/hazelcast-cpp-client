#ifndef HAZELCAST_ATOMIC_NUMBER
#define HAZELCAST_ATOMIC_NUMBER

#include <string>
#include "ClientService.h"

namespace hazelcast {
    namespace client {

        class impl::ClientService;

        class IAtomicLong {
        public:

            IAtomicLong(std::string instanceName, impl::ClientService& clientService);

            IAtomicLong(const IAtomicLong& rhs);

            ~IAtomicLong();

            /**
             * Returns the name of this IAtomicLong instance.
             *
             * @return name of this instance
             */
            std::string getName() const;

            /**
             * Atomically adds the given value to the current value.
             *
             * @param delta the value to add
             * @return the updated value
             */
            long addAndGet(long delta);

            /**
             * Atomically sets the value to the given updated value
             * only if the current value {@code ==} the expected value.
             *
             * @param expect the expected value
             * @param update the new value
             * @return true if successful; or false if the actual value
             *         was not equal to the expected value.
             */
            bool compareAndSet(long expect, long update);

            /**
             * Atomically decrements the current value by one.
             *
             * @return the updated value
             */
            long decrementAndGet();

            /**
             * Gets the current value.
             *
             * @return the current value
             */
            long get();

            /**
             * Atomically adds the given value to the current value.
             *
             * @param delta the value to add
             * @return the old value before the add
             */
            long getAndAdd(long delta);

            /**
             * Atomically sets the given value and returns the old value.
             *
             * @param newValue the new value
             * @return the old value
             */
            long getAndSet(long newValue);

            /**
             * Atomically increments the current value by one.
             *
             * @return the updated value
             */
            long incrementAndGet();

            /**
             * Atomically increments the current value by one.
             *
             * @return the old value
             */
            long getAndIncrement();

            /**
             * Atomically sets the given value.
             *
             * @param newValue the new value
             */
            void set(long newValue);

        private:
            std::string instanceName;
            impl::ClientService& clientService;
        };
    }
}

#endif /* HAZELCAST_ATOMIC_NUMBER */