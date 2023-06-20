#include "Binary_tree.hpp"

class Dirt{
public:
    BTree Temperature;
    BTree Humidity;
    BTree pH;

    void UpdateData(float Temp, float Humi, float pH, time_t now){
        this->Temperature.InsertNode(Temp, now);
        this->Humidity.InsertNode(Humi, now);
        this->pH.InsertNode(pH, now);
    }

    void ShowTemp(int i, Date time){
        string message1 = "Nhiet do trung binh cua dat kha thap, can don trong dat va thu gon mai che de dat tiep xuc anh sang tot!!";
        string message2 = "Nhiet do trung binh cua dat kha cao, can bat he thong phun suong, nen che phu dat hoac bat mai che!!";
        Temperature.Show(message1, message2, 20, 35, i, time, "Nhiet do cua dat");
    }

    void ShowHumi(int i, Date time){
        string message1 = "Do am cua dat kha thap, can bat he thong phun suong hoac giam nhiet do cua dat xuong!!";
        string message2 = "Do am cua dat kha cao, can giam luong nuoc tuoi hoac tang nhiet do cua dat len!!";
        Humidity.Show(message1, message2, 50, 80, i, time, "Do am cua dat");
    }

    void ShowPH(int i, Date time){
        string message1 = "Do pH cua dat kha thap, nen bon them phan lan hoac voi de tang len!!";
        string message2 = "Do pH cua dat kha cao, can bon cac loai phan huu co de giam xuong!!";
        pH.Show(message1, message2, 6, 8, i, time, "Do pH cua dat");
    }

    void DeleteData(){
        Temperature.Delete();
        Humidity.Delete();
        pH.Delete();
    }

};
class Air{
public:
    BTree Temperature;
    BTree Humidity;
    BTree Cacbon_dioxide;

    void UpdateData(float Temp, float Humi, float CO2, time_t now){
        this->Temperature.InsertNode(Temp, now);
        this->Humidity.InsertNode(Humi, now);
        this->Cacbon_dioxide.InsertNode(CO2, now);
    }

    void ShowTemp(int i, Date time){
        string message1 = "Nhiet do trung binh cua khong khi kha thap, can thu gon mai che hoac tang do sang!!";
        string message2 = "Nhiet do trung binh cua khong khi kha cao, nen che bot sang, bat he thong phun suong hoac bat he thong thong khi!!";
        Temperature.Show(message1, message2, 20, 35, i, time, "Nhiet do cua khong khi");
    }

    void ShowHumi(int i, Date time){
        string message1 = "Do am trung binh cua khong khi kha thap, can bat he thong phun suong, giam hoat dong cua he thong thong khi!!";
        string message2 = "Do am trung binh cua khong khi kha cao, can bat he thong thong khi, tang nhiet do khong khi len!!";
        Humidity.Show(message1, message2, 50, 80, i, time, "Do am cua khong khi");
   }

    void ShowCO2(int i, Date time){
        string message1 = "Do am trung binh cua khong khi kha thap, can bat he thong phun suong, giam hoat dong cua he thong thong khi!!";
        string message2 = "Do am trung binh cua khong khi kha cao, can bat he thong thong khi, tang nhiet do khong khi len!!";
        Cacbon_dioxide.Show(message1, message2, 0.025, 0.035, i, time, "Nong do CO2 cua khong khi");
    }

    void DeleteData(){
        Temperature.Delete();
        Humidity.Delete();
        Cacbon_dioxide.Delete();
    }

};
class Sector{
private:
    Dirt Dirt;
    Air Air;
    BTree Lumen;
public:

    void UpdateData(float Temp1, float Humi1, float pH, float Temp2, float Humi2, float CO2, float Lumen, time_t now){
        this->Dirt.UpdateData(Temp1, Humi1, pH, now);
        this->Air.UpdateData(Temp2, Humi2, CO2, now);
        this->Lumen.InsertNode(Lumen, now);
    }

