/**
 * \file UtiliationPrincipalBorne.cpp
 * \brief Fichier contenant le programme d'utilisation de projet TP3.
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-08
 */

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include "ValidationFormat.h"
#include "SaisieDonnees.h"

using namespace std;
using namespace tp;
//using namespace util;

//Utilisation de test parsonnalisés
const bool TEST_PERSONNALISE = false; ///< Utilisé pour activer ou non des tets personnalisés.
void testPersonnalise();



/**
 * \fn int main()
 * \brief Fonction d'entrée, permettant de lancer le programme et d'interagir avec l'utilisateur.
 * \return Un int confirmant la fin de l'exécution.
 */
int main()
{
	//utilisation ou non de tests personnalisés
	if (TEST_PERSONNALISE)
	{
		testPersonnalise();
	}
	else
	{
	//----------------------------------------------------------------------------------
	//**Définition du programme principal**
	// Déclarations des variables
	int short entreesCompletees = 1;
	istringstream valeursBornes("");
	istringstream valeursBornes2("");
	istringstream valeursBornesStationnement("");
	istringstream valeursBornesFontaine("");

	int p_idBorne = 0; //Borne1
	string p_direction = "";
	string p_nomTopographique = "";
	double p_longitude = 0.0;
	double p_latitude = 0.0;

	int p_idBorne2 = 0; //Borne2
	string p_direction2 = "";
	string p_nomTopographique2 = "";
	double p_longitude2 = 0.0;
	double p_latitude2 = 0.0;

	string p_type = ""; //BorneSationnement
	double p_lectureMetrique = 0.0;
	int p_segmentRue = 0;
	string p_numBorne = "";
	string p_coteRue = "";
	string p_ville = ""; //BorneFontaine
	string p_arrondissement = "";
	string chaineTemp = "";

	RegistreBorne registreDesBornes("bornes de la ville de Québec 2015"); //Création du registre

	//Message d'accueuil
	cout << "Ce programme permet d'entrer successivement les spécifications associés à:" <<
			"\n- Une \"borne de stationnement\"." <<
			"\n- Une \"borne fontaine\"." <<
			"\n\nAppuyer sur \"Enter\" pour commencer."	<< endl;
	cin.get();

	// Saisie de données
	while (entreesCompletees < 3) // il y aura 2 passes.
	{
		switch (entreesCompletees)
		{
			case 1: //au final:borne de stationnement
				cout << "-------------------------------------------------------------" << endl;
				cout << "Entrez les valeurs associées à la \"borne de stationnement\"." << endl;

				// borne générique
				valeursBornes.str(saisirDonneesBorne());
				valeursBornes 	>> p_idBorne
								>> p_direction
								>> p_longitude
								>> p_latitude;

				getline(valeursBornes,chaineTemp); // saisir la chaine incluant les espaces
				for (int unsigned i = 1; i < chaineTemp.length() ; ++i) //éliminer le premier espace.
				{
					p_nomTopographique += chaineTemp[i];
				}

				//borne stationnement spécifique
				valeursBornesStationnement.str(saisirDonneesBorneStationnement());
				valeursBornesStationnement	>> p_type
											>> p_lectureMetrique
											>> p_segmentRue
											>> p_numBorne
											>> p_coteRue;
			break;

			case 2: //au final: bonre fontaine
				cout << "\n-------------------------------------------------------------" << endl;
				cout << "Entrez les valeurs associées à la \"borne fontaine\"." << endl;

				// borne générique
				valeursBornes2.str(saisirDonneesBorne());
				valeursBornes2 	>> p_idBorne2
								>> p_direction2
								>> p_longitude2
								>> p_latitude2;

				chaineTemp = "";
				getline(valeursBornes2,chaineTemp); // saisir la chaine incluant les espaces
				for (int unsigned i = 1; i < chaineTemp.length() ; ++i) //éliminer le premier espace.
				{
					p_nomTopographique2 += chaineTemp[i];
				}

				// borne fontaine
				valeursBornesFontaine.str(saisirDonneesBorneFontaine());
				valeursBornesFontaine	>> p_ville;

				chaineTemp = "";
				getline(valeursBornesFontaine,chaineTemp); // saisir la chaine incluant les espaces
				for (int unsigned i = 1; i < chaineTemp.length() ; ++i) //éliminer le premier espace.
				{
					p_arrondissement += chaineTemp[i];
				}
			break;
		}
		try // Utilisation du mécanisme test des des exception au contrat
		{
			//Instanciation des bornes
			if (entreesCompletees == 1) //borne stationnement
			{
				BorneStationnement borneStationnement1(p_idBorne,p_direction,p_nomTopographique,p_longitude,p_latitude,p_type,p_lectureMetrique,p_segmentRue,p_numBorne,p_coteRue);
				registreDesBornes.ajouterBorne(borneStationnement1);
			}
			else
			{
				BorneFontaine borneFontaine1(p_idBorne2,p_direction2,p_nomTopographique2,p_longitude2,p_latitude2,p_ville,p_arrondissement);
				registreDesBornes.ajouterBorne(borneFontaine1);
			}
		}
		catch (ContratException& e)
		{
		  cout << e.reqTexteException() << endl;//traitement de l'erreur de contrat
		}

		entreesCompletees ++;
	}// while

		try // Utilisation du mécanisme test des des exception au contrat
		{
			// Affichage du contenu du registre
			cout << registreDesBornes.reqRegistreBorneFormate();
			cout << "\nProgramme terminé!" << endl;
		}
		catch (ContratException& e)
		{
		  cout << e.reqTexteException() << endl;//traitement de l'erreur de contrat
		}
	}
	return 0;
}

