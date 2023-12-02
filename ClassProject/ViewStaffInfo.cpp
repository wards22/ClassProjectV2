/* Prologue
 * Name: View Staff Info
 * Description: Displays Staff Contact Information
 * Contributors: Scott Ward
 * Date created: Dec 1 2023
 * Date last modified: Dec 1 2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "ViewStaffInfo.h"

void ViewStaffInfo::displayStaffInfo() {
    fstream userRecordsFile;

    userRecordsFile.open("UserRecords.csv", ios::in);

    vector<string> row;
    string line, data;

    while (getline(userRecordsFile, line)) {
        row.clear();
        stringstream s(line);

        while (getline(s, data, ',')) {
            row.push_back(data);
        }

        if (row[3] == "Staff") {
            cout << row[4] << "'s contact information:" << endl;
            cout << "\tPhone Number: " << row[5] << endl;
            cout << "\tEmail: " << row[6] << endl << endl;
        }
    }

    userRecordsFile.close();
}