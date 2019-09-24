#include"observer.h"
void Observer::update(){}

Observer::Observer()
{

}

Observer::~Observer(){}

bool  Observer::operator==(const Observer& observer)const
{
	return (this->name== observer.name) && (this->sub== observer.sub);	
}


WechatObserver::WechatObserver(){}
NewsObserver::NewsObserver(){}
WechatObserver::~WechatObserver(){}
NewsObserver::~NewsObserver(){}

WechatObserver::WechatObserver(std::string name, subject* sub)
{
	this->name = name;
	this->sub = sub;
}

NewsObserver::NewsObserver(std::string name, subject* sub)
{
	this->name = name;
	this->sub = sub;
}


void WechatObserver::update()
{
	std::cout << sub->getsubjectState() << name<< " Turn off Wechat, go back to work."<<std::endl; 
}

void NewsObserver::update()
{
	std::cout << sub->getsubjectState() << name<<" Turn off news, go back to work."<< std::endl; 
}
