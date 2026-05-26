#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

// Class that loads a CSV bitcoin price database and evaluates
// the value of an amount of bitcoin on a given date.
class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & other);
		BitcoinExchange & operator=(BitcoinExchange const & other);
		~BitcoinExchange();

		// Load the database CSV file into the internal map.
		void	loadDatabase(std::string const & database_path);

		// Process the input file and print results to stdout.
		void	processInputFile(std::string const & input_path) const;

	private:
		// Internal map: date string → exchange rate (uses std::map)
		std::map<std::string, double>	_exchange_rates;

		// Parse and validate a date string "YYYY-MM-DD".
		bool	isValidDate(std::string const & date) const;

		// Parse and validate a value string (float or int, 0 to 1000).
		bool	isValidValue(std::string const & value_str, double & out_value) const;

		// Look up the exchange rate for a given date (closest lower or equal).
		double	getRate(std::string const & date) const;

		// Process a single line from the input file and print the result.
		void	processLine(std::string const & line) const;
};

#endif
