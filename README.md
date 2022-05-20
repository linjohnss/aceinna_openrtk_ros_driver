# Aceinna OpenRTK ROS Driver

Overview
--------
This is the ROS driver for Aceinna OpenRTK series GNSS/INS integrated navigation module products, with support for **Serial (UART)** port.

The ROS driver source files are located in the subfolder "openrtk_ros".

Several primary messages output by OpenRTK series products are defined in the subfolder "openrtk_msg", which are composed of ROS "std_msg" header and proprietary OpenRTK message content:

- openrtk_gnss.msg: GNSS solution message
- openrtk_imu.msg: raw IMU data message
- openrtk_ins.msg: INS solution message
- sensor_msgs.Imu: ros IMU data message
- sensor_msgs.NavSatFix: ros GNSS solution message

  Note: User could modify the content of the messages that are defined in the openrtk_msg/msg folder, and the modified messages should comply with ROS definitions.



Usage
--------

### Prerequisites

- PC with Ubuntu 18.04
- Python 3.x
- Install ROS Melodic, please refer to http://wiki.ros.org/melodic/Installation/Ubuntu
- OpenRTK330LI EVK (FW v23.05), please refer to https://openrtk.readthedocs.io/en/latest/firmware_upgrade.html for EVK upgrade steps



### Build

The following are steps to build the ROS driver from source code in your local development environment:

1. Go to your ROS workspace

   ​	`cd ~/catkin_ws`   

2. Copy folders to your ROS workspace 

   ​	`cp openrtk_ros openrtk_msg ./src`

3. Compile the code

   ​	`catkin_make`

### Operation

1. Launch the node

   ​	`roslaunch openrtk_ros run.launch`	

2. List topics

   ​	`rostopic list`

3. Message echo (xxx = imu, ins, gnss)

   ​	`rostopic echo /openrtk/topic_rtk_xxx`

   ​	                

## License

The source code is licensed under the MIT license --- refer to the LICENSE file for details.

