/*******************************************************
 * @file driver.h
 * @author khshen (khshen@aceinna.com)
 * @brief 
 * @date 2021-06-10
 * 
 * @copyright Copyright (c) 2021
 * 
*******************************************************/

#pragma once
#include <iostream>
using namespace std;
#include <queue>
#include <mutex>
#include <thread>
#include <signal.h>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <tf/transform_broadcaster.h>
#include "serial/serial.h"
#include "rtk.h"
#include "macro.h"
#include "protocol.h"
#include "openrtk_msg/openrtk_imu.h"
#include "openrtk_msg/openrtk_gnss.h"
#include "openrtk_msg/openrtk_ins.h"

class RTKDriver
{
public:
    RTKDriver(ros::NodeHandle nh);
    virtual ~RTKDriver();

    void Start();
    void Stop();
    bool Spin();

    static void SigintHandler(int sig);
    void ThreadGetDataUart(void);

    void ParseFrame(uint8_t* frame, uint16_t len);
    void Handle_RtkGNSSMessage(uint8_t* frame, uint16_t len);
    void Handle_RtkIMUMessage(uint8_t* frame, uint16_t len);
    void Handle_RtkINSMessage(uint8_t* frame, uint16_t len);    /* Process INS Msg */

    uint16_t calcCRC(uint8_t *ptr, uint32_t num);
    string Bytestohexstring(uint8_t* bytes,int bytelength);

private:
    ros::NodeHandle m_nh;
    ros::Publisher rtk_pub_imu;
    ros::Publisher rtk_pub_imu_ros;
    ros::Publisher rtk_pub_gnss;
    ros::Publisher rtk_pub_gnss_ros;
    ros::Publisher rtk_pub_ins;
    CRTK m_rtk;
    string m_topic;
    serial::Serial* m_pserial;

    std::mutex m_mt_buf;
    queue<uint8_t> m_uartBuf;

    bool m_uartBexit;
    std::mutex m_uart_exit;
    std::thread m_GetUartDataThread;
};