/**
 * \fn int testPersonnalise()
 * \brief Fonction utilisée pour faire des test personnalisées
 */
void testPersonnalise()
{
	try
	{
	//**Borne fontaine-Début
	BorneFontaine borneFontaine1(103270,"","Boulevard de L'Ormière",-71.35887584,46.83814462,"Québec","La Haute-Saint-Charles");
	BorneFontaine borneFontaine2(103270,"","Boulevard de L'Ormière",-71.35887584,46.83814462,"Québec","La Haute-Saint-Charles");
	BorneFontaine borneFontaine3(103270,"","Boulevard de L'Ormière",-71.35887584,46.83814462,"Québec","La Haute-Saint-Charles");
//	cout << borneFontaine1.reqBorneFormate()<< endl;

	//**Borne fontaine-Fin

	//Borne de stationnement-Début
	BorneStationnement borneStationnement1 (300070,"Nord","Boulevard René-Levesque Est",-71.226669,46.814323,"stationnement",23.7,20,"2172","Nord");
	BorneStationnement borneStationnement2 (300070,"Nord","Boulevard René-Levesque Est",-71.226669,46.814323,"stationnement",23.7,20,"2172","Nord");
	BorneStationnement borneStationnement3 (300070,"Nord","Boulevard René-Levesque Est",-71.226669,46.814323,"stationnement",23.7,20,"2172","Nord");
//	cout << "\n\n" << borneStationnement1.reqBorneFormate()<< endl;

	//Borne de stationnement-Fin


	//**RegistreBorne-Début
	RegistreBorne registreBorne1 ("bornes de la ville de Québec 2015"); //instanciation d'un registre
	//RegistreBorne-Fin

	//UtilisationPrincipale-Début
	registreBorne1.ajouterBorne(borneStationnement1);
	registreBorne1.ajouterBorne(borneStationnement2);
	registreBorne1.ajouterBorne(borneStationnement3);

	//doublon
	registreBorne1.ajouterBorne(borneStationnement1);
	registreBorne1.ajouterBorne(borneStationnement2);
	registreBorne1.ajouterBorne(borneStationnement3);

	//------------------

	registreBorne1.ajouterBorne(borneFontaine1);
	registreBorne1.ajouterBorne(borneFontaine2);
	registreBorne1.ajouterBorne(borneFontaine3);

	//doublon
	registreBorne1.ajouterBorne(borneFontaine1);
	registreBorne1.ajouterBorne(borneFontaine2);
	registreBorne1.ajouterBorne(borneFontaine3);


	cout << registreBorne1.reqRegistreBorneFormate() << endl;
	//UtilisationPrincipale-Fin

	}
	catch (ContratException& e)
	{
	  cout << e.reqTexteException() << endl;//traitement de l'erreur de contrat
	}


}

