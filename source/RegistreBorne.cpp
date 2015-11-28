/**
 * \file RegistreBorne.cpp
 * \brief Fichier contenant l'interface de la classe "RegistreBorne".
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-21
 */

#include <iostream>
#include <sstream>

#include <iostream>
#include "RegistreBorne.h"
#include "Borne.h"

using namespace std;

namespace tp
{
/**
 * \brief Constructeur explicite avec paramètres, associé à une liste d'initialisation
 * \param[in] p_nomRegistreBorne string contenant le nom du registre.
 * \pre	p_nomRegistreBorne ne doit pas être vide.
 */
RegistreBorne::RegistreBorne(
		const std::string& p_nomRegistreBorne):
		m_nomRegistreBorne(p_nomRegistreBorne)
{
	PRECONDITION(!p_nomRegistreBorne.empty())

	POSTCONDITION(m_nomRegistreBorne.compare(p_nomRegistreBorne) == 0);
	INVARIANTS();
}

/**
 * \brief Destructeur responsable de désallouer toutes les Bornes de la liste dans le vecteur.
 */
RegistreBorne::~RegistreBorne()
{
	for (unsigned int i = 0; i < m_vBornes.size(); i++)
		{
			// l'allocation mémoire est associé à une seule borne puisque chaque entrée
			// au registre a été certifié unique par "borneEstDejaPresente".
			delete m_vBornes[i];
//			cout << "\nEffacer " <<  m_vBornes[i] -> reqIdBorne();
		}
}

/**
 * \brief Méthode affichant les informations formatées concernant le registre de bornes.
 * \return string contenant des valeurs courantes formatées pour être affichées.
 */
std::string RegistreBorne::reqRegistreBorneFormate() const
{
	ostringstream monOsString;
		monOsString <<
				"\nRegistre : " <<  m_nomRegistreBorne << endl;

	for (unsigned int i = 0; i < m_vBornes.size(); i++)
	{
		monOsString <<
				m_vBornes [i] -> reqBorneFormate() <<
				"------------------------------------------------" << endl;
	}

	return monOsString.str();
}

/**
 * \brief Permet d'obtenir la valeur courante de m_nomRegistreBorne
 * \return m_nomRegistreBorne
 */
const std::string& RegistreBorne::reqNomRegistreBorne() const
{
	return m_nomRegistreBorne;
}

/**
 * \brief Méthode permettant d’ajouter une borne au vecteur de bornes seulement si\n
 *  la borne n’est pas déjà présente dans cette liste.
 */
void RegistreBorne::ajouterBorne(const Borne& p_borne)
{
	if (!this -> borneEstDejaPresente(p_borne))
	{
		m_vBornes.push_back(p_borne.clone());
	}
}

/**
 * \brief Méthode permettant de vérifier si la borne n’est pas déjà dans le vecteur
 * \param[in] p_borne Objet de type borne.
 * \return true si la Borne p_borne est dèjà dans le vecteur, false sinon.
 */
bool RegistreBorne::borneEstDejaPresente(const Borne& p_borne) const
{
	bool borneEstPresente = false;
	for (unsigned int i = 0; i < m_vBornes.size(); i++)
	{
		if (m_vBornes [i]-> operator == (p_borne))
		{
			borneEstPresente = true;
			break;
		}
	}

	return borneEstPresente;
}

/**
 * \brief Pour vérifier l'invariant de classe RegistreBorne, dans l'implantation de la théorie du contrat.
 */
void RegistreBorne::verifieInvariant() const
{
	INVARIANT(!m_nomRegistreBorne.empty());
}



} /* namespace tp */


