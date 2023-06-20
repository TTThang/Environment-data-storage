class Date{
private:
    int day,month,year;
public:

    Date(int day=0, int month=0, int year=0){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void GetToday(time_t now = time(0)){
        tm *ltm = localtime(&now);
        this->day = ltm->tm_mday;
        this->month = 1 + ltm->tm_mon;
        this->year = 1900 + ltm->tm_year;
    }

    friend ostream &operator<<(ostream &out, Date &tmp){
        out<<setfill('0');
        out<<setw(2)<<right<<tmp.day<<"/"<<setw(2)<<right<<tmp.month<<"/"<<tmp.year;
        out<<setfill(' ');
        return out;
    }
};

class Time{
private:
    int sec,min,hour;
public:

    Time(int hour=0, int min=0, int sec=0){
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    void Now(time_t now = time(0)){
        tm *ltm = localtime(&now);
        this->hour = ltm->tm_hour;
        this->min = ltm->tm_min;
        this->sec = ltm->tm_sec;
    }

    friend ostream &operator<<(ostream &out, Time &tmp){
        out<<setfill('0');
        out<<setw(2)<<right<<tmp.hour<<":"<<setw(2)<<right<<tmp.min<<":"<<setw(2)<<tmp.sec;
        out<<setfill(' ');
        return out;
    }

    bool operator<(Time a){
        int tmp1 = hour*3600 + min*60 + sec;
        int tmp2 = a.hour*3600 + a.min*60 + a.sec;
        if(tmp1 >= tmp2)
            return 0;
        return 1;
    }

    bool operator>(Time a){
        int tmp1 = hour*3600 + min*60 + sec;
        int tmp2 = a.hour*3600 + a.min*60 + a.sec;
        if(tmp1 <= tmp2)
            return 0;
        return 1;
    }

    bool operator==(Time a){
        if(this->sec==a.sec)
            if(this->min==a.min)
                if(this->hour == a.hour)
                    return 1;
        return 0;
    }

    int operator-(Time a){
        return this->sec - a.sec + (this->min-a.min)*60 + (this->hour-a.hour)*3600;
    }
};

int CheckDay(time_t time) {
    Time a;
    a.Now(time);
    Time b(23, 59, 59);
    int c = b - a + 1;
    return c;
}

void NextDay(time_t& time) {
    int a = CheckDay(time);
    time = time + a;
}
