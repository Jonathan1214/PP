#include <QApplication>
#include <QWidget>
#include "cloudmonitor.h"
#include "qwidgetserialtxecg.h"
#include "qwidgetserialtxibp2.h"
#include "qwidgetserialtxspo2.h"
#include "wavedata.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

/*
 *
 *  初始化三个发送串口 将串口连接好
 *  具体入口参数取决于写法
 *
 */
    // 注意串口需要一一对应上 2 8 4
    QWidgetSerialTxEcg *serialTxEcg = new QWidgetSerialTxEcg(2, "COM1", Ecg2_500DemoData, 500);
    QWidgetSerialTxIBP2 *serialTxIBP2 = new QWidgetSerialTxIBP2(8, "COM3", Ibp2_DemoData, 125);
    QWidgetSerialTxSPO2 *serialSPO2 = new QWidgetSerialTxSPO2(4, "COM5", Spo2_DemoData, 248);

    // 初始化监护仪
    // 下面三个变量是为了画图用的
    int maxEcg = 4096;
    int maxIBP2 = 80;
    int maxSPO2 = 100;

    CloudMonitor *monitor = new CloudMonitor();
    monitor->initClient(1234, 2);  // 监听端口 1234
    monitor->initSerials("COM2", "COM4", "COM6");
    monitor->initDisplayer(maxEcg, maxIBP2, maxSPO2);
    monitor->initSignalConnection();

    monitor->showInterface();

//    QWidgetSerialTxEcg *serialTxEcg_A = new QWidgetSerialTxEcg(2, "COM7", Ecg2_500DemoData, 500);
//    QWidgetSerialTxIBP2 *serialTxIBP2_A = new QWidgetSerialTxIBP2(8, "COM9", Ibp2_DemoData, 125);
//    QWidgetSerialTxSPO2 *serialSPO2_A = new QWidgetSerialTxSPO2(4, "COM11", Spo2_DemoData, 248);

//    CloudMonitor *monitor2 = new CloudMonitor();
//    monitor2->initClient(1234, 1);  // 监听端口 1234
//    monitor2->initSerials("COM8", "COM10", "COM12");
//    monitor2->initDisplayer(maxEcg, maxIBP2, maxSPO2);
//    monitor2->initSignalConnection();

//    monitor2->showInterface();


    return a.exec();
}
