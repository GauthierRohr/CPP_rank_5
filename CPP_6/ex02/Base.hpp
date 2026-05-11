#ifndef BASE_HPP
# define BASE_HPP

// Classe de base polymorphique avec destructeur virtuel.
// Le destructeur virtuel active le RTTI, nécessaire pour dynamic_cast.
class Base
{
public:
	virtual ~Base();
};

#endif
