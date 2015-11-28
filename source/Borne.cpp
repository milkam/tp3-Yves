/**
 * \file Borne.cpp
 * \brief Implantation de la classe Borne
 * \author Yves Gingras (NI:111102929)
 * \date 2015-10-06
 */

#include "Borne.h"
#include "ValidationFormat.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace util;

namespace tp
{

/**
 * \brief Constructeur explicite avec paramètres, associé à une liste d'initialisation
 * \param[in] p_idBorne int représentant l'identifiant de la borne.
 * \param[in] p_direction string représentant le coté du centre de chaussée ou l’intersection dans le cas d’un terre-plein.
 * \param[in] p_nomTopographique string représentant le nom topographique du centre de chaussée.
 * \param[in] p_longitude double représentant la coordonnée de longitude de la borne.
 * \param[in] p_latitude double représentant la coordonnée de longitude de la borne.
 * \pre	p_direction doit contenir un point cardinal valide\n
 * 		p_nomTopographique ne doit pas être vide\n
 * \post Chacun des attributs contient la valeur du paramètres auquel il est associé.
 */
Borne::Borne(int p_idBorne,
					const std::string& p_direction,
					const std::string& p_nomTopographique,
					double p_longitude,
					double p_latitude):
					m_idBorne(p_idBorne),m_direction(p_direction),
					m_nomTopographique(p_nomTopographique),
					m_longitude(p_longitude), m_latitude(p_latitude)
{
//	PRECONDITION(validerPointCardinal(p_direction))
	PRECONDITION(!p_nomTopographique.empty());

	POSTCONDITION(m_idBorne == p_idBorne);
	POSTCONDITION(m_direction.compare(p_direction) == 0 );
	POSTCONDITION(m_nomTopographique.compare(p_nomTopographique) == 0);
	POSTCONDITION(m_longitude == p_longitude);
	POSTCONDITION(m_latitude == p_latitude);
	INVARIANTS();
}

/**
 * \brief Méthode affichant le contenu de l'ensemble des attributs, dans un format de présentation.
 * \return string contenant des valeurs courantes formatées pour être affichées.
 */
std::string Borne::reqBorneFormate() const
{
	ostringstream monOsString;

	monOsString <<
			"Identifiant de la borne\t" << ": " << m_idBorne << endl <<
			"Direction\t\t" << ": " << m_direction << endl <<
			"Nom topographique\t" << ": " << m_nomTopographique << endl <<
			"Longitude\t\t" << ": " << setprecision(10) << m_longitude << endl <<
			"Latitude\t\t" << ": " << setprecision(10) << m_latitude;
	return monOsString.str();
}

/**
 * \brief Surcharge de l'opérateur "==".
 * \param[in] p_borne; Objet de type Borne, qui sera comparé à l'objet courant.

 * \return boolean indiquant si la valeur de tous les attributs des 2 objets comparés, sont identiques ou non.
 */
bool Borne::operator==(const Borne& p_borne)
{
	if ((p_borne.m_idBorne == m_idBorne) &&
		(p_borne.m_direction.compare(m_direction) == 0)  &&
		(p_borne.m_nomTopographique.compare(m_nomTopographique) == 0) &&
		(p_borne.m_longitude == m_longitude) &&
		(p_borne.m_latitude == m_latitude))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * \brief Mutateur permettant de modifier l'attribut "m_nomTopographique".
  */
void Borne::asgNomTopographique(const std::string& p_nomTopographique)
{
	PRECONDITION(p_nomTopographique != "")

	m_nomTopographique = p_nomTopographique;

	POSTCONDITION(m_nomTopographique.compare(p_nomTopographique) == 0)
	INVARIANTS();

}

/**
 * \brief Permet d'obtenir la valeur courante de "m_IdBorne"
 * \return m_IdBorne
 */
int tp::Borne::reqIdBorne() const
{
	return m_idBorne;
}

/**
 * \brief Accesseur permettant d'obtenir la valeur courante de "m_direction".
 * \return m_direction
 */
const std::string& Borne::reqDirection() const
{

	return m_direction;
}

/**
 * \brief Accesseur permettant d'obtenir la valeur courante de "m_nomTopographique".
 * \return m_nomTopographique
 */
const std::string& Borne::reqNomTopographique() const
{
	return m_nomTopographique;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_longitude"
 * \return m_longitude
 */
double tp::Borne::reqLongitude() const
{
	return m_longitude;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_latitude"
 * \return m_latitude
 */
double tp::Borne::reqLatitude() const
{
	return m_latitude;
}

/**
 * \brief Pour vérifier l'invariant de classe Borne, dans l'implantation de la théorie du contrat.
 */
void Borne::verifieInvariant() const
{
	INVARIANT(validerPointCardinal(m_direction));
	INVARIANT(!m_nomTopographique.empty());
}
} /* namespace tp */
