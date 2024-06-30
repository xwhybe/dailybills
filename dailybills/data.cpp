#include "data.h"

std::string income[7] = {"lottery", "salary", "part-time job", "borrowed fund", "bonus", "subsidy", "other income"};
std::string outcome[7] = {"shopping", "food", "car fare", "entertainment", "medical treatment", "education", "other outcome"};
int rank_now = 1;
double income_all = 0;
double outcome_all = 0;
double net_income = 0;
std::vector<bill_one> bill_all;
