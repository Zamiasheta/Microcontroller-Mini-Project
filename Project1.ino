#include <Keypad.h>

int buzzer = 13;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys [ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad kpd = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);

long Num1, Num2, Number;
char key, action;
boolean result = false;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
}





void loop() {

  
  
  
  // put your main code here, to run repeatedly:
  key = kpd.getKey();
  if (key != NO_KEY)
    DetectButtons();

  if (result == true)
    CalculateResult();

  DisplayResult();

}







void DetectButtons()
{
  //lcd.clear(); //Then clean it
  if (key == '*') //If cancel Button is pressed
  {
    Number = Num1 = Num2 = 0;
    result = false;
  }

  if (key == '1') //If Button 1 is pressed
  { Serial.println ("Button 1");
    if (Number == 0)
      Number = 1;
    else
      Number = (Number * 10) + 1; //Pressed twice
  }

  if (key == '4') //If Button 4 is pressed
  { Serial.println ("Button 4");
    if (Number == 0)
      Number = 4;
    else
      Number = (Number * 10) + 4; //Pressed twice
  }

  if (key == '7') //If Button 7 is pressed
  { Serial.println ("Button 7");
    if (Number == 0)
      Number = 7;
    else
      Number = (Number * 10) + 7; //Pressed twice
  }


  if (key == '0')
  { Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number == 0)
      Number = 0;
    else
      Number = (Number * 10) + 0; //Pressed twice
  }

  if (key == '2') //Button 2 is Pressed
  { Serial.println ("Button 2");
    if (Number == 0)
      Number = 2;
    else
      Number = (Number * 10) + 2; //Pressed twice
  }

  if (key == '5')
  { Serial.println ("Button 5");
    if (Number == 0)
      Number = 5;
    else
      Number = (Number * 10) + 5; //Pressed twice
  }

  if (key == '8')
  { Serial.println ("Button 8");
    if (Number == 0)
      Number = 8;
    else
      Number = (Number * 10) + 8; //Pressed twice
  }


  if (key == '#')
  { Serial.println ("Button Equal");
    Num2 = Number;
    result = true;
  }

  if (key == '3')
  { Serial.println ("Button 3");
    if (Number == 0)
      Number = 3;
    else
      Number = (Number * 10) + 3; //Pressed twice
  }

  if (key == '6')
  { Serial.println ("Button 6");
    if (Number == 0)
      Number = 6;
    else
      Number = (Number * 10) + 6; //Pressed twice
  }

  if (key == '9')
  { Serial.println ("Button 9");
    if (Number == 0)
      Number = 9;
    else
      Number = (Number * 10) + 9; //Pressed twice
  }

  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;
    Number = 0;
    if (key == 'A')
    {
      action = '+';
    }
    if (key == 'B')
    {
      action = '-';
    }
    if (key == 'C')
    {
      tone (buzzer,1000);
      action = '*';
    }
    if (key == 'D')
    {
      noTone (buzzer);
      action = '/';
    }

    delay(100);
  }

}






void CalculateResult()
{
  if (action == '+')
    Number = Num1 + Num2;

  if (action == '-')
    Number = Num1 - Num2;

  if (action == '*')
    Number = Num1 * Num2;

  if (action == '/')
    Number = Num1 / Num2;
}











void DisplayResult()
{
  if (result == true)
  {
    Serial.println(Number);
    Number=0;
  }
  result=false;
  

}
