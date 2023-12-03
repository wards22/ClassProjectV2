/* Prologue
 * Name: View Rent Receipts Info Class
 * Description: Creates and modifies tenant's Rent file
 * Contributors: Crischelle Polley
 * Date created: Dec 1 2023
 * Date last modified: Dec 3 2023
*/

/* References:
 * https://stackoverflow.com/questions/1784573/iterator-for-2d-vector
 * https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
 * https://cplusplus.com/reference/chrono/
 * https://cplusplus.com/reference/thread/thread/
 */

#pragma once
#ifndef VIEW_RENT_RECEIPTS_H
#define VIEW_RENT_RECEIPTS_H

#include <vector>
#include <string>

using namespace std;


class ViewRentReceipts {
	public:
	// Should reference be used here if this is boundary class?
	static void displayRentReceipts(const vector<vector<string>>&);         

};

#endif
