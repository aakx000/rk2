#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using namespace std;
class command
{
public:
   virtual void execute()=0;
};
class Fan
{
public:
    void SetCircuitTringle()
    {
        std::cout<<"SetPower In Tringle toplogy circuit"<<std::endl;
    }
  void SetCircuitStar()
  {
      std::cout<<"SetPower In star toplogy circuit"<<std::endl;
  }
  void ConnectPower()
  {
      std::cout<<"Connect Power"<<std::endl;
  }
  void DisconnectPower()
  {
      std::cout<<"Disconnect Power"<<std::endl;
  }
  void Delay(int miliseconds)
  {

       std::cout<<"wait for "<<miliseconds<<" miliseconds"<<std::endl;
  }
};
class TurnOnFanCommand:public command
{
    Fan *_fan;
public:
    TurnOnFanCommand(Fan*fan)
    {
        _fan=fan;
    }

    void execute() override
    {
        _fan->SetCircuitStar();
        _fan->ConnectPower();
        _fan->Delay(20000);
        _fan->SetCircuitTringle();
    }

};
class Controller
{
    command *_command;
public:
    Controller(){}
    void SetCommand(command* command)
    {
        _command=command;
    }
    void ButtonClicked()
    {
        _command->execute();

    }
    ~Controller()
    {
        delete  _command;
    }
};
class TurnOffFanCommand:public command
{
    Fan* _fan;
public:
    TurnOffFanCommand(Fan*fan){_fan=fan;}

    void execute() override
    {
        _fan->DisconnectPower();
    }

};


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