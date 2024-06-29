#ifndef DATA_H
#define DATA_H
#include <QString>
#include <vector>
#include <string>

extern std::string income[7];//彩票，工资，兼职，借入资金，奖金，补贴，其他
extern std::string outcome[7];

extern int rank_now;
/*extern int rank_income_now;
extern int rank_outcome_now;*/
extern double income_all;
extern double outcome_all;
extern double net_income;

struct data_inf{
    int year;
    int month;
    int day;
    int rank;//代表这一天的第几次数据；
    bool operator<(const data_inf & d){
        if(year!=d.year)return year<d.year;
        if(month!=d.month)return month<d.month;
        if(day!=d.day)return day<d.day;
        return rank<d.rank;
    }
    data_inf(int y=2024,int m=1,int d=1,int r=1):year(y),month(m),day(d),rank(r){};
};

struct bill_one{
    data_inf bill_data;
    std::string name;
    int label;
    bool isincome;
    double money;
    QString remark=QString("无");
    bool operator<(const bill_one & b){
        return bill_data<b.bill_data;
    }
};
extern std::vector<bill_one> bill_all;
#endif // DATA_H
