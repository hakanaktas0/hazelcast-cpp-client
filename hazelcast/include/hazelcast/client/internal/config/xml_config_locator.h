/*
* Copyright (c) 2008-2022, Hazelcast, Inc. All Rights Reserved.
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
#pragma once

#include <string>
#include <vector>
#include "hazelcast/util/export.h"
#include <boost/property_tree/ptree.hpp>
#include "hazelcast/client/client_config.h"
#include "hazelcast/client/client_properties.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(push)
#pragma warning(disable : 4251) // for dll export
#endif

namespace hazelcast {
namespace client {
namespace internal {
namespace config {
/**
 * Utility class for handling declarative configuration files.
 */
class HAZELCAST_API declarative_config_util
{
private:
    declarative_config_util() = default;

public:
    /**
     * Validates if the config file referenced in property_key has an accepted suffix.
     * If the environment variable is not set, the validation passes without throwing exception.
     * @param property_key – The name of the environment variable to validate
     * @throw HazelcastException – If the suffix of the config file name is not in the accepted suffix list
     */
    static void validate_suffix_in_system_property(
      const std::string& property_key);
    /**
     * Throws HazelcastException unconditionally referring to that the configuration file referenced
     * in the environment variable property_key has a suffix not in the accepted suffix list defined in accepted_suffixes.
     * @param property_key – The name of the environment variable holding the reference to the configuration file
     * @param config_resource – The value of the environment variable
     * @param accepted_suffixes – The list of the accepted suffixes
     * @throw HazelcastException – Thrown unconditionally with a message referring to the unaccepted suffix of the file referenced by property_key
     */
    static void throw_unaccepted_suffix_in_system_property(
      const std::string& property_key,
      const std::string& config_resource,
      const std::vector<std::string>& accepted_suffixes);
    /**
     * Checks if the suffix of the passed config_file is in the accepted suffixes list passed in accepted_suffixes.
     * @param config_file – The configuration file to check
     * @param accepted_suffixes – The list of the accepted suffixes
     * @return true if the suffix of the configuration file is in the accepted list, false otherwise
     */
    static bool is_accepted_suffix_configured(
      const std::string& config_file,
      std::vector<std::string> accepted_suffixes);
};
/**
 * Base class for config locators.
 */
class HAZELCAST_API abstract_config_locator
{
private:
    std::shared_ptr<std::ifstream> in;
    bool load_from_system_property(
      const std::string& property_key,
      bool fail_on_unaccepted_suffix,
      const std::vector<std::string>& accepted_suffixes);
    void load_system_property_file_resource(
      const std::string& config_system_property);

protected:
    /**
     * Locates the configuration file in an environment variable.
     * @return true if the configuration file is found in the environment variable
     * @throw HazelcastException – if there was a problem locating the configuration file
     */
    virtual bool locate_from_system_property() = 0;
    /**
     * Locates the configuration file in the working directory.
     * @return true if the configuration file is found in the working directory
     * @throw HazelcastException – if there was a problem locating the configuration file
     */
    virtual bool locate_in_work_directory() = 0;
    bool load_from_working_directory(const std::string& config_file_path);
    bool load_from_system_property(const std::string& property_key,
                                   const std::vector<std::string>& accepted_suffixes);
public:
    std::shared_ptr<std::ifstream> get_in();
};
/**
 * A support class for the xml_client_config_builder to locate the client xml configuration.
 */
class HAZELCAST_API xml_client_config_locator : public abstract_config_locator
{
public:
    bool locate_from_system_property() override;
    bool locate_in_work_directory() override;
};

} // namespace config
}
} // namespace client
} // namespace hazelcast

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#pragma warning(pop)
#endif