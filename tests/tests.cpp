#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "example2.cpp"
#include <string>

class MockFan: public Fan {
    public:
    MockFan() : Fan() {}
};



Test(MockFan, SetCircuitTringle) {
    MockFan fan;
    
    testing::internal::CaptureStdout();
    fan.Fan::SetCircuitTringle();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In Tringle toplogy circuit\n");
    
    testing::internal::CaptureStdout();
    fan.Fan::SetCircuitStar();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In star toplogy circuit\n");
    
    testing::internal::CaptureStdout();
    fan.Fan::ConnectPower();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Connect Power\n");
    
    testing::internal::CaptureStdout();
    fan.Fan::DisconnectPower();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Disconnect Power\n");
    
    testing::internal::CaptureStdout();
    fan.Fan::Delay(2000);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "wait for 2000 miliseconds\n");
}

Test(Controller, TurnOnFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    testing::internal::CaptureStdout();
    controller.ButtonClicked();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "SetPower In star toplogy circuit\nConnect Power\nwait for 20000 miliseconds\nSetPower In Tringle toplogy circuit\n");
}

Test(Controller, TurnOffFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    testing::internal::CaptureStdout();
    controller.ButtonClicked();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Disconnect Power\n");
}