#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Global variable
int userID = 0;
int today_date, today_month, today_year;
int tableA[13][7], tableB[13][7], tableC[13][7]; // Time table for room A, B, C


// Set Time Table of A, B, C room
void clear_table(char table[13][7]) {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 12; j++) {
            tableA[j][i] = '0';
            tableB[j][i] = '0';
            tableC[j][i] = '0';
        };
    };
};


// Prototype

// Class

// Class for users
class Account;

// Functions

// set Today Date
void setTodayDate(int&, int&, int&);

// Welcome message
void welcomeMessage();

// Main Menu
void reservation();

// Resere Conference Room
void reserve();

// Modify Reservation
void modify();

// Cancel Reservation
void cancel();

// Show Reservation Record
void record();

// Show Staff Requirements
void staff();

// Show Credits
void credits();

// Main Program ******************************************************************************************************************************************************************************
int main() {
    Account Accounts[10000];
    setTodayDate(today_date, today_month, today_year);

    welcomeMessage();
    return 0;
}

class Account {
public:
    // Constructor set account is Not exist
    Account() { isExist = false; }

    // Set Name
    void setName(char inName[]) { strcpy(name, inName); }

    // Get Name
    string getName() { return name; }

    // Set phone
    void setPhone(int inPhone) { phone = inPhone; }

    // Get Phone
    int getPhone() { return phone; }

    // Set Email
    void setEmail(char inEmail[]) { strcpy(email, inEmail); }

    // Get Email
    string getEmail() { return email; }

    // Set Date
    void setDate(int d, int m, int y) { date = d; month = m; year = y; }

    // get Date
    int getDate() { return date; }

    // get Month
    int getMonth() { return month; }

    // get Year
    int getYear() { return year; }

    // Set day
    void setDay(int d) { day = d; }

    // Set Start Time
    void setStartTime(int inStartTime) { startTime = inStartTime; }

    // Get Start Time
    int getStartTime() { return startTime; }

    // Set End Time
    void setEndTime(int inEndTime) { endTime = inEndTime; }

    // Get End Time
    int getEndTime() { return endTime; }

    // Get Duration
    int getDuration() { return duration; }

    // Set Numbers of participants
    void setParticipants(int inParticipants) { number = inParticipants; }

    // Get Numbers of participants
    int getParticipants() { return number; }

    // Set Cost
    void setCost(int inCost) { cost = inCost };

    // Get Cost
    int getCost() { return cost; }

    // Set Room
    void setRoomandCapacity() {
        if (number <= 50) {
            room = 'A';
            capacity = 50;
        }
        else if (number <= 75) {
            room = 'B';
            capacity = 75;
        }
        else {
            room = 'C';
            capacity = 100;
        }
    }

    // Get Room
    char getRoom() { return room; }

    // Get Capacity
    int getCapacity() { return capacity; }

    // Set account exist
    void setExist() { isExist = true; }

    // Ser account not exist
    void setNotExist() { isExist = false; }

    //Get exist
    bool getExist() { return isExist; }

private:
    char name[100], email[50], room;
    int phone, date, month, year, day, startTime, endTime, number, capacity, cost;
    int duration = endTime - startTime;
    bool isExist;
};

// Set Today Date
void setTodayDate(int& date, int& month, int& year) {
    int hour;

    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);

    year = 1900 + local_time->tm_year;
    month = 1 + local_time->tm_mon;
    date = local_time->tm_mday;
    hour = 8 + local_time->tm_hour;
    if (hour >= 24) { hour -= 24; date += 1; }
    makeCorrectDate(date, month, year);
};

// Welcome Message
void welcomeMessage() {
    int welcomeMessageOption;

    cout << "Welcome Message designed by our group" << endl;
    cout << "* Main Menu *" << endl;
    cout << "[1] Reservation" << endl;
    cout << "[2] Show Reservation Record" << endl;
    cout << "[3] Show Staff Requirements" << endl;
    cout << "[4] Credits and Exit" << endl;
    cout << "*" << endl;
    cout << "Option (1 - 4): " << endl;

    // check input validity
    do {
        cout << "Your option: ";
        cin >> welcomeMessageOption;

        switch (welcomeMessageOption) {
        case 1:
            reservation();
            break;
        case 2:
            record();
            break;
        case 3:
            staff();
            break;
        case 4:
            credits();
            break;
        default:
            cout << "Invalid input. Please enter again.";
        }
    } while ((welcomeMessageOption < 1) || (welcomeMessageOption > 3));
}

