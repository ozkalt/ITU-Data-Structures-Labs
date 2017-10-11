#define NAME_LENGTH 30
#define PHONENUM_LENGTH 15
#define TYPE_LENGTH 7

struct Phone_node{
    char *name;
    char *lastname;
    char *phonenum;
    Phone_node *next;
};
