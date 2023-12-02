/* Prologue
 * Name: Manage Notifications Implementation File
 * Description: Directs tenant to different
 *              features of the Apartment Services System
 * Contributors: Crischelle Polley
 * Date created: Nov 28 2023
 * Date last modified: Nov 29 2023
*/

#include "ManageNotifications.h"
#include "Notifications.h"
#include "ViewNotifications.h"
#include <iostream>

using namespace std;

void ManageNotifications::manageNotifications(int uid, int option) {
    Notifications note;

    // [1] View Notifications
    // This will access View Notifications boundary class
    if (option == 1) {
        ViewNotifications::displayNotifications();
    }

    // Rest of options are only for staff
    // [2] Create Notification
    else if (option == 2) {
        note.createNotification();
    }

    // [3] Edit Notification
    else if (option == 3) {
        // Check if there is note waiting to be sent
        // Show notification menu if no note is waiting to be sent


        if (note.getPostNoteStatus() == false) {
            note.editNotification();
        } else {
            cout << "There is no notification to post.\n\n";
        }
    }

    // [4] Delete Notification
    else if (option == 4) {

    }

    // [5] Post Notification
    else if (option == 5) {
        if (note.getPostNoteStatus() == true) {
            note.postNotification();
        } else {
            cout << "There is no notification to post.\n\n";
        }

        cout << "You have posted the notification successfully.\n"
            << "Return to Notifications Menu and press View Notifications\n"
            << "to see new notification.\n\n";

    }

}