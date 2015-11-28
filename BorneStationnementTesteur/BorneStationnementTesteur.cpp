/**
 * \file BorneStationnementTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe BorneStationnement
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-08
 */

#include <gtest/gtest.h>
//#include "Borne.h"
#include "BorneStationnement.h"
#include "ValidationFormat.h"

using namespace tp;
using namespace std;
using namespace util;

/**
 * \brief Test du constructeur avec paramètres\n
 * 	constructeurParametreValide: Création d'un objet BorneStationnement avec des valeurs valides.<p>
 *
 *  Cas valides:
 *  - Tous les paramètres\n\n
 *	  Vérifier les 6 cas ci-dessous, qui sont eux mêmes valider par la méthode "validerPointCardinal"
 *	- pointCardinalNordValide: Vérification du point cardinal "Nord".
 *	- pointCardinalSudValide: Vérification du point cardinal "Sud".
 *	- pointCardinalEstdValide: Vérification du point cardinal "Est".
 *	- pointCardinalOuestValide: Vérification du point cardinal "Ouest".
 *	- pointCardinalNullValide: Vérification du point cardinal "null".
 *	- pointCardinalChaineVideValide: Vérification du point cardinal "".
 *
 *	Cas invalides:
 *	- typeInvalide: m_type ne contient pas "stationnement" ou "paiement".
 *	- lectureMetriqueInvalide: m_lectureMetrique n'est pas plus grand que 0.
 *	- segmentRueInvalide: m_segmentRue n'est pas plus grand que 0.
 *	- numBorneInvalide: m_numBorne est vide
 *	- coteRueInvalide: m_coteRue n'est pas une des 6 possibilitées valides (voir ci-haut).
  */
TEST(BorneStationnement,ConstructeurParametreValide)
{
	BorneStationnement borneStationnement1 (1,
											"Nord",
											"nomTopo",
											123.4,
											432.1,
											"stationnement",
											567.8,
											500,
											"NoBorne",
											"Sud");
	ASSERT_EQ(1,borneStationnement1.reqIdBorne());
	ASSERT_EQ("Nord",borneStationnement1.reqDirection());
	ASSERT_EQ("nomTopo",borneStationnement1.reqNomTopographique());
	ASSERT_EQ(123.4,borneStationnement1.reqLongitude());
	ASSERT_EQ(432.1,borneStationnement1.reqLatitude());
	ASSERT_EQ("stationnement",borneStationnement1.reqType());
	ASSERT_EQ(567.8,borneStationnement1.reqLectureMetrique());
	ASSERT_EQ(500,borneStationnement1.reqSegmentRue());
	ASSERT_EQ("NoBorne",borneStationnement1.reqNumBorne());
	ASSERT_EQ("Sud",borneStationnement1.reqCoteRue());
}

/**
 * \brief Test de validation du point cardinal "Nord".
 */
