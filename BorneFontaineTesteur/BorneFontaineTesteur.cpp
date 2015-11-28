/**
 * \file BorneFontaineTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe BorneFontaine
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-08
 */

#include <gtest/gtest.h>
//#include "Borne.h"
#include "BorneFontaine.h"

using namespace tp;
using namespace std;

/**
 * \brief Test du constructeur avec paramètres\n
 * 	constructeurParametreValide: Création d'un objet BorneFontaine avec des valeurs valides.<p>
 *
 *  Cas valides:
 *  - Tous les paramètres\n\n
 *
 *	Cas invalides:
 *	- ArrondissementInvalide: m_nomTopographique est vide lorsque "m_ville == Qubec".
  */
TEST(BorneFontaine,ConstructeurParametreValide)
{
	BorneFontaine borneFontaine1 (1,"Nord","nomTopo",123.4,432.1,"Québec","La Haute-Saint-Charles");
	ASSERT_EQ(1,borneFontaine1.reqIdBorne());
	ASSERT_EQ("Nord",borneFontaine1.reqDirection());
	ASSERT_EQ("nomTopo",borneFontaine1.reqNomTopographique());
	ASSERT_EQ(123.4,borneFontaine1.reqLongitude());
	ASSERT_EQ(432.1,borneFontaine1.reqLatitude());
	ASSERT_EQ("Québec",borneFontaine1.reqVille());
	ASSERT_EQ("La Haute-Saint-Charles",borneFontaine1.reqArrondissement());
}

//Cas invalide
/**
 * \brief Test d'une entrée vide pour "m_arrondissement", lorsque "m_ville == Qubec"
 */
TEST(BorneFontaine,ArrondissementInvalide)
{
	ASSERT_THROW(BorneFontaine bonreFontaine(1,"Nord","nomTopo",123.4,432.1,"Québec",""),ContratException);
}

/**
 * \class BorneFontaineFixture
 * \brief Création d'une fixture pour exécuter une série de test sur différentes méthodes de la classe "BorneFontaine".
 */
class BorneFontaineFixture:public ::testing::Test
{
public:
	BorneFontaineFixture():
		m_borneFontaine(1,"Nord","nomTopo",123.4,432.1,"Québec","La Haute-Saint-Charles"){}

	BorneFontaine m_borneFontaine; /**< Instanciation d'un objet "BorneFontaine" dans l'attribut "m_borneFontaine" de la classe "BorneFontaineFixture". */
};

/**
 * \fn TEST_F(BorneFontaineFixture,reqBorneFormate)
 * \brief Test de la méthode "reqBorneFormate"\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqBorneFormate".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneFontaineFixture,reqBorneFormate)
{
	ostringstream monOsString;
	monOsString << "Borne fontaine" << endl <<
				"------------------------------------------------" << endl <<
				m_borneFontaine.Borne::reqBorneFormate() << endl <<
				"Ville\t\t\t" << ": " << "Québec" << endl <<
				"Arrondissement\t\t" << ": " << "La Haute-Saint-Charles" << endl;

	ASSERT_EQ(monOsString.str(),m_borneFontaine.reqBorneFormate());
}

/**
 * \fn TEST_F(BorneFontaineFixture,reqVille)
 * \brief Test de la méthode reqVille()\n
 *  Cas valide:
 *  - Vérifier le retour du nom de la ville de la borne fontaine.
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneFontaineFixture,reqVille)
{
	ASSERT_EQ("Québec",m_borneFontaine.reqVille());
}

/**
 * \fn TEST_F(BorneFontaineFixture,reqArrondissement)
 * \brief Test de la méthode reqArrondissement()\n
 *  Cas valide:
 *  - Vérifier le retour du nom de l'arrondissement de la borne fontaine.
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneFontaineFixture,reqArrondissement)
{
	ASSERT_EQ("La Haute-Saint-Charles",m_borneFontaine.reqArrondissement());
}









