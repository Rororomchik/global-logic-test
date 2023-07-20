#pragma once
#ifndef _FINDH

#define _FINDH
using namespace std;
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <filesystem>

void searchFile(const filesystem::path& directory, const string& filename);

#endif