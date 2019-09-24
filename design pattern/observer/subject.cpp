#include"subject.h"
std::string subject::getsubjectState()
{
	return subjectState;
	
}

void subject::setsubjectState(std::string state)
{
	this->subjectState = state;//why this pointer?
}

void Boss::attach(Observer* observer)
{
	observers.push_back(observer);

}

void Boss::detach(Observer* observer)
{
	std::vector<Observer*>::iterator it;
	for(it=observers.begin();it!=observers.end();it++)
	{
		if(*it==observer)
			observers.erase(it);
		break;
	}
	
}

void Boss::notify()
{
	std::vector<Observer*>::iterator it;
	for(it=observers.begin();it!=observers.end();it++)
	{
		(*it)->update();
	}
	
}
