#ifndef BASE_HPP
# define BASE_HPP

// Polymorphic base; virtual dtor enables RTTI for dynamic_cast
class Base
{
public:
	virtual ~Base();
};

#endif
