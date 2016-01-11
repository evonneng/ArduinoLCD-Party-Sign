
// LCD initialization
#include <LiquidCrystal.h>
char array1[] = "Are you ready...             "; //the string to print on the LCD
char array2[] = "Let's PARTY!!!            "; //the string to print on the LCD
int tim = 250;  //the value of delay time
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

// button initialization
//int ledPin = 13;

void setup()
{
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop()
{
  readyStatement(); // prints a scrolling first statement
  
  // set up pause and prommpt
  lcd.setCursor(0, 0);
  lcd.print("Press & Hold -->");
  delay(1000);
  lcd.clear();
  delay(250);

  // countddown effect
  for ( int i = 3; i >= 1; i --) {
    lcd.setCursor(7, 0);
    lcd.print(i);
    delay(500);
    lcd.clear();
  }

  // check if button is pressed
  lcd.setCursor(0, 0);
  delay(500);
  // if button is not pressed, loops back to the beginning 
  if (digitalRead(7) == 0) {
    delay(250);
  } else {
    // continuously prints party statment if button is pressed
    delay(250);
    while (true) {
      partyStatement();   // infinitely loops
    }
  }

  // clear after done
  lcd.clear();
}

/**
   statement to be printed before button is pressed
   repeats itself if button is not pressed 
*/
void readyStatement() {
  delay(250);
  lcd.setCursor(15, 0); // set the cursor to column 15, line 0
  for ( int positionCounter1 = 0; positionCounter1 < 26; positionCounter1++)
  {
    lcd.scrollDisplayLeft();  //Scrolls the contents of the display one space to the left.
    lcd.print(array1[positionCounter1]);  // Print a message to the LCD.
    delay(tim);  //wait for 250 microseconds
  }
  lcd.clear();  //Clears the LCD screen and positions the cursor in the upper-left corner.

  char party[] = " to PARTY?????             ";
  lcd.setCursor(15, 1); // set the cursor to column 15, line 1
  for (int positionCounterA = 0; positionCounterA < 26; positionCounterA++)
  {
    lcd.scrollDisplayLeft();
    lcd.print(party[positionCounterA]);
    delay(tim);
  }
  lcd.clear();
}

/**
   statement to be printed after button is pressed
   programmed code does a variety of scrolls.. from left to right, right to left
   blinking signs, etc.
*/
void partyStatement() {
  // scroll display right to left effect
  lcd.clear();
  lcd.setCursor(15, 0);
  for (int positionCounter2 = 0; positionCounter2 < 26; positionCounter2++)
  {
    lcd.scrollDisplayLeft();
    lcd.print(array2[positionCounter2]);
    delay(250);
  }
  lcd.clear();

  // creates a blinking effect on two different rows
  for (int repeat = 0; repeat < 11; repeat ++) {
    if ( repeat % 3 == 0) {
      lcd.setCursor(5, 0);
      lcd.print("FETTY");
    } else if (repeat % 3 == 1) {
      lcd.setCursor(3, 1);
      lcd.print("WIPPPSSS!!");
    }
    delay(500);
    lcd.clear();
  }

  // creates a scrolling down to up effect
  lcd.setCursor(3, 0);
  lcd.print("WIPPPSSS!!");
  delay(250);
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("it");
  delay(250);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("it");
  delay(250);
  lcd.setCursor(15, 1);
  lcd.clear();

  // simultaneously scrolls from left to right on the bottom
  // and from right to left on the top
  char array4[] = "up! UP! up! UP! up!       ";
  char array3[] = "             heh heh heh   ";
  int positionCounter3 = 26;
  int positionCounter4 = 0;
  int top = 0;
  int bottom = 15;
  for (; positionCounter3 > 0, positionCounter4 < 26; positionCounter3--, positionCounter4++)
  {
    //heh
    lcd.scrollDisplayRight();
    lcd.setCursor(top++, 0);
    lcd.print(array4[positionCounter4]);
    delay(250);

    lcd.scrollDisplayLeft();
    lcd.setCursor(bottom--, 1);
    lcd.print(array3[positionCounter3]);
    delay(250);

    //if(positionCounter4 % 4 ==3) {
    // lcd.clear();
  }
}
//  lcd.clear();
//}

