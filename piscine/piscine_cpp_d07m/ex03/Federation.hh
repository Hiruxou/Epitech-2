//
// Federation.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:25:25 2015 Nicolas Charvoz
// Last update Tue Jan 13 15:04:46 2015 Nicolas Charvoz
//

#ifndef FEDERATION_HH_
# define FEDERATION_HH_

# include <iostream>
# include <string>
# include "Warpsystem.hh"
# include "Destination.hh"
//# include "Borg.hh"

namespace Borg {
  class Ship;
}

namespace Federation {
  class Ship
  {
  private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core *Core;
    Destination _location;
    Destination _home;

  public:
    Ship(int, int, std::string);
    ~Ship();
    void setupCore(WarpSystem::Core*);
    void checkCore();
    WarpSystem::Core *getCore();
    bool move(int, Destination);
    bool move(int);
    bool move(Destination);
    bool move();
  };

  namespace Starfleet {

    class Captain {
    private:
      std::string _name;
      int _age;
    public:
      Captain(std::string);
      ~Captain();
      std::string getName();
      int getAge();
      void setAge(int);
    };
    class Ship
    {
    private:
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
      WarpSystem::Core *Core;
      Captain *captain;
      Destination _location;
      Destination _home;
      int _shield;
      int _photonTorpedo;
    public:
      Ship(int length = 289, int width = 132, std::string string = "Entreprise", short maxWarp = 6, int torpedo = 20);
      ~Ship();

      void setupCore(WarpSystem::Core*);
      void checkCore();
      void promote(Captain*);
      bool move(int, Destination);
      bool move(int);
      bool move(Destination);
      bool move();
      int getShield();
      void setShield(int);
      int getTorpedo();
      void setTorpedo(int);
      void fire(Borg::Ship *ship);
      void fire(int torpedoes, Borg::Ship *ship);
    };
    class  Ensign {
    private:
      std::string _name;
    public:
      explicit Ensign(std::string);
      ~Ensign();
    };
  };
};


#endif
