#define _CRT_SECURE_NO_WARNINGS

// ******���������******
#define MAX_NAME 10 // ��Ա��Ϣ�� ���� ���ַ������С
#define MAX_SEX 5   // ��Ա��Ϣ�� �Ա� ���ַ������С
#define MAX_TELE 15 // ��Ա��Ϣ�� �绰 ���ַ������С
#define MAX_ADDR 15 // ��Ա��Ϣ�� ��ַ ���ַ������С

#define MAX 1000 // ͨѶ�ʴ�С



// ******ͷ�ļ�����******
#include <stdio.h>
#include <memory.h>
#include <string.h>


// ******�Զ�������******
enum Option // ����ѡ��
{
	EXIT,    // Ĭ�� ֵ Ϊ 0
	ADD,     // Ĭ�� ֵ Ϊ 1
	DEL,     // Ĭ�� ֵ Ϊ 2
	SEARCH,  // Ĭ�� ֵ Ϊ 3
	MODIFY,  // Ĭ�� ֵ Ϊ 4
	SORT,    // Ĭ�� ֵ Ϊ 5
	SHOW     // Ĭ�� ֵ Ϊ 6

};

struct PeoInfo // ��Ա��Ϣ 
	// ��д�� struct Contest ֮ǰ�������޷��� struct Contest ʹ��
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contest // ͨѶ¼
{
	struct PeoInfo date[MAX]; // ��Ա��Ϣ ��
	int size; // ��¼ͨѶ¼���ж��ٸ���Ա
};


//******����������******
void InitContest(struct Contest* ps); // ��ʼ��ͨѶ¼

void AddContest(struct Contest* ps); // ���ӳ�Ա

void ShowContest(const struct Contest* ps); // չʾͨѶ¼

void DelContest(struct Contest* ps); // ɾ����Ա

void SearchContest(const struct Contest* ps); // ���ҳ�Ա

void ModifyContest(struct Contest* ps); // �޸�ͨѶ��

void SortContest(struct Contest* ps); // ����ͨѶ��