    void ShowTemp(int i, Date time){
        bool tmp;
        system("CLS");
        cout<<"Ban muon xem nhiet do cua:"<<endl;
        cout<<"[0]: Dat"<<endl<<"[1]: Khong khi"<<endl;
        cout<<"Nhap lua chon cua ban: ";cin>>tmp;
        if(tmp)
            Air.ShowTemp(i, time);
        else
            Dirt.ShowTemp(i, time);
    }

    void ShowHumi(int i, Date time){
        bool tmp;
        system("CLS");
        cout<<"Ban muon xem nhiet do cua:"<<endl;
        cout<<"[0]: Dat"<<endl<<"[1]: Khong khi"<<endl;
        cout<<"Nhap lua chon cua ban: ";cin>>tmp;
        if(tmp)
            Air.ShowHumi(i, time);
        else
            Dirt.ShowHumi(i, time);
    }

    void ShowPH(int i, Date time){
        Dirt.ShowPH(i, time);
    }

    void ShowCO2(int i, Date time){
        Air.ShowCO2(i, time);
    }

    void ShowLumen(int i, Date time){
        string message1 = "Do am trung binh cua khong khi kha thap, can bat he thong phun suong, giam hoat dong cua he thong thong khi!!";
        string message2 = "Do am trung binh cua khong khi kha cao, can bat he thong thong khi, tang nhiet do khong khi len!!";
        Lumen.Show(message1, message2, 80, 400, i, time, "Quang thong");
    }

