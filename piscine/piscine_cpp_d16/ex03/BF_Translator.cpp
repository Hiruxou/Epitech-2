//
// BF_Translator.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Jan 22 03:40:29 2015 Nicolas Charvoz
// Last update Thu Jan 22 03:40:30 2015 Nicolas Charvoz
//

#include "BF_Translator.h"

BF_Translator::BF_Translator()
{
  _commands['+'] = &BF_Translator::inc;
  _commands['-'] = &BF_Translator::desc;
  _commands['<'] = &BF_Translator::next;
  _commands['>'] = &BF_Translator::prev;
  _commands['.'] = &BF_Translator::write;
  _commands[','] = &BF_Translator::read;
  _commands['['] = &BF_Translator::jump;
  _commands[']'] = &BF_Translator::back;
}

BF_Translator::~BF_Translator()
{
}

int		BF_Translator::translate(std::string in, std::string out)
{
  bf_commands		co;
  char			c;

  try
    {
      _in.open(in.data(), std::ios::in);
      _out.open(out.data(), std::ios::out | std::ios::trunc);
      if (!_in.is_open() || !_out.is_open())
	throw std::exception();
      header();
      while (_in.eof())
	{
	  c = _in.get();
	  co = _commands[c];
	  if (co)
	    (this->*co)();
	  else if (!isspace(c) && c != -1)
	    throw std::exception();
	}
      footer();
      _out.flush();
      _in.close();
      _out.close();
    }
  catch (std::exception &ex)
    {
      _in.close();
      _out.close();
      return (-1);
    }
  return (0);
}

void		BF_Translator::header()
{
  _out << "#include <stdlib.h>\n"
       << "#include <string.h>\n"
       << "#define MEMORY_MAX 60*1024\n\n"
       << "int main() {\n"
       << " char memory[MEMORY_MAX];\n"
       << " unsigned int cursor = 0;\n"
       << "memset(memory, 0, MEMORY_MAX);\n\n";
}

void		BF_Translator::footer()
{
  _out << "}\n";
}

void		BF_Translator::inc()
{
  _out << "memory[cursor++];\n";
}

void		BF_Translator::desc()
{
  _out << "memory[cursor--];\n";
}

void		BF_Translator::next()
{
  _out << "cursor++;\n";
}

void		BF_Translator::prev()
{
  _out << "cursor--;\n";
}

void		BF_Translator::write()
{
  _out << "write(1, &memory[cursor], 1);\n";
}

void		BF_Translator::read()
{
  _out << "read(0, &memory[cursor], 1);\n";
}

void		BF_Translator::jump()
{
  _out << "while (memory[cursor]) {\n";
}

void		BF_Translator::back()
{
  _out << "}\n";
}
