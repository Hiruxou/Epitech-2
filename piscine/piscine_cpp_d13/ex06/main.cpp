#include <iostream>
#include "Toy.h"
#include "Woody.h"
#include "Buzz.h"
#include "ToyStory.h"

int main()
{
  Buzz b("buzzi");
  Woody w("wood");
  ToyStory::tellMeAStory("superStory.txt", b, &Toy::speak_es, w, &Toy::speak);
}
