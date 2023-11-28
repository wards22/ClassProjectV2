/* Prologue
 * Name: Tenant Driver
 * Description: Tests TenantUI class
 * Contributors: Crischelle Polley
 * Date created: Nov 15 2023
 * Date last modified: Nov 22 2023
*/

/* References:
 * https://stackoverflow.com/questions/67515155/vscode-not-importing-functions-from-other-files-in-c-language
 * https://stackoverflow.com/questions/51117196/undefined-reference-error-in-vscode
 * CP: I was having an issue with compiling .cpp files. Calls
 *     to TenantUI class methods were not linking to TenantUI
 *     implementation file. Solution was changing tasks.json
 *     file args from ${file} to ${workspaceFolder}\\*.cpp
 */

#include "Tenant.h"
#include "TenantUI.h"

using namespace std;


int tenantui() {
    TenantUI tui;

    tui.displayMainMenu();

    return 0;
}  

