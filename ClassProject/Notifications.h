/* Prologue
 * Name: Notifications Class
 * Description: Creates and modifies notification file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 29 2023
*/


#pragma once
#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <string>
#include <vector>

using namespace std;

class Notifications {
    private:
    string title;
    string content;
    bool postNoteStatus;
    vector<vector<string>> notifications;

    string getDateTime() const;

    string formatDateTime(const char* dt) const;


    public:
    string getTitle() const;

    void setTitle(const string&);

    string getContent() const;

    void setContent(const string&);

    bool getPostNoteStatus() const;

    void readNotification();

    void writeNotification();

    void createNotification();

    void editNotification();

    void deleteNotification();

    void postNotification();
};

#endif