// main menu
void reservation() {
    int option; //"option" for chosing function

    // basic output
    cout << "* Reservation * \n";
    cout << "[1] Reserve Conference Room \n";
    cout << "[2] Modify Reservation \n";
    cout << "[3] Cancel Reservation \n";
    cout << "* \n";
    cout << "Option (1 - 3): \n";

    // check input validity
    do {
        cout << "Your option: "; cin >> option;

        switch (option) {
        case 1:
            reserve();
            break;
        case 2:
            modify();
            break;
        case 3:
            cancel();
            break;
        default:
            cout << "Invalid input. Please enter again.";
        }
    } while ((option < 1) || (option > 3));
}

// Resere Conference Room
void reserve() {
    userID++;
    cout << "To reserve, please enter the following information. \n";
    cout << "Each data will have at most three attempts. \n";
    cout << "After three wrong input, you will be redirected to the reservation page. \n";
    cout << "If the reserve is accepted, an reserve ID will be printed, please remember it. \n";
    cout << "It will be useful for reservation checking, modifling, and cancelling.\n \n";

    checkName();
    checkPhone();
    checkEmail();
    checkDate();
    checkStartTime();
    checkEndTime();
    checkParticipants();

    confirmation(0);
}

// Input Check and record

// Name Check
void checkName() {

    char name[100] = {};
    int errorCount = 0;
    bool check;

    do {
        cout << "Please Enter Your Name: ";
        cin.getline(name, 100, '\n');
        check = true;

        for (int i; i <= strlen(name); i++)
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
                check = false;

        if (check) {
            Accounts[userID].setName(name);
            break;
        }
        else {
            cout << "* The input is not correct. * \n";
            cout << "* Names only accept alphabatic input. * \n";
            errorCount++;
        }

    } while (errorCount <= 3);

    if (errorCount == 3)
        return reservation();
}

// Phone Check
void checkPhone() {

    int phone;
    int errorCount = 0;
    bool check;

    do {
        cout << "Please Enter Your Phone Number: ";
        cin >> phone;
        check = true;

        if (!((phone < 100000000) && (phone > 9999999)))
            check = false;

        if (check) {
            Accounts[userID].setPhone(phone);
            break;
        }
        else {
            cout << "* The input is not correct. * \n";
            cout << "* Phone numbers should have and only have 8 digits. * \n";
            errorCount++;
        }

    } while (errorCount <= 3);

    if (errorCount == 3)
        return reservation();
}

// Email Check
void checkEmail() {

    char email[50];
    int errorCount = 0;
    bool check;

    do {
        cout << "Please Enter Your Email Address: ";
        cin >> email;
        check = false;

        for (int i = 0; i <= strlen(email); i++)
            if (email[i] == '@')
                check = true;

        if (check) {
            Accounts[userID].setEmail(email);
            break;
        }
        else {
            cout << "* The input is not correct.* \n";
            cout << "* Email should include a \"@\" sign. * \n";
            errorCount++;
        }

    } while (errorCount <= 3);

    if (errorCount == 3)
        return reservation();
}

// Check date
bool isValidDate(int d, int m, int y)
{
    int  m2;
    bool isCorrect;

    if (m <= 7)
        m2 = m + 1;

    isCorrect = false;

    if ((d >= 0 && d <= 31) && (m >= 1 && m <= 12) && (y >= 1)) {
        switch (d) {
        case 29: if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) isCorrect = true; break;
        case 30: if (m != 2) isCorrect = true; break;
        case 31: if (m2 % 2 == 0 && m != 2) isCorrect = true; break;
        default: isCorrect = true;
        }
    }

    return isCorrect;
}

