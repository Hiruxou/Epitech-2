#ifndef PIZZAGENERATOR_HH_
# define PIZZAGENERATOR_HH_

# include <map>
# include "APizza.hh"
# include "Margarita.hh"
# include "Regina.hh"
# include "Americaine.hh"
# include "Fantasia.hh"
# include "../Serializer.hpp"

class		PizzaGenerator
{
  std::map<std::string, APizza *(*)(APizza::TaillePizza)> _pizza;
  std::map<APizza::TypePizza,  APizza *(*)(APizza::TaillePizza)> _pizza2;
public:
  PizzaGenerator();
  ~PizzaGenerator();
  APizza	*createForReception(APizza::TypePizza type, APizza::TaillePizza size);
  APizza	*createForKitchen(std::string order);
  template<typename T>
  static APizza				*generatePizza(APizza::TaillePizza);
};

#endif /* !PIZZAGENERATOR_HH_ */
