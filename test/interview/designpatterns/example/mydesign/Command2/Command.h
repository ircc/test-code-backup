#ifndef _COMMAND_H_ 
#define _COMMAND_H_

template <class Reciever> 
class SimpleCommand:public Command 
{ 
public: 
	typedef void (Reciever::* Action)();
	SimpleCommand(Reciever* rev,Action act) 
	{ 
		_rev = rev;
		_act = act; 
	}

	virtual void Excute() 
	{
		(_rev->* _act)(); 
	}

	~SimpleCommand() 
	{
		delete _rev; 
	}
protected:
private: 
	Reciever* _rev;
	Action _act; 
};


#endif