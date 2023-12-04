/* Prologue
 * Name: Notifications Class
 * Description: Creates and modifies notification file
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Dec 3 2023
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
    Notifications();

    Notifications(int);

    string getTitle() const;

    void setTitle(const string&);

    string getContent() const;

    void setContent(const string&);

    bool getPostNoteStatus() const;

    vector<vector<string>> getNotifications() const;

    void setNotifications(const vector<vector<string>>&);

    void readNotifications();

    void writeNotification();

    void createNotification();

    void editNotification();

    void deleteNotification();

    void postNotification();
};

#endif