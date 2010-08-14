#ifndef STDLIB_H
#define STDLIB_H

#define STRLEN(S)		misc_strlen(S)
#define STRCAT(S1,S2)	misc_strcat(S1, S2)
#define STRSTR(S1,S2)	misc_strstr(S1,S2)
#define STRCMP(S1,S2)	misc_strcmp(S1,S2)
#define STRNCMP(S1,S2,N)	misc_strncmp(S1, S2, N)
#define STRCPY(S1,S2)	misc_strcpy(S1,S2)
#define STRNCPY(S1,S2,N) misc_strncpy(S1,S2,N)

typedef int (*stdputs)(char *s);


// �ɱ������
///? C �����йŹֵ����ݣ�һЩ�еĺ����
///? �˴����ݽ���࿴�� C �ο��ֲ�
// va_list �ǿɱ������Ĭ������
///? Ϊʲô va_list �� char * ������ void *��
typedef char *va_list;

// ϵͳĬ�ϳ���ջ�����ݴ�С��һ����� ANSI C �� int ��С
#define STACKITEMSIZE sizeof(int)
// ���ɱ�������뵽ջ��Ŀ���ݴ�С
#define VA_SIZE(n) ((sizeof(n) + STACKITEMSIZE - 1) & ~(STACKITEMSIZE - 1))
// ap �ǿɱ����ջ�ף���һ��������v �����һ������
// ��ô�������� va_start ���ǿɱ����ջ��
// �ɴ˿ɼ� C ��������ջ˳�򣬺Ǻ�
#define va_start(ap,v) (ap = (va_list)&v + VA_SIZE(v))
// ȡ������һ����������ת�����͡���������
// ��Ϊ�����˲����� ap ����ȡ�����ص�ʱ��Ҫ�� VA_SIZE(t)
// ��Ȼȡ��������һ�������������ǵ�ǰ����
#define va_arg(ap,t) (*(t *)((ap += VA_SIZE(t)) - VA_SIZE(t)))
// �ɱ��������
// �ܶ� C �������Դ��� stdarg.h �н� va_end ����Ϊ�գ�������
// ���ｨ�齫����������
#define va_end(ap) (ap = (va_list)0)


typedef int size_t;

// misc_memset(): ���� siz �ֽڴ�С�ڴ�� p ����Ϊ ch
EXTERN INLINE void misc_memset(void *p, unsigned char ch, size_t siz);
// misc_memcpy(): ���� siz �ֽ��ڴ�� src ���ڴ�� dest
EXTERN INLINE void misc_memcpy(void *dest, void *src, size_t siz);

EXTERN INLINE int misc_memcmp(void *dest, void *src, size_t siz);
// misc_strlen(): ������ '\0' ��β�ַ��� s �ĳ���
EXTERN INLINE int misc_strlen(char *s);
// misc_strcmp(): �Ƚ��ַ��� s1 �� s2
// ���ʱ���� 0 ������ ASCII ����˳�򷵻� 1 ���� -1
EXTERN INLINE int misc_strcmp(char *s1, char *s2);
// misc_strncmp(): �Ƚ� n ���ֽڳ����ַ��� s1 �� s2
// ����ֵͬ misc_strcmp() ���ַ������Բ��� '\0'
EXTERN INLINE int misc_strncmp(char *s1, char *s2, int n);
// misc_strcpy(): �����ַ��� src �� dest
// siz Ϊ dest �Ŀռ��С
// ����ֵָ�� dest ������ src �ַ�����
// ��Ϊ���������������Ƽ�ʹ�ñ�����
EXTERN INLINE char *misc_strcpy(char *dest, char *src);
// misc_strncpy(): ���� n ���ֽ��ַ��� src �� dest
// ����ֵָ�� dest ������ src �ַ�����
EXTERN INLINE char *misc_strncpy(char *dest, char *src, int n);
// misc_strcat(): �����ַ��� src �� dest �ַ�����
// ����ֵָ�� dest ������ src �ַ�����
EXTERN INLINE char *misc_strcat(char *dest, char *src);
// misc_strncat(): ���� n ���ַ��� src �� dest �ַ�����
// ����ֵָ�� dest ������ src �ַ�����
EXTERN INLINE char *misc_strncat(char *dest, char *src, int n);
// misc_strchr(): ���ַ��� s �������ַ� c
// �ҵ� s �е�һ�� c �󷵻ظ��ַ��� s ��λ��ָ��
// �Ҳ������� NULL (void *)0
EXTERN INLINE char *misc_strchr(char *s, int c);
// misc_strchr(): ���ַ��� s �з��������ַ� c
// �����ҵ� s �е�һ�� c �󷵻ظ��ַ��� s ��λ��ָ��
// �Ҳ������� NULL (void *)0
EXTERN INLINE char *misc_strrchr(char *s, int c);
// misc_strstr(): ���ַ��� s1 �������ַ��� s2
// �ҵ� s1 �е�һ��ƥ��� s2 �ַ����󷵻ظ��ַ����� s1 ����ʼλ��ָ��
// �Ҳ������� NULL (void *)0
EXTERN INLINE char *misc_strstr(char *s1, char *s2);


// misc_snprintf(): ʹ�� fmt ��ʽ������ɱ���� ... �� siz �ֽڴ�С���� buf
// ���������������ַ���
EXTERN int misc_snprintf(char *buf, size_t siz, char *fmt, ...);
// misc_buf: 1K ��С�ַ�����
EXTERN char misc_buf[1024];
// misc_printf(): ʹ�� fmt ��ʽ������ɱ���� ... ��Ĭ�����
// ����������ַ���
EXTERN int misc_printf(char *fmt, ...);


int atoi_s(char **s);
unsigned long atol(const unsigned char *s);

unsigned long hex2dec(const unsigned char *s);


#endif
