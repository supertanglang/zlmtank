#ifndef _DEF_H
#define _DEF_H

#include <list>
#include <map>
#include <vector>
#include "hge.h"
#include "hgegui.h" 
#include "hgefont.h" 
#include "hgevector.h" 
#include "hgecolor.h" 
 



//types
#define NULL 0
#define DWORD unsigned long
#define WORD   unsigned short
#define BYTE     unsigned char
#define CHAR    char
#define BOOL    bool
#define FLOAT  float

#define U32 unsigned long
#define U16 unsigned short
#define U8   unsigned char
#define S32 long
#define S16 short
#define S8   char




#ifdef WIN32
#define ASSERT(X) assert(X)
#else
#define ASSERT(X)
#endif

class FPOINT
{
public:
    FLOAT x;
	FLOAT y;
	FPOINT(){x=0;y=0;};
	void Set(FLOAT a,FLOAT b){x=a;y=b;};
	void SetZero(){x=0;y=0;};
};




#include "sysinterface.h"

#include "m_list.h" 
#include "m_str.h"
#include "gui.h"
#include "guiobj.h"
#include "guibutton.h"
#include "guiedit.h"
#include "guiscrollbar.h"
#include "guilistbox.h"
#include "guilabel.h"
#include "guiwindow.h"



#include "obj.h"
#include "vobj.h"


#include "scene.h"

#include "ue.h"
#include "game.h"


#include <include\box2d.h>
#include "b2obj.h"

#include "world.h"

//server
#include "net.h"



#endif
