#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

// [x] Charger data.csv avec prix du btc en fonction de la date
// [x] Charger l'input.txt avec quantite de btc echangee en fonction de la date
// [x] Calculer valeur du btc échangé en fction de la date :
//		[x] Si date pas existante, prendre date EN DESSOUS la plus proche
class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & other);
		BitcoinExchange & operator=(BitcoinExchange const & other);
		~BitcoinExchange();

		void	loadDatabase(std::string const & database_path);
		void	processInputFile(std::string const & input_path) const; // +print stdout

	private:
		std::map<std::string, double>	_exchange_rates; // date string -> exchange rate
		bool	isValidDate(std::string const & date) const; // Parsing + check de la date
		bool	isValidValue(std::string const & value_str, double & out_value) const; // parsing valeur (folat ou int de 0 à 1000)
		double	getRate(std::string const & date) const; // Check l'echange rate a une adte = ou < le plus proche
		void	processLine(std::string const & line) const; // process la ligne que je veux + print
};

#endif
