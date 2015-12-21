//
// Lexer.cpp for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Feb 10 16:31:58 2015 Nicolas Charvoz
// Last update Fri Apr 17 21:45:03 2015 Nicolas Charvoz
//

#include "Lexer.hpp"

Lexer::Lexer(std::string const &string) : _string(string)
{
}

Lexer::Lexer(Lexer const &lex) : _string(lex._string)
{
}

bool isJunk(char c) {
  return isspace(c);
}

std::string trim_string(std::string s) {
  std::ostringstream result;
  trim(s.begin(), s.end(), std::ostream_iterator<char>(result, ""), isJunk);
  return result.str();
}

std::size_t myMin(std::size_t const &one, std::size_t const &other)
{
   if (one > other)
    return other;
  else if (other > one)
    return one;
  return one;

}

std::string trim_comments(std::string const& code) {
  typedef std::string::size_type size_t;

  std::string const comment_start = ";";
  std::ostringstream result;
  size_t newline_pos = 0;

  while (newline_pos != std::string::npos)
    {
    size_t const comment_pos = code.find(comment_start, newline_pos);
    if (comment_pos == std::string::npos)
      {
	result << code.substr(newline_pos);
	break;
      }
    result << code.substr(newline_pos, comment_pos - newline_pos);
    newline_pos = code.find('\n', comment_pos + comment_start.length());
  }
  return result.str();
}

void Lexer::setToken()
{
  std::string tmp;
  std::size_t pos = 0, begin = 0;
  std::string::iterator end;
  std::string::size_type comment_start;
  std::string::size_type newline;

  std::replace(_string.begin(), _string.end(), '\t', ' ');
  _string += "exit";
  _string = trim_comments(_string);
  _string = trim_string(_string);

  for (std::string::iterator it = _string.begin() ; it + pos != _string.end() ; ++it)
    {
      if ((int)(pos = myMin(_string.find('\n', pos), _string.find(' ', pos))) == -1)
	{
	  _token.push_back("exit");
	  return;
	}
      tmp = _string.substr(begin, pos-begin);
      pos++;
      begin = pos;
      _token.push_back(tmp);
    }
}

std::list<std::string> Lexer::getToken() const
{
  return _token;
}
