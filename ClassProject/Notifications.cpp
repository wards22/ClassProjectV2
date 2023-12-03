/* Prologue
 * Name: Notifications Implementation File
 * Description: Creates and modifies notification file
 * Contributors: Crischelle Polley
 * Date created: Nov 28 2023
 * Date last modified: Nov 29 2023
*/

/* References:
 * https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
 * https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono#:~:text=Here%27s%20a%20C%2B%2B20%20solution%3A%20%23include%20%3Cchrono%3E%20%23include%20%3Cformat%3E,%28%29%29%3B%20return%20std%3A%3Aformat%20%28%22%20%7B%3A%25Y-%25m-%25d%20%25X%7D%22%2C%20time%29%3B%20%7D
 * https://cplusplus.com/reference/chrono/system_clock/
 * https://cplusplus.com/reference/ctime/
 * https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s?view=msvc-170
 * ctime is deprecated, ctime_s must be used
 * https://en.cppreference.com/w/c/chrono/ctime
 * https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring
 */

#include "Notifications.h"
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using chrono::system_clock;


string Notifications::getDateTime() const {
    // Read current date and time from system
    system_clock::time_point tp = system_clock::now();


    // Convert system_clock object to ctime object to format dateTime
    time_t tt = system_clock::to_time_t(tp);

    // char * of size 26 to fit date and time of tt
    const int dtSize = 26;
    char dt[dtSize];

    // ctime_s(char *, char * size, time_t *)
    // when only dt is used, it acts as char *
    // string of tt will be stored in dt
    ctime_s(dt, dtSize, &tt);

    return formatDateTime(dt);
}

string Notifications::formatDateTime(const char* dt) const {
    // Copy char * to string
    string s = dt;

    // Remove null terminator
    s = s.substr(0, 24);

    // Format dt to WWW MMM DD YYYY HH:MM:SS
    s = s.substr(0, 11) + s.substr(20, 24) + " " + s.substr(11, 8);

    return s;
}

string Notifications::getTitle() const
{
    return title;
}

void Notifications::setTitle(const string& t)
{
    title = t;
}

string Notifications::getContent() const
{
    return content;
}

void Notifications::setContent(const string& c)
{
    content = c;
}

bool Notifications::getPostNoteStatus() const
{
    return postNoteStatus;
}

void Notifications::readNotification() {
    // When reading from notifications file, must replace delimiter (`) with commas
    // Also must replace delimiter (_) with newlines
    // Also must append commas to fields

    /*
    fstream inputFile;
    inputFile.open("Notifications.csv", ios::in);

    string line, data;
    vector<string> row;
    int i;                 // Keep track of which field is content to format

    while (getline(inputFile, line)) {  
        row.clear();
        stringstream s(line);

        i = 0;
        while (getline(s, data, ',')) {
            if(
            row.push_back(data);
        }

        notifications.push_back(row);

        inputFile.close();
    } */

}

void Notifications::writeNotification() {
    // When writing to notifications file, must replace commas with other delimiter (`)
    // Also must replace newlines with delimiter (_)
    // Also must append commas to fields
}

void Notifications::createNotification() {
    // Check if notification is already created
    if (title != "" || content != "") {
        cout << "A notification is waiting to be posted.\n"
            << "Go to Edit Notification to edit current notification.\n\n";

    } else {

        title = "";
        content = "";
        postNoteStatus = false;

        cout << "Enter a title for your notification:\n";
        getline(cin, title);

        cout << "Enter the content your notification will contain:\n";
        getline(cin, content);

    }


}


void Notifications::editNotification() {

}

void Notifications::deleteNotification() {
    // Code here
    postNoteStatus = false;
}

void Notifications::postNotification() {
    // Write it to file
    // Then access View Notifications boundary class to print
    postNoteStatus = true;
}