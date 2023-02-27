#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
   ClapTrap NiceStud("NiceStud");
   ClapTrap Random("Random");

   NiceStud.attack("Random");
   Random.takeDamage(NiceStud.getAttack());
   NiceStud.attack("Random");
   Random.takeDamage(NiceStud.getAttack());
   Random.beRepaired(1);
   NiceStud.attack("Random");
   Random.takeDamage(NiceStud.getAttack());
   NiceStud.attack("Random");
   Random.takeDamage(NiceStud.getAttack());
   NiceStud.attack("Random");
   Random.takeDamage(NiceStud.getAttack());

   std::cout << std::endl;

   ScavTrap Bocal("Bocal");
   NiceStud.attack("Bocal");
   Bocal.takeDamage(NiceStud.getAttack());
   Bocal.guardGate();
   Bocal.attack("NiceStud");
   NiceStud.takeDamage(Bocal.getAttack());
}
