/* 
 * File:   Rectangle.h
 * Author: rcc
 *
 * Created on October 12, 2015, 2:30 PM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

class Rectangle{
    private:
        int width;
        int length;
    public:
        void setWidth(int);
        void setLength(int);
        int getWidth() const;
        int getLength() const;
        int getArea() const;
};

#endif	/* RECTANGLE_H */

