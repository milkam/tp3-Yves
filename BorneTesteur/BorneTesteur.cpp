/**
 * \file BorneTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe abstraite Borne
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-07
 */

#include <gtest/gtest.h>
#include "Borne.h"
#include "ValidationFormat.h"
#include <iomanip>
using namespace std;
using namespace tp;
using namespace util;

/**
 * \class BorneDeTest
 * \brief Classe de test dérivé de la classe abstraite "Borne".
 */
class BorneDeTest: public Borne
{
public:
/**
 * \brief Constructeur de la classe "BorneDeTest"
 */
	BorneDeTest(int p_idBorne,
				const std::string& p_direction,
				const std::string& p_nomTopographique,
				double p_longitude,
				double p_latitude):
				Borne(p_idBorne,p_direction,p_nomTopographique,
					  p_longitude,p_latitude)
	{
	}

	/**
	 * \brief Implantation de la méthode virtuelle "reqBorneFormate".
	 */
	virtual string reqBorneFormate() const
	{
		return Borne::reqBorneFormate();
	};

	/**
	 * \brief Implantation de la méthode virtuelle "clone".
	 */
	virtual Borne* clone() const
	{
		return new BorneDeTest(*this);
	};
};

/**
 * \brief Test du constructeur avec paramètres\n
 * 	constructeurParametreValide: Création d'un objet Borne avec des valeurs valides.<p>
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
 *	- nomTopoInvalide: m_nomTopographique est vide
 *	- pointCardinalInvalide: N'est pas une des 6 possibilitées valides (voir ci-haut).
  */
TEST(Borne,ConstructeurParametreValide)
{
	BorneDeTest borneDeTest (1,"Nord","nomTopo",123.4,432.1);
	ASSERT_EQ(1,borneDeTest.reqIdBorne());
	ASSERT_EQ("Nord",borneDeTest.reqDirection());
	ASSERT_EQ("nomTopo",borneDeTest.reqNomTopographique());
	ASSERT_EQ(123.4,borneDeTest.reqLongitude());
	ASSERT_EQ(432.1,borneDeTest.reqLatitude());
}

/**
 * \brief Test de validation du point cardinal "Nord".
 */
TEST(Borne,PointCardinalNordValide)
{
	BorneDeTest borneTest (1,"Nord","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

/**
 * \brief Test de validation du point cardinal "Sud".
 */
TEST(Borne,PointCardinalSudValide)
{
	BorneDeTest borneTest (1,"Sud","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

/**
 * \brief Test de validation du point cardinal "Est".
 */
TEST(Borne,PointCardinalEstValide)
{
	BorneDeTest borneTest (1,"Est","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

/**
 * \brief Test de validation du point cardinal "Ouest".
 */
TEST(Borne,PointCardinalOuestValide)
{
	BorneDeTest borneTest (1,"Ouest","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

/**
 * \brief Test de validation du point cardinal "null".
 */
TEST(Borne,PointCardinalNullValide)
{
	BorneDeTest borneTest (1,"null","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

/**
 * \brief Test de validation du point cardinal "" (chaîne vide)
 */
TEST(Borne,PointCardinalChaineVideValide)
{
	BorneDeTest borneTest (1,"","nomTopo",123.4,432.1);
	ASSERT_TRUE(validerPointCardinal(borneTest.reqDirection()));
}

//Cas invalide
/**
 * \brief Test d'une entrée vide pour "nomTopographique".
 */
TEST(Borne,NomTopographiqueInvalide)
{
	ASSERT_THROW(BorneDeTest borneTest(1,"Nord","",123.4,432.1),ContratException);
}

/**
 * \brief Test de validation du point cardinal qui n'est pas "légal".
 */
TEST(Borne,PointCardinalInvalide)
{
	ASSERT_THROW(BorneDeTest borneTest(1,"Erreur","nomTopo",123.4,432.1),ContratException);
}

/**
 * \class BorneFixture
 * \brief Création d'une fixture pour exécuter une série de test sur différentes méthodes de la classe "BorneDeTest".
 *
 */
class BorneFixture:public ::testing::Test
{
public:
	BorneFixture():
		m_borne(1,"Nord","nomTopo",-71.35887584,46.83814462){}

	BorneDeTest m_borne; /**< Instanciation d'un objet "BorneDeTest" dans l'attribut "m_borne" de la classe "BorneFixture". */
};

/**
 * \fn TEST_F(BorneFixture,reqIdBorne)
 * \brief Test de la méthode reqIdBorne()\n
 *  Cas valide:
 *  - Vérifier le retour de l'identification de la borne.
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneFixture, reqIdBorne)
{
	ASSERT_EQ(1,m_borne.reqIdBorne());
}

/**
 * \fn TEST_F(BorneFixture,reqDirection)
 * \brief Test de la méthode reqDirection()\n
 *  Cas valide:
 *  - Vérifier du  point cardinal "Nord".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(BorneFixture,reqDirection)
{
	ASSERT_EQ("Nord",m_borne.reqDirection());
}

/**
* \fn TEST_F(BorneFixture,reqBorneFormate)
 * \brief Test de la méthode reqBorneFormate()\n
 *  Cas valide:
 *  - Vérifier le retour de la chaine formatée, affichant le contenu des attributs.

 *  Cas invalide:
 *  - Aucun identifié
 */
TEST_F(BorneFixture,reqBorneFormate)
{
	ostringstream monOsString;
	monOsString <<
				"Identifiant de la borne\t" << ": " << 1 << endl <<
				"Direction\t\t" << ": " << "Nord" << endl <<
				"Nom topographique\t" << ": " << "nomTopo" << endl <<
				"Longitude\t\t" << ": " << setprecision(10) << -71.35887584 << endl <<
				"Latitude\t\t" << ": " << setprecision(10) << 46.83814462;

	ASSERT_EQ(monOsString.str(),m_borne.reqBorneFormate());
}

/**
 * \brief Test de la méthode reqNomTopographique()\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de l'attribut "m_nomTopographique"

 *  Cas invalide:
 *  - Aucun identifié
 */
TEST_F(BorneFixture,reqNomTopographique)
{
	ASSERT_EQ("nomTopo",m_borne.reqNomTopographique());
}

/**
 * \fn TEST_F(BorneFixture,asgNomTopographiqueValide)
 * \brief Test de la méthode asgNomTopographique()\n
 *  Cas valide:
 *  - Vérifier la valeur assignée à l'attribut "m_nomTopographique"
 */
TEST_F(BorneFixture,asgNomTopographiqueValide)
{
	m_borne.asgNomTopographique("NouveauNomTopo");
	ASSERT_EQ("NouveauNomTopo",m_borne.reqNomTopographique());
}

/**
 * \fn TEST_F(BorneFixture,asgNomTopographiqueInvalide)
 * \brief Test de la méthode asgNomTopographique()\n
  *  Cas invalide:
 *  - Entrée vide
 */
TEST_F(BorneFixture,asgNomTopographiqueInvalide)
{
	ASSERT_THROW(m_borne.asgNomTopographique(""),PreconditionException);
}





