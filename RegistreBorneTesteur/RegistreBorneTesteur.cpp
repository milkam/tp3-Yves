/**
 * \file RegistreBorneTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe RegistreBorne
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-08
 */

#include <gtest/gtest.h>
#include "RegistreBorne.h"

using namespace std;
using namespace tp;

/**
 * \brief Test du constructeur avec paramètres\n
 * 	constructeurParametreValide: Création d'un objet RegistreBorne avec des valeurs valides.<p>
 *
 *  Cas valides:
 *  - Tous les paramètres\n\n
 *
 *	Cas invalides:
 *	- Aucun. Dans le contexte actuel, l'unique paramètres requis est passé par le probramme.
  */
TEST(RegistreBorne,ConstructeurParametreValide)
{
	RegistreBorne registreBorne1 ("bornes de la ville de Québec 2015");
	ASSERT_EQ("bornes de la ville de Québec 2015",registreBorne1.reqNomRegistreBorne());
}

/**
 * \class RegistreBorneFixture
 * \brief Création d'une fixture pour exécuter une série de test sur différentes méthodes de la classe "RegistreBorne".
 */
class RegistreBorneFixture:public ::testing::Test
{
public:
	RegistreBorneFixture():
		m_registreBorne("bornes de la ville de Québec 2015"){}

	RegistreBorne m_registreBorne; /**< Instanciation d'un objet "RegistreBorne" dans l'attribut "m_registreBorne" de la classe "RegistreBorneFixture". */
};

/**
 * \fn TEST_F(RegistreBorneFixture,reqRegistreBorneFormate)
 * \brief Test de la méthode "reqRegistreBorneFormate"\n
 *  Cas valide:
 *  - Vérifier la valeur de retour de la méthode "reqRegistreBorneFormate".
 *
 *  Cas invalide:
 *  - Aucun.
 */
TEST_F(RegistreBorneFixture,reqRegistreBorneFormate)
{
	// **À développer...

//	ostringstream monOsString;
//	monOsString <<
//			"Registre" << endl <<
//			"------------------------------------------------" << endl <<
//			m_borneFontaine.Borne::reqBorneFormate() << endl <<
//			"Ville\t\t\t" << ": " << "Québec" << endl <<
//			"Arrondissement\t\t" << ": " << "La Haute-Saint-Charles" << endl;
//
//	ASSERT_EQ(monOsString.str(),m_borneFontaine.reqBorneFormate());
}
