#include <gtest/gtest.h>
#include "example2.cpp"

Test(Fan, Methods) {
    Fan fan;
    EXPECT_EQ(fan->SetCircuitTringle(), "SetPower In Tringle toplogy circuit");
    EXPECT_EQ(fan->SetCircuitStar(), "SetPower In star toplogy circuit");
    EXPECT_EQ(fan->ConnectPower(), "Connect Power");
    EXPECT_EQ(fan->DisconnectPower(), "Disconnect Power");
    EXPECT_EQ(fan->Delay(2000), "wait for 20000 miliseconds");
}

Test(Fan, TurnOnFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    EXPECT_EQ(controller.ButtonClicked(), "SetPower In star toplogy circuit\nConnect Power\nwait for 20000 miliseconds\nSetPower In Tringle toplogy circuit");
}

Test(Fan, TurnOffFanCommand) {
    Controller controller;
    Fan fan;
    controller.SetCommand(new TurnOnFanCommand(&fan));
    EXPECT_EQ(controller.ButtonClicked(), "Disconnect Power");
}