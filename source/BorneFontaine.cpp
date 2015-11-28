/**
 * \file BorneFontaine.cpp
 * \brief Fichier contenant l'implémentation de la classe "BorneFontaine".
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-14
 */

#include <iostream>
#include <sstream>
#include "BorneFontaine.h"
using namespace std;

namespace tp
{
/**
 * \brief Constructeur explicite avec paramètres, associé à une liste d'initialisation
 * \param[in] p_idBorne int représentant l'identifiant de la borne.
 * \param[in] p_direction string représentant le coté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
 * \param[in] p_nomTopographique string représentant le nom topographique du centre de chaussée.
 * \param[in] p_longitude double représentant la coordonnée de longitude de la borne.
 * \param[in] p_latitude double représentant la coordonnée de longitude de la borne.
 * \param[in] p_ville string représentant le nom de la ville.
 * \param[in] p_arrondissement représentant le nom de l'arrondissement.
 * \pre	p_direction doit contenir un point cardinal valide (Ok, déjà testée dans la classe de base)\n
 * 		p_nomTopographique ne doit pas être vide (Ok, déjà testée dans la classe de base)\n
 *		p_arrondissement ne doit pas être vide si la ville est Québec.\n
 * \post Chacun des attributs contient la valeur passée dans le paramètres auquel il est associé.
 */
BorneFontaine::BorneFontaine(
						int p_idBorne,
						const std::string& p_direction,
						const std::string& p_nomTopographique,
						double p_longitude,
						double p_latitude,
						const std::string& p_ville,
						const std::string& p_arrondissement):
						Borne(p_idBorne,p_direction,p_nomTopographique,p_longitude,p_latitude),
						m_ville(p_ville),m_arrondissement(p_arrondissement)
{
	//ici, on ne répete pas les test de respect de contrant fait par la classe "Borne".
	PRECONDITION((p_ville.compare("Québec")== 0 && (p_arrondissement.empty()) ?false:true));

	POSTCONDITION(m_ville.compare(p_ville) == 0);
	POSTCONDITION(m_arrondissement.compare(p_arrondissement) == 0);
	INVARIANTS();
}

/**
 * \brief Méthode permettant de faire une copie allouée sur le monceau de l'objet courant.
 * \return BorneFontaine Un nouvel objet.
 */
Borne* BorneFontaine::clone() const
{
	return new BorneFontaine(*this);
}

/**
 * \brief Méthode affichant le contenu de l'ensemble des attributs, dans un format de présentation.
 * \return string contenant des valeurs courantes formatées pour être affichées.
 */
std::string BorneFontaine::reqBorneFormate() const
{
	ostringstream monOsString;
	monOsString << "Borne fontaine" << endl <<
			"------------------------------------------------" << endl <<
			Borne::reqBorneFormate() << endl <<
			"Ville\t\t\t" << ": " << m_ville << endl <<
			"Arrondissement\t\t" << ": " << m_arrondissement << endl;

	return monOsString.str();
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_ville".
 * \return m_ville
 */
const std::string& BorneFontaine::reqVille() const
{
	return m_ville;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_arrondissement".
 * \return m_arrondissement
 */
const std::string& BorneFontaine::reqArrondissement() const
{
	return m_arrondissement;
}

/**
 * \brief Pour vérifier l'invariant de classe BorneFontaine, dans l'implantation de la théorie du contrat.
 */
void BorneFontaine::verifieInvariant() const
{
	INVARIANT((m_ville.compare("Québec")== 0 && (m_arrondissement.empty()) ?false:true));
}

} /* namespace tp */
