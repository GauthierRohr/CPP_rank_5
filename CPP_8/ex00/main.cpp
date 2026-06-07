#include "easyfind.hpp"

int	main()
{
	std::cout << "💥 vector<int> trouvé 💥" << std::endl;
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(7);
	vec.push_back(99);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 vector<int> pas trouvé 💥" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 list<int> trouvé 💥" << std::endl;
	std::list<int>	lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	try
	{
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 deque<int> non trouvé 💥" << std::endl;
	std::deque<int>	dq;
	dq.push_back(5);
	dq.push_back(15);
	try
	{
		std::deque<int>::iterator it = easyfind(dq, 99);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return (0);
}







// =============================================================================
// VECTOR vs LIST vs DEQUE
// =============================================================================
//
// VECTOR  <vector>
//   Mémoire  : contigue (comme un tableau C, se redimensionne automatiquement)
//   Accès    : accès direct en O(1) → vec[i]
//   Insertion: push_back O(1) amorti / insertion au milieu O(n) (décale tout)
//   Suppres. : pop_back O(1) / erase au milieu O(n)
//   Utiliser : quand on lit beaucoup, fait des push_back, et a besoin de vec[i]
//
// LIST  <list>
//   Mémoire  : liste doublement chaînée (chaque noeud a un pointeur prev + next)
//   Accès    : PAS d'accès direct → pas de lst[i], obligé d'itérer
//   Insertion: O(1) n'importe où si on a déjà un itérateur (aucun décalage)
//   Suppres. : O(1) n'importe où si on a déjà un itérateur
//   Utiliser : quand on insère/supprime souvent au milieu, sans besoin de [i]
//
// DEQUE  <deque>  (file à double entrée)
//   Mémoire  : blocs segmentés (pas totalement contiguë, mais accès rapide)
//   Accès    : accès direct en O(1) → dq[i]
//   Insertion: push_front ET push_back tous les deux O(1) / milieu O(n)
//   Suppres. : pop_front ET pop_back tous les deux O(1) / milieu O(n)
//   Utiliser : quand on a besoin de push_front + push_back + accès direct [i]
//
// -----------------------------------------------------------------------------
// COMPARAISON RAPIDE
//
//               vector    list    deque
//   accès [i]    O(1)     NON     O(1)
//   push_back    O(1)    O(1)     O(1)
//   push_front   O(n)    O(1)     O(1)   ← list/deque gagnent ici
//   insert mid   O(n)    O(1)     O(n)   ← list gagne (avec itérateur)
//   mémoire     compacte  fragmentée  mixte
//
// -----------------------------------------------------------------------------
// ITÉRER
//
//   TypeConteneur::iterator it = conteneur.begin();
//   while (it != conteneur.end())
//   {
//       std::cout << *it << std::endl;  // déréférencer pour avoir la valeur
//       ++it;
//   }
//
// -----------------------------------------------------------------------------
// MÉTHODES COMMUNES
//
//   .push_back(val)   ajoute à la fin
//   .push_front(val)  ajoute au début   (list et deque seulement, pas vector)
//   .pop_back()       supprime le dernier
//   .front()          premier élément
//   .back()           dernier élément
//   .size()           nombre d'éléments
//   .empty()          true si vide
//   .begin()          itérateur vers le premier élément
//   .end()            itérateur après le dernier (ne jamais déréférencer)
//   .insert(it, val)  insère avant la position de l'itérateur
//   .erase(it)        supprime l'élément à la position de l'itérateur
