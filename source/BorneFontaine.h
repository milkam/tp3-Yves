/**
 * \file BorneFontaine.h
 * \brief Fichier contenan l'interface de la classe "BorneFontaine",\n
 *  	  dérivée de la classe "Borne".
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-14
 */

#ifndef BORNEFONTAINE_H_
#define BORNEFONTAINE_H_
#include <string>
#include "Borne.h"

namespace tp
{
/**
 * \class BorneFontaine
 * \brief Classe représentant les bornes fontaine de la ville de Québec.
 */
class BorneFontaine: public Borne
{

public:

	//constructeur
	BorneFontaine(
			int p_idBorne,
			const std::string& p_direction,
			const std::string& p_nomTopographique,
			double p_longitude,
			double p_latitude,
			const std::string& p_ville,
			const std::string& p_arrondissement);

	//méthodes
	virtual Borne* clone() const;
	virtual std::string reqBorneFormate() const;

	//accesseurs
	const std::string& reqVille() const;
	const std::string& reqArrondissement() const;

private:

	//attributs
	std::string m_ville;
	std::string m_arrondissement;

	//méthodes
	void verifieInvariant() const;
};
} /* namespace tp */

#endif /* BORNEFONTAINE_H_ */
