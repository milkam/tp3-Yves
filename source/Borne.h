/**
 * \file Borne.h
 * \brief Fichier contenant l'interface de la classe Borne et des heritiers.
 * \author Yves Gingras (NI:111102929)
 * \date 2015-10-06
 */

#ifndef BORNE_H_
#define BORNE_H_
#include <string>
#include "ContratException.h"
//#include "ValidationFormat.h"

namespace tp
{

/**
 * \brief Constante de type int utilisée comme sentinelle de fin de boucle.
 */
const int NB_PARAMETRES = 6;

/**
 * \brief Constante de type string utilisée pour afficher les choix de sélection à l'utilisateur.
 */
const std::string CHOIX_ACTIONS = "\n1-Entrer les données associées à la nouvelle borne."
								  "\n2-Modifier l'adresse de la borne."
					   	   	   	  "\n3-Quitter.\n";
/**
 * \class Borne
 * \brief Classe de base, permettant de sasisir et traiter l'information relative aux bornes.
 */
class Borne
{
public:

	//constructeur/Destructeur
	Borne( int p_idBorne,
			const std::string& p_direction,
			const std::string& p_nomTopographique,
			double p_longitude,
			double p_latitude);

	virtual ~Borne(){};

	//méthodes
	virtual std::string reqBorneFormate() const = 0 ; //virtuelle pure
	virtual Borne* clone() const = 0; //virtuelle pure

	//opérateurs
	bool operator==(const Borne& p_borne);

	//Mutateur
	void asgNomTopographique(const std::string& p_nomTopographique);

	//Accesseurs
	int reqIdBorne() const;
	const std::string& reqDirection() const;
	const std::string& reqNomTopographique() const;
	double reqLongitude() const;
	double reqLatitude() const;

private:
	//attributs
	int m_idBorne;
	std::string m_direction;
	std::string m_nomTopographique;
	double m_longitude;
	double m_latitude;

	//méthodes
	void verifieInvariant() const;

};

} /* namespace tp */

#endif /* BORNE_H_ */