// Check Within 7 days
bool isWithinDate(int d, int m, int y) {
    int valid_date, valid_month, valid_year;
    int dayCount = 0;

    valid_date = today_date;
    valid_month = today_month;
    valid_year = today_year;

    for (int i = 1; i <= 7; i++) {  // sliding the valid backward to check if it is saem as the input date
        valid_date++;
        dayCount++;
        makeCorrectDate(valid_date, valid_month, valid_year);

        if ((d == valid_date) && (m == valid_month) && (y == valid_year)) { //checking
            Accounts[userID].setDay(dayCount - 1);
            return true;
        }
    };

    return false;
}

// Make Correct Date
void makeCorrectDate(int& d, int& m, int& y) {
    if (!isValidDate(d, m, y)) { // avoid improper date
        d = 1;
        m++;
    }

    if (!isValidDate(d, m, y)) { //avoid improper month
        m = 1;
        y++;
    }
};

// Resevation Date Check
void checkDate() {
    int day, month, year, errorCount = 0;
    char dummy1, dummy2;

    do {
        cout << "Please Enter the Date you want to book (dd-mm-yyyy) \n";
        cin >> day >> dummy1 >> month >> dummy2 >> year;

        if (isValidDate(day, month, year) && isWithinDate(day, month, year)) {
            Accounts[userID].setDate(day, month, year);
            break;
        }
        else {
            cout << "* The input is not correct.* \n";
            cout << "* The date is not valid or within 7 days * \n";
            errorCount++;
        }
    } while (errorCount <= 3);

    if (errorCount == 3) return reservation();
}

// Start Time Check
void checkStartTime() {

    char dummy[5];
    int startTime;
    int errorCount = 0;
    bool check;

    do {
        cout << "Please Enter the Start Time (hh:mm): ";
        cin >> startTime >> dummy;
        check = true;

        if (!((startTime >= 9) && (startTime <= 20))) check = false;

        if (check) {
            Accounts[userID].setStartTime[startTime];
            break;
        };
    } while (errorCount <= 3);

    if (errorCount == 3)
        return reservation();
}

// End Time Check
void checkEndTime() {

    char dummy[5];
    int endTime;
    int errorCount = 0;
    bool check;

    do {
        cout << "Please Enter the End Time (hh:mm): ";
        cin >> endTime >> dummy;
        check = true;

        if (!((endTime >= Accounts[userID].getStartTime()) && (endTime <= 22)))
            check = false;

        if (check) {
            Accounts[userID].setEndTime(endTime);
            break;
        }

    } while (errorCount <= 3);

    if (errorCount == 3)
        return reservation();
}

// Number of Participants Check
void checkParticipants() {

    int participants;
    int errorCount = 0;
    bool check;

    do {
        cout << " Plaese Enter the Number of Participants: ";
        cin >> participants;

        if (!((participants > 0) && (participants <= 100))) check = false;

        if (check) {
            Accounts[userID].setParticiants(participants);
            break;
        }
        else errorCount++;

    } while (errorCount <= 3);
}

// end of error checking and input

// Functions of Confirmation and Suggestion

// Check if the timeslot required is free
int checkTimeTable(int st, int et, int duration, int day, char room) {

    int ast = st; // avaible start time
    int count = 1;
    int i = st; // for looping

    switch (room) {
    case 'A':
        while ((i <= et) && (count <= duration)) {
            if (tableA[i][day] == ' ') {
                count++;
                i++;
            }
            else {
                ast = i + 1;
                count = 1;
            }
        }
        break;

    case 'B':
        while ((i <= et) && (count <= duration)) {
            if (tableB[i][day] == ' ') {
                count++;
                i++;
            }
            else {
                ast = i + 1;
                count = 1;
            }
        }
        break;

    case 'C':
        while ((i <= et) && (count <= duration)) {
            if (tableC[i][day] == ' ') {
                count++;
                i++;
            }
            else {
                ast = i + 1;
                count = 1;
            }
        }
        break;

    default:
        cout << "Sorry, we faced an system error. \n";
        cout << "Please Reserve again. \n";
        reserve();
        return;
    }

    if (count == duration) return ast;
    else return 0;
}