    void ShowFullData(int i,Date time,int a){
        system("CLS");
        cout << setw(105) << "" << "Khu vuc: " << i << endl;
        cout << setw(105) << "" << time << endl;
        bool Select[7] = {};
        int surplus;
        int tmp = a;
        int count=0;
        while(tmp!=1){
            surplus = tmp % 10;
            Select[surplus] = 1;
            tmp=tmp/10;
            count++;
        }
        vector<BNode*> TempDirt, HumiDirt, PH;
        vector<BNode*> TempAir, HumiAir, CO2, lumen;
        string Name[7]={"Nhiet do cua dat","Do am cua dat","Do pH cua dat","Nhiet do cua khong khi",
                        "Do am cua khong khi","Nong do khi CO2","Quang thong"};
        BNode *Min[7], *Max[7];
        float Avr[7];
        if(Lumen.root==NULL){
            cout<<setw(89)<<""<<"Hien tai chua co du lieu cap nhat!"<<endl;
            cout<<setw(85)<<""<<"Nhap phim bat ki de tiep tuc chuong trinh!";
            system("pause >nul");
            return;
        }
        for(int i=0;i<7;i++){
            if(Select[i]==0)
                continue;
            switch(i){
                case(0):{
                    if(Select[i]){
                        Dirt.Temperature.CopyData(TempDirt);
                        sort(TempDirt.begin(),TempDirt.end(),compareBNode);
                        Min[0] = Dirt.Temperature.Min(Dirt.Temperature.root);
                        Max[0] = Dirt.Temperature.Max(Dirt.Temperature.root);
                        Avr[0] = Dirt.Temperature.Avr();
                        break;
                    }
                }
                case(1):{
                    if(Select[i]){
                        Dirt.Humidity.CopyData(HumiDirt);
                        sort(HumiDirt.begin(),HumiDirt.end(),compareBNode);
                        Min[1] = Dirt.Humidity.Min(Dirt.Humidity.root);
                        Max[1] = Dirt.Humidity.Max(Dirt.Humidity.root);
                        Avr[1] = Dirt.Humidity.Avr();
                        break;
                    }
                }
                case(2):{
                    if(Select[i]){
                        Dirt.pH.CopyData(PH);
                        sort(PH.begin(),PH.end(),compareBNode);
                        Min[2] = Dirt.pH.Min(Dirt.pH.root);
                        Max[2] = Dirt.pH.Max(Dirt.pH.root);
                        Avr[2] = Dirt.pH.Avr();
                        break;
                    }
                }
                case(3):{
                    if(Select[i]){
                        Air.Temperature.CopyData(TempAir);
                        sort(TempAir.begin(),TempAir.end(),compareBNode);
                        Min[3] = Air.Temperature.Min(Air.Temperature.root);
                        Max[3] = Air.Temperature.Max(Air.Temperature.root);
                        Avr[3] = Air.Temperature.Avr();
                        break;
                    }
                }
                case(4):{
                    if(Select[i]){
                        Air.Humidity.CopyData(HumiAir);
                        sort(HumiAir.begin(),HumiAir.end(),compareBNode);
                        Min[4] = Air.Humidity.Min(Air.Humidity.root);
                        Max[4] = Air.Humidity.Max(Air.Humidity.root);
                        Avr[4] = Air.Humidity.Avr();
                        break;
                    }
                }
                case(5):{
                    if(Select[i]){
                        Air.Cacbon_dioxide.CopyData(CO2);
                        sort(CO2.begin(),CO2.end(),compareBNode);
                        Min[5] = Air.Cacbon_dioxide.Min(Air.Cacbon_dioxide.root);
                        Max[5] = Air.Cacbon_dioxide.Max(Air.Cacbon_dioxide.root);
                        Avr[5] = Air.Cacbon_dioxide.Avr();
                        break;
                    }
                }
                case(6):{
                    if(Select[i]){
                        Lumen.CopyData(lumen);
                        sort(lumen.begin(),lumen.end(),compareBNode);
                        Min[6] = Lumen.Min(Lumen.root);
                        Max[6] = Lumen.Max(Lumen.root);
                        Avr[6] = Lumen.Avr();
                        break;
                    }
                }
            }
        }
        vector<vector<BNode*> > Data{TempDirt, HumiDirt, PH, TempAir, HumiAir, CO2, lumen};
        int align = (211 - 30*count)/2;
        cout<<setw(align)<<"";
        for(int i=0;i<7;i++){
            if(Select[i]){
                for(int j=1;j<=30;j++)
                    cout<<"_";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i])
                cout<<setw(29)<<left<<Name[i]<<"|";
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i]){
                cout<<left<<"Gia tri trung binh: "<<setw(9)<<left<<Avr[i]<<"|";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            //cout<<Select[i];
            if(Select[i]){
                cout<<setw(29)<<left<<"Gia tri nho nhat: "<<"|";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i]){
                cout<<setw(7)<<left<<Min[i]->value<<"    "<<Min[i]->time<<setw(11)<<right<<"|";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i]){
                cout<<setw(29)<<left<<"Gia tri lon nhat: "<<"|";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i]){
                cout<<setw(7)<<left<<Max[i]->value<<"    "<<Max[i]->time<<setw(11)<<right<<"|";
            }
        }
        cout<<endl;
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            //cout<<Select[i];
            if(Select[i]){
                cout<<setw(10)<<right<<"Gia tri"<<setw(19)<<left<<"    Thoi gian"<<"|";
            }
        }
        cout<<endl;
        int color;
        for(int line=0;line<Lumen.CountNode();line++){
            cout<<setw(align-1)<<""<<"|";
            color++;
            if(color>5){
                color=1;
            }
            for(int type=0;type<7;type++){
                if(Select[type]){
                    SetConsoleTextAttribute(hConsole, (color+1)+15*16);
                    cout<<setw(10)<<right<<Data[type][line]->value<<"    "<<Data[type][line]->time<<setw(8)<<right;
                    SetConsoleTextAttribute(hConsole, 0+15*16);
                    cout<<"|";
                }
            }
            cout<<endl;
        }
        cout<<setw(align-1)<<""<<"|";
        for(int i=0;i<7;i++){
            if(Select[i]){
                for(int j=1;j<=29;j++)
                    cout<<"_";
                cout<<"|";
            }
        }
        cout<<endl;
        cout<<setw(85)<<""<<"Nhap phim bat ki de tiep tuc chuong trinh!";
        system("pause >nul");
    }

    void DeleteData(){
        Dirt.DeleteData();
        Air.DeleteData();
        Lumen.Delete();
    }

};

Sector *CreateSector(){
    Sector *sector = new Sector;
    return sector;
}
