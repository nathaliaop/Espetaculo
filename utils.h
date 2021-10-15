#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <algorithm>

using namespace std;

/// Biblioteca para ajudar na valida�ao de classes que possuam String.
class StringUtils {
    private:
        string test;
    public:
        StringUtils(string _test) {
            test = _test;
        }

        size_t size() {
            return test.size();
        }

        bool hasDigit() {
            for(char c : test){
                if(c >= '0' && c <= '9')
                    return true;
            }
            return false;
        }

        bool allUpperCase() {
            for(char c : test) {
                if(c < 'A' && c > 'Z')
                    return false;
            }
            return true;
        }
        bool AllDigits() {
            for(char c : test) {
                if(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6'
                   && c != '7' && c != '8' && c != '9' && c != '0')
                    return false;
            }
            return true;
        }
        bool allLowerCase() {
            for(char c : test) {
                if(c < 'a' && c > 'z')
                    return false;
            }
            return true;
        }
        bool allDigit() {
            for(char c : test){
                if(c < '0' && c > '9')
                    return false;
            }
            return true;
        }

        bool equalsTo(string other) {
            return test.compare(other) == 0 ? true : false;
        }

        bool endsWith(string suffix) {
            if(suffix.size() > test.size())
                return false;
            size_t i = test.size()-suffix.size();
            size_t j = 0;
            for(;i < test.size() && j < suffix.size();i++, j++){
                if(test[i] != suffix[j])
                    return false;
            }
            return true;
        }

        bool beginWith(string prefix) {
            if(prefix.size() > test.size())
                return false;
            size_t i = 0, j = 0;
            for(;i < test.size() && j < prefix.size(); i++, j++) {
                if(test[i] != prefix[j])
                    return false;
            }
            return true;
        }

        bool allAlphaDigitEmailSpecial() {
            for(char c : test){
                if((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9') && (c != '@') && (c != '.') &&
                   (c != '!') && (c != '#') && (c != '$') && (c != '%') && (c != '&') && (c != '\'') &&
                   (c != '*') && (c != '+') && (c != '-') && (c != '/') && (c != '=') && (c != '?') &&
                   (c != '^') && (c != '_') && (c != '`') && (c != '{') && (c != '|') && (c != '}') && (c != '~'))
                    return false;
            }
            return true;
        }

        bool allAlphaDigitSpecial() {
            for(char c : test){
                if((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9') &&
                   (c != '!') && (c != '@') && (c != '#') && (c != '$') && (c != '%') && (c != '&') && (c != '?'))
                    return false;
            }
            return true;
        }

        bool allAlphaSpaceComma() {
            for(char c : test){
                if((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c != '.') && (c != ' '))
                    return false;
            }
            return true;
        }

        bool hasAt() {
            for(char c : test){
                if(c == '@')
                    return true;
            }
            return false;
        }

        bool hasAlpha() {
            for(char c : test){
                if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                    return true;
            }
            return false;
        }

        bool hasSpecial() {
            for(char c : test){
                if((c == '!') || (c == '@') || (c == '#') || (c == '$') || (c == '%') || (c == '&') || (c == '?'))
                    return true;
            }
            return false;
        }

        bool hasRepeatedchar() {
            sort(test.begin(), test.end());
            for (int i = 0; i < test.size() - 1; i++){
               if(test[i] == test[i + 1]) return true;
            }
            return false;
        }

        bool hasSequencespace() {
            for (int i = 0; i < test.size() - 1; i++){
                if (test[i] == ' ' && test[i+1] == ' ')
                    return true;
            }
            return false;
        }

        bool hasNoLetterb4comma() {
            for (int i = 1; i < test.size(); i++){
                if (test[i] == '.' && ((test[i-1] < 'a' || test[i-1] > 'z') && (test[i-1] < 'A' || test[i-1] > 'Z')))
                    return true;
            }
            return false;
        }

        bool isFirstUpperAfterSpace() {
            for (int i = 0; i < test.size() - 1; i++){
                if (test[i] == ' ' && (test[i+1] < 'A' || test[i+1] > 'Z'))
                    return false;
            }
            return true;
        }

        bool isFirstUpper() {
            if ((test[0] < 'A' || test[0] > 'Z')) {
                return false;
            }
            return true;
        }

        bool hasSequenceComma() {
            for (int i = 0; i < test.size() - 1; i++)
                if (test[i] == '.' and test[i+1] == '.')
                    return true;
            return false;
        }

        int sizeBeforeAt() {
            int size = 0;
            for (int i = 0; test[i] != '@'; i++)
                size++;
            return size;
        }

        int sizeAfterAt() {
            int size = 0;
            bool after = false;
            for (int i = 0; i < test.size(); i++)
                if (test[i] == '@'){
                    after = true;
                }
                else if (after){
                    size++;
                }
            return size;
        }
};

/// Biblioteca para ajudar na valida�ao da classe Data.
class DataUtils{
    private:
        int day,month,year;
        string data;
    public:
        DataUtils(string _data){
            data = _data;
        }

        bool isDataInForm(){
            if(data[2] != '/' && data[5] != '/')
                return false;
            return true;
        }

        int dataDay(){
            string strDay;
            strDay.append(data,0,2);
            day = stoi(strDay);
            return day;
        }

        int dataMonth(){
            string strMonth;
            strMonth.append(data,3,2);
            month = stoi(strMonth);
            return month;
        }

        int dataYear(){
            string strYear;
            strYear.append(data,6,4);
            year = stoi(strYear);
            return year;
        }

        bool isValid(){
            year = dataYear(), month = dataMonth(), day = dataDay();
            if(year >=2000 && year <= 9999)
                if(month >= 01 && month <= 12)
                    if(month == 11 || month == 9 || month == 6 || month == 4){
                        if(day >= 1 && day <= 30)
                            return true;
                    }
                    //Ano bissexto
                    else if(month == 2){
                        if(year%4 == 0){
                            if(day >= 1 && day <= 29)
                                return true;
                        }
                        else
                            if(day>= 1 && day <= 28)
                                return true;
                    }
                    else{
                        if(day >=1 && day <= 31)
                            return true;
                    }
            return false;
        }
};

#endif // UTILS_H_INCLUDED
