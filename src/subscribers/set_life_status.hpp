/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#ifndef LIFESTATUS_SUBSCRIBER_HPP
#define LIFESTATUS_SUBSCRIBER_HPP

/*
 * LOCAL includes
 */
#include "subscriber_base.hpp"

/*
 * ROS includes
 */
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace naoqi
{
namespace subscriber
{

class LifeStatusSubscriber: public BaseSubscriber<LifeStatusSubscriber>
{
public:
	LifeStatusSubscriber(const std::string& name, const std::string& life_status, const qi::SessionPtr& session);
	~LifeStatusSubscriber(){}

	void reset(ros::NodeHandle& nh);
	void lifestatus_callback(const std_msgs::StringConstPtr& life_status_msg);

private:
	std::string life_status_;

	qi::AnyObject p_life_status_;
	ros::Subscriber sub_life_status_;

};

}
}

#endif
