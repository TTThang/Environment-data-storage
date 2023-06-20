#include "Sector.hpp"
#include <random>
#include <math.h>

template<class Type>
Type Random(Type HI, Type LO){
    Type r = LO + static_cast <Type> (rand()) /( static_cast <Type> (RAND_MAX/(HI-LO)));
    return round(r*1000)/1000;
}

class DateNode{
private:
    vector<Sector*> Area;

    int Selector(){
        int tmp;
        for(int i=0;i<Area.size();i++){
            cout<<"["<<i<<"]: Khu "<<i+1<<endl;
        }
        cout<<"["<<Area.size()<<"]: Huy thao tac"<<endl;
        cout<<"Nhap lua chon cua ban: ";cin>>tmp;
        return tmp;
    }

    void DeleteSector(Sector *&tmp){
        tmp->DeleteData();
        delete tmp;
        tmp = NULL;
    }

public:
    Date date;

    void Init(int count, time_t now){
        this->date.GetToday(now);
        for(int i=0;i<count;i++){
            Sector *Stmp = CreateSector();
            this->Area.push_back(Stmp);
        }
    }

    void UpdateData(time_t now){
        for(int i=0;i<Area.size();i++){
            this->Area[i]->UpdateData(Random(10.0,50.0),Random(20.0,99.0),Random(2.0,12.0),Random(10.0,50.0),Random(20.0,99.0),Random(0.01,0.0399),Random(40,600), now);
        }
    }

    void ShowTemp(Date time){
        system("CLS");
        cout<<"Ban muon xem nhiet do cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowTemp(tmp+1, time);
    }

    void ShowHumi(Date time){
        system("CLS");
        cout<<"Ban muon xem do am cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowHumi(tmp+1, time);
    }

    void ShowPH(Date time){
        system("CLS");
        cout<<"Ban muon xem pH cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowPH(tmp+1, time);
    }

    void ShowCO2(Date time){
        system("CLS");
        cout<<"Ban muon xem nong do CO2 cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowCO2(tmp+1, time);
    }

    void ShowLumen(Date time){
        system("CLS");
        cout<<"Ban muon xem quang thong cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowLumen(tmp+1, time);
    }

    void ShowFullData(Date time,int select){
        system("CLS");
        cout<<"Ban muon xem du lieu cua khu vuc nao:"<<endl;
        int tmp = Selector();
        if(tmp==Area.size())
            return;
        Sector *Stmp;
        Stmp = this->Area[tmp];
        Stmp->ShowFullData(tmp+1,time,select);
    }

    void IncludeSector(int tmp){
        for(int i=0;i<tmp;i++){
            Sector *Stmp = CreateSector();
            this->Area.push_back(Stmp);
        }
    }

    int RemoveSector() {
        int n = 0, tmp = 0 ;
        while (tmp < Area.size()) {
            system("CLS");
            if (Area.size() != 0){
                cout << " Lua chon khu vuc ban muon xoa:" << endl;
                tmp = Selector();
                if (tmp >= Area.size())
                    break;
                n++;
                DeleteSector(this->Area[tmp]);
                Area.erase(Area.begin() + tmp);
            }
            else {
                tmp = 1;
                cout << " Hien khong con khu vuc quan ly nao!" << endl;
                cout << " Nhap phim bat ki de tiep tuc chuong trinh!";
                system("pause >nul");
            }
        }
        return n;
    }

    void DeleteData(){
        for(int i=0;i<Area.size();i++){
            DeleteSector(this->Area[i]);
        }
        Area.clear();
    }

};

DateNode *CreateDateNode(int count, time_t now){
    DateNode *daynode = new DateNode;
    daynode->Init(count,now);
    return daynode;
}
