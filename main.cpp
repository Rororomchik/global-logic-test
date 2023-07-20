#include "find.h"

using namespace std;

int main()
{
    string filename;
    cout << "Enter the file name to search: ";
    cin >> filename;

    thread searchThread(searchFile, "/", filename);
    searchThread.join();

    return 0;
}