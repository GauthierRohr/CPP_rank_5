#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) :
	_exchange_rates(other._exchange_rates) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
		_exchange_rates = other._exchange_rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Checks whether a date string is valid (YYYY-MM-DD format, logical values).
// Returns true if valid, false otherwise.
bool	BitcoinExchange::isValidDate(std::string const & date) const
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t index = 0; index < date.size(); index++)
	{
		if (index == 4 || index == 7)
			continue;
		if (!std::isdigit(date[index]))
			return (false);
	}
	int	year;
	int	month;
	int	day;
	std::istringstream year_stream(date.substr(0, 4));
	std::istringstream month_stream(date.substr(5, 2));
	std::istringstream day_stream(date.substr(8, 2));
	year_stream >> year;
	month_stream >> month;
	day_stream >> day;
	if (year < 2009 || year > 2026)
		return (false);
	if (date < "2009-01-03")
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

// Parses a value string and stores the parsed double in out_value.
// Returns true if the value is a valid positive float or int between 0 and 1000.
bool	BitcoinExchange::isValidValue(std::string const & value_str, double & out_value) const
{
	std::istringstream value_stream(value_str);
	value_stream >> out_value;
	if (value_stream.fail())
		return (false);
	std::string remaining;
	value_stream >> remaining;
	if (!remaining.empty())
		return (false);
	return (true);
	// true: string is a valid numeric value
}

// Returns the exchange rate for the given date, using the closest lower or equal date.
// Throws std::runtime_error if no valid rate is found (date before all records).
double	BitcoinExchange::getRate(std::string const & date) const
{
	std::map<std::string, double>::const_iterator it;
	it = _exchange_rates.upper_bound(date);
	if (it == _exchange_rates.begin())
		throw std::runtime_error("no rate available for date: " + date);
	--it;
	return (it->second);
	// it->second: exchange rate for the closest lower or equal date
}

// Parses and processes one line of the input file.
// Prints result or error message to stdout.
void	BitcoinExchange::processLine(std::string const & line) const
{
	if (line.empty())
		return;

	size_t	separator_pos = line.find(" | ");
	if (separator_pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string	date = line.substr(0, separator_pos);
	std::string	value_str = line.substr(separator_pos + 3);

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	double	amount;
	if (!isValidValue(value_str, amount))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	if (amount < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}

	if (amount > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	try
	{
		double	rate = getRate(date);
		std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
		// output: date => amount = result
	}
	catch (std::runtime_error const & error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
}

// Opens and parses the CSV database file, populating the internal exchange rate map.
// Throws std::runtime_error if the file cannot be opened.
void	BitcoinExchange::loadDatabase(std::string const & database_path)
{
	std::ifstream	database_file(database_path.c_str());
	if (!database_file.is_open())
		throw std::runtime_error("could not open database file.");

	std::string	line;
	std::getline(database_file, line);
	// skip header line

	while (std::getline(database_file, line))
	{
		if (line.empty())
			continue;
		size_t	comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			continue;
		std::string	date = line.substr(0, comma_pos);
		std::string	rate_str = line.substr(comma_pos + 1);
		double		rate;
		std::istringstream rate_stream(rate_str);
		rate_stream >> rate;
		if (!rate_stream.fail())
			_exchange_rates[date] = rate;
	}
}

// Opens and processes each line of the input file.
// Prints results or error messages to stdout.
void	BitcoinExchange::processInputFile(std::string const & input_path) const
{
	std::ifstream	input_file(input_path.c_str());
	if (!input_file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string	line;
	std::getline(input_file, line);
	// skip header line "date | value"

	while (std::getline(input_file, line))
		processLine(line);
}
