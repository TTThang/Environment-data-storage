#include <iostream>
using namespace std;
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <vector>
#include <random>
#include <math.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include "MainProgram.hpp"

MainProgram Main;
Date StartupDate;
Time StartupTime;
int TimerUpdate;

#include "Interface.hpp"

int main() {
    system("Color F0");
    LogoStartup();
    StartupDate.GetToday();
    StartupTime.Now();
    time_t SimulationNow = time(0);
    Main.Init(SimulationNow);
    cout << " Nhap thoi gian cap nhat du lieu (don vi phut): "; cin >> TimerUpdate;
    int quit = 0;
    int tmp;
    while (!quit) {
        system("Color F0");
        tmp = MainScreen(SimulationNow);
        switch (tmp) {
        case(0):
        {
            SimulationNow += (TimerUpdate * 60);
            Main.UpdateData(SimulationNow);
            break;
        }
        case(1):
        {
            int i = SimulationNow + CheckDay(SimulationNow);
            while (SimulationNow < i ) {
                Main.UpdateData(SimulationNow);
                SimulationNow += 3600;
            }
            SimulationNow -= 86400;
            NextDay(SimulationNow);
            Main.PushDateNode(SimulationNow);
            break;
        }
        case(2):
        {
            Main.ShowData();
            break;
        }
        case(3):
        {
            Main.ShowData(Main.Selector());
            break;
        }
        case(4):
        {
            system("CLS");
            int tmp;
            cout << " Nhap so khu vuc muon them: "; cin >> tmp;
            Main.IncludeSector(tmp);
            Main.CountSector += tmp;
            break;
        }
        case(5):
        {
            Main.CountSector -= Main.RemoveSector() ;
            break;
        }
        case(6):
        {
            ExitScreen(3);
            quit = 1;
            break;
        }
        }
    }
    return 0;
}
