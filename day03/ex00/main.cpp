
#include "ClapTrap.hpp"

int main(void)
{
   ClapTrap one("one");
   ClapTrap Random("Random");

   one.attack("Random");
   Random.takeDamage(one.getAttack());
   one.attack("Random");
   Random.takeDamage(one.getAttack());
   Random.beRepaired(1);
   one.attack("Random");
   Random.takeDamage(one.getAttack());
   ClapTrap oneCanon(one);
   oneCanon.attack("Random");
   Random.takeDamage(oneCanon.getAttack());
   oneCanon.attack("Random");
   Random.takeDamage(oneCanon.getAttack());
}
