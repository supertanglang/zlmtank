#ifndef SYSCFG_H
#define SYSCFG_H





// StartMode
#define STARTMODE_NORMAL 0
#define STARTMODE_SAFE   1
#define STARTMODE_DEBUG  2

// StartModeExt
#define STARTMODEEXT_

typedef struct _syscfg
{
  BOOTINFO Bootinfo;
  DWORD CpuType;
  DWORD CpuFreq;
  DWORD CpuNum;


  DWORD StartMode;
  DWORD StartModeExt;

}SYSTEMCONFIG;

BOOL GetSystemConfig(SYSTEMCONFIG *);

#endif
