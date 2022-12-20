/* 
  Final Lab 2022
  Author: Bipra Dey
  Last Modified: 12/19/22
  Known bug: N/A
*/

#include "Timer.h"
#include "TimerList.h"
#include <iostream>
#include <fstream>
#include <string>
#include<limits>

using namespace std;

int main()
{
  Timer temp;
  do {
    cin >> temp;
    if (!cin.fail())
    {
      cout << temp;
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
  }
  while (!cin.eof());
  cout << "Hello";
}

/*Function that prints each of the Timers in the TimerList tL on a new line
void printList(TimerList<Timer> tL)
{
  //For loop that prints each element of the timerlist on a new line
  for (int i = 0; i < tL.get_size(); i++)
  {
    cout << tL[i] << endl;
  }
}
//Function to get timer from user and validate input
void getTimer(Timer& t)
{
    do {
      cin >> t;
      //if the input is invalid, cin is reset
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid timer in the format Hours:Minutes:Seconds: ";
      }
      //if the input is valid, the code breaks out of the loop
      else
      {
        break;
      }
    } while(true);
}

int main()
{
  //TimerList that holds values from the txt file
  TimerList<Timer> timerList;  
  //Temporary timer object to hold values from each line of the txt file
  Timer temp;
  //Temporary string to hold an invalid timer object
  string badTimerStr;
  ifstream inFS;
  //Open text file
  inFS.open("test_data.txt");
  //While loop runs until the end of the file
  while (!inFS.eof())
  {
    //inFS reads in a line of the file
    inFS >> temp;
    //if the timer is valid then it is appended to list
    if(inFS.good())
    {
      timerList.append(temp);
    }
    //else cin is reset and the line is read into the invalid timer string
    else
    {
      inFS.clear();
      inFS.ignore();
      inFS >> badTimerStr;
    }
  }
  //Close the file
  inFS.close();
  //String that holds the user's operation
  string operation = "";
  //TimerList to hold the user's timer objects
  TimerList<Timer> userTimerList;
  //The user's first timer object
  Timer userTimer1;
  //The user's second timer object
  Timer userTimer2;
  //Variable that holds the amount of seconds inputted by the user
  int seconds;
  //Gets the user's input for the first timer and appends it to the user's timer list
  cout << "Enter a timer in the format Hours:Minutes:Seconds: ";
  getTimer(userTimer1);
  userTimerList.append(userTimer1);
  do
  {
    //Prompts the user to enter an operation
    cout << "Please enter an operation from the following list [+, -, ++, --, ==, !=, >, <, (p)rint timer list, c(lear), q(uit)]: ";
    cin >> operation;
    //If the operation is + then the user is prompted to enter a valid value for seconds and adds the seconds to timer1 
    if (operation == "+")
    {
      cout << "Please enter an amount in seconds to add to the timer: ";
      cin >> seconds;
      while (cin.fail())
      {
        cout << "Please enter a valid amount in seconds: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> seconds;
      }
      //The sum of timer1 and seconds is stored in a new timer object that is appended to userTimerlist
      Timer timerSum = userTimer1 + seconds;
      userTimerList.append(timerSum);
      cout << "The sum is " << timerSum << endl;
    }
     //If the operation is - then the user is prompted to enter a valid value for seconds and subtracts the seconds from timer1 
    else if (operation == "-")
    {
      cout << "Please enter an amount in seconds to subtract from the timer: ";
      cin >> seconds;
      while (cin.fail())
      {
        cout << "Please enter a valid amount in seconds: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> seconds;
      }
      //The difference of timer1 and seconds is stored in a new timer object that is appended to userTimerlist
      Timer timerDifference = userTimer1 - seconds;
      userTimerList.append(timerDifference);
      cout << "The difference is " << timerDifference << endl;
    }
    //The value of userTimer1 is increased by one second
    else if (operation == "++")
    {
      userTimer1++;
      userTimerList.append(userTimer1);
      cout << "The new user timer is " << userTimer1 << endl;
    }
    //The value of userTimer1 is decreased by one second
    else if (operation == "--")
    {
      userTimer1--;
      userTimerList.append(userTimer1);
      cout << "The new user timer is " << userTimer1 << endl;
    }
    //The user is prompted to enter a new value for userTimer1 in seconds
    else if (operation == "C" || operation == "c")
    {
      cout << "Please enter a new time for the timer in seconds: ";
      cin >> seconds;
      while (cin.fail())
      {
        cout << "Please enter a valid amount in seconds: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> seconds;
      }
      userTimer1.set_value(seconds);
      userTimerList.append(userTimer1);
      cout << "The newTimer is " << userTimer1 << endl;
    }
    //The user's current timer list is printed out
    else if (operation == "P" || operation == "p")
    {
      cout << "Here is the current history of your timers: " << endl;
      printList(userTimerList);
    }
    //The user is prompted to enter another timer object to check if userTimer1 is equal to it
    else if (operation == "==")
    {
      cout << "Enter another timer in the format Hours:Minutes:Seconds: ";
      getTimer(userTimer2);
      if (userTimer1 == userTimer2)
      {
        cout << "Timer 1 is equal to Timer 2" << endl;
      }
      else
      {
        cout << "Timer 1 is not equal to Timer 2" << endl;
      }
    }
    //The user is prompted to enter another timer object to check if userTimer1 is not equal to it
    else if (operation == "!=")
    {
      cout << "Enter another timer in the format Hours:Minutes:Seconds: ";
      getTimer(userTimer2);
      if (userTimer1 != userTimer2)
      {
        cout << "Timer 1 is not equal to Timer 2" << endl;
      }
      else
      {
        cout << "Timer 1 is equal to Timer 2" << endl;
      }
    }
    //The user is prompted to enter another timer object to check if userTimer1 is greater than it
    else if (operation == ">")
    {
      cout << "Enter another timer in the format Hours:Minutes:Seconds: ";
      getTimer(userTimer2);
      if (userTimer1 > userTimer2)
      {
        cout << "Timer 1 is greater than Timer 2" << endl;
      }
      else
      {
        cout << "Timer 1 is smaller than Timer 2" << endl;
      }
    }
    //The user is prompted to enter another timer object to check if userTimer1 is smaller than it
    else if (operation == "<")
    {
      cout << "Enter another timer in the format Hours:Minutes:Seconds: ";
      getTimer(userTimer2);
      if (userTimer1 < userTimer2)
      {
        cout << "Timer 1 is smaller than Timer 2" << endl;
      }
      else
      {
        cout << "Timer 1 is greater than Timer 2" << endl;
      }
    }
    //If the user wants to quit the program it prints all of the timers in userTimerList and breaks out of the loop
    else if (operation == "Q" || operation == "q")
    {
      cout << "Here is the history of your timers: " << endl;
      printList(userTimerList);
      break;
    }
    //Prompts the user to enter a valid operation
    else
    {
      cout << "Please enter a valid operation from the following list [+, -, ++, --, ==, !=, >, <, (p)rint timer list, c(lear), q(uit)]: ";
      cin >> operation;
    }
  } while (operation != "Q" || operation != "q"); //Loop runs until user enters Q or q

  //Tests the copy constructor by creating a new copy of userTimerList and printing it
  TimerList<Timer> copyTimerList = userTimerList;
  cout << "Here is a copy of the user's timer list using the copy constructor:" << endl;
  printList(copyTimerList);
  //Tests the assignment operator by assigning an existing timer object to the txt file's timerList and prints the list
  TimerList<Timer> assignmentTimerList;
  assignmentTimerList = timerList;
  cout << "Here is a copy of the file's timer list using the assignment operator:" << endl;
  printList(assignmentTimerList);
}*/

