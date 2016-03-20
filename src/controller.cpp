#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char **argv)
{
    double v=0.05, w=0;
    //Start ROS within this node
    ros::init(argc,argv,"controller");
    //Declaring node
    ros::NodeHandle node;
    //Declare topic to be published
    ros::Publisher pub_right = node.advertise<std_msgs::Float64> ("/vrep/vehicle/motorRightSpeed",1);
    ros::Publisher pub_left = node.advertise<std_msgs::Float64> ("/vrep/vehicle/motorLeftSpeed",1);
    
    //Define ROS loop_rate
    ros::Rate loop_rate(60);
    
    //Define messages
    std_msgs::Float64 wl, wr;
    
    //ROS LOOP
    while(ros::ok())
    {
        //Compute wr and wl
        wr.data = (v + 0.35*w/2)/0.1;
        wl.data = (v - 0.35*w/2)/0.1;
        
        //Publish
        pub_right.publish(wr);
        pub_left.publish(wl);
        
        //ROS routines
        ros::spinOnce();
        loop_rate.sleep();
        
    }
    
}