/**
 * \file BorneStationnement.cpp
 * \brief Fichier contenan l'interface de la classe 
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-14
 */

#include <iostream>
#include <sstream>
#include "BorneStationnement.h"
#include "ValidationFormat.h"
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
 * \param[in] p_type string Le type de borne de stationnement
 * \param[in] p_lectureMetrique double La distance mesurée à partir du début du tronçon dans le sens des numéros d'immeuble.
 * \param[in] p_segmentRue int L’identifiant du segment de voie publique.
 * \param[in] p_numBorne string Le numéro de la borne.
 * \param[in] p_coteRue string Le coté par rapport au centre de chaussée où est la borne.
 * \pre	p_direction doit contenir un point cardinal valide (Ok, déjà testée dans la classe de base)\n
 * 		p_nomTopographique ne doit pas être vide (Ok, déjà testée dans la classe de base)\n
 *	 	p_type Doit  être "Stationnement" ou "Paiement"\n
 * 		p_lectureMetrique Doit être plus grand que 0\n
 *		p_segmentRue Doit être plus grand que 0.\n
 *		p_numBorne Doit être non vide\n
 *		p_coteRue Doit correspondre à un point cardinal.
 * \post Chacun des attributs contient la valeur passée dans le paramètres auquel il est associé.
 */
BorneStationnement::BorneStationnement(
							int p_idBorne,
							const std::string& p_direction,
							const std::string& p_nomTopographique,
							double p_longitude,
							double p_latitude,
							const std::string& p_type,
							double p_lectureMetrique,
							int p_segmentRue,
							const std::string& p_numBorne,
							const std::string& p_coteRue):
							Borne(p_idBorne,p_direction,p_nomTopographique,p_longitude,p_latitude),
							m_type(p_type),m_lectureMetrique(p_lectureMetrique),
							m_segmentRue(p_segmentRue),m_numBorne(p_numBorne),m_coteRue(p_coteRue)
{
		PRECONDITION((p_type == "stationnement" || p_type ==  "paiement")?true:false);
		PRECONDITION(p_lectureMetrique > 0);
		PRECONDITION(p_segmentRue > 0);
		PRECONDITION(!p_numBorne.empty());
		PRECONDITION(validerPointCardinal(p_coteRue))

		POSTCONDITION(m_type.compare(p_type) == 0);
		POSTCONDITION(m_lectureMetrique == p_lectureMetrique);
		POSTCONDITION(m_segmentRue == p_segmentRue);
		POSTCONDITION(m_numBorne.compare(p_numBorne) == 0);
		POSTCONDITION(m_coteRue.compare(p_coteRue) == 0);
		INVARIANTS();
}

/**
 * \brief Méthode permettant de faire une copie allouée sur le monceau de l'objet courant.
 * \return BorneStationnement Un nouvel objet.
 */
Borne* BorneStationnement::clone() const
{
	return new BorneStationnement(*this);
}

/**
 * \brief Méthode affichant le contenu de l'ensemble des attributs, dans un format de présentation.
 * \return string contenant des valeurs courantes formatées pour être affichées.
 */
std::string BorneStationnement::reqBorneFormate() const
{
	ostringstream monOsString;
		monOsString << "Borne de stationnement" << endl <<
				"------------------------------------------------" << endl <<
				Borne::reqBorneFormate() << endl <<
				"Distance mesuree\t" << ": " << m_lectureMetrique << endl <<
				"Segment de rue\t\t" << ": " << m_segmentRue << endl <<
				"Numero de la borne\t" << ": " << m_numBorne << endl <<
				"Cote de la rue\t\t" << ": " << m_coteRue << endl;

		return monOsString.str();
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_type".
 * \return m_type
 */
const std::string& BorneStationnement::reqType() const
{
	return m_type;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_coteRue".
 * \return m_coteRue
 */
double BorneStationnement::reqLectureMetrique() const
{
	return m_lectureMetrique;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_segmentRue".
 * \return m_segmentRue
 */
int BorneStationnement::reqSegmentRue() const
{
	return m_segmentRue;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_numBorne".
 * \return m_numBorne
 */
const std::string& BorneStationnement::reqNumBorne() const
{
	return m_numBorne;
}

/**
 * \brief Permet d'obtenir la valeur courante de "m_coteRue".
 * \return m_coteRue
 */
const std::string& BorneStationnement::reqCoteRue() const
{
	return m_coteRue;
}

/**
 * \brief Pour vérifier l'invariant de classe BorneStationnement, dans l'implantation de la théorie du contrat.
 */
void BorneStationnement::verifieInvariant() const
{
	INVARIANT((m_type == "stationnement" || m_type ==  "paiement")?true:false);
	INVARIANT(m_lectureMetrique > 0);
	INVARIANT(m_segmentRue > 0);
	INVARIANT(!m_numBorne.empty());
	INVARIANT(validerPointCardinal(m_coteRue))
}

} /* namespace tp */


