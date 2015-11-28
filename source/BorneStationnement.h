/**
 * \file BorneStationnement.h
 * \brief Fichier contenan l'interface de la classe "BorneStationnement".
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-14
 */

#ifndef BORNESTATIONNEMENT_H_
#define BORNESTATIONNEMENT_H_
#include <string>
#include "Borne.h"

namespace tp
{

/**
 * \class BorneStationnement
 * \brief classe permettant la gestion des bornes fontaine et de stationnement.
 */
class BorneStationnement: public Borne
{

public:

	//constructeur
	BorneStationnement(
				int p_idBorne,
				const std::string& p_direction,
				const std::string& p_nomTopographique,
				double p_longitude,
				double p_latitude,
				const std::string& p_type,
				double p_lectureMetrique,
				int p_segmentRue,
				const std::string& p_numBorne,
				const std::string& p_coteRue);

	//méthodes
	virtual Borne* clone() const;
	virtual std::string reqBorneFormate() const;

	//accesseurs

	const std::string& reqCoteRue() const;
	double reqLectureMetrique() const;
	const std::string& reqNumBorne() const;
	int reqSegmentRue() const;
	const std::string& reqType() const;

private:

	//attributs
	std::string m_type;
	double m_lectureMetrique;
	int m_segmentRue;
	std::string m_numBorne;
	std::string m_coteRue;

	//méthodes
	void verifieInvariant() const;


};
} /* namespace tp */

#endif /* BORNESTATIONNEMENT_H_ */
