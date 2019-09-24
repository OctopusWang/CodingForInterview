#ifndef OBSERVER_H 
#define OBSERVER_H

#include"subject.h"
class subject;

class Observer
{
public:	
	Observer();
	Observer(std::string name, subject* sub);
	~Observer();
	virtual void update();
	bool operator==(const Observer&)const;//
protected:
	std::string name;
	subject* sub;

};

class WechatObserver:public Observer
{
public:
	WechatObserver();
	WechatObserver(std::string name,subject* sub);
	~WechatObserver();
	void update();	
	
};

class NewsObserver:public Observer
{
public:
	NewsObserver();
	NewsObserver(std::string name,subject* sub);
	~NewsObserver();
	void update();
	
	
};
#endif
