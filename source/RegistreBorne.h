/**
 * \file RegistreBorne.h
 * \brief Fichier contenan l'interface de la classe 
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-21
 */

#ifndef REGISTREBORNE_H_
#define REGISTREBORNE_H_
#include <string>
#include <vector>
#include "ContratException.h"
#include "Borne.h"


namespace tp
{

/**
 * \class RegistreBorne
 * \brief Classe permettant la gestion des bornes fontaine et de stationnement.
 */
class RegistreBorne
{
public:

	//constructeur/Destructeur
	RegistreBorne(const std::string& p_nomRegistreBorne);
	~RegistreBorne();



	//Méthodes
	void ajouterBorne(const Borne& p_borne);

	//Accesseurs
	std::string reqRegistreBorneFormate() const;
	const std::string& reqNomRegistreBorne() const;

private:

	//Attributs
	std::string m_nomRegistreBorne;
	std::vector<Borne*> m_vBornes;

	//méthodes
	bool borneEstDejaPresente(const Borne& p_borne) const;
	void verifieInvariant() const;

	RegistreBorne(const RegistreBorne& p_registreBorne); //constructeur copie; pas implémenté
	const RegistreBorne& operator= (const RegistreBorne& p_registreBorne); //opérateur d'assignation; pas implanté

};


//Méthodes
//Accesseurs/Mutateurs

} /* namespace tp */

#endif /* REGISTREBORNE_H_ */
