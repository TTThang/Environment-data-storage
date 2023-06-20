#include "Date_time.hpp"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class BNode{
public:
    float value;
    Time time;
    BNode *pLeft;
    BNode *pRight;
};

BNode *CreateNode(float data, time_t now){
    BNode *node = new BNode;
    node->value = data;
    node->time.Now(now);
    node->pLeft = node->pRight = NULL;
    return node;
}

bool compareBNode(BNode *a, BNode *b){
    return (a->time<b->time);
}

class BTree{
public:
    BNode *root = NULL;
    int CountNode(BNode *tmp){
        if(tmp==NULL)
            return 0;
        else
            return 1 + CountNode(tmp->pLeft) + CountNode(tmp->pRight);
    }

    float Sum(BNode *tmp){
        if(tmp==NULL)
            return 0;
        else
            return tmp->value + Sum(tmp->pLeft) + Sum(tmp->pRight);
    }

    BNode *Min(BNode *tmp){
        if(tmp->pLeft==NULL)
            return tmp;
        else
            return Min(tmp->pLeft);
    }

    BNode *Max(BNode *tmp){
        if(tmp->pRight==NULL)
            return tmp;
        else
            return Max(tmp->pRight);
    }

    void InOrder(BNode *root, int &color){
        if(root!=NULL){
            InOrder(root->pLeft,color);
            SetConsoleTextAttribute(hConsole, (color+1)+15*16);
            cout<<setw(10)<<right<<root->value<<"\t "<<root->time<<endl;
            color++;
            if(color>5)
                color=1;
            InOrder(root->pRight,color);
        }
    }

    void CopyData(BNode *root, vector<BNode*> &M){
        if(root!=NULL){
            CopyData(root->pLeft,M);
            M.push_back(root);
            CopyData(root->pRight,M);
        }
    }

    void DeleteSubtree(BNode *&tmp){
        if(tmp==NULL){
            return;
        }
        DeleteSubtree(tmp->pLeft);
        DeleteSubtree(tmp->pRight);
        delete tmp;
        tmp = NULL;
    }

    void InsertNode(float data, time_t now){
        BNode *node = CreateNode(data, now);
        if(root == NULL){
            root = node;
        }
        else{
            BNode *Tmp = root;
            BNode *Parent = NULL;
            while(Tmp){
                Parent = Tmp;
                if(Tmp->value>node->value)
                    Tmp = Tmp->pLeft;
                else
                    Tmp = Tmp->pRight;
            }
            if(Parent->value>node->value)
                Parent->pLeft = node;
            else
                Parent->pRight = node;
        }
    }
    int CountNode(){
        return CountNode(root);
    }

    float Sum(){
        return Sum(root);
    }

    float Avr(){
        return Sum()/float(CountNode());
    }

    void ShowMin(float Warning){
        cout<<"Gia tri nho nhat: ";
        if(Min(root)->value<=Warning){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<setw(6)<<right<<Min(root)->value<<"\t"<<Min(root)->time<<"  (Canh bao!!!)"<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else{
            cout<<setw(6)<<right<<Min(root)->value<<"\t"<<Min(root)->time<<endl;
        }
    }

    void ShowMax(float Warning){
        cout<<"Gia tri lon nhat: ";
        if(Max(root)->value>=Warning){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<setw(6)<<right<<Max(root)->value<<"\t"<<Max(root)->time<<"  (Canh bao!!!)"<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else{
            cout<<setw(6)<<right<<Max(root)->value<<"\t"<<Max(root)->time<<endl;
        }
    }

    void Delete(){
        DeleteSubtree(root);
    }

    void CopyData(vector<BNode*> &M){
        CopyData(root,M);
    }

    void ShowByTime(string message1, string message2, int min, int max, int i, Date time, string Name){
        system("CLS");
        cout << " Khu vuc: " << i << endl << " " << time << endl <<  " " << Name << endl;
        if(root==NULL){
            cout<<"Khong co gia tri duoc cap nhat!"<<endl;
            cout<<"Nhap phim bat ki de tiep tuc chuong trinh!"<<endl;
            system("pause >nul");
            return;
        }
        cout<<"Gia tri trung binh: ";
        float avr = Avr();
        if(avr<=min){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<avr<<endl;
            cout<<message1<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else if(avr>=max){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<avr<<endl;
            cout<<message2<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else
            cout<<avr<<endl;
        ShowMin(min);
        ShowMax(max);
        cout<<endl<<setw(10)<<right<<"Gia tri"<<"\tThoi gian"<<endl;
        cout<<setfill('-');
        cout<<setw(25)<<"-"<<endl;
        cout<<setfill(' ');
        int countnode = CountNode();
        vector<BNode*> tmp;
        CopyData(root, tmp);
        sort(tmp.begin(),tmp.end(),compareBNode);
        int color=0;
        for(int i=0;i<countnode;i++){
            color++;
            if(color>5)
                color=1;
            SetConsoleTextAttribute(hConsole, (color+1)+15*16);
            cout<<setw(10)<<right<<tmp[i]->value<<"\t "<<tmp[i]->time<<endl;
        }
        SetConsoleTextAttribute(hConsole, 0+15*16);
        cout<<endl<<"Nhap phim TAB de sap xep theo gia tri!"<<endl;
        cout<<"Nhap phim bat ki de tiep tuc chuong trinh!"<<endl;
        system("pause >nul");
        if ((GetKeyState(VK_TAB) & 0x8000))
            {
                Show(message1,message2, min, max, i, time, Name);
            }
    }

    void Show(string message1, string message2, int min, int max, int i, Date time, string Name){
        system("CLS");
        cout << " Khu vuc: " << i << endl << " " << time << endl <<  " " << Name << endl;
        if(root==NULL){
            cout<<"Khong co gia tri duoc cap nhat!"<<endl;
            cout<<"Nhap phim bat ki de tiep tuc chuong trinh!"<<endl;
            system("pause >nul");
            return;
        }
        cout<<"Gia tri trung binh: ";
        float avr = Avr();
        if(avr<=min){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<avr<<endl;
            cout<<message1<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else if(avr>=max){
            SetConsoleTextAttribute(hConsole, 4+15*16);
            cout<<avr<<endl;
            cout<<message2<<endl;
            SetConsoleTextAttribute(hConsole, 0+15*16);
        }
        else
            cout<<Avr()<<endl;
        ShowMin(min);
        ShowMax(max);
        cout<<endl<<setw(10)<<right<<"Gia tri"<<"\tThoi gian"<<endl;
        cout<<setfill('-');
        cout<<setw(25)<<"-"<<endl;
        cout<<setfill(' ');
        int color = 1;
        InOrder(root, color);
        cout<<endl;
        SetConsoleTextAttribute(hConsole, 0+15*16);
        cout<<"Nhap phim TAB de sap xep theo thoi gian!"<<endl;
        cout<<"Nhap phim bat ki de tiep tuc chuong trinh!"<<endl;
        system("pause >nul");
        if ((GetKeyState(VK_TAB) & 0x8000))
            {
                ShowByTime(message1, message2, min, max, i, time, Name);
            }
    }
};
