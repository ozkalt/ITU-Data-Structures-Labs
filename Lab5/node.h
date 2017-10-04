#define NAME_LENGTH 30
#define PHONENUM_LENGTH 15
#define TYPE_LENGTH 7

struct number{
	char type[TYPE_LENGTH];
	char num[PHONENUM_LENGTH];
	number *next;
};

struct Phone_node{
	char name[NAME_LENGTH];
	number *phonenum;
	Phone_node *next;
	Phone_node *previous;
};