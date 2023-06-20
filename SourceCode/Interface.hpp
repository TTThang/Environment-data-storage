#include <fstream>
#include <windows.h>

#pragma comment(lib, "user32")
string getFileContents (std::ifstream& File){
    string Lines = "";
    if(File){
        while (File.good ()){
            string TempLine;
            getline (File , TempLine);
            TempLine += "\n";
            for(int i=0;i<73;i++){
                TempLine += " ";
            }
            Lines += TempLine;
        }
        return Lines;
    }
}

void LogoStartup(){
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    cout<<setw(80)<<""<<"CHAO MUNG DEN VOI CHUONG TRINH QUAN LY NHA KINH 4 TY"<<endl;
    ifstream Reader ("Logo");
    string Art = getFileContents (Reader);
    cout<< Art << std::endl;
    Reader.close ();
    cout<<setw(87)<<""<<"Nhap phim bat ki de vao chuong trinh!!!";
    system("pause >nul");
    system("CLS");
}

int MainScreen(time_t time){
    system("CLS");
    Date SimulationDate;
    SimulationDate.GetToday(time);
    Time SimulationTime;
    SimulationTime.Now(time);
    cout<<" Thoi gian khoi dong chuong trinh: "<<StartupTime<<"_"<<StartupDate<<endl<<endl;
    cout<<setw(71)<<""<<"*********************************************************************"<<endl; //69 char
    cout<<setw(71)<<""<<"*             _CHUONG TRINH QUAN LY HE THONG NHA KINH_              *"<<endl;
    cout<<setw(71)<<""<<"* Lap trinh boi Nhom 12:                                            *"<<endl;
    cout<<setw(71)<<""<<"*     ::.  :                                                        *"<<endl;
    cout<<setw(71)<<""<<"*    .--- -= ..           Ho va ten           Ma so sinh vien       *"<<endl;
    cout<<setw(71)<<""<<"*     ---. #- ---::..                                               *"<<endl;
    cout<<setw(71)<<""<<"*   :--: +*= ..:-----.    Tran Toan Thang     20139015              *"<<endl;
    cout<<setw(71)<<""<<"*  .--- .*##*=-. ::::                                               *"<<endl;
    cout<<setw(71)<<""<<"*  ::::.. .-+**. :..      Dinh Thanh Tung     20139096              *"<<endl;
    cout<<setw(71)<<""<<"*  ....:... :*: :...                                                *"<<endl;
    cout<<setw(71)<<""<<"*      ...: :+ ....       Mai Van Anh         20139059              *"<<endl;
    cout<<setw(71)<<""<<"*           :: :.:                                                  *"<<endl;
    cout<<setw(71)<<""<<"*            : .:         Nguyen Ba Quoc Tai  20139089              *"<<endl;
    cout<<setw(71)<<""<<"*   Thoi gian gia lap: "<<SimulationTime<<"_"<<SimulationDate<<"                          *"<<endl;
    cout<<setw(71)<<""<<"*   So khu vuc dang quan ly: "<<setw(3)<<left<<Main.CountSector<<"                                    *"<<endl;
    cout<<setw(71)<<""<<"*   Thoi gian cap nhat du lieu(phut): "<<setw(3)<<left<<TimerUpdate<<"                           *"<<endl;
    cout<<setw(71)<<""<<"*********************************************************************"<<endl;
    cout<<setw(71)<<""<<"\tHay chon thao tac muon thuc hien:"<<endl;
    cout<<setw(71)<<""<<"\t[0] Gia lap thoi gian cap nhat du lieu."<<endl;
    cout<<setw(71)<<""<<"\t[1] Gia lap thoi gian qua ngay hom sau."<<endl;
    cout<<setw(71)<<""<<"\t[2] Kiem tra du lieu cua ngay hom nay."<<endl;
    cout<<setw(71)<<""<<"\t[3] Kiem tra du lieu cua cac ngay truoc."<<endl;
    cout<<setw(71)<<""<<"\t[4] Them khu vuc quan ly."<<endl;
    cout<<setw(71)<<""<<"\t[5] Xoa khu vuc quan ly."<<endl;
    cout<<setw(71)<<""<<"\t[6] Thoat chuong trinh."<<endl<<endl;
    cout<<setw(71)<<""<<"\tNhap thao tac muon thuc hien: ";
    int tmp;cin>>tmp;
    return tmp;
}

void ExitScreen(int ExitTime) {
    for (int i = ExitTime; i >= 1; i--) {
        system("CLS");
        ifstream Reader("Logo");
        string Art = getFileContents(Reader);
        cout << Art << std::endl;
        Reader.close();
        cout << setw(87) << "" << "CAM ON BAN DA SU DUNG CHUONG TRINH!!!" << endl;
        cout << setw(83) << "" << "Chuong trinh se tu dong thoat sau " << i << " giay...!";
        Sleep(i * 500);
    }
}
