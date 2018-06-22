/*
 * string_parser.cpp
 *
 *  Created on: 22-Jun-2018
 *      Author: rajarshi
 */


#include "string_parser.h"
#include <boost/tokenizer.hpp>


std::list<std::pair<double, std::string> > linexp_parser(std::string expr)
{
	std::list<std::pair<double, std::string> > res;
	typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
	boost::char_separator<char> sep("+ ");
	tokenizer tokens(expr, sep);

	for(tokenizer::iterator tok_iter = tokens.begin(); tok_iter!=tokens.end();tok_iter++)
	{
		std::string term = *tok_iter;
		sep = boost::char_separator<char>("* ");
		tokenizer subtokens = tokenizer(term, sep);

		tokenizer::iterator iter = subtokens.begin();
		std::string item = *iter;
		double coeff = std::atof(item.c_str());

		iter++; // next token

		std::string varname;
		varname = *iter;
		std::pair<double, std::string> coeff_varname;
		coeff_varname.first = coeff;
		coeff_varname.second = varname;
		res.push_back(coeff_varname);
	}
	return res;

}

