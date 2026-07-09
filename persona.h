typedef struct Person Person;

struct Person{
  int (*get_age)(struct Person *);
  int (*set_age)(struct Person *, int );
};

Person *create_person(int);



