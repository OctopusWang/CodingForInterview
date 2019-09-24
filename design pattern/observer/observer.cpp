#include"observer.h"
#include"subject.h"

int main()
{
	subject* jinli = new Boss();
	jinli->setsubjectState("Jinli is back! ");
	
	Observer* tongshi1 = new WechatObserver("xiaoli",jinli);
	Observer* tongshi2 = new NewsObserver("damin",jinli);
	
	jinli->attach(tongshi1);
	jinli->attach(tongshi2);
	
	
	jinli->notify();
	delete jinli;
	delete tongshi1;
	delete tongshi2;
	
	system("pause");
	return 0;
}
