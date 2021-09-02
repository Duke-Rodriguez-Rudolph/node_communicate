#include"ros/ros.h"
#include"std_msgs/String.h"

using namespace ros;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
   ROS_INFO("I heard: [%s]",msg->data.c_str());
}
 
int main(int argc, char **argv)
{
   //初始化节点
   init(argc,argv,"receive");
   //节点句柄
   NodeHandle n;
   //订阅者，注册回调函数，队列函数1000
   Subscriber sub=n.subscribe("message",1000,chatterCallback);
   spin();
   return 0;
}

