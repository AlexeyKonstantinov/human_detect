#include "ros/ros.h"
#include "std_msgs/Bool.h"

#include <sstream>
#include <ros/console.h>
#include "iostream"

#include "opencv_apps/Rect.h"
#include "opencv_apps/RectArrayStamped.h"

ros::Publisher human_detected_pub;

void foundCallback(const opencv_apps::RectArrayStamped& array)
{
	std_msgs::Bool data;
	
	bool humanFound = false;
	for(opencv_apps::Rect rect : array.rects)
	{
		humanFound = true;
	}
	if(humanFound)
	{
		ROS_INFO("Human detected");
		data.data=true;
		human_detected_pub.publish(data);
	}else
	{
		data.data=false;
		human_detected_pub.publish(data);
	}
	
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "human_detector");

  	ros::NodeHandle n;

	human_detected_pub = n.advertise<std_msgs::Bool>("humanDetected", 1000);

	ros::Subscriber found_sub = n.subscribe("people_detect/found", 1000, foundCallback);

  	ros::spin();

  return 0;
}

