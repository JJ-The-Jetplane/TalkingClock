/******************************************************************************************************/
/* Created by: Matt Jackels
/* Created on: 7/9/17
/*
/* Description: The program should take a time input in the form hh:mm (hour, minute), and 
/* output that time of day in a sentence.
/*
/* This project is sourced from: 
/* https://www.reddit.com/r/dailyprogrammer/comments/6jr76h/20170627_challenge_321_easy_talking_clock/
/*
/* Example: 
/* input: 01:15
/* output: It's one fifteen am.
/*
/******************************************************************************************************/


#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;
void convertClock( int hour, int minute);

int main(void){
    string str_timeEntered;
    string str_timeEnteredHour, str_timeEnteredMinute;
    int int_timeEnteredHour, int_timeEnteredMinute;
    string delimiter = ":";
    int flagFailure = 0;
    string continueOption;
    int flagCont = 1;

    while(flagCont){
        cout << "Enter the time in HH:MM format: ";
        getline(cin, str_timeEntered);
        str_timeEnteredHour = str_timeEntered.substr(0, str_timeEntered.find(delimiter)); //assigns first 2 characters to hour string
        str_timeEnteredMinute = str_timeEntered.substr(str_timeEntered.find(delimiter)+1, str_timeEntered.length()-1); //assigns last 2 characters to minute string

        //converts hour input string to int and throws error if not an int
        stringstream ss1(str_timeEnteredHour);
        if((ss1 >> int_timeEnteredHour).fail()){
            cout << "Error int_timeEnteredHour \n";
            flagFailure = 1;
        }

        //converts minute input string to int and throws error if not an int
        //valid input here is defined as a number
        stringstream ss2(str_timeEnteredMinute);
        if((ss2 >> int_timeEnteredMinute).fail()){
            cout << "Error int_timeEnteredMinute \n";
            flagFailure = 1;
        }

        //if invalid input, runs error script for trying again
        //valid input here is defined as a number
        if(flagFailure){
            cout << "Would you like to try again? (y/n): ";
            cin >> continueOption;
            if(continueOption == "n" || continueOption == "N"){
                flagCont = 0;
            }
            flagFailure = 0; //reset error flag
        }

        //checks if the numbers are within valid time ranges
        //if the input is valid, runs the clock function and gives user the input to continue
        else{
            if(int_timeEnteredHour > 23 || int_timeEnteredHour < 0){
                cout << "invalid hour. Try again.\n";
            }
            else if(int_timeEnteredMinute > 59 || int_timeEnteredMinute < 0){
                cout << "invalid minute. Try again.\n";
            }
            else convertClock(int_timeEnteredHour, int_timeEnteredMinute);

            cout << "Would you like to try another time? (y/n): ";
            cin >> continueOption;

            if(continueOption == "n" || continueOption == "N"){
                flagCont = 0;
                cout << "Goodbye! \n";
            }
        }
        cin.ignore();//clears the return character from cin
    }
}

// Function Description: takes a time and outputs the "voice" of that time by converting the hours and
// minutes into words. 
//
// Input: int hour is the hour (0-23) of the time, int minute is the minute (0-59) of the time
// Output: prints the words on the screen. Void return.
//
// Logic: This function works by building arrays of the possible words for the hours, minute tens, and minute ones.
// It then finds the proper hour index of the array to print by taking the modulus of the hour (hour mod 12).
// The minutes output index is found by dividing the minute by ten (minute / 10) to get the index of the tens word
// and find the one by taking the modulus of the minute (minute mod 10). 
// The am/pm flag tells the morning/evening status depending on it it's less than 12 (am), else (pm).
//
void convertClock(int hour, int minute){

    string ampmFlag = "pm";
    string nameHours[] = {"Twelve ", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                            "Nine", "Ten", "Eleven"};
    string nameMinuteTens[] = {"Oh", "", "Twenty", "Thirty", "Fourty", "Fifty"};
    string nameMinuteOnes[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    if(hour <= 12) ampmFlag = "am";

    cout << "It's " << nameHours[hour%12]; //outputs the hour segment of the time

    if(minute == 0){ //if the minute is zero then no minute output is necessary. am/pm status is printed
        cout << " " << ampmFlag << "\n";

    }

    else if(minute >= 10  && minute < 20){//if the minute is between 10 and 20, it will be a "teen", so no Tens is needed
        cout << " " << nameMinuteOnes[minute] << " " << ampmFlag << "\n";
    }

    else{
        cout << " " << nameMinuteTens[minute/10] << " " << nameMinuteOnes[minute%10] << " " << ampmFlag << "\n"; //outputs the minute tens, and minute ones and am/pm status
    }

}