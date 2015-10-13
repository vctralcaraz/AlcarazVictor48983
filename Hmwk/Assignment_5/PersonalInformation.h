/* 
 * File:   PersonalInformation.h
 * Author: Victor Alcaraz
 * Created on October 13, 2015, 9:38 AM
 */

#ifndef PERSONALINFORMATION_H
#define	PERSONALINFORMATION_H

class PersonalInformation {
    private:
        string name;
        string address;
        int age;
        long long phone;
    public:
        void setName(string);
        void setAdd(string);
        void setAge(int);
        void setPhne(long long);
        void print();
        string getName(){return name;}
};

#endif	/* PERSONALINFORMATION_H */

