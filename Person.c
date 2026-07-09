#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


static int set_age(Person *, int);
static int get_age(Person *);

typedef struct privatePerson{
  int (*get_age)(struct Person *);
  int (*set_age)(struct Person *, int );
  int age;
}privatePerson;

Person *create_person(int age){
  privatePerson *p = malloc(sizeof(privatePerson));
  *p = (privatePerson){.age = age, .get_age = get_age, .set_age = set_age};
  return (Person *)p;
}

static int get_age(Person *p){
  return ((privatePerson *)p)->age;
}

static int set_age(Person *p, int age){
  ((privatePerson *)p)->age = age;
  return 0; 
}
