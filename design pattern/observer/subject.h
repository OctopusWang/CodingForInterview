#ifndef SUBJECT_H
#define SUBJECT_H

#include<iostream>
#include "observer.h"
#include <string>
#include <vector>
class Observer;

class subject
{
public:
	std::string subjectState;
	virtual void attach(Observer* observer)=0;
	virtual void detach(Observer* observer)=0;
	virtual void notify()=0;
	std::string getsubjectState();
	void setsubjectState(std::string state);
	std::vector<Observer*> observers;
};

class Boss:public subject
{
public:
	
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify();
		
};

#endif
