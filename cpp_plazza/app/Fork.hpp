//
// Fork.hpp for Fork in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Thu Apr 23 10:30:17 2015 Antoine Garcia
// Last update Thu Apr 23 10:42:34 2015 Antoine Garcia
//

#ifndef FORK_HPP_
# define FORK_HPP_

#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

class	Fork
{
  int	_pid;
 public:
  Fork()
    {
      _pid = fork();
    }
  ~Fork()
    {
      int	status;

      waitpid(_pid, &status, 0);
    }
  bool	isSon() const
  {
    return (_pid == 0);
  }
};

#endif