void confirmation(int ID) {
    if (ID == 0) ID = userID;
    
    // Variables for time checking 
    int st = Accounts[ID].getStartTime;
    int et = Accounts[ID].getEndTime;
    int duration = Accounts[ID].getDuration;
    int day = Accounts[ID].getDay;
    char room = Accounts[ID].getRoom;

    // variables for output
    int capacity = Accounts[ID].getCapacity;
    int date = Accounts[ID].getDate;
    int month = Accounts[ID].getMonth;
    int year = Accounts[ID].getYear;
    int cost;

    if (room == 'A') cost = 1500 * duration;
    else if (room == 'B') cost = 2000 * duration;
    else cost = 2500 * duration;

    Accounts[userID].setCost(cost);

    char firm = 'a';

    int avast;  // Avaliable start time

    avast = checkTimeTable(st, et, duration, day, room);

    if (avast != st) suggestion(st, et, duration, day, room);
    else {
        cout << "*** Reservation ***" << endl;
        cout << "Room:  Room " << room << endl;
        cout << "Maximum Capacity" << Accounts[userID].getCapacity << endl;
        cout << setw(7) << "Date:" << date << "/" << month << "/" << year << endl;
        cout << setw(7) << "Time:" << st << ":00 - " << et << ":00" << endl;
        cout << setw(7) << "Cost:" << "$" << cost << endl;

        while ((firm != 'Y') || (firm != 'N')) {
            cout << "Confirm Booking (Y or N): ";
            cin >> firm;

            if (firm == 'Y') {
                addBookingRecord(st, et, day, room, ID);
                cout << "Your reservation has been confirmed. \n";
                cout << "Please remember your ID value:     " << userID;
                cout << "Directing you back to main menu.";
            }

            if (firm == 'N') {
                cout << "Your reservation has been rejected. \n";
                cout << "Directing you back to main menu.";
            }
        }
        return welcomeMessage();
    }
}

// Suggestion 
void suggestion(int st, int et, int duration, int day, char room) {
    int sug1, sug2; // Start time of suggest 1 and suggest 2

    int date = Accounts[userID].getDate;
    int month = Accounts[userID].getMonth;
    int year = Accounts[userID].getYear;

    sug1 = checkTimeTable(9, 21, duration, day, room);
    sug2 = checkTimeTable(st, et, duration, day + 1, room);

    cout << "*** Reservation *** \n";
    cout << "Sorry, no room is available at the time slot. \n";
    cout << "Suggestions: \n";
    
    if (sug1 != 0)
        cout << "[1]" << date << "/" << month << "/" << year << " " << sug1 << ":00 - " << sug1 + duration << ":00 \n";
    else cout << "[1] There is no availble time slot on the same date. Please choose another option.";

    date++;

    makeCorrectDate(date, month, year);

    if (sug2 != 0)
        cout << "[2]" << date << "/" << month << "/" << year << " " << sug2 << ":00 - " << sug2 + duration << ":00 \n";
    else cout << "[2] There is no availble time slot on the same date. Please choose another option.";

    cout << "[3] Cancel Reservation \n";
    
    char option;

    do {
        cout << "Your Choice: \n";
        cin >> option;

        switch (option) {
        case '1' :
            if (sug1 != 0) {
                cout << "Choice accpeted. \n \n";
                Accounts[userID].setStartTime(sug1);
                Accounts[userID].setEndTime(sug1 + duration);
                return confirmation(0);
            }
            else {
                cout << "This option is not available. Please choose another option. \n";
            }
            break;

        case '2':
            if (sug2 != 0) {
                cout << "Choice accpeted. \n \n";
                Accounts[userID].setDate(date);
                Accounts[userID].setMonth(month);
                Accounts[userID].setYear(year);
                return confirmation(0);
            }
            else {
                cout << "This option is not available. Please choose another option. \n";
            }
            break;

        case '3':
            cout << "Reservation being cancelled. \n";
            cout << "Thank you! \n";
            cout << "Redirecting to main menu";
            return welcomeMessage();
            break;

        default : 
            cout << "Invalid Input. \n";
            cout << "Please enter a number between 1 to 3.";
            break;
        }
    } while ((option != '1') || (option != '2') || (option != '3'));
}

