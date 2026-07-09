#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main(){
  Person *Daniele = create_person(20);
  printf("%d\n", Daniele->get_age(Daniele));
}
