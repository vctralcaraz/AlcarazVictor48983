/* 
 * File:   Date.h
 * Author: rcc
 *
 * Created on October 12, 2015, 2:54 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date {
private:
    int month;
    int day;
    int year;
public:
    void print();
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
};

#endif	/* DATE_H */