// Modify Reservation
void modify() {
    char resNum; // choice: X or C or ReservationNumber

    cout << "*** Modify Reservation ***" << endl;

    do {
        cout << "Enter Reservation Number: "; cin >> resNum;

        if (Accounts[resNum].getExist()) {  // if account exixt then output
            cout << "[1] Person:  " << Accounts[resNum].getName() << endl;
            cout << "[2] Contact:  " << Accounts[resNum].getphone() << endl;
            cout << "[3] Email:  " << Accounts[resNum].getEmail() << endl;
            cout << "[4] Date:  " << Accounts[resNum].getDate << "/" << Accounts[resNum].getMonth << "/" << Accounts[resNum].getYear << endl;
            cout << "[5] Start Time:  " << Accounts[resNum].getStartTime() << ":00" << endl;
            cout << "[6] End Time:  " << Accounts[resNum].getEndTime() << ":00" << endl;
            cout << "[7] Number of participants:  " << Accounts[resNum].getNumber() << endl;
            cout << setw(15) << right << "Room: Room " << Accounts[resNum].getRoom() << endl;
            cout << setw(12) << right << "Cost:  $" << Accounts[resNum].getCost() << endl;
        }
        else if (resNum != 0) {             // if account not exist then enter again
            cout << "Rerservation Number incorrect. \n";
            cout << "Please Enter again. \n";
            cout << "If you have not reserve a booking, please enter \" 0 \" to go back and reserve first. \n";
        }

    } while (!(Accounts[resNum].getExist()));

    // Save Original Information

    char name[100] = Accounts[resNum].getName();
    int phone = Accounts[resNum].getphone();
    char email[50] = Accounts[resNum].getEmail();
    int date = Accounts[resNum].getDate();
    int month = Accounts[resNum].getMonth();
    int year = Accounts[resNum].getYear();
    int startTime = Accounts[resNum].getStartTime();
    int endTime = Accounts[resNum].getEndTime();
    int number = Accounts[resNum].getNumber();
    int day = Accounts[resNum].getDay();
    char room = Accounts[resNum].getRoom();

    char option;
    int avast;

    do {
        cout << "Option (1 - 7), C to complete, or X to cancel: "; cin >> option;

        switch (option) {
        case '1':
            checkName();
            break;

        case '2':
            checkPhone();
            break;

        case '3':
            checkEmail();
            break;

        case '4':
            checkDate();
            break;

        case '5':
            checkStartTime();
            break;

        case '6':
            checkEndTime();
            break;

        case '7':
            checkParticipants();
            break;

        case 'C':
            if ((date != Accounts[resNum].getDate()) || (startTime != Accounts[resNum].getStartTime()) || (endTime != Accounts[resNum].getEndTime()) || (number != Accounts[resNum].getNumber())) {
                deleteBookingRecord(startTime, endTime, day, room);

                avast = checkTimeTable(Accounts[resNum].getStartTime(), Accounts[resNum].getEndTime(), Accounts[resNum].duration, Accounts[resNum].getDay, Accounts[resNum].getRoom);

                if (avast != 0) {
                    cout << "The details have been updated.\n";
                    return confirmation(resNum);
                }
                else {
                    cout << "New time slot is not avaliable. \n";
                    cout << "Modification in Date, Start Time, End Time, and / or Number of Participants is / are set to previous detail. \n";
                    Accounts[resNum].setDate(date);
                    Accounts[resNum].setMonth(month);
                    Accounts[resNum].setYear(year);
                    Accounts[resNum].setStartTime(startTime);
                    Accounts[resNum].setEndTime(endTime);
                    cout << "Returning to main menu";
                    return reservation();
                }
            }
            else {
                cout << "The details have been updated.";
                return reservation();
            }

        case 'X':
            cout << "All modifications have been erased.";
            Accounts[resNum].setName(name[100]);
            Accounts[resNum].setphone(phone);
            Accounts[resNum].setEmail(email[50]);
            Accounts[resNum].setDate(date, month, year);
            Accounts[resNum].setStartTime(startTime);
            Accounts[resNum].setEndTime(endTime);
            Accounts[resNum].setParticipants(number);
            Accounts[resNum].setRoomandCapacity;
            return reservation();
            break;

        default:
            cout << "Input Invalid. \n";
            cout << "Please Input again. \n:";
            break;
        }
    } while( (option != 'C') || (option != 'X') );
}

