#include <gtest/gtest.h>
#include "example2.cpp"
#include <string>

Test(Fan, SetCircuitTringle) {
    Fan fan;
    
    testing::internal::CaptureStdout();
    fan.SetCircuitTringle();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In Tringle toplogy circuit\n");
    
    testing::internal::CaptureStdout();
    fan.SetCircuitStar();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In star toplogy circuit\n");
    
    testing::internal::CaptureStdout();
    fan.ConnectPower();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Connect Power\n");
    
    testing::internal::CaptureStdout();
    fan.DisconnectPower();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Disconnect Power\n");
    
    testing::internal::CaptureStdout();
    fan.Delay(2000);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "wait for 2000 miliseconds\n");
}

Test(Controller, TurnOnFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    testing::internal::CaptureStdout();
    controller.ButtonClicked();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In star toplogy circuit\nConnect Power\nwait for 20000 miliseconds\nSetPower In Tringle toplogy circuit\n");
}

Test(Controller, TurnOffFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    testing::internal::CaptureStdout();
    controller.ButtonClicked();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(controller.ButtonClicked(), "Disconnect Power\n");
}