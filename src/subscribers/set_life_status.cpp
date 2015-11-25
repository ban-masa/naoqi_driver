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

/*
 * LOCAL includes
 */
#include "set_life_status.hpp"

namespace naoqi
{
namespace subscriber
{

LifeStatusSubscriber::LifeStatusSubscriber(const std::string& name, const std::string& life_status, const qi::SessionPtr& session):
	life_status_(life_status),
	BaseSubscriber(name, life_status, session),
	p_life_status_(session->service("ALAutonomousLife"))
{}

void LifeStatusSubscriber::reset(ros::NodeHandle& nh)
{
	sub_life_status_ = nh.subscribe(life_status_, 10, &LifeStatusSubscriber::lifestatus_callback, this);
	is_initialized_ = true;
}

void LifeStatusSubscriber::lifestatus_callback(const std_msgs::StringConstPtr& life_status_msg)
{
	p_life_status_.async<void>("setState", life_status_msg->data);
}

}
}