// Cancel Reservation
void cancel() {
    char resNum; // choice: X or C or ReservationNumber

    cout << "*** Cancel Reservation ***" << endl;

    do {
        cout << "Enter Reservation Number: "; cin >> resNum;

        if (Accounts[resNum].getExist()) {
            cout << "Person:  " << Accounts[resNum].getName() << endl;
            cout << "Contact:  " << Accounts[resNum].getphone() << endl;
            cout << "Email:  " << Accounts[resNum].getEmail() << endl;
            cout << "Date:  " << Accounts[resNum].getDate << "/" << Accounts[resNum].getMonth << "/" << Accounts[resNum].getYear << endl;
            cout << "Start Time:  " << Accounts[resNum].getStartTime() << ":00" << endl;
            cout << "End Time:  " << Accounts[resNum].getEndTime() << ":00" << endl;
            cout << "Number of participants:  " << Accounts[resNum].getNumber() << endl;
            cout << "Room: Room " << Accounts[resNum].getRoom() << endl;
            cout << "Cost:  $" << Accounts[resNum].getCost() << endl;
        }
        else if (resNum != 0) {
            cout << "Rerservation Number incorrect. \n";
            cout << "Please Enter again. \n";
            cout << "If you have not reserve a booking, please enter \" 0 \" to go back and reserve first. \n";
        }

    } while (!(Accounts[resNum].getExist()));

    char option;

    do {
        cout << "Confirm the Cancellation (Y or N): "; cin >> option;

        if (option == 'Y') {
            cout << "Cancellation accpeted. \n";
            Accounts[resNum].setNotExist();
            deleteBookingRecord(Accounts[resNum].getStartTime(), Accounts[resNum].getEndTime(), Accounts[resNum].getDay, Accounts[resNum].getRoom());
        }
        else if (option == 'N') {
            cout << "Cancellation rejected. \n";
            return reservation();
            DisplayReservationRecord();
        }
        else {
            cout << "Input Invald. \n";
            cout << "Please input again. \n";
        }
    } while ((option != 'Y') || (option != 'N'));
}

// Add Booking Record
void addBookingRecord(int st, int et, int day, char room, int ID) {
    switch (room) {
    case 'A' :
        for (int i = st - 9; i <= et - 9; i++) tableA[i][day] = ID;
        break;

    case 'B' :
        for (int i = st - 9; i <= et - 9; i++) tableB[i][day] = ID;
        break;

    case 'C':
        for (int i = st - 9; i <= et - 9; i++) tableC[i][day] = ID;
        break;

    default :
        cout << "Sorry, we faced an system error. \n";
        cout << "Please Reserve again. \n";
        reserve();
        break;
    }
}

// Delete Booking Record
void deleteBookingRecord(int st, int et, int day, char room) {
    switch (room) {
    case 'A':
        for (int i = st - 9; i <= et - 9; i++) tableA[i][day] = 0;
        break;

    case 'B':
        for (int i = st - 9; i <= et - 9; i++) tableB[i][day] = 0;
        break;

    case 'C':
        for (int i = st - 9; i <= et - 9; i++) tableC[i][day] = 0;
        break;

    default:
        cout << "Sorry, we faced an system error. \n";
        cout << "Please Reserve again. \n";
        cancel();
        break;
    }
}

