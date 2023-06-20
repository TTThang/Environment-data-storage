#include "DateNote.hpp"
class MainProgram
{
private:
    vector<DateNode*> DateData;

    int SelectData(){
        system("CLS");
        int tmp;
        cout<<"Ban muon xem du lieu nao:"<<endl;
        cout<<"\t[0] Nhiet do."<<endl;
        cout<<"\t[1] Do am."<<endl;
        cout<<"\t[2] Do pH."<<endl;
        cout<<"\t[3] Nong do CO2 trong khong khi."<<endl;
        cout<<"\t[4] Quang thong(lumen)."<<endl;
        cout<<"\t[5] Kiem tra hang loat."<<endl;
        cout<<"\t[6] Huy thao tac."<<endl;
        cout<<"Hay nhap lua chon cua ban: ";
        cin>>tmp;
        return tmp;
    }

    int SelectDatatoShowFull(){
        system("CLS");
        string tmp;
        cout<<"Ban muon xem du lieu nao:"<<endl;
        cout<<"\t[0] Nhiet do cua Dat."<<endl;
        cout<<"\t[1] Do am cua Dat."<<endl;
        cout<<"\t[2] Do pH cua Dat."<<endl;
        cout<<"\t[3] Nhiet do cua Khong khi."<<endl;
        cout<<"\t[4] Do am cua khong khi."<<endl;
        cout<<"\t[5] Nong do CO2 trong khong khi."<<endl;
        cout<<"\t[6] Quang thong(lumen)."<<endl;
        cout<<"Hay nhap cac lua chon cua ban(VD: 0423): ";
        cin>>tmp;
        tmp = '1' + tmp;
        return atoi(tmp.c_str());
    }

    void ShowTemp(Date time, int tmp = 0) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowTemp(time);
    }

    void ShowHumi(Date time, int tmp = 0) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowHumi(time);
    }

    void ShowPH(Date time, int tmp = 0) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowPH(time);
    }

    void ShowCO2(Date time, int tmp = 0) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowCO2(time);
    }

    void ShowLumen(Date time, int tmp = 0) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowLumen(time);
    }

    void ShowFullData(Date time, int select, int tmp) {
        if (tmp == DateData.size())
            return;
        DateData[tmp]->ShowFullData(time, select);
    }

public:
    int CountSector;
    int MaxCountDate;

    void Init(time_t now){
        cout<<"Vui long nhap so khu vuc ban can quan ly: ";cin>>CountSector;
        cout<<"Vui long nhap so ngay toi da can luu du lieu: ";cin>>MaxCountDate;
        DateData.push_back(CreateDateNode(CountSector, now));
    }

    void DeleteDateNode(){
        DateNode *tmp = DateData[DateData.size()-1];
        tmp->DeleteData();
        delete tmp;
        tmp = NULL;
        DateData.pop_back();
    }

    void PushDateNode(time_t now){
        if(DateData.size()>=MaxCountDate){
            DeleteDateNode();
        }
        DateData.insert(DateData.begin(), CreateDateNode(CountSector, now));
    }

    void IncludeSector(int tmp){
        DateData[0]->IncludeSector(tmp);
    }

    int RemoveSector() {
        return DateData[0]->RemoveSector();
    }

    int Selector(){
        system("CLS");
        int tmp;
        for(int i=1;i<DateData.size();i++){
            cout<<"["<<i<<"]: Ngay "<<DateData[i]->date<<endl;
        }
        cout<<"["<<DateData.size()<<"]: Huy thao tac"<<endl;
        cout<<"Hay nhap lua chon cua ban: ";cin>>tmp;
        return tmp;
    }

    void UpdateData(time_t now){
        DateData[0]->UpdateData(now);
    }

    void ShowData(int tmp = 0){
        if(tmp==DateData.size())
            return;
        int data = SelectData();
        switch(data){
            case(0):
            {
                ShowTemp(DateData[tmp]->date, tmp);
                break;
            }
            case(1):
            {
                ShowHumi(DateData[tmp]->date, tmp);
                break;
            }
            case(2):
            {
                ShowPH(DateData[tmp]->date, tmp);
                break;
            }
            case(3):
            {
                ShowCO2(DateData[tmp]->date, tmp);
                break;
            }
            case(4):
            {
                ShowLumen(DateData[tmp]->date, tmp);
                break;
            }
            case(5):
            {
                ShowFullData(DateData[tmp]->date, SelectDatatoShowFull(), tmp);
                break;
            }
        }
    }
};
