#ifndef _B2OBJ_H
#define _B2OBJ_H

#define B2OBJ_PARENT_CLASS vobj

class b2obj :public vobj
{
public:

	b2Body *m_b2body;
    b2obj();
	~b2obj();
	virtual BOOL RenderFunc(float);
};

#endif