// Show Reservation Record
void time_date(char room) 
{
    int date = today_date;
    int month = today_month;
    int year = today_year;

    cout << setw(7) << " ";
    for (int i = 0; i < 7; i++) {
        date++;
        makeCorrectDate(date, month, year);
        cout << date << "/" << month << "   ";
    }

    int timeCounter = 9;
    for (int i = 0; i < 13; i++) {

        if (timeCounter == 9)
            cout << endl << "0" << timeCounter << ":00" << "    ";
        else
            cout << endl << timeCounter << ":00" << "    ";

        for (int j = 0; j < 7; j++) {
            switch (room) {
            case 'A': 
                if (tableA[i][j] == 0) cout << "   ";
                else cout << " x ";
                break;
            case 'B': 
                if (tableA[i][j] == 0) cout << "   ";
                else cout << " x ";
                break;
            case 'C':
                if (tableA[i][j] == 0) cout << "   ";
                else cout << " x ";
                break;
            default: 
                cout << "system error."; 
                cout << "Returning the main menu";
                return welcomeMessage();
            }
        }

        timeCounter++;
    }
}


void DisplayReservationRecord(int booking[13][7]) {
    char Y;   // Input of user 

    cout << "*** Reservation Record ***\n";
    cout << "Display Which Room (A - C):";

    while (true) {
        cin >> Y;

        switch (Y) {
        case 'A':
            cout << "Room " << Y << "\n\n";
            // call a function to retrieve the room data
            break;

        case 'B':
            cout << "Room " << Y << "\n\n";
            break;

        case 'C':
            cout << "Room " << Y << "\n\n";
            break;

        case 'X': 
            cout << "Exiting... \n";
            cout << "Redirecting to home page. \n";
            return welcomeMessage();

        default:
            cout << "Wrong option" << endl;
            DisplayReservationRecord(booking);
        }

        time_date(Y);

        cout << endl << "Option(A - C), X to exit: ";
    }
}

// Show Staff Requirements
void staff() {
    int d = today_date;
    int m = today_month;
    int y = today_year;  //checking

    int day[2], month[2], year[4]; // input
    char input[10];

    cout << "*** Staff Requirements ***";
    cout << "Enter the Date (dd/mm/yyyy) or X to exit: "; cin >> input;
    if (input[0] == 'X') return welcomeMessage();
    else {
        day[0] = input[0]; day[1] = input[1];
        month[0] = input[3]; month[1] = input[4];
        year[0] = input[6]; year[1] = input[7]; year[2] = input[8]; year[3] = input[9];
    }

    for (int i = 0; i < 7; i++) {  // sliding the valid backward to check if it is saem as the input date
        d++;
        makeCorrectDate(valid_date, valid_month, valid_year);

        if ((d == valid_date) && (m == valid_month) && (y == valid_year)) { //checking
            Accounts[userID].setDay(dayCount - 1);
            return true;
        }
    };
}

// Credits
void printcredit() {
    cout << endl << "* Credits *" << endl;
    cout << "member:" << endl << endl;
    cout << left;
    cout << setw(20) << "Chan Sze Wing" << setw(17) << "21100571A" << setw(17) << "102C" << endl;
    cout << setw(20) << "Shum Ka Ho" << setw(17) << "21113450A" << setw(17) << "102B" << endl;
    cout << setw(20) << "Lo Chun Yin" << setw(17) << "21016730A" << setw(17) << "102B" << endl;
    cout << setw(20) << "Ng Shun Kai" << setw(17) << "21115732A" << setw(17) << "102B" << endl;
    cout << setw(20) << "Tang Cheuk Hin" << setw(17) << "21135614A" << setw(17)  << "102C" << endl;
    cout << setw(20) << "Chan Cory Yuk Yin" << setw(17) << "21168497A" << setw(17) << "103C" << endl;
}

void credit() {
    char option;


    do {
        cout << "Confirm to show Credits and terminate the program?  "; cin >> option;

        if ( (option == 'y') || (option == 'Y') ) {
        printcredit();
        exit(0);
        }
        else if ( (option == 'n') || (option == 'N') ) {
            cout << "Returning to main menu"; 
            return welcomeMessage();
        }
    } while ( (option == 'y') || (option == 'Y') || (option == 'n') || (option == 'N') );
