#include <types.h>
#include <vga.h>

//�ոս���c���
//��ʱ������4M��һ����λ��
//�ոս��뱣��ģʽ
//GDTֻ��3�ű�
//code / data���ص�,����0-4G





void ntldr_main()
{
  //
  vga_init();
  vga_puts("aaaa\n");
  for(;;);
  
  return;
}

