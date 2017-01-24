#ifndef VIEW_H
#define VIEW_H

class View{
public:
	virtual ~View();
	virtual void notify(int, int, char) = 0;
	virtual void update(int, int, int, char) = 0;
};

#endif

