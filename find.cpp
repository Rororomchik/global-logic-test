#include "find.h"
using namespace std;
mutex printMutex;
atomic<bool> stopSearch(false);

void searchFile(const filesystem::path& directory, const string& filename)
{
    for (const auto& entry : filesystem::directory_iterator(directory))
    {
        if (stopSearch)
            return;

        if (entry.is_directory())
        {
            thread searchThread(searchFile, entry.path(), filename);
            searchThread.detach();
        }
        else if (entry.is_regular_file() && entry.path().filename() == filename)
        {
            lock_guard<mutex> lock(printMutex);
            cout << "Found file: " << entry.path() << endl;
            stopSearch = true;
        }
    }
 
}