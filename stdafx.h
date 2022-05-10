#pragma once

#pragma comment(lib, "d2d1.lib")

#include <Windows.h>
#include <CommCtrl.h>
#include <iostream>

#include <d2d1.h>
#include <d2d1_1.h>

#define WindowClassName L"BaseWindow"
#define WindowMenuName L"Direct2DPingPong!"

#define HInstance GetModuleHandle(NULL)