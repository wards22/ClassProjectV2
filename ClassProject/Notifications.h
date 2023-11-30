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

using namespace std;

class Notifications {
    private:
    string title;
    string content;
    bool postNoteStatus;

    string getDateTime() const;

    string formatDateTime(const char* dt) const;


    public:
    string getTitle() const
    {
        return title;
    }

    void setTitle(const string& t)
    {
        title = t;
    }

    string getContent() const
    {
        return content;
    }

    void setContent(const string& c)
    {
        content = c;
    }

    bool getPostNoteStatus() const
    {
        return postNoteStatus;
    }

    void readNotification();

    void writeNotification();

    void createNotification();

    void editNotification();

    void deleteNotification();

    void postNotification();
};

#endif