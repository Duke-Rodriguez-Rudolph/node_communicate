#include"ros/ros.h"
#include"std_msgs/String.h"
#include"sstream"

using namespace std;
using namespace ros;
using namespace std_msgs;
int main(int argc,char **argv)
{
   //初始化节点
   init(argc,argv,"send");
   //创建节点句柄
   NodeHandle n;
   //创建发布者，队列长度1000
   Publisher chatter_pub=n.advertise<String>("message",1000);
   //设置循环频率
   Rate loop_rate(10);
   //
   while(ok())
   {
      //发送数据
      String msg;
      stringstream ss;
      ss<<"I am the send node";
      msg.data=ss.str();
      chatter_pub.publish(msg);
      spinOnce();
      //延时
      loop_rate.sleep();
   }
   return 0;
}