TEST(BorneStationnement,PointCardinalNordValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","Nord");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

/**
 * \brief Test de validation du point cardinal "Sud".
 */
TEST(BorneStationnement,PointCardinalSudValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","Sud");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

/**
 * \brief Test de validation du point cardinal "Est".
 */
TEST(BorneStationnement,PointCardinalEstValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","Est");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

/**
 * \brief Test de validation du point cardinal "Ouest".
 */
TEST(BorneStationnement,PointCardinalOuestValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","Ouest");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

/**
 * \brief Test de validation du point cardinal "null".
 */
TEST(BorneStationnement,PointCardinalNullValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","null");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

/**
 * \brief Test de validation du point cardinal ""  (chaîne vide).
 */
TEST(BorneStationnement,PointCardinalChaineVidelValide)
{
	BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","");
	ASSERT_TRUE(validerPointCardinal(borneStationnement1.reqCoteRue()));
}

//Cas invalide
/**
 * \brief Test d'un type ne contenant pas "stationnement" ou "paiement".
 */
TEST(BorneStationnement,TypeInvalide)
{
	ASSERT_THROW(BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"ErreurType",567.8,500,"NoBorne","Sud"),ContratException);
}

/**
 * \brief Test de lectureMetrique avec une valeur pas plus grande que 0
 */
TEST(BorneStationnement,LectureMetriqueInvalide)
{
	ASSERT_THROW(BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",0,500,"NoBorne","Sud"),ContratException);
}

/**
 * \brief Test de segmentRue avec une valeur pas plus grande que 0
 */
TEST(BorneStationnement,segmentRueInvalide)
{
	ASSERT_THROW(BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,0,"NoBorne","Sud"),ContratException);
}

/**
 * \brief Test de numBorne avec aucne valeur (vide)
 */
TEST(BorneStationnement,numBorneInvalide)
{
	ASSERT_THROW(BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"","Sud"),ContratException);
}

/**
 * \brief Test de coteRue avec une valeur que celles validées par les 6 permises (voir test du constructeur).
 */
TEST(BorneStationnement,coteRueInvalide)
{
	ASSERT_THROW(BorneStationnement borneStationnement1 (1,"Nord","nomTopo",123.4,432.1,"stationnement",567.8,500,"NoBorne","ErreurCoteRue"),ContratException);
}

/**
 * \class BorneStationnementFixture
 * \brief Création d'une fixture pour exécuter une série de test sur différentes méthodes de la classe "BorneStationnement".
 */
class BorneStationnementFixture:public ::testing::Test
{
public:
	BorneStationnementFixture():
		m_borneStationnement(1,"Nord","nomTopo",123.4,432.1,"paiement",567.8,500,"NoBorne10","Nord"){}

	BorneStationnement m_borneStationnement; /**< Instanciation d'un objet "BorneStationnement" dans l'attribut "m_borneStationnement" de la classe "BorneStationnementFixture". */
};

/**
 * \fn TEST_F(BorneStationnementFixture,reqBorneFormate)
 * \brief Test de la méthode "reqBorneFormate"\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqBorneFormate".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqBorneFormate)
{
	ostringstream monOsString;
	monOsString << "Borne de stationnement" << endl <<
					"------------------------------------------------" << endl <<
					m_borneStationnement.Borne::reqBorneFormate() << endl <<
					"Distance mesuree\t" << ": " << 567.8 << endl <<
					"Segment de rue\t\t" << ": " << 500 << endl <<
					"Numero de la borne\t" << ": " << "NoBorne10" << endl <<
					"Cote de la rue\t\t" << ": " << "Nord" << endl;

		ASSERT_EQ(monOsString.str(),m_borneStationnement.reqBorneFormate());
}

/**
 * \fn TEST_F(BorneStationnementFixture,reqTypePaiement)
 * \brief Test de la méthode reqType()\n
 *  Cas valide:
 *  - Vérifier la valeur de retour du type lorsque "paiement est utilisé.
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqTypePaiement)
{
	ASSERT_EQ("paiement",m_borneStationnement.reqType());
}

/**
 * \fn TEST_F(BorneStationnementFixture,reqLectureMetrique)
 * \brief Test de la méthode "reqLectureMetrique"\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqLectureMetrique".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqLectureMetrique)
{
	ASSERT_EQ(567.8,m_borneStationnement.reqLectureMetrique());
}

/**
 * \fn TEST_F(BorneStationnementFixture,reqSegmentRue)
 * \brief Test de la méthode "reqSegmentRue".\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqSegmentRue".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqSegmentRue)
{
	ASSERT_EQ(500,m_borneStationnement.reqSegmentRue());
}

/**
 * \fn TEST_F(BorneStationnementFixture,reqNumBorne)
 * \brief Test de la méthode "reqNumBorne".\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqNumBorne".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqNumBorne)
{
	ASSERT_EQ("NoBorne10",m_borneStationnement.reqNumBorne());
}

/**
 * \fn TEST_F(BorneStationnementFixture,reqCoteRue)
 * \brief Test de la méthode "reqCoteRue"\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqCoteRue".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneStationnementFixture,reqCoteRue)
{
	ASSERT_EQ("Nord",m_borneStationnement.reqCoteRue());
}




