#ifndef _VOBJ_H
#define _VOBJ_H

#define VOBJ_PARENT_CLASS obj

class vobj :public obj
{
public:
	FLOAT x;
	FLOAT y;
	FLOAT sx;
	FLOAT sy;
	HGE *m_hge;
	hgeSprite* m_hgeSprite;

    vobj();
	~vobj();

	virtual BOOL RenderFunc(FLOAT dt);
};

#endif

