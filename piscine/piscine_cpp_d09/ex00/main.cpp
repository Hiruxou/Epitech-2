#include "Character.hh"

int		main()
{
  // Character _c("poney", 42);

  // _c.Range = Character::CLOSE;
  // _c.Range = Character::RANGE;
  // return (0);
  Character _c("poney", 42);
  _c.TakeDamage(50);
  _c.Heal();
  _c.TakeDamage(200);
  _c.TakeDamage(200);
}
